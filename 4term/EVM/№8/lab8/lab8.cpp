#include <iostream>
#include <math.h>
#define eps 1e-5
using namespace std;

double f_1(double x, int i)
{
	if(i == 1)
		return (x-1)*(x-1) - 2*exp(x);
	else
		return powl(0.5, x) - 1 - (x+2)*(x+2);
}
double f__1(double x, int i)
{
	if(i == 1)
		return 2*(x-1) - 2*exp(x);
	else
		return powl(0.5, x)*log(0.5) - 2*(x+2);
}
double f_2(double x)
{
	return pow(x,4) + 4*pow(x,3) - 8*pow(x,2) - 17;
}
void meth_kasat(int i)
{
	double o = -1, O = 1;
	while(fabs(o-O) > eps)
	{
		O = o;
		o = o - f_1(o,i)/f__1(o,i);
	}
	printf("Function %d root is: %0.5lf\n",i, o);
}
void meth_hord(double a, double b)
{
	double x, y;
	x = a;
	y = b;
	while(fabs(b - a) > eps)
    {
        a = b - (b - a) * f_2(b)/(f_2(b) - f_2(a));
        b = a - (a - b) * f_2(a)/(f_2(a) - f_2(b));
    }
	printf("Function 3 root on [%0.4lf, %0.4lf] if %0.4lf\n", x,y,b);
}

void iterat()
{
	double x = 0, X = 1;
	while (fabs(x-X) > eps)
	{
		X = x;
		x = (5*x + 1.5 - 2*sin(x-0.6))/6;
	}
	printf("Function 4 root  if %0.4lf\n", x);
}
int main()
{
	double a,b,c;
	for(int i = 1; i < 3; i++)
	{
		a = -2;
		b = 0;
		while(fabs(b-a)> eps)
		{
 			c = (a+b)/2;
			if(f_1(a, i) > -eps && f_1(c, i) < eps)
			{
				b = c;
				continue;
			}
			else
			{
				a = c;
				continue;
			}
		}
		printf("Function %d root is: %0.5lf\n",i, (a+b)/2);
	}
	meth_hord(0,3);
	meth_hord(-7, -4);
	meth_kasat(1);
	meth_kasat(2);
	iterat();
	cin >> a;
	return 0;
}