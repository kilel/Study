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
void row_mult_r(double **a, int n, int i, double k)
{
	for(int j = 0; j < n; j++)
	{
		a[i][j] *= k;
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
				a[i][j] = rand_num(10, 1.01);
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
		a[i][i] = temp*rand_num(10, 5.01);
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

double** transpose(double**a, int n)
{
	double **b = new double*[n];
	for(int i = 0; i < n; i++)
		b[i] = new double[n];
	for(int i = 0; i < n ; i++)
		for(int j = 0; j < n; j++)
			b[i][j] = a[j][i];
	return b;
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
double sum(double** r, double**r2, int i, int j, int t)
{
	double temp = 0;
	for(int k = 0; k < t; k++)
		temp += r2[i][k]*r[k][j];
	return temp;
}
void lu(double** a,double *b, int n)
{
	double temp;
	double **r, **r2, *b2;
	b2 = new double[n];
	r = new double*[n];
	r2 = new double*[n];
	for(int i = 0; i < n; i++)
	{
		b2[i] = b[i];
		r[i] = new double[n];
		r2[i] = new double[n];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i > j)
			{
				r[i][j] = 0;
				r2[i][j] = a[i][j] - sum(r,r2,i,j,j-1);
			}
			else if (j > i)
			{
				r2[i][j] = 0;
				r[i][j] = (a[i][j] - sum(r,r2,i,j,i-1))/r2[i][i];
			}
			else
			{
				r[i][j] = 1;
				r2[i][j] = a[i][j] - sum(r,r2,i,j,j-1);
			}
		}
	}
	//print_matrix(a,b,n,n);
	//print_matrix(r2,b,n,n);
	solve_sys(r2,b,n,n,1);
	//print_matrix(r,b,n,n);
	solve_sys(r,b,n,n,0);
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
double* norm(double **r, int i, int n)
{
	double *nor = new double[n], temp = 0;
	for(int j = 0; j < n; j++)
		temp += r[i][j]*r[i][j];
	temp = sqrt(temp);
	for(int j = 0; j < n; j++)
		nor[j] = r[i][j]/temp;
	return nor;
}
double* getrow(double **r, int i, int n)
{
	double *nor = new double[n];
	for(int j = 0; j < n; j++)
		nor[j] = r[i][j];
	return nor;
}
double scalar_mult(double** a, double** b, int i, int j, int n)
{
	double temp = 0;
	for(int k = 0; k < n; k++)
		temp += a[i][k]*b[j][k];
	return temp;
}
double koeff_to_r(double **a, double** s, int k, int n, int j)
{
	double temp = 0, sp = 0;
	for(int i = 0; i <= k-1; i++)
	{
		sp += scalar_mult(a,s,k,i,n+1)*s[i][j];
	}
	return sp;
}
void print_row(double* a, int n)
{
	printf("\n\nprinting row\n");
	for(int i = 0; i < n; i++)
		printf("%.3lf | ", a[i]);
}
void algo_ortonorm(double** st,double *b, int n)
{
	printf("\n\nOrtoganalization algorithm\n");
	double **r = new double*[n+1], **s = new double*[n+1], **a = new double*[n+1];
	double sp = 1, *x = new double[n], temp = 0;
	for(int i = 0; i <= n; i++)
	{
		x[i] = 0;
		a[i] = new double[n+1];
		r[i] = new double[n+1];
		s[i] = new double[n+1];
	}
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
		{
			if(i < n && j < n)
				a[i][j] = st[i][j];
			else if(j == n && i != n)
				a[i][j] = -b[i];
			else if(i == n && j != n)
				a[i][j] = 0;
			else 
				a[i][j] = 1;
			r[i][j] = 0;
			s[i][j] = 0;
		}
	r[0] = getrow(a,0,n+1);
	//print_row(a[0], n+1);
	//print_row(r[0], n+1);
	s[0] = norm(a,0,n+1);
	//print_row(s[0], n+1);
	for(int k = 1; k <= n; k++)
	{
		for(int j = 0; j <= n; j++)
			r[k][j] = a[k][j] - koeff_to_r(a,s,k,n,j);
		//print_row(r[k], n+1);
		s[k] = norm(r, k, n+1);
		//print_row(s[k], n+1);
	}
	for(int j = 0; j < n; j++)
		x[j]= r[n][j]/r[n][n];
	printf("\n");
	for(int j = 0; j < n; j++)
		printf("x[%d] = %.6lf\n", j+1, x[j]);

}
void qr(double**a, double*b, int n)
{
	printf("\n\nQR algorithm\n");
	double **q = new double*[n], **r = new double*[n], **s = new double*[n], **a1, **a2;
	a1 = transpose(a,n);	//tr
	a2 = transpose(a1,n);	//origin
	a = transpose(a2,n);	//tr
	double sp = 1, *x = new double[n], temp = 0;
	for(int i = 0; i < n; i++)
	{
		x[i] = 0;
		r[i] = new double[n];
		q[i] = new double[n];
		s[i] = new double[n];
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			q[i][j] = a[i][j];
			s[i][j] = 0;
			r[i][j] = 0;
			r[i][i] = 1;
		}
	s[0] = norm(q,0,n);
	//row_mult_r(r,n,0,1/sqrt(scalar_mult(q,q,0,0,n)));
	for(int k = 1; k < n; k++)
	{
		for(int i = 0; i < k; i++)
			{
				r[k][i] = scalar_mult(q,q,k,i,n)/scalar_mult(q,q,i,i,n);
			}
		for(int j = 0; j < n; j++)
		{
			double temp = 0, sp = 0;
			
			for(int i = 0; i < k; i++)
			{		
				sp += r[k][i]*q[i][j];
			}
			q[k][j] -= sp;
		}
		s[k] = norm(q,k,n);
		//row_mult_r(r,n,k,1/sqrt(scalar_mult(q,q,k,k,n)));
	}
	double **c1 = matrix_mult(q,transpose(q,n),n);
	/*printf("\n A|B\n");
	print_matrix(a,b,n,n);
	printf("\n R.Q|B\n");
	print_matrix(matrix_mult(r,q,n),b,n,n);
	printf("\n Q|R\n");
	print_matrix_matrix(q,r,n,n);
	printf("\n Q|Q.transpose(Q)\n");
	print_matrix_matrix(q,c1,n,n);*/
	/*printf("\n Q|Q.Q\n");
	print_matrix_matrix(s,matrix_mult(s,s,n),n,n);*/
	/*for(int i = 0; i < n; i++)
		row_mult_r(r,n,i,c1[i][i]);
	printf("\n");
	cout << scalar_mult(q,q,1,2,n);*/
	r = transpose(r,n);
	q = transpose(q,n);
	b = matrix_mult(transpose(q,n),b,n);
	for(int i = 0; i < n; i++)
		row_mult_r(r,n,i,c1[i][i]);
	solve_sys(r,b,n,n,0);
	//double **c = transpose(q,n);
	//x = matrix_mult(c,b,n);
	//for(int i = 0; i < n; i++)
	//	b[i] = 0;
	printf("\n");
	for(int j = 0; j < n; j++)
		printf("x[%d] = %.6lf\n", j+1, b[j]);
}