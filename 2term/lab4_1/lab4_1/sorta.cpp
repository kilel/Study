#include "StdAfx.h"
#include "sorta.h"
#include <stdlib.h>
#include <time.h>

sorta::sorta(int n)
{
	r = n;
	a = new int [r];
	for(int i = 0; i < r; i++)
		a[i] = (double)rand()/(RAND_MAX +1)*(INT_MAX - INT_MIN) + INT_MIN;
}
