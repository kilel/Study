#include "BigInt.h"
namespace long_math {

    BigInt *ZERO = new BigInt(0);
    BigInt *ONE = new BigInt(1);
    BigInt *TWO = new BigInt(2);

    BigInt::BigInt() : BigInt(0) {
    }

    BigInt::BigInt(int value) {
        innerData = new BigIntData(0);
        if (value < 0) {
            sign = -1;
            value = -value;
        } else {
            sign = 1;
        }
        if (value == 0) {
            innerData->push_back(0);
        }
        int temp = value;
        while (temp != 0) {
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
        for (BigIntData::iterator it = source.begin(); it != source.end(); ++it) {
            innerData->push_back(*it);
        }
    }

    BigInt::BigInt(const BigInt& source) {
        innerData = new BigIntData(0);
        this->sign = source.sign;
        for (BigIntData::iterator it = source.innerData->begin(); it != source.innerData->end(); ++it) {
            innerData->push_back(*it);
        }
    }

    BigInt::BigInt(string& source) {
        innerData = new BigIntData(0);
        sign = 1;
        initFromString(source);
    }

    BigInt::BigInt(char *source) {
        innerData = new BigIntData(0);
        sign = 1;
        string s = "";
        s.append(source);
        initFromString(s);
    }

    void BigInt::initFromString(string source) {
        int begin = 0;
        int end = source.length();
        if (source[begin] == '-') {
            sign = -1;
            ++begin;
        } else if (source[begin] == '+') {
            ++begin;
        }

        for (int i = begin; i < end; ++i) {
            if ((source[i] > '9' || source[i] < '0') && (source[i] > 'F' || source[i] < 'A')
                    && (source[i] > 'f' || source[i] < 'a')) {
                throw "Illegal format of number: [" + source + "]";
            }
        }
        for (int i = end - 1; i >= begin; i -= MODULE_LENGTH) {
            int temp = 0;
            int shiftLength = min<int>(i - begin, MODULE_LENGTH - 1);

            for (int j = shiftLength; j >= 0; --j) {
                char digit = source[i - j];
                temp <<= MODULE_DIGIT_BIT_LENGTH;

                if (digit >= '0' && digit <= '9') {
                    temp |= digit - '0';
                } else if (digit >= 'A' && digit <= 'F') {
                    temp |= digit - 'A' + 10;
                } else if (digit >= 'a' && digit <= 'f') {
                    temp |= digit - 'a' + 10;
                }
            }
            innerData->push_back(temp);
        }
    }

    void BigInt::copy(BigInt& source) {
        innerData->clear();
        this->sign = source.sign;
        for (BigIntData::iterator it = source.innerData->begin(); it != source.innerData->end(); ++it) {
            innerData->push_back(*it);
        }
    }

    BigIntData* BigInt::getData() {
        return innerData;
    }

    BigInt* BigInt::shift(int digits) {
        if (digits == 0) {
            return this;
        }
        int lastSize = innerData->size();
        if (digits > 0) {
            for (int i = 0; i < digits; ++i) {
                innerData->push_back(0);
            }
            for (int i = lastSize - 1; i >= 0; --i) {
                (*innerData)[i + digits] = (*innerData)[i];
            }
            for (int i = 0; i < digits; ++i) {
                (*innerData)[i] = 0;
            }
        } else {
            if (digits >= lastSize) {
                innerData->clear();
                innerData->push_back(0);
                return this;
            }
            for (int i = digits; i < lastSize; ++i) {
                (*innerData)[i - digits] = (*innerData)[i];
            }
            for (int i = 0; i < digits; ++i) {
                innerData->pop_back();
            }
        }
        return this;
    }

    BigInt* BigInt::add(BigInt& value) {
        if (value.sign != this->sign) {
            BigInt *tempVal = new BigInt(value);
            tempVal->sign *= -1;
            this->sub(*tempVal);
            delete tempVal;
            return this;
        }
        int overflow = 0;
        for (BigIntData::iterator it_this = innerData->begin(), it_val = value.innerData->begin();
                it_this != innerData->end() || it_val != value.innerData->end();) {
            if (it_val == value.innerData->end() && overflow == 0) { //no data to add from addition operand
                break;
            }
            int currData = overflow;
            if (it_val != value.innerData->end()) {
                currData += *it_val;
                ++it_val;
            }
            if (it_this != innerData->end()) {
                currData += *it_this;
                *it_this = currData % MODULE;
                ++it_this;
            } else {
                innerData->push_back(currData % MODULE);
                it_this = innerData->end();
            }
            overflow = currData / MODULE;
        }
        if (overflow != 0) {
            this->innerData->push_back(overflow);
        }

        return this;
    }

    BigInt* BigInt::sub(BigInt& value) {
        if (value.sign != this->sign) {
            BigInt *tempVal = new BigInt(value);
            tempVal->sign *= -1;
            this->add(*tempVal);
            delete tempVal;
            return this;
        }

        if (cmp(value) == 0) {
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

        for (BigIntData::iterator it_base = subBase->innerData->begin(), it_val = subActive->innerData->begin();
                it_base != subBase->innerData->end() || it_val != subActive->innerData->end();) {
            if (it_val == subActive->innerData->end() && overflow == 0) { //no data to add from addition operand
                break;
            }
            int currData = overflow;
            if (it_val != subActive->innerData->end()) {
                currData -= *it_val;
                ++it_val;
            }
            if (it_base != subBase->innerData->end()) {
                currData += *it_base;
                if (currData < 0) {
                    overflow = -1;
                    currData += MODULE;
                } else {
                    overflow = 0;
                }
                *it_base = currData % MODULE;
                ++it_base;
            }
        }
        if (overflow != 0) {
            subBase->innerData->push_back(overflow);
        }
        this->copy(*subBase);
        if (isLower) {
            this-> sign *= -1;
        }

        delete subBase;
        delete subActive;

        while (*(this->innerData->end() - 1) == 0 && this->innerData->size() > 1) {
            this->innerData->pop_back();
        }

        return this;
    }

    BigInt* BigInt::mult(int value) {
        assert(value <= MODULE);
        if (value < 0) {
            value *= -1;
            this->sign *= -1;
        }
        int overflow = 0;
        for (BigIntData::iterator it_this = innerData->begin(); it_this != innerData->end(); ++it_this) {
            long long currData = (long long) (*it_this) * value + overflow;
            *it_this = currData % MODULE;
            overflow = currData / MODULE;
        }
        if (overflow != 0) {
            this->innerData->push_back(overflow);
        }
        return this;
    }

    BigInt* BigInt::mult(BigInt& value) {
        BigInt* sumOfMult = new BigInt(0);
        BigInt* tempVal = new BigInt(0);
        int resSign = this->sign * value.sign;
        this->sign = 1;
        value.sign = 1;
        int shift = 0;
        for (BigIntData::iterator it_val = value.innerData->begin(); it_val != value.innerData->end(); ++it_val) {
            tempVal->copy(*this);
            tempVal->mult(*it_val);
            tempVal->shift(shift++);
            sumOfMult->add(*tempVal);
        }
        this->copy(*sumOfMult);
        this->sign = resSign;
        while (*(this->innerData->end() - 1) == 0 && this->innerData->size() > 1) {
            this->innerData->pop_back();
        }
        delete sumOfMult;
        delete tempVal;
        return this;
    }

    pair<BigInt*, BigInt*> BigInt::divMod(int value) {
        assert(value < MODULE);

        BigInt* temp = new BigInt(0);
        temp->copy(*this);
        if (value < 0) {
            value *= -1;
            temp->sign *= -1;
        }
        int overfloat = 0;
        int mod = 0;
        for (BigIntData::iterator it = temp->innerData->end() - 1; it != temp->innerData->begin() - 1; --it) {
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
        if (value == 2) {
            if (*(innerData->begin()) % 2 == 1) {
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
        if (value.cmp(*TWO) == 0) {
            if (*(innerData->begin()) % 2 == 1) {
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
        if (cmp(value) < 0) {
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
        for (int i = 0; i < shiftLength + 1; ++i) {
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
        for (BigIntData::iterator it = divDataAggregator->end() - 1; it != divDataAggregator->begin() - 1; --it) {
            div->innerData->push_back(*it);
        }

        delete divDataAggregator;
        delete base;
        delete dividor;

        return DivModData(div, mod);
    }

    int BigInt::divSimple(BigInt& base, BigInt& dividor) {
        int cmpResult = base.cmp(dividor);
        if (cmpResult < 0) {
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
            } else if (cmpResult > 0) {
                left = center + 1;
            } else { // equals
                left = right = center;
            }
        }
        temp->copy(dividor);
        temp->mult(left);
        if (base.cmp(*temp) < 0) {
            left--;
        }
        delete temp;
        return left;
    }

    int BigInt::cmp(BigInt& value) {
        if (this->innerData->size() > value.innerData->size()) {
            return 1;
        } else if (this->innerData->size() < value.innerData->size()) {
            return -1;
        }
        size_t len = this->innerData->size();
        for (int i = len - 1; i >= 0; --i) {
            if ((*(this->innerData))[i] > (*(value.innerData))[i]) {
                return 1;
            } else if ((*(this->innerData))[i] < (*(value.innerData))[i]) {
                return -1;
            }
        }
        return 0;
    }

    BigInt* BigInt::powMod(BigInt& deg, BigInt& module) {
        BigInt* ret = new BigInt(*ONE);

        BigInt* p2t = new BigInt(*this);

        int len = deg.innerData->size() * MODULE_DIGIT_BIT_LENGTH * MODULE_LENGTH;
        for (size_t i = 0; i < len; ++i) {
            size_t shift = i % (MODULE_DIGIT_BIT_LENGTH * MODULE_LENGTH);
            size_t digit = i / (MODULE_DIGIT_BIT_LENGTH * MODULE_LENGTH);
            int val = deg.innerData->at(digit) & 1 << shift;
            if (val) {
                ret->mult(*p2t)->mod(module);
            }
            p2t->mult(*p2t)->mod(module);
        }

        ret->mod(module);

        this->copy(*ret);
        delete ret;
        delete p2t;

        return this;
    }

    void BigInt::powMod(vector<BigInt*>* data, BigInt& deg, BigInt& module) {
        vector<BigInt*> *ret = new vector<BigInt*>();
        for (int i = 0; i < data->size(); ++i) {
            ret->push_back(new BigInt(*ONE));
        }

        int len = deg.innerData->size() * MODULE_DIGIT_BIT_LENGTH * MODULE_LENGTH;
        for (size_t i = 0; i < len; ++i) {
            size_t shift = i % (MODULE_DIGIT_BIT_LENGTH * MODULE_LENGTH);
            size_t digit = i / (MODULE_DIGIT_BIT_LENGTH * MODULE_LENGTH);
            int val = deg.innerData->at(digit) & 1 << shift;
            for (int i = 0; i < ret->size(); ++i) {
                if (val) {
                    ret->at(i)->mult(*data->at(i))->mod(module);
                }
                data->at(i)->mult(*data->at(i))->mod(module);
            }
        }

        for (int i = 0; i < ret->size(); ++i) {
            data->at(i)->copy(*ret->at(i));
            delete ret->at(i);
        }
        delete ret;

    }

    void BigInt::print(string message) {
        if (message != "") {
            cout << message << ": ";
        }
        cout << toString();
    }

    void BigInt::println(string message) {
        print(message);
        printf("\n");
    }

    string BigInt::toString() {
        string out = "";
        stringstream tos;
        if (sign < 0) {
            tos << "-";
        }
        tos << hex << *(innerData->end() - 1);
        for (BigIntData::iterator it = innerData->end() - 2; it != innerData->begin() - 1; --it) {
            int temp = *it;
            for (int i = 0; i < MODULE_LENGTH; ++i) {
                int toPrint = ((temp & READ_MASK[i]) >> READ_MASK_shift[i]);
                tos << hex << toPrint;
            }
        }
        return tos.str();
    }

    bool BigInt::isPrime() {
        BigInt* curr = new BigInt(2);
        BigInt* end = new BigInt(200);
        BigInt* base = new BigInt();
        BigInt* deg = (new BigInt(*this))->sub(*ONE);

        bool ret = true;

        while (*curr < *end) {
            base->copy(*this);
            if (*base->mod(*curr) == *ZERO) {
                ret = false;
                break;
            }
            curr->add(*ONE);
        }

        delete curr;
        delete end;
        delete base;

        vector<BigInt*> *data = new vector<BigInt*> ();
        for (int i = 0; i < 200; ++i) {
            data->push_back(new BigInt(rand()));
        }

        powMod(data, *deg, *this);
        
        for(int i = 0; i < data->size(); ++i) {
            if(ret && *data->at(i) != *ONE) {
                ret = false;
            }
            delete data->at(i);
        }
        delete data;
        delete deg;

        return ret;
    }

    BigInt* BigInt::makePrime() {
        while (!isPrime()) {
            add(*ONE);
        }
        return this;
    }

    BigInt* BigInt::gcd(BigInt& second) {
        BigInt* firstOne, *secondOne;
        firstOne = new BigInt(*this);
        secondOne = new BigInt(second);
        while (*secondOne != *ZERO) {
            firstOne->mod(*secondOne);
            BigInt* temp = firstOne;
            firstOne = secondOne;
            secondOne = temp;
        }
        this->copy(*firstOne);

        delete firstOne;
        delete secondOne;
        return this;
    }

    pair<BigInt*, BigInt*> BigInt::getXYEucledian(BigInt* left, BigInt* right) {
        if (*right == *ZERO) {
            return pair<BigInt*, BigInt*>(new BigInt(1), new BigInt(0));
        }

        BigInt *x1, *x2;
        pair<BigInt*, BigInt*> divModTemp;
        divModTemp = left->divMod(*right);

        pair<BigInt*, BigInt*> result = getXYEucledian(right, divModTemp.second);

        x1 = new BigInt(*result.second); //x1 = retX2
        x2 = new BigInt(*result.first); //x2 = retX1 - (left/right) * retX2
        x2->sub(*(divModTemp.first->mult(*result.second)));

        delete divModTemp.first;
        delete divModTemp.second;
        delete result.first;
        delete result.second;

        return pair<BigInt*, BigInt*>(x1, x2);
    }

    BigInt* BigInt::inverseMod(BigInt& module) {
        pair<BigInt*, BigInt*> ret = getXYEucledian(this, &module);
        ret.first->add(module)->mod(module);
        this->copy(*ret.first);

        delete ret.second;
        delete ret.first;

        return this;
    }
}
