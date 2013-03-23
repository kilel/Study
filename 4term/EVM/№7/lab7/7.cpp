#include <iostream>
#include "algorithms.h"
#define eps 1e-3

using namespace std;

void c4newton(double*c,double x, double y)
{
	c[0] = sin(x+y) - 1.5*x + 0.1;
	c[1] = x*x + y*y - 1;
}
void a4newton(double**a, double x, double y)
{
	a[0][0] = cos(x+y) - 1.5;
	a[0][1] = cos(x+y);
	a[1][0] = 2*x;
	a[1][1] = 2*y;
}
void sol(double**a, double*c)
{
	double x,y,z,k,det;
	det = a[0][0]*a[1][1] - a[0][1]*a[1][0];
	x = c[0]*a[1][1] - a[0][1]*c[1];
	y = a[0][0]*c[1] - c[0]*a[1][0];
	c[0] = -x/det;
	c[1] = -y/det;
}

int main()
{
	srand(time(0));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n,m, t;	/////simple iterations
	double x1[2] = {0};
	for(int i = 0; i < 10; i++)
	{
		x1[0] = 1 - sin(x1[1])/2;
		x1[1] = 0.7 - cos(x1[0]-1);
	}
	printf("x = [%.5lf, %.5lf]", x1[0], x1[1]);
	///////newton
	double x[2] = {1,0}, *c = new double[2], **a = new double*[2];
	a[0] = new double[2];
	a[1] = new double[2];

	for(int i = 0; i < 10; i++)
	{
		c4newton(c,x[0], x[1]);
		a4newton(a,x[0], x[1]);
		sol(a,c);
		x[0] += c[0];
		x[1] += c[1];
	}
	printf("\n\n/////////////\n\nx = [%.5lf, %.5lf]", x[0], x[1]);
	return 0;
}