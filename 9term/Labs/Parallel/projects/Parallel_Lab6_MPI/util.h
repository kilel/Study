#ifndef UTIL_H
#define	UTIL_H

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int numStarts = 7;
int start[] = {10, 50, 100, 200, 300, 400, 500};


int Min(int a, int b) {
    return a < b ? a : b;
}

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

void print(int** a, int n, ofstream *out) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            *out << a[i][j] << " ";
        }
        *out << "\n";
    }
    *out << "\n";
}


#endif	/* UTIL_H */

