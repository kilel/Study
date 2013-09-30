#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <assert.h>

namespace long_math {
    class BigInt;

    using namespace std;
    typedef vector<int> BigIntData;
    typedef pair<BigInt*, BigInt*> DivModData;

    static const int READ_MASK[] = {0xF000, 0xF00, 0xF0, 0xF};
    static const int READ_MASK_shift[] = {12, 8, 4, 0};

    class BigInt {
    public:
        static const int MODULE = 1 << 16;
        static const int MODULE_LENGTH = 4;
        static const int MODULE_DIGIT_BIT_LENGTH = 4;
        
        /**
         * @param left
         * @param right
         * @return pair (e,v):  left*e + right*v = GCD(left, right) (mod module)
         */
        static pair<BigInt*, BigInt*> getXYEucledian(BigInt* left, BigInt* right);

        BigInt();
        BigInt(int value);
        virtual ~BigInt();
        BigInt(const BigInt& source);
        BigInt(BigIntData& source);
        BigInt(string& source);
        BigInt(char *source);

        void copy(BigInt& source);

        BigInt* shift(int digits);
        BigInt* add(BigInt& value);
        BigInt* sub(BigInt& value);
        BigInt* mult(BigInt& value);
        BigInt* mult(int value); // assumed, that value < MODULE
        BigInt* div(int value); // assumed, that value < MODULE
        BigInt* mod(int value); // assumed, that value < MODULE
        BigInt* div(BigInt& value);
        BigInt* mod(BigInt& value);
        BigInt* powMod(BigInt& deg, BigInt& module);

        BigInt* gcd(BigInt& second);

        int cmp(BigInt& value);

        friend BigInt& operator+(BigInt& left, BigInt& right);
        friend BigInt& operator+(int left, BigInt& right);
        friend BigInt& operator+(BigInt& left, int right);

        friend BigInt& operator-(BigInt& left, BigInt& right);
        friend BigInt& operator-(int left, BigInt& right);
        friend BigInt& operator-(BigInt& left, int right);

        friend BigInt& operator*(BigInt& left, BigInt& right);
        friend BigInt& operator*(int left, BigInt& right);
        friend BigInt& operator*(BigInt& left, int right);

        friend BigInt& operator/(BigInt& left, BigInt& right);
        friend BigInt& operator/(int left, BigInt& right);
        friend BigInt& operator/(BigInt& left, int right);

        friend BigInt& operator%(BigInt& left, BigInt& right);
        friend BigInt& operator%(int left, BigInt& right);
        friend BigInt& operator%(BigInt& left, int right);

        friend bool operator<(BigInt& left, BigInt& right);
        friend bool operator<(int left, BigInt& right);
        friend bool operator<(BigInt& left, int right);

        friend bool operator>(BigInt& left, BigInt& right);
        friend bool operator>(int left, BigInt& right);
        friend bool operator>(BigInt& left, int right);

        friend bool operator==(BigInt& left, BigInt& right);
        friend bool operator==(int left, BigInt& right);
        friend bool operator==(BigInt& left, int right);

        friend bool operator!=(BigInt& left, BigInt& right);
        friend bool operator!=(int left, BigInt& right);
        friend bool operator!=(BigInt& left, int right);

        BigInt* inverseMod(BigInt& module);
        bool isPrime();
        BigInt* makePrime();

        void print(string message = "");
        void println(string message = "");
        string toString();

        BigIntData* getData();

        int getSign() {
            return sign;
        }

    private:
        BigIntData* innerData;
        int sign = 1; // +1 or -1;
        ///
        DivModData divMod(int value);
        DivModData divMod(BigInt& dividor);
        static int divSimple(BigInt& base, BigInt& dividor);
        void initFromString(string s);

    };
}

#endif // BIGINT_H
