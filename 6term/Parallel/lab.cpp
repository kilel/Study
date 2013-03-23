#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <mpi.h> 
#define PI 3.14159265358979323
using namespace std;

double circle(double x)
{
    return sqrt(1. - x*x);
}
double get_r()
{
    return ((double)rand()/(RAND_MAX + 1.0));
}
double MC(int n)
{
	double  sum = 0,x,y;
	int k=0;
	for(int i = 0; i < n; i++)
	{
		x = get_r();
		y = get_r();
		x*=x;
		y*=y;
		if(x+y < 1)
			k++;
	}
	sum = (double)k/n;
	return sum;
}
double integr(int n, int size, int rank)
{
	double sum = 0;
	double delta = 1./n;
	for(int i = rank; i < n; i+=size)
	{
	  sum += delta*circle(i*delta);
	}
	return sum;
}
int main(int argc, char *argv[])
{
	srand(time(0));
	int size,rank,a[3]= {0};
	double r,res=0,RES=0;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	///<enter MPI>
	if(rank == 0)
	{
		cout << "Chose your destiny.\nInput 1 to use Monte-Carlo meth\nInput 2 to use circle integration meth (int(sqrt(R^2-x^2),x=0..R))\n";
		cin >> a[1];
		if(a[1] > 2 || a[1] < 1)
		{
				cout << "Incorrect data. I'll use circle int\n";
				a[1] = 2;
		}
		cout << "Input R and count of iterations\n";
		cin >> r >> a[2];
		if(r<0)
			r = -r;
	}
	
	MPI_Bcast(&a, 3, MPI_INT, 0, MPI_COMM_WORLD);
	if(a[1] == 1) res = MC(a[2]);
	else res = integr(a[2],size,rank);
	MPI_Reduce(&res, &RES, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if(rank == 0)
	{
		if(a[1] == 1) RES = RES/size;
		RES *= 4.;
		printf("\nsquare is %.9lf\n",RES*r*r);
		printf("accuracy = %.9lf\n", fabs(RES-PI)*r*r);
	}
	///<end MPI>
	MPI_Finalize();
	return 0;
}
