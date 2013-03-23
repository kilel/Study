#include "StdAfx.h"
#include "sorta.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

int Max(int a, int b)
{
	if(a > b)
		return a;
	else return b;
}

void qs(int* a, int N);
sorta::sorta(int n):r(n)
{
	a = new int [r];
	for(int i = 0; i < r; i++)
		a[i] = a[i] = pow(-1.0, rand()%2)*rand();
}
sorta::~sorta(void)
{
	delete a;
}

void sorta::summ(int *f, int fn)
{
	int *g = new int[fn + this->r];
	for(int i = 0; i < (this->r + fn); i++)
	{
		if(i < this->r)
			g[i] = this->a[i];
		else
			g[i] = f[i - this->r];
	}
	delete this->a;
	this->a = g;
	this->r = fn + this->r;
}

double sorta::foreach(int ind)
{
	int t;
	for(int i = 0; i < ind; i++)
		for(int j = i+1; j < ind; j++)
			if(a[i] > a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	return 0;
}

void qs(int *a, int N) 
{
  long i = 0, j = N; 		
  int temp, p;
  p = a[N>>1];		
  do 
  {
    while (a[i] < p) 
		i++;
    while (a[j] > p) 
		j--;

    if (i <= j) 
	{
      temp = a[i]; 
	  a[i] = a[j]; 
	  a[j] = temp;
      i++; j--;
    }
  }while (i<=j);
  if (j > 0) 
	  qs(a, j);
  if (N > i) 
	  qs(&a[i], N-i);
}