#include <iostream>
#include "algorithms.h"
#define eps 1e-3

using namespace std;

int main()
{
	srand(time(0));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, t;
	//n = m = 2;//
	m = n = rand()%9 + 2;
	double **a = new double*[n], *b = new double[n], temp, *b2 = new double[n];
	for(int i = 0; i < m; i++)
		a[i] = new double[m];
	make_diag_preobl(a,n);
	for(int i = 0; i < n; ++i)
		b2[i] = b[i] = rand_num(5,0.1);
	//print_matrix(a,b,n,n);
	lu(a,b,n);
	for(int i = 0; i < n; i++)
		b[i] = b2[i];
	//print_matrix(a,b,n,n);
	algo_ortonorm(a,b2,n);

	///////////////////////

	//print_matrix(a,b,n,n);
	qr(a,b,n);
	return 0;
}