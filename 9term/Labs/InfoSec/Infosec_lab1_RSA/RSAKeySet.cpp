#include "RSAKeySet.h"

namespace RSA {
    BigInt* ONE = new BigInt(1);

    BigInt* createBigint(int length) {
        BigInt* value = new BigInt();
        value->getData()->clear();
        for (int i = 0; i < length; ++i) {
            //rand gives us 15-bit number. Let concat rand and rand, and use result.
            unsigned int rValue = ((rand() % (1 << 15)) << 15) | (rand() % (1 << 15));
            if (rValue == 0) {
                --i;
                continue;
            }
            value->getData()->push_back(rValue % BigInt::MODULE);
        }
        return value;
    }

    RSAKeySet::RSAKeySet(int length) {
        BigInt* p;
        BigInt* q;
        BigInt n;
        BigInt fi;
        while (true) {
            p = createBigint(length / 2)->makePrime();
            q = createBigint(length / 2 + 1)->makePrime();
            if(*q == *p) {
                q->add(*ONE)->makePrime();
            }
            n = *p * *q;
            fi = (*p - *ONE) * (*q - *ONE);
            delete p;
            delete q;

            BigInt *check = new BigInt(n);
            if (*check->gcd(fi) == *ONE) {
                delete check;
                break;
            }
            delete check;
        }

        BigInt *e = createBigint(fi.getData()->size() - 1);

        {
            BigInt *temp = new BigInt(*e);
            while (*temp->gcd(fi) != *ONE) {
                e->add(*ONE);
                temp->copy(*e);
            }
            delete temp;
        }

        BigInt *d = new BigInt(*e);
        d->inverseMod(fi);

        assert(((*d * *e) % fi) == *ONE);

        BigInt *test = createBigint(length - 1);
        BigInt *testCopy = new BigInt(*test);
        
        test->powMod(*d,n)->powMod(*e,n);
        
        assert (*test == *testCopy);
        
        privateKey = new RSAKey(&n, d);
        publicKey = new RSAKey(&n, e);
    }

    RSAKeySet::~RSAKeySet() {
        delete privateKey;
        delete publicKey;
    }
}

