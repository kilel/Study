#include <cstdlib>

#include "utils.h"
#include <string>

using namespace std;

//seq div
//Eratosfen's grid
const int numStarts = 7;
const uint64_t startVal[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
//const uint64_t startVal[] = {100000, 1000000, 10000000, 100000000, 1000000000};
int *arrayTest;

void testFunction(string name, vector<uint64_t>* (*funk)(uint64_t)) {
    for (int i = 0; i < numStarts; ++i) {
        uint64_t maxPrimes = startVal[i];
        uint64_t start = getTime();
        vector<uint64_t>* toValidate = funk(maxPrimes);
        uint64_t end = getTime();
        bool validated = isValid(toValidate, maxPrimes);
        printf("%s %ld: %ld (valid = %d)\n", &name[0], maxPrimes, end - start, validated);
    }
    printf("\n");
}

void test(string name, void (*funk)(uint64_t)) {
    for (int i = 0; i < numStarts; ++i) {
        uint64_t maxPrimes = startVal[i];
        uint64_t start = getTime();
        funk(maxPrimes);
        uint64_t end = getTime();
        printf("%s %ld: %ld\n", &name[0], maxPrimes, end - start);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    //*
    testFunction("Sequent division", sequentSDPNS);
    testFunction("Sequent Eratosfen", sequentEratosfen);
    testFunction("OMP division", ompSDPNS);
    testFunction("OMP Eratosfen", ompEratosfen);
    testFunction("OMP common", ompCommon);
    //*/


    return 0;
}

