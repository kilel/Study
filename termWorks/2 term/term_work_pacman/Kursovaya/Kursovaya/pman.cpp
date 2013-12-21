#include "StdAfx.h"		///89058720661
#include "pman.h"
#include <math.h>
#define delta 15/8


#define STARTX 60 + 13*15
#define STARTY 60 + 23*15


void changexy(const int m, const int i, int% dx, int %dy, int %x, int %y);

pman::pman(void)
{
	super_time = 0;
	super_pacman_mode = false;
	usenot = 0;
	j = 0;
	a = new int* [6];
		for(int k = 0; k < 12; k++)
			a[k] = new int [2];
		for(int k = 1; k <= 3; k++)
		{
			a[0][k] = 45 - 15*k;
			a[1][k] = a[0][k]/2;
			a[0][6-k] = a[0][k];//45 - 15*k;
			a[1][6-k] = a[1][k];//a[0][12-k]/2;
		}
		a[0][0] = 45;
		a[1][0] = 22;
}
void pman::st(int i)
{
	switch(i)
	{
	case 0:
		x = 13;
		y = 23;
		break;
	case 1:
		x = 14;
		y = 25;
		break;
	case 2:
		x = 14;
		y = 23;
		break;
	}
	dy = dx = 0;
	way = 3;
	p = Point(45 + x*15, 45 + y*15);
}
void pman::death(Graphics ^g, int i)
{
	if(j != 1)
		j = 1;	//перевести рот в начальное положнение
	if(way != 3)
		way = 3;
	g->FillEllipse(Brushes::Yellow, p.X-10, p.Y-10 ,20, 20);
	g->FillPie(Brushes::Black, p.X-11, p.Y-11 ,22, 22, -15*i - 90, 30*i); 
}
pman::~pman()
{
	for(int k = 0; k < 6; k++)
		delete a[k];
	delete a;
}
bool pman::draw(int w, level^ lev, int% points)
{
	usenot = 0;
	SolidBrush^ brush1 =gcnew SolidBrush(Color::Yellow);
	SolidBrush^ brush2 =gcnew SolidBrush(Color::Black);
	int h, m;
	//////////////////портал
	switch(lev->retln())
	{
	case 0:
		if(((x == 27) && (y == 14))&&(dx == 0))
			x = 0;
		else if(((x == 0)&&( y == 14)) && (dx == 0))
			x = 27;
	break;
	case 1:
		if(((x == 27) && (y == 15))&&(dx == 0))
			x = 0;
		else if(((x == 0)&&( y == 15)) && (dx == 0))
			x = 27;
		break;
	case 2:
		if(((x == 27) && (y == 15))&&(dx == 0))
			x = 0;
		else if(((x == 0)&&( y == 15)) && (dx == 0))
			x = 27;
		break;
	}
	//////////////////
	switch (w)		//проверка возможности пути текущего и заданного
	{
	case 1: h = lev->retc(y-1, x); break;
	case 2: h = lev->retc(y+1, x); break;
	case 3: h = lev->retc(y, x-1); break;
	case 4: h = lev->retc(y, x+1); break;
	}
	switch (way)
	{
	case 1: m = lev->retc(y-1, x); break;
	case 2: m = lev->retc(y+1, x); break;
	case 3: m = lev->retc(y, x-1); break;
	case 4: m = lev->retc(y, x+1); break;
	}
	if(lev->retc(y, x) == 2)		//съедание точки
	{
		lev->changec(y, x);
		points++;
		return false;
	}
	else if(lev->retc(y, x) == 3)	//съндпние энерджайзера
	{
		lev->changec(y, x);
		lev->changec(y, x);
		points += 2;
		super_pacman_mode = true;
		super_time = 500;
		return true;				//съели, говорим
	}
	if((h == 0) && (m == 0))		//сли не можем идти ни по одному пути, то стоим с раскрытым ртом
		{
			usenot = 1;
			j = 1;
		}
	if((((dx == 7)||(dx == -7))&&((dy == 7)||(dy == -7)))||((dx == 0)&&(dy == 0)))		//если почти дошли или дошли до поворота
	{
		if(dx == 7)		//если не дошли, то доходим
		{
			dx = 0;
			x++;
		}
		else if(dx == -7)
		{
			dx = 0;
			x--;
		}
		if(dy == 7)
		{
			dy = 0;
			y++;
		}
		else if(dx == -7)
		{
			dy = 0;
			y--;
		}

		if(h != 0)		//если можем повернуть, то поворачиваем
		{
			m = h;
			way = w;
		}
	}
	else if((way + w == 3) || (way + w == 7))	//если пути противоположные, то просто поворачиваем
	{
		m = h;
		way = w;
	}
	changexy(m, way, dx, dy, x, y);				//меняем координаты
	p = Point(45 + x*15 + dx*delta, 45 + y*15 + dy*delta);		//заносим в массив
	if(x == -1)
		x = 0;
	if(!usenot)		//если не простаиваем, то жуём
	{
		j++;
		j = j%18;
	}
	return false;			//не съели энерджайзер
}
void pman::only_draw(Graphics ^g, int i)
{
	switch(i)
	{
	case 1:
		g->FillEllipse(Brushes::Yellow, p.X-10, p.Y-10 ,20, 20);
		g->FillPie(Brushes::Black, p.X-15, p.Y-12 ,30, 30, -a[1][j/3] - 90, a[0][j/3]); 
		break;
	case 2:
		g->FillEllipse(Brushes::Yellow, p.X-10, p.Y-10 ,20, 20);
		g->FillPie(Brushes::Black, p.X-15, p.Y-18 ,30, 30, -a[1][j/3] + 90, a[0][j/3]); 
		break;
	case 3:
		g->FillEllipse(Brushes::Yellow, p.X-10, p.Y-10 ,20, 20);
		g->FillPie(Brushes::Black, p.X-11, p.Y-15 ,30, 30, -a[1][j/3] - 180, a[0][j/3]); 
		break;
	case 4:
		g->FillEllipse(Brushes::Yellow, p.X-10, p.Y-10 ,20, 20);
		g->FillPie(Brushes::Black, p.X-18, p.Y-15 ,30, 30, -a[1][j/3], a[0][j/3]); 
		break;
	}
}
void changexy(const int m, const int i, int% dx, int %dy, int %x, int %y)
{
	switch(i)		//смена координат
			{
			case 1:
				if(dy == 0)
				{
					if(m)
						dy--;
				}
				else
				{
					dy--;					
					if(dy == -8)
					{
						dy = 0;
						y--;
					}
				}
				break;
			case 2:
				if(dy == 0)
				{
					if(m)
						dy++;
				}
				else 
				{
						dy++;
					if(dy == 8)
					{
						dy = 0;
						y++;
					}
				}
				break;
			case 3:
				if(dx == 0)
				{
					if(m)
						dx--;
				}
				else
				{
					dx--;
					if(dx == -8)
					{
						dx = 0;
						x--;
					}
				}
				break;
			case 4:
				if(dx == 0)
				{
					if(m)
						dx++;
				}
				else
				{
					dx++;
					if(dx == 8)
					{
						dx = 0;
						x++;
					}
				}
				break;
			}
}