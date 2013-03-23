/* 
 * File:   main.cpp
 * Author: hkyten
 *
 * Created on 23 Март 2013 г., 11:45
 */

#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <cmath>
#include <unistd.h>
#include <time.h>
#include <fstream>

using namespace std;

fstream in, out;
const int MAX_SIZE = 100;


inline unsigned long long  rdtsc()
{
    unsigned long long lo, hi;
    __asm__ __volatile__ (
      "xorl %%eax, %%eax\n"
      "cpuid\n"
      "rdtsc\n"
      : "=a" (lo), "=d" (hi)
      :
      : "%ebx", "%ecx" );
    return (unsigned long long)hi << 32 | lo;
}

int xmmVectDotProd(int*a, int*b, int len){
    int sum = 0;
    int *s = &sum;
    int *t[3] = {a,b};
    while(len%4 != 0){
        sum += *(a+len-1) * *(b+len-1);
        --len;
    }
    for(int i = 0; i < len; i+=4){
        asm("mov %0, %%rax\n\t"
        "movups (%%rax), %%xmm1\n\t"
        "mov %1, %%rbx\n\t"
        "movups (%%rbx), %%xmm2\n\t"
        "pmulld %%xmm2, %%xmm1\n\t"
        "mov %2, %%rbx\n\t"
        //"movups %%xmm1, (%%rbx)\n\t"
        "movd %%xmm1, %%edx\n\t"
        "psrldq $4, %%xmm1\n\t"
        "movd %%xmm1, %%eax\n\t"
        "add %%eax, %%edx\n\t"
        "psrldq $4, %%xmm1\n\t"
        "movd %%xmm1, %%eax\n\t"
        "add %%eax, %%edx\n\t"
        "psrldq $4, %%xmm1\n\t"
        "movd %%xmm1, %%eax\n\t"
        "add %%eax, %%edx\n\t"
        "add %%edx, (%%rbx)"
        : 
        : "m"((t[0])), "m"((t[1])), "m"(s));
        t[0]+=4;
        t[1]+=4;
    }
    //cout << sum << " " ;
    return sum; 
}
int dotProd(int*a, int*b, int len){
    int sum = 0;
    for(int j = 0; j < len; ++j)
        sum += *(a+j) * *(b+j);
    return sum;
}
void transpose(int* a, int len){
    register int t = 0;
    for(int i = 0; i < len; ++i)
        for(int j = 0; j < i; j++){
            t = *(a + i*len + j);
            *(a + i*len + j) = *(a + j*len + i);
            *(a + j*len + i) = t;
        }
}

unsigned int fillProd(int *a, int*b, int*c, int type, int len){
    int (*func)(int*a, int*b, int len);
    unsigned int start = 0, end = 0;
    double avg = 0;
    switch(type){
        case 1: func = dotProd; break;
        case 2: func = xmmVectDotProd; break;
    }
    //transposing b matrix
    transpose(b, len);
    //calculating production
    int temp = 1;
    for(int t = 0; t < 1000; ++t){
        start = rdtsc();
        for(int i = 0; i < len; ++i)
            for(int j = 0; j < len; ++j){
                temp = func(a+i*len,b+j*len, len);
                //cout << t << " " << func(a+i*len,b+j*len, len) << endl; 
                c[i*len + j] = temp;
            }
        end = rdtsc();
        avg += (end - start)/1000.;
    }
    //transposing back b matrix
    transpose(b, len);
    return avg;
}

void printData(int* c, int len){
    for(int i = 0; i < len; ++i){
        for(int j = 0; j < len; ++j){
            out << *(c+i*len + j) << " ";
        }
        out << endl;
    }
}
void readData(int*a, int len){
    for(int i = 0; i < len; ++i){
        for(int j = 0; j < len; ++j){
            in >> *(a+(i*len+j) );
        } 
    }
}
void fillData(int *a, int len){
    for(int i = 0; i < len; ++i){
        for(int j = 0; j < len; ++j){
            *(a+(i*len+j)) = 3;
        } 
    }
}
int main(int argc, char** argv) {
    int *a,*b,*c;
    srand(time(0));
    a = new int[MAX_SIZE*MAX_SIZE];
    b = new int[MAX_SIZE*MAX_SIZE];
    c = new int[MAX_SIZE*MAX_SIZE];
    in.open("in", fstream::in);
    out.open("out",fstream::out);
    //readData(a);
    //readData(b);
    fillData(a, MAX_SIZE);
    fillData(b, MAX_SIZE);
    in.close();
    for(int i = 1; i < 3; ++i)
        out << fillProd(a, b, c, i, MAX_SIZE) << " ";
    
    out << endl << endl;
    //printData(c, MAX_SIZE);
    out.close();
    delete[]a;
    delete[]b;
    delete[]c;
    return 0;
}

