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
	m = n = rand()%9 + 2;
	double **a = new double*[n], *b = new double[n], temp;
	for(int i = 0; i < m; i++)
		a[i] = new double[m];
	make_diag_preobl(a,n);
	for(int i = 0; i < n; ++i)
		b[i] = rand_num(5,0.1);
	
	square_root(a,b,n);

	///////////////////////

	rand_full_matrix(a,n);
	printf("\nInverce random matrix A and check solution\n\n");
	gauss_inverce(a,n,1);	
	return 0;
}