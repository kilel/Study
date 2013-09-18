#include "BigInt.h"

namespace long_math {

    BigInt& operator+(BigInt& left, BigInt& right) {
        BigInt* ret = new BigInt(left);
        ret->add(right);
        return *ret;
    }

    BigInt& operator+(int left, BigInt& right) {
        BigInt* ret = new BigInt(right), *temp = new BigInt(left);
        ret->add(*temp);
        delete temp;
        return *ret;
    }

    BigInt& operator+(BigInt& left, int right) {
        BigInt* ret = new BigInt(left), *temp = new BigInt(right);
        ret->add(*temp);
        delete temp;
        return *ret;
    }

    BigInt& operator-(BigInt& left, BigInt& right) {
        BigInt* ret = new BigInt(left);
        ret->sub(right);
        return *ret;
    }

    BigInt& operator-(int left, BigInt& right) {
        BigInt* ret = new BigInt(right), *temp = new BigInt(left);
        ret->sub(*temp);
        delete temp;
        return *ret;
    }

    BigInt& operator-(BigInt& left, int right) {
        BigInt* ret = new BigInt(left), *temp = new BigInt(right);
        ret->sub(*temp);
        delete temp;
        return *ret;
    }

    BigInt& operator*(BigInt& left, BigInt& right) {
        BigInt* ret = new BigInt(left);
        ret->mult(right);
        return *ret;
    }

    BigInt& operator*(int left, BigInt& right) {
        BigInt* ret = new BigInt(right), *temp = new BigInt(left);
        ret->mult(*temp);
        delete temp;
        return *ret;
    }

    BigInt& operator*(BigInt& left, int right) {
        BigInt* ret = new BigInt(left), *temp = new BigInt(right);
        ret->mult(*temp);
        delete temp;
        return *ret;
    }

    BigInt& operator/(BigInt& left, BigInt& right) {
        BigInt* ret = new BigInt(left);
        ret->div(right);
        return *ret;
    }

    BigInt& operator/(int left, BigInt& right) {
        BigInt* ret = new BigInt(right), *temp = new BigInt(left);
        ret->div(*temp);
        delete temp;
        return *ret;
    }

    BigInt& operator/(BigInt& left, int right) {
        BigInt* ret = new BigInt(left), *temp = new BigInt(right);
        ret->div(*temp);
        delete temp;
        return *ret;
    }

    BigInt& operator%(BigInt& left, BigInt& right) {
        BigInt* ret = new BigInt(left);
        ret->mod(right);
        return *ret;
    }

    BigInt& operator%(int left, BigInt& right) {
        BigInt* ret = new BigInt(right), *temp = new BigInt(left);
        ret->mod(*temp);
        delete temp;
        return *ret;
    }

    BigInt& operator%(BigInt& left, int right) {
        BigInt* ret = new BigInt(left), *temp = new BigInt(right);
        ret->mod(*temp);
        delete temp;
        return *ret;
    }

    bool operator<(BigInt& left, BigInt& right) {
        return left.cmp(right) < 0;
    }

    bool operator<(int left, BigInt& right) {
        BigInt *temp = new BigInt(left);
        bool ret = right.cmp(*temp) < 0;
        delete temp;
        return ret;
    }

    bool operator<(BigInt& left, int right) {
        return right < left;
    }

    bool operator>(BigInt& left, BigInt& right) {
        return right < left;
    }

    bool operator>(int left, BigInt& right) {
        return right < left;
    }

    bool operator>(BigInt& left, int right) {
        return right < left;
    }

    bool operator==(BigInt& left, BigInt& right) {
        return left.cmp(right) == 0;
    }

    bool operator==(int left, BigInt& right) {
        BigInt *temp = new BigInt(left);
        bool ret = right.cmp(*temp) == 0;
        delete temp;
        return ret;
    }

    bool operator==(BigInt& left, int right) {
        return right == left;
    }


}
