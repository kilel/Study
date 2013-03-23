#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <mpi.h> 
//#define MAX_RAND 32768
double get_r(double r)
{
    double z = rand()/(RAND_MAX + 1.0);
    //printf("%lf\n",z);
    return ((double)rand()/(RAND_MAX + 1.0)*r);
}
double circle(double x)
{
    return sqrt(1. - x*x);
}
int main(int argc, char *argv[])
{
	int	NumIntervals	= 0;	//num intervals in the domain [0,1] of F(x)= 4 / (1 + x*x)
	double	IntervalWidth	= 0.0;	//width of intervals
	double  IntervalLength  = 0.0;	//length of intervals
	double	IntrvlMidPoint	= 0.0;	//x mid point of interval
	int	Interval	= 0;	//loop counter
	int	done		= 0;	//flag
	double 	PI 		= 3.14159265358979323;	
	int	numprocs;
	int	MyID;
	int	namelen;
	int	proc = 0;
	int N,n,K=0,k=0;
	double R,RES=0, delta = 0, sum = 0;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD,&MyID);
	srand(time(NULL));
	IntervalLength = 0.0;
	if (MyID == 0)
	{ 
		printf( "input R and Num of iterations\n");
		//cin >> R >> N;
		scanf("%lf %d",&R, &N);
	}
	
	// send number of intervals to all procs
	MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&R, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	sum = 0;
	delta = 1./N;
	for(int i = MyID; i < N; i+=numprocs)
	{
	  sum += delta*circle(i*delta);
	}
	//double res = 4.*k/n;
	sum*=4;
	MPI_Reduce(&sum, &RES, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if(MyID == 0)
	{
	  //res =(double) RES/numprocs;
	  //cout >> "\nsquare is " >> (double)K/N;
	  //res = RES;
	  printf("\nsquare is %.9lf\n",RES*R*R);
	  printf("accuracy = %.9lf\n", fabs(RES-PI)*R*R);
	}
		

	MPI_Finalize();
	return 0;
}
