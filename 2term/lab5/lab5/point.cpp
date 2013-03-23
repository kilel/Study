#include "StdAfx.h"
#include "point.h"
#include <math.h>

point::point(int i, int j)
{
	x = i;
	y = j;
	p = 0;
	px = 0;
	py = 0;
}

	void operator +=(point %T, point %T2)
	{
		int x1 = T.getx(), x2 = T2.getx(), y1 = T.gety(), y2 = T2.gety();
		T.changex(x1+x2);
		T.changey(y1+y2);
	}
	double operator &(point %T)
	{
		double X = T.getx();
		double Y = T.gety();
		return (sqrt(X*X + Y*Y));
	}
	bool operator ==(point %T, point %T2)
	{
		if((T2.getx() == T.getx())&&(T2.gety() == T.gety()))
			return true;
		else return false;
	}

	double operator /(point %T, point %T2)
	{
		double x1 = T.getx(), x2 = T2.getx(), y1 = T.gety(), y2 = T2.gety();
		return (sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
	}

	point% operator -(point %T)
	{
		double X = T.getx(), Y = T.gety(), ro, fi ;
		T.p = 1;
		ro = sqrt(X*X + Y*Y);
		fi = acos(Y/ro);
		T.changex(ro);
		T.changey((fi*180/3.14));
		return T;
	}