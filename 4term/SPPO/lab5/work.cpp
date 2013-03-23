#include "StdAfx.h"
#include "work.h"
#include <math.h>

work::work(void)
{
	sum = 0;
	t1=t2=t3=t4=t5 = 0;
	w1 = w2= w3 =w4 =w5 = 0;
}

void work::proc1()
{
	for(int i = 1; i < 10000000; i++, t1 = i/100000)
		w1 += i*cos((double)i) - 2*i;
}
void work::proc2()
{
	for(int i = 1; i < 10000000; i++, t2 = i/100000)
		w2 += sin(cos((double)i))*sin(cos((double)i));
}
void work::proc3()
{
	for(int i = 1; i < 10000000; i++, t3 = i/100000)
		w3 += cos((double)i+2);
}
void work::proc4()
{
	for(int i = 1; i < 10000000; i++, t4 = i/100000)
		w4 += sin((double)i);
}
void work::proc5()
{
	for(int i = 1; i < 10000000; i++, t5 = i/100000)
		w5 += i + 1.0/i + 1.0/2.0/i;
}