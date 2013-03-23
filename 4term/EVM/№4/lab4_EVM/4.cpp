#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define eps 1e-3

using namespace std;

int find_max_in_row(double **a, int m, int k)
{
	double max = fabs(a[k][0]);
	int in = 0;
	for(int i = 0; i < m; i++)
		if(fabs(a[k][i]) > max)
		{
			max = fabs(a[k][i]); 
			in = i;
		}
	return in;
}

void sub_row(double **a, int n, int m, int k, int t, double *b)
{
	double temp = 0;
	for(int i = k + 1; i < n; i++)
	{
		temp = a[i][t]/a[k][t];
		b[i] -= b[k]*temp;
		for(int j = 0; j < m; j++)
		{
			a[i][j] -= a[k][j]*temp;
		}
	}
}

void solve_sys(double **a, double *b, int n, int m)
{
	int *u = new int[m], k = 0;
	double *res = new double[m], temp = 0;
	for(int i = 0; i < m; i++)
	{
		u[i] = 0;
		res[i] = 0;
	}
	for(int i = n-1; i >= 0; i--)
	{
		temp = 0;
		k = -1;
		for(int j = 0; j < m; j++)
		{
			if(fabs(a[i][j]) > eps && !u[j])
			{
				k = j;
				continue;
			}
			temp += a[i][j]*res[j];
		}
		if(k < 0)
		{
			cout << "unknown error!";
			return;
		}
		res[k] = (b[i] - temp)/a[i][k];
		u[k] = 1;
	}
	for(int i = 0; i < n; i++)
		printf("\nx[%d] = %.2lf ", i+1, res[i]);
	delete u;
	delete res;
}
double rand_num(double k, double minimum)
{
	double t = (double)rand()/(RAND_MAX +1)*k + minimum;
	if(rand()%2 == 0)
		t = -t;
	return t;
}
int main()
{
	srand(time(0));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, t;
	cin >> n >> m;
	if(n*m == 0)
	{
		cout << "error!";
		return 0;
	}
	double **a = new double*[n], *b = new double[n], temp;
	for(int i = 0; i < m; i++)
		a[i] = new double[m];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> a[i][j];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	for(int i = 0; i < n; i++)
	{
		t = find_max_in_row(a, m, i);
		if(fabs(a[i][t]) < eps)
		{
			cout << "error! det(main_matrix) must be <> 0!";
			return 0;
		}
		sub_row(a,n,m,i,t,b);
	}
	/*
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			printf("%.2lf ", a[i][j]);
		printf("\n");
	}
	for(int i = 0; i < n; i++)
		printf("%.2lf ", b[i]);
	*/
	printf("Solution:");
	solve_sys(a,b,n,m);
	

	printf("\n/////////////////////////\n\n");////////////

	cin >> n;
	double *alpha, *beta, *gamma, *sol;
	alpha = new double[n+1];
	beta = new double[n+1];
	gamma = new double[n+1];
	sol = new double[n+1];
	for(int i = 1; i <= n; i++)
	{
		sol[i] = rand_num(50, 0.1);
		alpha[i] = rand_num(50, 0.1);
		gamma[i] = rand_num(50, 0.1);
		beta[i] = (fabs(alpha[i]) + fabs(gamma[i]))*rand_num(5, 1.01);
	}
	alpha[1] = 0;
	gamma[n] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j < i-1 || j > i+1)
				printf("%7d ", 0);
			else if(j == i)
				printf("%7.2lf ", -beta[i]);
			else if(j == i-1)
				printf("%7.2lf ", alpha[i]);
			else
				printf("%7.2lf ", gamma[i]);
		}
		printf("|%7.2lf\n", sol[i]);
	}
	printf("\nSolution:\n");
	double *p = new double[n+1], *q = new double[n+1];
	p[1] = gamma[1]/beta[1];
	q[1] = -sol[1]/beta[1];
	for(int i = 2; i <= n; i++)
	{
		p[i] = (gamma[i])/(beta[i] - alpha[i]*p[i-1]);
		q[i] = (alpha[i]*q[i-1] - sol[i])/(beta[i] - alpha[i]*p[i-1]);
	}
	for(int i =  n; i > 0; i--)
	{
		if(n == i)
		{
			temp = q[n];
		}
		else
		{
			temp = p[i]*temp + q[i];
		}
		printf("x[%d] = %.2lf\n", i, temp);
	}
	printf("\n\n\nA := <");
	for(int i = 1; i <= n; i++)
	{
		printf("<");
		for(int j = 1; j <= n; j++)
		{
			if(j < i-1 || j > i+1)
				printf("0");
			else if(j == i)
				printf("%.2lf", -beta[i]);
			else if(j == i-1)
				printf("%.2lf", alpha[i]);
			else
				printf("%.2lf", gamma[i]);
			if(j != n)
				printf("|");
		}
		if(i != n)
			printf(">,");
		else
			printf(">");
	}
	printf(">;\nB := <");
	for(int i = 1; i <= n; i++)
	{
		printf("%.2lf", sol[i]);
		if(i != n)
			printf(",");
	}
	printf(">;\nLinearSolve(A,B);");
	
	
	return 0;
}