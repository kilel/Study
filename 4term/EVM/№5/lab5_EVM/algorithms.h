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

void solve_sys(double **a, double *b, int n, int m, int type)
{
	int k, d;
	double *res = new double[m], temp = 0;
	for(int i = 0; i < m; i++)
		res[i] = 0;
	for(int i = n-1; i >= 0; i--)
	{
		if(type == 1)
			k = n - i - 1;
		else 
			k = i;
		temp = 0;
		for(int j = n-1; j > i; j--)
		{
			if(type == 1)
				d = n - j - 1;
			else 
				d = j;
			temp += a[k][d]*res[d];
		}
		res[k] = (b[k] - temp)/a[k][k];
	}
	for(int i = 0; i < n; i++)
		b[i] = res[i];//printf("\nx[%d] = %.2lf ", i+1, res[i]);
	delete res;
}
double rand_num(double k, double minimum)
{
	double t = (double)rand()/(RAND_MAX +1)*k + minimum;
	if(rand()%2 == 0)
		t = -t;
	return t;
}



void print_matrix(double **a, double* b, int n, int m)
{
	printf("\nSolving system:\n");
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			printf("%7.2lf ", a[i][j]);
		printf("|%7.2lf\n", b[i]);
	}
}
void print_matrix_matrix(double **a, double** b, int n, int m)
{
	printf("\nSource\\Result:\n");
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			printf("%7.2lf ", a[i][j]);
		printf("|");
		for(int j = 0; j < m; ++j)
			printf("%7.2lf ", b[i][j]);
		printf("\n");
	}
}

double** matrix_mult(double **a, double** b, int n)
{
	double **c = new double*[n];
	for(int i = 0; i < n; i++)
	{
		c[i] = new double[n];
		for(int j = 0; j < n; j++)
		{
			c[i][j] = 0;
			for(int k = 0; k < n; k++)
				c[i][j] += a[i][k]*b[k][j];
		}
	}
	return c;
}
double* matrix_mult(double **a, double* b, int n)
{
	double *c = new double[n];
	for(int i = 0; i < n; i++)
	{
		c[i] = 0;
		for(int j = 0; j < n; j++)
			c[i] += a[i][j]*b[j];
	}
	return c;
}

void swap_row(double **a,double **b, int n, int i, int j)
{
	double temp;
	for(int k = 0; k < n; k++)
	{
		temp = a[i][k];
		a[i][k] = a[j][k];
		a[j][k] = temp;
		temp = b[i][k];
		b[i][k] = b[j][k];
		b[j][k] = temp;
	}
}
int swap_not_null(double**a,double **b, int n, int i, int j)
{
	for(int k = i; k < n; k++)
	{
		if(fabs(a[k][j]) > eps)
		{
			if(k != i)
				swap_row(a,b,n,i,k);
			return 1;
		}
	}
	return -1;
}
void row_mult_r(double **a, double **b, int n, int i, double k)
{
	for(int j = 0; j < n; j++)
	{
		a[i][j] *= k;
		b[i][j] *= k;
	}
}
int _super_row_minus(double **a, double **b, int n)
{
	double koeff = 0;
	for(int i = 0; i < n; i++)
	{
		if(swap_not_null(a,b,n,i,i) == -1)
		{
			printf("No solution, because det(A) = 0");
			return -1;
		}
		for(int j = i+1; j < n; j++)
		{
			koeff = a[j][i]/a[i][i];
			for(int k = 0; k < n; k++)
			{
				a[j][k] -= koeff*a[i][k];
				b[j][k] -= koeff*b[i][k];
			}
		}
	}
	for(int i = n-1; i >= 0; i--)
	{
		row_mult_r(a,b,n,i,1/a[i][i]);
	}
	for(int i = n-1; i >= 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			for(int k = 0; k < n; k++)
			{
				b[j][k] -= a[j][i]*b[i][k];
				//a[j][k] -= a[j][i]*a[i][k];		//это не надо, так как от а[i][j] 
			}										//может зависеть вычет в b[i][j].
		}											//в общем, с этой строкой работало некорректно
	}
	
}

double** gauss_inverce(double **a, int n, int write)
{
	double **b = new double*[n],**c = new double*[n];
	for(int i = 0; i < n; i++)
	{
		b[i] = new double[n];
		c[i] = new double[n];
		for(int j = 0; j < n; j++)
		{
			b[i][j] = 0;
			c[i][j] = a[i][j];
		}
		b[i][i]++;
	}
	_super_row_minus(a,b,n);									
	if(write)
		print_matrix_matrix(c,b,n,n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			a[i][j] = 0;
			c[i][j] = b[i][j];
		}
		a[i][i]++;
	}
	_super_row_minus(b,a,n);
	if(write)
		print_matrix_matrix(c,a,n,n);
	return c;
}

void make_diag_preobl(double** a, int n)
{
	double temp;
	for(int i = 0; i < n; i++)
	{
		a[i][i] = 0;
		for(int j = i + 1; j < n; j++)
		{
			if(i != j)
			{
				a[i][j] = rand_num(10, 0.01);
				a[j][i] = a[i][j];
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		temp = 0;
		for(int j = 0;  j < n; j++)
		{
			temp += fabs(a[i][j]);
		}
		a[i][i] = temp*rand_num(2, 1.01);
	}
	//print_matrix_matrix(a,a,n,n);
}



void rand_full_matrix(double **a, int n)
{	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			a[i][j] = rand_num(20, 0.01);
	}
}

double sign(double a)
{
	if(a < 0)
		return -1;
	return 1;
}

double sum(double** r, double**d, int i, int j)
{
	double temp = 0;
	for(int k = 0; k <= i-1; k++)
	{
		temp += r[k][i]*r[k][j]*d[k][k];
	}
	return temp;
}
void square_root(double** a,double *b, int n)
{
	double temp;
	double **d, **r, **r2, *b2;
	b2 = new double[n];
	d = new double*[n];
	r = new double*[n];
	r2 = new double*[n];
	for(int i = 0; i < n; i++)
	{
		b2[i] = b[i];
		d[i] = new double[n];
		r[i] = new double[n];
		r2[i] = new double[n];
	}
	for(int i = 0; i < n; i++)
	{
		temp = a[i][i] - sum(r,d,i,i);
		d[i][i] = sign(temp);
		r[i][i] = sqrt(fabs(temp));
		r2[i][i] = r[i][i];
		temp = d[i][i]*r[i][i];
		for(int j = i + 1; j < n; j++)
		{
			d[i][j] = d[j][i] = 0;
			r[j][i] = 0;
			r2[i][j] = 0;
			r2[j][i] = 	r[i][j] = (a[i][j] - sum(r,d,i,j))/temp;
		}
	}
	print_matrix(a,b,n,n);
	print_matrix(r2,b,n,n);
	solve_sys(r2,b,n,n,1);
	r = matrix_mult(d,r,n);
	print_matrix(r,b,n,n);
	solve_sys(r,b,n,n, 0);
	printf("\n");
	for(int i = 0; i < n; i++)
		printf("\nx[%d] = %.6lf ", i+1, b[i]);
	printf("\n\nChecking answer:\n");
	
	b = matrix_mult(matrix_mult(r2,r,n),b,n);
	for(int i = 0; i < n; i++)
	{
		printf("%.6lf = %.6lf\n", b[i], b2[i]);	
	}

	//print_matrix_matrix(a, matrix_mult(r2,r,n),n,n);
}