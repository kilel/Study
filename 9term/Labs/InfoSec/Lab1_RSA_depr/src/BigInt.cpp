#include "../include/BigInt.h"
namespace long_math {

BigInt *ZERO = new BigInt(0);
BigInt *ONE = new BigInt(1);
BigInt *TWO = new BigInt(2);

BigInt::BigInt() : BigInt(0) {
}

BigInt::BigInt(int value) {
    innerData = new BigIntData(0);
    if(value < 0) {
        sign = -1;
        value = -value;
    } else {
        sign = 1;
    }
    if(value == 0) {
        innerData->push_back(0);
    }
    int temp = value;
    while(temp != 0) {
        innerData->push_back(temp % MODULE);
        temp /= MODULE;
    }
}

BigInt::~BigInt() {
    innerData->clear();
    delete innerData;
}

BigInt::BigInt(BigIntData& source) {
    innerData = new BigIntData(0);
    this->sign = 1;
    for(BigIntData::iterator it = source.begin(); it != source.end(); ++it) {
        innerData->push_back(*it);
    }
}

BigInt::BigInt(const BigInt& source) {
    innerData = new BigIntData(0);
    this->sign = source.sign;
    for(BigIntData::iterator it = source.innerData->begin(); it != source.innerData->end(); ++it) {
        innerData->push_back(*it);
    }
}

void BigInt::copy(BigInt& source) {
    innerData->clear();
    this->sign = source.sign;
    for(BigIntData::iterator it = source.innerData->begin(); it != source.innerData->end(); ++it) {
        innerData->push_back(*it);
    }
}

BigIntData* BigInt::getData() {
    return innerData;
}

BigInt* BigInt::shift(int digits) {
    if(digits == 0) {
        return this;
    }
    int lastSize = innerData->size();
    if(digits > 0) {
        for(int i = 0; i < digits; ++i) {
            innerData->push_back(0);
        }
        for(int i = lastSize - 1; i >= 0; --i) {
            (*innerData)[i + digits] = (*innerData)[i];
        }
        for(int i = 0; i < digits; ++i) {
            (*innerData)[i] = 0;
        }
    } else {
        if(digits >= lastSize) {
            innerData->clear();
            innerData->push_back(0);
            return this;
        }
        for(int i = digits; i < lastSize; ++i) {
            (*innerData)[i-digits] = (*innerData)[i];
        }
        for(int i = 0; i < digits; ++i) {
            innerData->pop_back();
        }
    }
    return this;
}

BigInt* BigInt::add(BigInt& value) {
    if(value.sign != this->sign) {
        BigInt *tempVal = new BigInt(value);
        tempVal->sign *= -1;
        this->sub(*tempVal);
        delete tempVal;
        return this;
    }
    int overflow = 0;
    for(BigIntData::iterator it_this = innerData->begin(), it_val = value.innerData->begin() ;
            it_this != innerData->end() || it_val != value.innerData->end() ;) {
        if(it_val == value.innerData->end() && overflow == 0) { //no data to add from addition operand
            break;
        }
        int currData = overflow;
        if(it_val != value.innerData->end()) {
            currData += *it_val * value.sign;
            ++it_val;
        }
        if(it_this != innerData->end()) {
            currData += *it_this * this->sign;
            *it_this = currData % MODULE;
            ++it_this;
        } else {
            innerData->push_back(currData % MODULE);
            it_this = innerData->end();
        }
        overflow = currData / MODULE;
    }
    if(overflow != 0) {
        this->innerData->push_back(overflow);
    }

    return this;
}

BigInt* BigInt::sub(BigInt& value) {
    if(value.sign != this->sign) {
        BigInt *tempVal = new BigInt(value);
        tempVal->sign *= -1;
        this->add(*tempVal);
        delete tempVal;
        return this;
    }

    if(cmp(value) == 0) {
        innerData->clear();
        innerData->push_back(0);
        sign = 1;
        return this;
    }
    BigInt *subBase = new BigInt(), *subActive = new BigInt();
    int overflow = 0;
    bool isLower = false;
    if (cmp(value) < 0) {
        isLower = true;
        subBase->copy(value);
        subActive->copy(*this);
    } else {
        subBase->copy(*this);
        subActive->copy(value);
    }

    for(BigIntData::iterator it_base = subBase->innerData->begin(), it_val = subActive->innerData->begin() ;
            it_base != subBase->innerData->end() || it_val != subActive->innerData->end() ;) {
        if(it_val == subActive->innerData->end() && overflow == 0) { //no data to add from addition operand
            break;
        }
        int currData = overflow;
        if(it_val != subActive->innerData->end()) {
            currData -= *it_val;
            ++it_val;
        }
        if(it_base != subBase->innerData->end()) {
            currData += *it_base;
            if(currData < 0 ) {
                overflow = -1;
                currData += MODULE;
            } else {
                overflow = 0;
            }
            *it_base = currData % MODULE;
            ++it_base;
        }
    }
    if(overflow != 0) {
        subBase->innerData->push_back(overflow);
    }
    this->copy(*subBase);
    if(isLower) {
        this-> sign *= -1;
    }

    delete subBase;
    delete subActive;

    while(*(this->innerData->end() - 1) == 0) {
        this->innerData->pop_back();
    }

    return this;
}

BigInt* BigInt::mult(int value) {
    assert(value <= MODULE);
    if(value < 0) {
        value *= -1;
        this->sign *= -1;
    }
    int overflow = 0;
    for(BigIntData::iterator it_this = innerData->begin(); it_this != innerData->end(); ++it_this) {
        int currData = (*it_this) * value + overflow;
        *it_this = currData % MODULE;
        overflow = currData / MODULE;
    }
    if(overflow != 0) {
        this->innerData->push_back(overflow);
    }
    return this;
}

BigInt* BigInt::mult(BigInt& value) {
    BigInt* sumOfMult = new BigInt(0);
    BigInt* tempVal = new BigInt(0);
    int shift = 0;
    for(BigIntData::iterator it_val = value.innerData->begin(); it_val != value.innerData->end(); ++it_val) {
        tempVal->copy(*this);
        tempVal->mult(*it_val);
        tempVal->shift(shift++);
        sumOfMult->add(*tempVal);
    }
    this->copy(*sumOfMult);
    delete sumOfMult;
    delete tempVal;
    return this;
}

pair<BigInt*, BigInt*> BigInt::divMod(int value) {
    assert (value < MODULE);

    BigInt* temp = new BigInt(0);
    temp->copy(*this);
    if(value < 0) {
        value *= -1;
        temp->sign *= -1;
    }
    int overfloat = 0;
    int mod = 0;
    for(BigIntData::iterator it = temp->innerData->end() - 1; it != temp->innerData->begin() - 1; --it) {
        int currData = overfloat * MODULE + *it;
        *it = currData / value;
        overfloat = currData % value;
    }
    mod = overfloat;
    return pair<BigInt*, BigInt*>(temp, new BigInt(mod));
}

BigInt* BigInt::div(int value) {
    DivModData temp = divMod(value);
    this->copy(*(temp.first));
    delete temp.first;
    delete temp.second;
    return this;
}

BigInt* BigInt::mod(int value) {
    if(value == 2) {
        if(*(innerData->begin()) % 2 == 1) {
            this->copy(*ONE);
        } else {
            this->copy(*ZERO);
        }
        return this;
    }
    DivModData temp = divMod(value);
    this->copy(*(temp.second));
    delete temp.first;
    delete temp.second;
    return this;
}

BigInt* BigInt::div(BigInt& value) {
    DivModData temp = divMod(value);
    this->copy(*(temp.first));
    delete temp.first;
    delete temp.second;
    return this;
}

BigInt* BigInt::mod(BigInt& value) {
    if(value.cmp(*TWO) == 0) {
        if(*(innerData->begin()) % 2 == 1) {
            this->copy(*ONE);
        } else {
            this->copy(*ZERO);
        }
        return this;
    }
    DivModData temp = divMod(value);
    this->copy(*(temp.second));
    delete temp.first;
    delete temp.second;
    return this;
}

DivModData BigInt::divMod(BigInt& value) {
    if(cmp(value) < 0) {
        return DivModData(new BigInt(0), new BigInt(*this));
    } else if (cmp(value) == 0) {
        return DivModData(new BigInt(1), new BigInt(0));
    }

    int resultSign = this->sign * value.sign;

    BigInt* base = new BigInt(*this);
    base->sign *= base->sign; // make sign == 1;

    BigIntData* divDataAggregator = new BigIntData(0);

    int shiftLength = base->innerData->size() - value.innerData->size();

    BigInt* dividor = new BigInt(value);
    for(int i = 0; i < shiftLength + 1; ++i) {
        dividor->copy(value);
        dividor->shift(shiftLength - i);
        dividor->sign *= dividor->sign; // make sign == 1;

        int resDiv = divSimple(*base, *dividor);
        divDataAggregator->push_back(resDiv);
        dividor->mult(resDiv);
        base->sub(*dividor);
    }

    base->sign *= resultSign;

    BigInt* mod = new BigInt(*base);
    BigInt* div = new BigInt(*base);

    div->innerData->clear();
    for(BigIntData::iterator it = divDataAggregator->end() - 1; it != divDataAggregator->begin() - 1; --it) {
        div->innerData->push_back(*it);
    }

    delete divDataAggregator;
    delete base;
    delete dividor;

    return DivModData(div, mod);
}

int BigInt::divSimple(BigInt& base, BigInt& dividor) {
    int cmpResult = base.cmp(dividor);
    if(cmpResult < 0) {
        return 0;
    } else if (cmpResult == 0) {
        return 1;
    }
    BigInt* temp = new BigInt(base);
    int left = 1, right = MODULE - 1;
    while (left < right) {
        int center = (left + right) >> 1;
        temp->copy(dividor);
        temp->mult(center);
        cmpResult = base.cmp(*temp);
        if (cmpResult < 0) {
            right = center - 1;
        } else if(cmpResult > 0) {
            left = center + 1;
        } else { // equals
            left = right = center;
        }
    }
    temp->copy(dividor);
    temp->mult(left);
    if(base.cmp(*temp) < 0) {
        left --;
    }
    delete temp;
    return left;
}

int BigInt::cmp(BigInt& value) {
    if(this->innerData->size() > value.innerData->size()) {
        return 1;
    } else if(this->innerData->size() < value.innerData->size()) {
        return -1;
    }
    size_t len = this->innerData->size();
    for(int i = len - 1; i >= 0; --i) {
        if((*(this->innerData))[i] > (*(value.innerData))[i]) {
            return 1;
        } else if((*(this->innerData))[i] < (*(value.innerData))[i]) {
            return -1;
        }
    }
    return 0;
}

BigInt* BigInt::powMod(BigInt& deg, BigInt& module) {
    vector<BigInt*> *pow2 = new vector<BigInt*>(0);
    vector<BigInt*> *pow2this = new vector<BigInt*>(0);
    pow2->push_back(new BigInt(1));
    pow2this->push_back(new BigInt(*this));
    //array of 2^n: maxDeg if first, such 2^maxDeg > deg.
    //parallelly build array of this^(2^i) by adding last*last to end.
    while(true) {
        vector<BigInt*>::iterator lastPow2 = pow2->end() - 1;
        vector<BigInt*>::iterator lastPow2This = pow2this->end() - 1;
        BigInt* temp = new BigInt(**lastPow2This);
        pow2this->push_back(temp->mult(*temp));

        temp = new BigInt(**lastPow2);
        pow2->push_back(temp->mult(*temp));

        if(*temp > deg) {
            break;
        }
    }
    //for each 2^n check, if it exists in deg.
    BigInt* ret = new BigInt(*ONE);
    BigInt* temp = new BigInt();
    for(size_t i = 0; i < pow2->size(); ++i) {
        temp->copy(deg);
        temp->div(*pow2->at(i));
        if(*temp->mod(*TWO) == *ONE) {
            ret->mult(*pow2this->at(i));
            ret->mod(module);
        }
    }

    this->copy(*ret);

    delete temp;
    for(size_t i = 0; i < pow2->size(); ++i) {
        delete (*pow2)[i];
        delete (*pow2this)[i];
    }
    delete[] pow2;
    delete[] pow2this;
    delete ret;

    return this;
}

void BigInt::print(string message) {
    if(message != "") {
        cout << message << ": ";
    }
    BigIntData::iterator it = innerData->end() - 1;
    printf("%d", *it);
    while(--it != innerData->begin() - 1) {
        printf("%04d", *it);
    }
}
void BigInt::println(string message) {
    print(message);
    printf("\n");
}

////
////
////

BigInt& operator+ (BigInt& left, BigInt& right) {
    BigInt* ret = new BigInt(left);
    ret->add(right);
    return *ret;
}

BigInt& operator+ (int left, BigInt& right) {
    BigInt* ret = new BigInt(right), *temp = new BigInt(left);
    ret->add(*temp);
    delete temp;
    return *ret;
}

BigInt& operator+ (BigInt& left, int right) {
    BigInt* ret = new BigInt(left), *temp = new BigInt(right);
    ret->add(*temp);
    delete temp;
    return *ret;
}

BigInt& operator- (BigInt& left, BigInt& right) {
    BigInt* ret = new BigInt(left);
    ret->sub(right);
    return *ret;
}

BigInt& operator- (int left, BigInt& right) {
    BigInt* ret = new BigInt(right), *temp = new BigInt(left);
    ret->sub(*temp);
    delete temp;
    return *ret;
}

BigInt& operator- (BigInt& left, int right) {
    BigInt* ret = new BigInt(left), *temp = new BigInt(right);
    ret->sub(*temp);
    delete temp;
    return *ret;
}

BigInt& operator* (BigInt& left, BigInt& right) {
    BigInt* ret = new BigInt(left);
    ret->mult(right);
    return *ret;
}

BigInt& operator* (int left, BigInt& right) {
    BigInt* ret = new BigInt(right), *temp = new BigInt(left);
    ret->mult(*temp);
    delete temp;
    return *ret;
}

BigInt& operator* (BigInt& left, int right) {
    BigInt* ret = new BigInt(left), *temp = new BigInt(right);
    ret->mult(*temp);
    delete temp;
    return *ret;
}

BigInt& operator/ (BigInt& left, BigInt& right) {
    BigInt* ret = new BigInt(left);
    ret->div(right);
    return *ret;
}

BigInt& operator/ (int left, BigInt& right) {
    BigInt* ret = new BigInt(right), *temp = new BigInt(left);
    ret->div(*temp);
    delete temp;
    return *ret;
}

BigInt& operator/ (BigInt& left, int right) {
    BigInt* ret = new BigInt(left), *temp = new BigInt(right);
    ret->div(*temp);
    delete temp;
    return *ret;
}

BigInt& operator% (BigInt& left, BigInt& right) {
    BigInt* ret = new BigInt(left);
    ret->mod(right);
    return *ret;
}

BigInt& operator% (int left, BigInt& right) {
    BigInt* ret = new BigInt(right), *temp = new BigInt(left);
    ret->mod(*temp);
    delete temp;
    return *ret;
}

BigInt& operator% (BigInt& left, int right) {
    BigInt* ret = new BigInt(left), *temp = new BigInt(right);
    ret->mod(*temp);
    delete temp;
    return *ret;
}

bool operator< (BigInt& left, BigInt& right) {
    return left.cmp(right) < 0;
}

bool operator< (int left, BigInt& right) {
    BigInt *temp = new BigInt(left);
    bool ret = right.cmp(*temp) < 0;
    delete temp;
    return ret;
}

bool operator< (BigInt& left, int right) {
    return right < left;
}

bool operator> (BigInt& left, BigInt& right) {
    return right < left;
}

bool operator> (int left, BigInt& right) {
    return right < left;
}

bool operator> (BigInt& left, int right) {
    return right < left;
}

bool operator== (BigInt& left, BigInt& right) {
    return left.cmp(right);
}

bool operator== (int left, BigInt& right) {
    BigInt *temp = new BigInt(left);
    bool ret = right.cmp(*temp) == 0;
    delete temp;
    return ret;
}

bool operator== (BigInt& left, int right) {
    return right == left;
}

}
