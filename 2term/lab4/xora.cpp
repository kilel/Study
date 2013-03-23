#include "StdAfx.h"
#include "xora.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
int Min(int ng, int nb)
{
	if(ng<nb)
		return ng; 
	else return nb;
}

xora::xora(int n):r(n)
{
	a = new int [r];
	for(int i = 0; i < r; i++)
		a[i] = pow(-1.0, rand()%2)*rand();
}

xora::~xora(void)
{
	delete a;
}

void xora::summ(int *f, int fn)
{
	int n = Min(this->r, fn);
	for(int i = 0; i < n; i++)
		this->a[i] = this->a[i]|f[i];
}
double xora::foreach(int i)
{
	return sqrt((double)this->a[i]);
}
