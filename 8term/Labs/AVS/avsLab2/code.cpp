/* 
 * File:   code.cpp
 * Author: hkyten
 *
 * Created on 12 Март 2013 г., 9:48
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
/*unsigned int a[MAX_SIZE][MAX_SIZE] = {{0}}, 
        b[MAX_SIZE][MAX_SIZE] = {{0}}, 
        c[MAX_SIZE][MAX_SIZE] = {{0}};
*/
unsigned int *a,*b,*c;

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


void asmSum(unsigned int*a, unsigned int*b, unsigned int*c, int len){
    if(len%2 != 0){
        *(c+len-1) = *(a+len-1) + *(b+len-1);
        --len;
    }
    unsigned int *t[3] = {a,b,c};
    for(int i = 0; i < len; i++){
        asm("mov %0, %%eax\n\t"
        "mov (%%eax), %%eax\n\t"
        "mov %1, %%ebx\n\t"
        "mov (%%ebx), %%ebx\n\t"
        "add %%ebx, %%eax\n\t"
        "mov %2, %%ebx\n\t"
        "mov %%eax, (%%ebx)\n\t"
        "\n\t"
        "\n\t"
        :
        : "m"((t[0])), "m"((t[1])), "m"((t[2]))        );
        ++t[0];++t[1];++t[2];
    }
}
void vectSum(unsigned int*a, unsigned int*b, unsigned int*c, int len){
    unsigned int *t[3] = {a,b,c};
    if(len%2 != 0){
        *(c+len-1) = *(a+len-1) + *(b+len-1);
        --len;
    }
    for(int i = 0; i < len; i+=2){
        asm("mov %0, %%eax\n\t"
        "movq (%%rax), %%mm1\n\t"
        "mov %1, %%ebx\n\t"
        "movq (%%rbx), %%mm2\n\t"
        "paddd %%mm2, %%mm1\n\t"
        "mov %2, %%ebx\n\t"
        "movq %%mm1, %%rax\n\t"
        //"mov $0x0, %%rax\n\t"
        "movq %%rax, (%%rbx)\n\t"
        "\n\t"
        "\n\t"
        : 
        : "m"((t[0])), "m"((t[1])), "m"((t[2]))        );
        ++t[0];++t[1];++t[2];
        ++t[0];++t[1];++t[2];
    }
}
void xmmVectSum(unsigned int*a, unsigned int*b, unsigned int*c, int len){
    unsigned int *t[3] = {a,b,c};
    while(len%4 != 0){
        *(c+len-1) = *(a+len-1) + *(b+len-1);
        --len;
    }
    for(int i = 0; i < len; i+=4){
        asm("mov %0, %%rax\n\t"
        "movups (%%rax), %%xmm1\n\t"
        "mov %1, %%rbx\n\t"
        "movups (%%rbx), %%xmm2\n\t"
        "paddd %%xmm2, %%xmm1\n\t"
        "mov %2, %%rbx\n\t"
        "movups %%xmm1, (%%rbx)\n\t"
        "\n\t"
        "\n\t"
        : 
        : "m"((t[0])), "m"((t[1])), "m"((t[2]))        );
        t[0]+=4;
        t[1]+=4;
        t[2]+=4;
    }
}
void sum(unsigned int*a, unsigned int*b, unsigned int*c, int len){
    for(int j = 0; j < len; ++j)
        *(c+j) = *(a+j) + *(b+j);
}

unsigned int fillSumm(int type){
    void (*f)(unsigned int*a, unsigned int*b, unsigned int*c, int len);
    unsigned int start = 0, end = 0;
    double avg = 0;
    switch(type){
        case 1: f = sum; break;
        case 2: f = asmSum; break;
        case 3: f = vectSum; break;
        case 4: f = xmmVectSum; break;
    }
    for(int t = 0; t < 1000; ++t){
        start = rdtsc();
        for(int i = 0; i < MAX_SIZE; ++i){
            f(a+i*MAX_SIZE,b+i*MAX_SIZE,c+i*MAX_SIZE,MAX_SIZE);    
        }    
        end = rdtsc();
        avg += (end - start)/1000.;
    }
    return avg;
}

void printData(){
    for(int i = 0; i < MAX_SIZE; ++i){
        for(int j = 0; j < MAX_SIZE; ++j){
            out << *(c+i*MAX_SIZE + j) << " ";
        }
        out << endl;
    }
}
void readData(unsigned int*a){
    for(int i = 0; i < MAX_SIZE; ++i){
        for(int j = 0; j < MAX_SIZE; ++j){
            in >> *(a+(i*MAX_SIZE+j) );
        } 
    }
}
void fillData(unsigned int *a){
    for(int i = 0; i < MAX_SIZE; ++i){
        for(int j = 0; j < MAX_SIZE; ++j){
            *(a+(i*MAX_SIZE+j)) = 2000000000;
        } 
    }
}
int main(int argc, char** argv) {
    srand(time(0));
    a = new unsigned int[MAX_SIZE*MAX_SIZE];
    b = new unsigned int[MAX_SIZE*MAX_SIZE];
    c = new unsigned int[MAX_SIZE*MAX_SIZE];
    in.open("in", fstream::in);
    out.open("out",fstream::out);
    //readData(a);
    //readData(b);
    fillData(a);
    fillData(b);
    in.close();
    for(int i = 1; i < 5; ++i)
        out << fillSumm(i) << " ";
    
    out << endl << endl;
    printData();
    out.close();
    delete[]a;delete[]b;delete[]c;
    return 0;
}

