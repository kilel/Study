#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

namespace long_math {
    class BigInt;

    using namespace std;
    typedef vector<int> BigIntData;
    typedef pair<BigInt*, BigInt*> DivModData;

    class BigInt {
    public:
        static const int MODULE = 1e4;

        BigInt();
        BigInt(int value);
        virtual ~BigInt();
        BigInt(const BigInt& source);
        BigInt(BigIntData& source);

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

        int cmp(BigInt& value);

        friend BigInt& operator+ (BigInt& left, BigInt& right);
        friend BigInt& operator+ (int left, BigInt& right);
        friend BigInt& operator+ (BigInt& left, int right);

        friend BigInt& operator- (BigInt& left, BigInt& right);
        friend BigInt& operator- (int left, BigInt& right);
        friend BigInt& operator- (BigInt& left, int right);

        friend BigInt& operator* (BigInt& left, BigInt& right);
        friend BigInt& operator* (int left, BigInt& right);
        friend BigInt& operator* (BigInt& left, int right);

        friend BigInt& operator/ (BigInt& left, BigInt& right);
        friend BigInt& operator/ (int left, BigInt& right);
        friend BigInt& operator/ (BigInt& left, int right);

        friend BigInt& operator% (BigInt& left, BigInt& right);
        friend BigInt& operator% (int left, BigInt& right);
        friend BigInt& operator% (BigInt& left, int right);

        friend bool operator< (BigInt& left, BigInt& right);
        friend bool operator< (int left, BigInt& right);
        friend bool operator< (BigInt& left, int right);

        friend bool operator> (BigInt& left, BigInt& right);
        friend bool operator> (int left, BigInt& right);
        friend bool operator> (BigInt& left, int right);

        friend bool operator== (BigInt& left, BigInt& right);
        friend bool operator== (int left, BigInt& right);
        friend bool operator== (BigInt& left, int right);

        //BigInt& inverseMod(const BigInt& mod);
        //bool isPrime();

        void print(string message = "");
        void println(string message = "");

        BigIntData* getData();
        int getSign() { return sign; }

    private:
        BigIntData* innerData;
        int sign = 1; // +1 or -1;
        ///
        DivModData divMod(int value);
        DivModData divMod(BigInt& dividor);
        static int divSimple(BigInt& base, BigInt& dividor);

    };
}

#endif // BIGINT_H
