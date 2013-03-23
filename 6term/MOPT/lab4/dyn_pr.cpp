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
	vvii d = vvii(m, vii(0));		//сумма, суммарная прибыль
	vvii from = vvii(m,vii(0));				//откуда пришли сюда
	s += "\nШаг 1:\n";
	rep(i,0,n)
	{
		d[0].push_back(ii(x[i], f[i][0]));
		from[0].push_back(ii(-1,i));
		s += "\nЭтап "+(i+1)+": Используя " + d[0][i].first+" средств прибыль "+d[0][i].second + " используя x["+(i+1)+"]";
	}
	rep(j,1,m)
	{
		s += "\n\nШаг "+(j+1)+":\n";
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
						from[j][S] = ii(i,k);	//из i-й вершины, используя x[k]
					}
					s += "\nЭтап "+(S+1)+": Используя " + d[j][S].first+" средств прибыль "+d[j][S].second + " используя x["+(from[j][S].second+1)+"]  из этапа "+ (from[j][S].first+1)+ "шага "+ j ;
		}
	}
	rep(i,0,d[m-1].size())
		if(d[m-1][i].first == val)
			s += "\n\nЕсли использовать ровно "+val+" средств, то максимальная прибыль составит "+d[m-1][i].second;
	/*if(s->Length == 0)
		s += "Нет распределения с использованием ровно "+val+" средств";*/
	long long max = 0, maxi = -1;
	rep(i,0,d[m-1].size())
		if(d[m-1][i].first <= val && d[m-1][i].second > max)
		{
			max = d[m-1][i].second;
			maxi = i;
		}
	if(maxi == -1)
	{
		s += "\nВообще нет распределения с использованием не более "+val+" средств";
		return s;
	}
	s += "\n\nОптимальное распределение с использованием не болеечем "+val+" средств даст прибыль, равную "+max;
	s += "\n\nВклады:\n";
	max = m-1;
	/*rep(i,0,d[m-1].size())
		if(d[m-1][i].first == maxi)
		{
			maxi = i;
			break;
		}*/
	while(max >= 0)
	{
		s += "В предприятие "+(max+1)+" вклад " + x[from[max][maxi].second]+"\n";
		maxi = from[max][maxi].first;
		max--;
	}
	return s;
}
