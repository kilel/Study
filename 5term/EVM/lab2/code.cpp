#include <iostream>
#include <vector>
#include <math.h>
#include <windows.h>
using namespace std;
#define sq3 1.7320508075688772935274463415059
#define pi 3.14159265358979323
double a = pi/6, b = 5*pi/3;									//пределы интегрирования:  pi/6..5*pi/3
int n;
double value_f(double arg)
{
	return( 1.0/(1+2*sin(arg)*sin(arg)));
}
double method_rect(double eps)
{		
	double value = 0, h, value2 = 0;
	n = 10;
	h = (b-a)/n;
	for(int i = 0; i < n; i++)
		value += value_f(a+h*(i+0.5));
	value *= h;
	while(1)
	{
		value2 = 0;
		n *= 2;
		h = (b-a)/n;
		for(int i = 0; i < n; i++)
			value2 += value_f(a+h*(i+0.5));
		value2 *= h;
		if(fabs(value-value2)< eps)
			return value2;
		else
			value = value2;
	}
}
double method_trapeze(double eps)
{
	double value = 0, h, value2 = 0;
	n = 10;
	h = (b-a)/n;
	for(int i = 1; i < n; i++)
		value += value_f(a+h*i);
	value += (value_f(a) + value_f(b))/2;
	value *= h;
	while(1)
	{
		value2 = 0;
		n *= 2;
		h = (b-a)/n;
		for(int i = 1; i < n; i++)
			value2 += value_f(a+h*i);
		value2 += (value_f(a) + value_f(b))/2;
		value2 *= h;
		if(fabs(value-value2)< eps)
			return value2;
		else
			value = value2;
	}
}
double method_simpson(double eps)
{
	double value = 0, h, value2 = 0;
	n = 10;
	h = (b-a)/n;
	for(int i = 1; i < n; i++)
		if(i%2 == 0)
			value += 2*value_f(a+i*h);
		else
			value += 4*value_f(a+i*h);
	value += value_f(a) + value_f(b);
	value *= h/3.0;
	while(1)
	{
		value2 = 0;
		n *= 2;
		h = (b-a)/n;
		for(int i = 1; i < n; i++)
			if(i%2 == 0)
				value2 += 2*value_f(a+i*h);
			else
				value2 += 4*value_f(a+i*h);
		value2 += value_f(a) + value_f(b);
		value2 *= h/3.0;
		if(fabs(value-value2)< eps)
			return value2;
		else
			value = value2;
	}
}
double method_gauss(double eps)
{
	double value = 0, h, value2 = 0, temp;
	n = 10;
	h = (b-a)/n;
	temp = h/(sq3);
	for(int i = 0; i < n-1; i++)
			value += value_f(a+h*(i+0.5) + h/2/sq3) + value_f(a+h*(i+0.5) - h/2/sq3);
	value *= h/2.0;
	while(1)
	{
		value2 = 0;
		n *= 2;
		h = (b-a)/n;
		temp = h/(sq3);
		for(int i = 0; i < n; i++)
			value2 += value_f(a+h*(i+0.5) + h/2/sq3) + value_f(a+h*(i+0.5) - h/2/sq3);
		
		value2 *= h/2.0;
		if(fabs(value-value2)< eps)
			return value2;
		else
			value = value2;
	}
}
int main()
{
	double eps;
	while(1)
	{
	printf( "input accuracy:\n");
	cin >> eps;
	system("cls");
	printf( "accuracy =  %.9lf \n", eps);
	printf( "rectangle formula: %.9lf", method_rect(eps));
	printf(", n = %d\n",n);
	printf( "trapeze formula:   %.9lf" ,method_trapeze(eps));
	printf(", n = %d\n",n);
	printf( "Simpson formula:   %.9lf" ,method_simpson(eps));
	printf(", n = %d\n",n);
	printf( "Gauss formula:     %.9lf" ,method_gauss(eps));
	printf(", n = %d\n",n);
	printf( "Real value:        2.453011974 \n");
	}
	return 0;
}