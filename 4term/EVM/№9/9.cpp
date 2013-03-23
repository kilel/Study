#include <iostream>
#include "algorithms.h"
#define eps 1e-3

using namespace std;

int main()
{
	srand(time(0));
	//freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, t;
	//n = m = 2;//
	m = n = rand()%9 + 2;
	double **a = new double*[n], *b = new double[n], temp, *b2 = new double[n];
	for(int i = 0; i < m; i++)
		a[i] = new double[m];
	make_diag_preobl(a,n);
	find_eign(a,n,1,1);
	return 0;
}