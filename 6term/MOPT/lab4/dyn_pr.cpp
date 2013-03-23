#include "StdAfx.h"
#include "dyn_pr.h"

dyn_pr::dyn_pr(vi X, vvi F, int V)
{
	x = X; f = F;
	n = x.size();
	m = f[0].size();
	val = V;
	sort(x.begin(),x.end());
}

dyn_pr::~dyn_pr(void)
{
	;
}
int contains(vii s, int k)
{
	rep(i,0,s.size())
		if(s[i].first == k)
			return 1;
	return 0;
}
int dyn_pr::check(int i, int j, int k, vvii from)
{
	while(j>=0)
	{
		if(k == from[j][i].second)
			return 0;
		i = from[j][i].first;
		j--;
	}
	return 1;
}
String^ dyn_pr::solve()
{
	String^ s = "";
	vvii d = vvii(m, vii(0));		//�����, ��������� �������
	vvii from = vvii(m,vii(0));				//������ ������ ����
	s += "\n��� 1:\n";
	rep(i,0,n)
	{
		d[0].push_back(ii(x[i], f[i][0]));
		from[0].push_back(ii(-1,i));
		s += "\n���� "+(i+1)+": ��������� " + d[0][i].first+" ������� ������� "+d[0][i].second + " ��������� x["+(i+1)+"]";
	}
	rep(j,1,m)
	{
		s += "\n\n��� "+(j+1)+":\n";
		rep(i,0,d[j-1].size())
			rep(k,0,x.size())
			if(!contains(d[j], d[j-1][i].first+x[k]) && d[j-1][i].first+x[k] <= val)
				d[j].push_back(ii(d[j-1][i].first+x[k],0));
		from[j] = vii(d[j].size(), ii(0,0));
		rep(S,0,d[j].size())
		{
			rep(i,0,d[j-1].size())
				rep(k,0,x.size())
					if(d[j][S].first == d[j-1][i].first+x[k] && d[j-1][i].second+f[k][j] > d[j][S].second && d[j-1][i].first+x[k] <= val)//&& check(i,j-1,k,from))
					{
						d[j][S].second = d[j-1][i].second+f[k][j];
						from[j][S] = ii(i,k);	//�� i-� �������, ��������� x[k]
					}
					s += "\n���� "+(S+1)+": ��������� " + d[j][S].first+" ������� ������� "+d[j][S].second + " ��������� x["+(from[j][S].second+1)+"]  �� ����� "+ (from[j][S].first+1)+ "���� "+ j ;
		}
	}
	rep(i,0,d[m-1].size())
		if(d[m-1][i].first == val)
			s += "\n\n���� ������������ ����� "+val+" �������, �� ������������ ������� �������� "+d[m-1][i].second;
	/*if(s->Length == 0)
		s += "��� ������������� � �������������� ����� "+val+" �������";*/
	long long max = 0, maxi = -1;
	rep(i,0,d[m-1].size())
		if(d[m-1][i].first <= val && d[m-1][i].second > max)
		{
			max = d[m-1][i].second;
			maxi = i;
		}
	if(maxi == -1)
	{
		s += "\n������ ��� ������������� � �������������� �� ����� "+val+" �������";
		return s;
	}
	s += "\n\n����������� ������������� � �������������� �� �������� "+val+" ������� ���� �������, ������ "+max;
	s += "\n\n������:\n";
	max = m-1;
	/*rep(i,0,d[m-1].size())
		if(d[m-1][i].first == maxi)
		{
			maxi = i;
			break;
		}*/
	while(max >= 0)
	{
		s += "� ����������� "+(max+1)+" ����� " + x[from[max][maxi].second]+"\n";
		maxi = from[max][maxi].first;
		max--;
	}
	return s;
}
