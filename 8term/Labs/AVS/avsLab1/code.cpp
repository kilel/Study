#pragma comment(linker, "/STACK:36777216")
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <vector>
#include <string>

using namespace std;

int a[110000]; 

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

void frep1(int len){
	for(int i = 0; i < len; ++i)
		a[i]  = 5;
}

void frep2(int len){
	for(int i = len-1; i >= 0; --i)
		a[i]  = 5;
}

void frep3(int len){
	int r = 1; 
	for(int i = len-1; i >= 0; --i){
		r = (r*7333)  %99991;
		a[r%len]  = 5;
	}
}


int main(int argc, char *argv[]){
	
	srand(time(0));
	fstream in;
	int len = 0, type = 1;
	
	int rep = 10;
	if(argc > 1){
		type = atoi(argv[1]);
	}
	if(argc > 3)
		rep = atoi(argv[3]);
		
	fstream fout;
	
	fout.open("out.txt", fstream::out);
	
	unsigned long long st, en, s = 0;
	vector<unsigned long long> vt(0);
	while(len < 100001){
		len +=  128;
		
		
		while(rep--){
			st = rdtsc();
			if(type == 1)
				frep1(len);
			else if(type == 2)
				frep2(len);
			else if (type == 3)
				frep3(len);	
			en = rdtsc();
			s += en - st;
		}
		rep = 10;
		vt.push_back(s/rep);
	}
	for(int i = 0; i < vt.size(); ++i)
		fout << vt[i] << "\n";
	fout.close();
	return 0;

}
