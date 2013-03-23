/* 
 * File:   main.cpp
 * Author: hkyten
 *
 * Created on 16 Февраль 2013 г., 21:00
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>

using namespace std;

void printArr(int *a){
    cout << "\n";
    for(int i = 0; i < 20; ++i)
        cout << a[i] << " ";
}

int main(int argc, char** argv) {
    srand(time(0));
   int in1 = 2, in2 = 4, n = 20, sum = 0;
   int c[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},
       d[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
   for(int i = 0; i < n; ++i){
       c[i] = rand()%101;
       d[i] = rand()%101;
   }
   cout << "initial arrays:";
   printArr(&c[0]);
   printArr(&d[0]);
    asm(
    "mov %[in1], %%edi\n\t"
    "mov (%[mas1], %%rdi, 4), %%eax\n\t"
    "mov %[in2], %%edi\n\t"
    "mov %%eax, (%[mas2], %%rdi, 4)"
    :  
    : [mas1]"r"(&c), [mas2]"r"(&d), [in1]"m"(in1), [in2]"m"(in2) );
    cout << "\n\nafter swapping:";
    printArr(&c[0]);
    printArr(&d[0]);
    //calc sum of mas1 elements
    asm(
    "mov $0, %%ecx\n\t"
    "mov $0, %[sum]\n\t"
    "mov %[mas], %%rdi\n\t"
    "calcsum:\n\t" 
    "add (%%rdi), %[sum]\n\t"
    "inc %%ecx\n\t"
    "add $4, %%rdi\n\t"
    "cmp %%ecx, %[len]\n\t"
    "je endcalc\n\t"
    "jmp calcsum\n\t"
    "endcalc:\n\t"
    "\n\t"
    : [sum]"=a"(sum)
    : [len]"m"(n), [mas]"d"(&c) );
    
    cout << "\n\nsum of first array elements: \n" << sum;
    return 0;
}

