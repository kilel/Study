#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define sq3 1.7320508075688772935274463415059

using namespace std;
double *f_x;
double f1(double x,double y)
{
	return(exp(x*x - 2*y*y));
}
double f2(double x,double y)
{
	if(x > y  + 1e-5)
		return 0;
	return(exp(x*x - 2*y*y));
	
}
double build_f_x(double eps)//simpson
{
	int n = 50,m = 66;
	double h1 = 1.0/n, h2 = 1.0/m, temp = 99999999, value = 999999999, value2 = 0, temp2 = 0;
	while(1)
	{
		value2 = 0;
		n*=2;
		h1 = 1.0/n;
		for(int i = 0; i < n+1; i++)
		{
			m = 66;
			while(1)
			{
				temp2 = 0;
				m *= 2;
				h2 = 1.0/m;
				for(int j = 0; j < m+1; j++)
				if(j > 0 && j < m)
					if(j%2 == 0)
						temp2 += 2*f1(h1*i, j*h2);
					else 
						temp2 += 4*f1(h1*i, j*h2);
				else
					temp2 += f1(h1*i, j*h2);
				temp2 *= h2;
				if(fabs(temp-temp2) < eps)
					break;
				else
					temp = temp2;
			}
			if(i > 0 && i < n)
				if(i%2 == 0)
					value2 += 2*(temp)/3.0;
				else
					value2 += 4*(temp)/3.0;
			else
				value2 += (temp)/3.0;
		}
		value2 *=  h1;
		if(fabs(value-value2) < eps)
					return value2/3.0;
		else
			value = value2;
	}
}
double build_f_x2(double eps)//simpson
{
	int n = 50,m = 66;
	double h1 = 1.0/n, h2 = 1.0/m, temp = 99999999, value = 999999999, value2 = 0, temp2 = 0;
	while(1)
	{
		value2 = 0;
		n*=2;
		h1 = 1.0/n;
		for(int i = 0; i < n+1; i++)
		{
			m = 66;
			while(1)
			{
				temp2 = 0;
				m *= 2;
				h2 = 1.0/m;
				for(int j = 0; j < m+1; j++)
				if(j > 0 && j < m)
					if(j%2 == 0)
						temp2 += 2*f2(h1*i, j*h2);
					else 
						temp2 += 4*f2(h1*i, j*h2);
				else
					temp2 += f2(h1*i, j*h2);
				temp2 *= h2;
				if(fabs(temp-temp2) < eps)
					break;
				else
					temp = temp2;
			}
			if(i > 0 && i < n)
				if(i%2 == 0)
					value2 += 2*(temp)/3.0;
				else
					value2 += 4*(temp)/3.0;
			else
				value2 += (temp)/3.0;
		}
		value2 *=  h1;
		if(fabs(value-value2) < eps)
					return value2/3.0;
		else
			value = value2;
	}
}

bool cmp(double x, double y, double z)
{
	if( (x*x + y*y + z*z < 121 + 1e-10) && (x*x + y*y + z*z > 25 - 1e-10))
		if( z < 0 && (z + sqrt((x*x + y*y)/24) < 0) && (y + x/sq3 > 0) && (y+x*sq3 > 0))
		return true;
	return false;
}
double randval()
{
	if(rand()%2==1)
		return ((double)rand()/(RAND_MAX + 1)*(6)+5);
	else
		return ((-1)*((double)rand()/(RAND_MAX + 1)*(6)+5));
}
double val(double eps)
{
	int n = 1000;
	double val1 = 999999999, val2 = 0, total = 22*22*22 - 10*10*10;
	while(1)
	{
		val2 = 0;
		for(int i = 0; i < n; i++)
		{
			if(cmp(randval(),randval(),randval()))
				val2++;
		}
		val2 *= total/n;
		if(fabs((val1-val2)) < eps)
			return val2;
		else
		{
			val1 = val2;
			n*=2;
		}
	}
}
int main()
{
	double eps;
	srand(time(0));
	srand(rand());
	printf("input accuracy:");
	cin >> eps;
	printf("Task 1. int(exp(x^2 - 2*y^2), x = 0..1, y = 0..1) = %0.9lf\n",build_f_x(eps/2));
	printf("Task 2. int(exp(x^2 - 2*y^2), x = 0..y, y = 0..1) = %0.9lf\n", build_f_x2(eps/2));
	printf("input accuracy to calculate value:");
	cin >> eps;
	printf("Task 3. Value is %.9lf", val(eps));
	cin >> eps;
	return 0;
}