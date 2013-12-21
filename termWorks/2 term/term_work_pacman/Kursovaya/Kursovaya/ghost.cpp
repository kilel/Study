#include "StdAfx.h"
#include "ghost.h"
#include <math.h>
#include <stdlib.h>

#define eps 1e-6

#define delta 15/8
#define pi 3.1415926
	
void changexy(const int i, int% dx, int %dy, int %x, int %y);

ghost::ghost(int t)
{
	type = t;
	switch (type)
	{
	case 1:
		br = gcnew SolidBrush(Color::Red);
		break;
	case 2:
		br = gcnew SolidBrush(Color::Pink);
		break;
	case 3:
		br = gcnew SolidBrush(Color::Aqua);
		break;
	case 4:
		br = gcnew SolidBrush(Color::Orange);
		break;
	}
}
ghost::~ghost(void)
{
	delete br;
}
void ghost::st(int i)		//отправление призрака в стандартное положение i-го уровня
{
	eated = false;
	sick_mode = false;
	switch (type)
	{
	case 1:
		way = nextway = 3;
		switch(i)
		{
		case 0:
			x = 13;
			y = 11;
			break;
		case 1:
			x = 14;
			y = 12;
			break;
		case 2:
			x = 14;
			y = 12;
			break;
		}
		break;
	case 2:
		way = nextway = 1;
		x = 12;
		y = 14;
		switch(i)
		{
		case 0:
			x = 12;
			y = 14;
			break;
		case 1:
			x = 13;
			y = 15;
			break;
		case 2:
			x = 12;
			y = 15;
			break;
		}
		break;
	case 3:
		way = nextway = 1;
		x = 14;
		y = 14;
		switch(i)
		{
		case 0:
			x = 14;
			y = 14;
			break;
		case 1:
			x = 10;
			y = 15;
			break;
		case 2:
			x = 13;
			y = 18;
			break;
		}
		break;
	case 4:
		way = nextway = 1;
		x = 16;
		y = 14;
		switch(i)
		{
		case 0:
			x = 16;
			y = 14;
			break;
		case 1:
			x = 17;
			y = 15;
			break;
		case 2:
			x = 15;
			y = 15;
			break;
		}
		break;
	}
	switch(i)
	{
	case 0:
		hx1 = 11;
		hx2 = 16;
		hy1 = 13;
		hy2 = 15;
		fhcx = 13;
		fhcy = 10;
		break;
	case 1:
		hx1 = 11;
		hx2 = 16;
		hy1 = 13;
		hy2 = 16;
		fhcx = 14;
		fhcy = 10;
		break;
	case 2:
		hx1 = 10;
		hx2 = 17;
		hy1 = 14;
		hy2 = 16;
		fhcx = 14;
		fhcy = 12;
		break;
	}
	dy = dx = 0;
	icon = 0;
}
bool ghost::draw(level^ lev, pman^ pacman, ghost ^binky, int %points, bool god)
{
	if((x == pacman->retx()) && (y == pacman->rety()))	
	{
		if(eated)
			;
		else if(!sick_mode)				//если полон сил,
		{				
			if(!god)					//то
				return true;			//пакмен мертв
		}
		else if(!eated)				//если же слаб и не съеден, то
		{
			eated = true;			//призрак съеден
			points += 20;
		}
	}
	int tx, ty;						//координаты цели
	///////////////портал
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
		if(((x == 27) && (y == 14))&&(dx == 0))
			x = 0;
		else if(((x == 0)&&( y == 14)) && (dx == 0))
			x = 27;
		break;
	}
	///////////////
	//int hx1, hx2, hy1, hy2;
	
	if(((x >= hx1) && (x <= hx2)) && ((y >= hy1) && (y <= hy2)))	//если в домике
	{
		if(eated)		//если съеден, то оживиться
		{
			sick_mode = false;
			eated = false;
		}
		if(!eated)	//если не съеден, то выйти из дома
		{
			tx = fhcx;					
			ty = fhcy;
		}
	}
	else		//выбираются координаты цели
	{
		if(eated) //если съеден, то идти домой
		{
			tx = ty = 14;
		}
		else if(sick_mode)	//если слаб, то рандомом
		{
			tx = ((int)rand())%30;
			ty = ((int)rand())%30;
		}
		else
		{
			switch (type)
			{
			case 1:
				tx = pacman->retx();	//binky - красное приведение. следует за пакменом.
				ty = pacman->rety();
				break;
			case 2:
				switch(pacman->retway())	//pinky - розовое приведение. следует за пакменом + 4 клеточки вперед от него. 
				{							//когда движется вверх, то +4 вверх и + 4 влево.
				case 1:
					tx = pacman->retx() - 4;
					ty = pacman->rety() - 4;
					break;
				case 2:
					tx = pacman->retx();
					ty = pacman->rety()+ 4;
					break;
				case 3:
					tx = pacman->retx() - 4;
					ty = pacman->rety();
					break;
				case 4:
					tx = pacman->retx() + 4;
					ty = pacman->rety();
					break;
				}
				break;
			case 3:							//inky - голубое приведение. Следует по сложной траектории. 
				switch(pacman->retway())	//Идёт в к конец отрезка, первым концом которого является binky, а серединой pacman
				{
				case 1:
					tx = pacman->retx() - 4 + (pacman->retx() - binky->retx());
					ty = pacman->rety() - 4 - (pacman->rety() - binky->rety());
					break;
				case 2:
					tx = pacman->retx() + (pacman->retx() - binky->retx());
					ty = pacman->rety()+ 4 - (pacman->rety() - binky->rety());
					break;
				case 3:
					tx = pacman->retx() - 4 + (pacman->retx() - binky->retx());
					ty = pacman->rety() - (pacman->rety() - binky->rety());
					break;
				case 4:
					tx = pacman->retx() + 4 + (pacman->retx() - binky->retx());
					ty = pacman->rety() - (pacman->rety() - binky->rety());
					break;
				}
				break;
			case 4:							//Clyle - оранжевое приведение. Если ближе 4х клеток от пакмена, то идет в правы нижний угол,
				tx = pacman->retx();		//иначе идёт к пакмену
				ty = pacman->rety();
				if((((tx - x) <= 5) || ((tx - x) >= -5)) && (((ty - y) <= 5) || ((ty - y) >= -5)))
				{
					tx = 100;
					ty = 100;
				}
				break;
			}
		}
	}
	/*
	if((eated)&&((x == 14)&&(x == y)))
	{
		eated = false;
		sick_mode = false;
	}
	*/
	int m, xx = x, yy = y, may[5], mini = 0;
	int use[5][3] = {{0,0,0}, {0, 0, -1}, {0, 0, 1}, {0, -1, 0}, {0, 1, 0}}, arara[5] = {0,1,3,2,4}, dopway[5] = {0,2,1,4,3};
	double min = 10000, temp;
	char stupid_sit = 1;

	if(nextway == way)
	{		
		switch (way)
		{
		case 1:
			yy--;
			m = lev->retc(yy, xx); 
			break;
		case 2:
			yy++;
			m = lev->retc(yy, xx);
			break;
		case 3:
			xx--;
			m = lev->retc(yy, xx); 
			break;
		case 4:
			xx++;
			m = lev->retc(yy, xx); 
			break;
		}
		if(m)		//если есть куда идти
		{
			for(int i = 1; i <=4; i++)
			{
				if(i == dopway[way])  //если поворачиваем назад, то пропускаем
					continue;
				may[i] = lev->retc(yy + use[i][2], xx + use[i][1]);	//рассматриваются возможность пути из следующей клетки
				if(may[i])
				{
					temp = sqrt((double)((yy + use[i][2] - ty)*(yy + use[i][2] - ty) + (xx + use[i][1] - tx)*(xx + use[i][1] - tx)));
					if(fabs(temp - min) > eps)
					{
						if(temp < min)	//выбирается минимальный путь до цели
						{
						 min = temp;
						 mini = i;
						 stupid_sit = 0;
						}
					}
					else
						stupid_sit = 1;
				}
			}
			if(stupid_sit)		//попали в ситуацию, когда пути равны
			{
				for(int i = 1; i <=4; i++)	//выбираем первый путь их приоритета
				{
					if((may[arara[i]])&&(dopway[way] != arara[i]))
					{
						nextway = arara[i];
						stupid_sit = 0;
					}
				}
			}
			else
				nextway = mini;
		}
		else
		{
			/*switch (way)	//возвращение в нормальные координаты
			{
			case 1:
				yy++;
				break;
			case 2:
				yy--;
				break;
			case 3:
				xx++;
				break;
			case 4:
				xx--;
				break;
			}
			for(int i = 1; i <=4; i++)	//выбор первого возможного пути, несовпадающего с данным
			{
				if(((may[arara[i]])&&(dopway[way] != arara[i]))&&(lev->retc(yy + use[i][2], xx + use[i][1]))) ;
			}*/
			way = dopway[way];			//если пришли в тупик, то идём назад
		}
	}
	changexy(way, dx, dy, x, y);	// смена координат
	if((dx == 0)&&(dy == 0))	//если есть возможность повернуть, то поворачиваем
	{
		way = nextway;
	}
	return false;		//пакмен жив
}

void ghost::drawgh(Graphics ^g, int par)
{
	if(icon == 0)			//первый вид рисовки
	{
		array <Point> ^p, ^t;
		p = gcnew array <Point>(72);
		t = gcnew array <Point>(6);
		int i;
		double fi = 0;

		for(fi = 0, i = 0; fi < 7*pi + pi/10; i++, fi += pi/10)		//задаётся нихняя часть призрака
		{
			p[i].X = fi*10;
			p[i].Y = (20 -6 + 10*cos(cos((fi))))*10;			// *10 для точности
		}
		p[71] = Point(100, 100);			// верх призрака и доп. точки
		t[0] = p[0];
		t[3] = Point(180, 40);
		t[2] = Point(100, 0);
		t[1] = Point(20, 40);
		t[4] = p[70];
		t[5] = Point(100, 120);
		for(i = 0; i < 72; i++)
		{
			p[i].X = 45 - 12 + x*15 + dx*delta + (p[i].X)/10;		//переводится в координаты
			p[i].Y = 45 - 12 + y*15 + dy*delta + (p[i].Y)/10;
		}
		for(i = 0; i < 6; i++)
		{
			t[i].X = 45 - 12 + x*15 + dx*delta + (t[i].X)/10;
			t[i].Y = 45 - 12 + y*15 + dy*delta + (t[i].Y)/10;
		}
		if(!eated)		//варианты рисовки
		{
			if(!sick_mode)
			{
				g->FillPolygon(br, p);
				g->FillClosedCurve(br, t);
			}
			else
			{
				g->FillPolygon(Brushes::Blue, p);
				g->FillClosedCurve(Brushes::Blue, t);
			}
		}
		g->FillEllipse(Brushes::White, (60 - 30)/10 + 45 + x*15 + dx*delta - 12 , (80 - 30 )/10 + 45 + y*15 + dy*delta - 12 , 5, 5);		//основа глаз
		g->FillEllipse(Brushes::White, (200 - 60 - 30 )/10 + 45 + x*15 + dx*delta - 12 , (80 - 30 )/10 + 45 + y*15 + dy*delta - 12 , 5, 5);
		switch (way)			//положение глаз в зависимости от пути
		{
		case 1: 
			g->FillEllipse(Brushes::Blue, 6-2 + 45 + x*15 + dx*delta - 12 , 8-3 + 45 + y*15 + dy*delta - 12 , 3, 3);
			g->FillEllipse(Brushes::Blue, 20-6-2 + 45 + x*15 + dx*delta - 12 , 8-3 + 45 + y*15 + dy*delta - 12 , 3, 3);
			break;
		case 2:
			g->FillEllipse(Brushes::Blue, 6-2 + 45 + x*15 + dx*delta - 12 , 8-1 + 45 + y*15 + dy*delta - 12 , 3, 3);
			g->FillEllipse(Brushes::Blue, 20-6-2 + 45 + x*15 + dx*delta - 12 , 8-1 + 45 + y*15 + dy*delta - 12 , 3, 3);
			break;
		case 3:
			g->FillEllipse(Brushes::Blue, 6-3 + 45 + x*15 + dx*delta - 12 , 8-2 + 45 + y*15 + dy*delta - 12 , 3, 3);
			g->FillEllipse(Brushes::Blue, 20-6-3 + 45 + x*15 + dx*delta - 12 , 8-2 + 45 + y*15 + dy*delta - 12 , 3, 3);
			break;
		case 4:
			g->FillEllipse(Brushes::Blue, 6-1 + 45 + x*15 + dx*delta - 12 , 8-2 + 45 + y*15 + dy*delta - 12 , 3, 3);
			g->FillEllipse(Brushes::Blue, 20-6-1 + 45 + x*15 + dx*delta - 12 , 8-2 + 45 + y*15 + dy*delta - 12 , 3, 3);
			break;
		}
		delete p;
		delete t;
	}
	else
	{
		int i;			//аналогично, но 2 вид рисовки
		array <Point> ^p, ^t;
		p = gcnew array <Point>(72);
		t = gcnew array <Point>(6);
		double fi = 0;
		for(fi = 0, i = 0; fi < 7*pi + pi/10; i++, fi += pi/10)
		{
			p[i].X = fi*10;
			p[i].Y = (20  + 4*sin(sin(fi)))*10; //cos(sin)
		}
		p[71] = Point(100, 100);
		t[0] = p[0];
		t[3] = Point(180, 40);
		t[2] = Point(100, 0);
		t[1] = Point(20, 40);
		t[4] = p[70];
		t[5] = Point(100, 120);
		for(i = 0; i < 72; i++)
		{
			p[i].X = 45 - 12 + x*15 + dx*delta + (p[i].X)/10;
			p[i].Y = 45 - 12 + y*15 + dy*delta + (p[i].Y)/10;
		}
		for(i = 0; i < 6; i++)
		{
			t[i].X = 45 - 12 + x*15 + dx*delta + (t[i].X)/10;
			t[i].Y = 45 - 12 + y*15 + dy*delta + (t[i].Y)/10;
		}
		if(!eated)
		{
			if(!sick_mode)
			{
				g->FillPolygon(br, p);
				g->FillClosedCurve(br, t);
			}
			else
			{
				if(!par)
				{
					g->FillPolygon(Brushes::Blue, p);
					g->FillClosedCurve(Brushes::Blue, t);
				}
				else
				{
					g->FillPolygon(Brushes::White, p);
					g->FillClosedCurve(Brushes::White, t);
				}
			}

		}
		g->FillEllipse(Brushes::White, (60 - 20)/10 + 45 + x*15 + dx*delta - 12 , (60 - 20 )/10 + 45 + y*15 + dy*delta - 12 , 4, 4);
		g->FillEllipse(Brushes::White, (200 -60 - 20 )/10 + 45 + x*15 + dx*delta - 12 , (60 - 20 )/10 + 45 + y*15 + dy*delta - 12 , 4, 4);
		switch (way)
		{
		case 1: 
			g->FillEllipse(Brushes::Blue, 6-2 + 45 + x*15 + dx*delta - 12 , 8-4 + 45 + y*15 + dy*delta - 12 , 3, 3);
			g->FillEllipse(Brushes::Blue, 20-6-2 + 45 + x*15 + dx*delta - 12 , 8-4 + 45 + y*15 + dy*delta - 12 , 3, 3);
			break;
		case 2:
			g->FillEllipse(Brushes::Blue, 6-2 + 45 + x*15 + dx*delta - 12 , 8-3 + 45 + y*15 + dy*delta - 12 , 3, 3);
			g->FillEllipse(Brushes::Blue, 20-6-2 + 45 + x*15 + dx*delta - 12 , 8-3 + 45 + y*15 + dy*delta - 12 , 3, 3);
			break;
		case 3:
			g->FillEllipse(Brushes::Blue, 6-3 + 45 + x*15 + dx*delta - 12 , 8-3 + 45 + y*15 + dy*delta - 12 , 3, 3);
			g->FillEllipse(Brushes::Blue, 20-6-3 + 45 + x*15 + dx*delta - 12 , 8-3 + 45 + y*15 + dy*delta - 12 , 3, 3);
			break;
		case 4:
			g->FillEllipse(Brushes::Blue, 6-1 + 45 + x*15 + dx*delta - 12 , 8-3 + 45 + y*15 + dy*delta -12, 3, 3);
			g->FillEllipse(Brushes::Blue, 20-6-1 + 45 + x*15 + dx*delta - 12 , 8-3 + 45 + y*15 + dy*delta - 12 , 3, 3);
			break;
		}
		delete p;
		delete t;
	}
}
void changexy(const int i, int% dx, int %dy, int %x, int %y)
{
	switch(i)		//смена координат
			{
			case 1:
				dy--;					
				if(dy == -8)
				{
					dy = 0;
					y--;
				}
				break;
			case 2:
				
				dy++;
				if(dy == 8)
				{
					dy = 0;
					y++;
				}
				break;
			case 3:
				dx--;
				if(dx == -8)
				{
					dx = 0;
					x--;
				}
				break;
			case 4:
				dx++;
				if(dx == 8)
				{
					dx = 0;
					x++;
				}
				break;
			}
}