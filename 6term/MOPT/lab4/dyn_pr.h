#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EPS 1e-12
#define rep(i,k,n) for(int (i) = (k); (i) < (n); (i)++)
#define sqr(r) (r)*(r)
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define di vector<double>
#define vvi vector<vi>
#define vvii vector<vii>
using namespace std;
using namespace System;
class dyn_pr
{
private:
	vvi f;
	vi x;
	int n,m;
	int val;
	int check(int i, int j, int k, vvii from);
public:
	dyn_pr(vi X, vvi F, int V);
	~dyn_pr(void);
	String^ solve();
};

