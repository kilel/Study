#ifndef UTILS_H
#define	UTILS_H

#include <inttypes.h>
#include <vector>
#include <omp.h>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const bool printValues = false;

uint64_t getTime() {
    uint64_t lo, hi;
    __asm__ __volatile__(
            "xorl %%eax, %%eax\n"
            "cpuid\n"
            "rdtsc\n"
            : "=a" (lo), "=d" (hi)
            :
            : "%ebx", "%ecx");
    return (uint64_t) hi << 32 | lo;
}

void printIndentArray(vector<bool> array, bool force = false) {
    if (force || printValues) {
        int size = array.size();
        for (int i = 0; i < size; ++i) {
            if (array[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}

void printArray(vector<uint64_t>* array, bool forced = false) {
    if (forced || printValues) {
        int size = array->size();
        for (int i = 0; i < size; ++i) {
            cout << array->at(i) << " ";
        }
        cout << endl;
    }
}

/**
 * Sequent version of sequend division prime numbers searcher.
 * @param maxValue
 */
vector<uint64_t>* sequentSDPNS(uint64_t maxValue) {
    vector<uint64_t> *primes = new vector<uint64_t>(0);

    //#pragma omp parallel for
    for (int checkPrime = 2; checkPrime <= maxValue; ++checkPrime) {
        uint64_t lim = sqrt(checkPrime) + 1.001;
        int isPrime = 1;
        int size = primes->size();

        for (int i = 0; i < size; ++i) {
            int div = primes->at(i);
            if (checkPrime % div == 0) {
                isPrime = 0;
                break;
            } else if (div > lim) {
                break;
            }
        }
        if (isPrime) {
            primes->push_back(checkPrime);
        }
    }

    printArray(primes);
    return primes;
}

/**
 * OMP version of sequend division prime numbers searcher.
 * @param maxValue
 */
vector<uint64_t>* ompSDPNS(uint64_t maxValue) {
    vector<uint64_t>* primes = new vector<uint64_t>(0);

#pragma omp parallel num_threads(8)
    {
        vector<bool> primesIndent = vector<bool>(maxValue + 1, 0);
#pragma omp for schedule(static)
        for (int checkPrime = 2; checkPrime <= maxValue; ++checkPrime) {
            uint64_t lim = sqrt(checkPrime) + 1.001;
            bool isPrime = 1;
            for (int div = 2; div < lim; ++div) {
                if (checkPrime % div == 0) {
                    isPrime = 0;
                    break;
                }
            }

            //#pragma omp critical
            primesIndent[checkPrime] = isPrime;
        }
#pragma omp critical
        for (int i = 0; i < maxValue; ++i) {
            if (primesIndent[i]) {
                primes->push_back(i);
            }
        }
    }
    printArray(primes);
    return primes;
}

vector<uint64_t>* sequentEratosfen(uint64_t maxValue) {
    vector<uint64_t>* primes = new vector<uint64_t>(0);
    vector<bool> primesIndent = vector<bool>(maxValue + 1, 1);
    primesIndent[0] = primesIndent[1] = 0;
    uint64_t lim = sqrt(maxValue) + 1.001;

    for (int i = 2; i <= lim; ++i) {
        if (primesIndent[i]) {
            int start = i * i;
            for (int j = start; j <= maxValue; j += i) {
                primesIndent[j] = 0;
            }
        }
    }
    printIndentArray(primesIndent);

    for (int i = 0; i < maxValue; ++i) {
        if (primesIndent[i]) {
            primes->push_back(i);
        }
    }
    return primes;
}

vector<uint64_t>* ompEratosfen(uint64_t maxValue) {
    vector<uint64_t>* primes = new vector<uint64_t>(0);
    vector<bool> primesIndent = vector<bool>(maxValue + 1, 1);
    primesIndent[0] = primesIndent[1] = 0;
    uint64_t lim = sqrt(maxValue) + 1.001;

    for (int i = 2; i <= lim; ++i) {
        if (primesIndent[i]) {
#pragma omp parallel shared(primesIndent, maxValue, i) num_threads(4)
            {
#pragma omp for
                for (int j = i * i; j <= maxValue; j += i) {
                    //#pragma omp critical
                    primesIndent[j] = 0;
                }
                //#pragma omp barrier
            }
        }
    }
    printIndentArray(primesIndent);

    for (int i = 0; i < maxValue; ++i) {
        if (primesIndent[i]) {
            primes->push_back(i);
        }
    }
    return primes;
}

vector<uint64_t>* ompCommon(uint64_t maxValue) {
    double maxima = maxValue;
    uint64_t lim = sqrt(maxima) + 1.001;
    vector<uint64_t> *primes = sequentEratosfen(lim);
    int size = primes->size();
#pragma omp parallel num_threads(16)
    {
        vector<uint64_t> *privatePrimes = new vector<uint64_t>();
#pragma omp for
        for (int i = lim; i <= maxValue; ++i) {
            int isPrime = 1;
            for (int j = 0; j < size; ++j) {
                int mod = i % primes->at(j);
                if (mod == 0) {
                    isPrime = 0;
                    break;
                }
            }
            if (isPrime) {
                //#pragma omp critical
                privatePrimes->push_back(i);
            }
            //cout << i <<"\n";
        }
#pragma omp critical
        for(int i = 0; i < privatePrimes->size(); ++i) {
            primes->push_back(privatePrimes->at(i));
        }
#pragma omp barrier
    }

    return primes;
}

bool isValid(vector<uint64_t>* listPrimes, uint64_t maxPrime) {
    vector<uint64_t>* valid = sequentEratosfen(maxPrime);
    sort(listPrimes->begin(), listPrimes->end());
    for (int i = 0; i < valid->size(); ++i) {
        if (listPrimes->at(i) != valid->at(i)) {
            return false;
        }
    }
    return true;
}

#endif	/* UTILS_H */
