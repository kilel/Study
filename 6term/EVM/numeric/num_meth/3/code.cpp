#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <math.h>
#include <time.h>
#include <stdio.h>
#define rep(i,k,n) for(int (i) = (k); (i) < (n); (i)++)
#define sqr(r) (r)*(r)
using namespace std;

vector<long long> vi;
set<long long> si;
long long mod;
int a[200000] = {0};
long long abss(long long n)
{
	if(n<0)
		return -n;
	return n;
}
bool prime(long long n)
{
	long long s = sqrt((double)n)+1;
	rep(i,2,s)
		if(n%i == 0)
			return false;
	return true;
}

int gcd(long long a,long long b)
{
	if(a < b)		return gcd(b,a);
	if(b == 0)		return a;
	return gcd(b,a%b);
}

bool qq(long long r)
{
	long long s = sqrt((double)(r));
	if(sqr(s)==r)
		return true;
	return false;
}
void sh(long long n)
{
  long long x,r,y;
  if(prime(n))
  {
	  vi.push_back(n);
	  return;
  }
  x = pow(n,0.33);
  if(n <=8)
  {
	  rep(i,2,8)
		  while(n%i==0)
		  {
			  cout << "ololo\n";
			  vi.push_back(i);
			  n = n/i;
		  }
		  return;
  }
  rep(i,2,x+1)
	  if(n%i==0)
	  {
		sh(i);
		sh(n/i);
		return;
	  }
  rep(k,1,x+1)
  {
	  y = sqrt((double)x/(16.*k))+1;
	  rep(d,0,y+1)
	  {
		  long long A = sqrt(4*k*n)+d;
		  long long B = sqr(A) - 4*k*n;
		  if(qq(B))
		  {
			  B = sqrt((double)B);
				r = gcd(A+B,n);
				if(x > 1 && x < n)
				{
						sh(r);
						sh(n/r);
						return;
				}
				r = gcd(A-B,n);
				if(x > 1 && x < n)
				{
						sh(r);
						sh(n/r);
						return;
				}
		  }
		}
	}


  sh(r);
  sh(n/r);
}
int main()
{
  freopen("input.txt","r", stdin);
  freopen("output.txt", "w", stdout);
  long long n;
  cin >> n;
  mod = n;
  srand(time(NULL));
  while(n%2==0)
  {
    vi.push_back(2);
    n = n/2;
  }
  //cout << n << '\n';
	sh(n);

  sort(vi.begin(),vi.end());
  n = vi.size();
  for(int i = 0; i < n; i++)
  {
    if(vi[i] == 1)
      continue;
    for(int j = i; j < n; j++)
    {
      if(vi[i] !=vi[j])
      {
        cout << vi[i] << " " << j-i << "\n";
        i = j-1;
        break;
      }
      else if(j == n-1)
      {
        cout << vi[i] << " " << j-i+1 << "\n";
        i = n+1;  
        break;
      }
    }
  }
  
  return 0;
}
