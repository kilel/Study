#include "StdAfx.h"
#include "clasa.h"

ghost::ghost()
{
	t = blinky;
	sp = 80;
	ea = false;
	img = gcnew Bitmap("b.jpg");
}
ghost::ghost(type tt)
{
	
	t = tt;
	sp = 80;
	ea = false;
	switch (tt)
	{
		case blinky: img = gcnew Bitmap("b.jpg");break;
		case pinky: img = gcnew Bitmap("p.jpg");break;
		case inky: img = gcnew Bitmap("i.jpg");break;
		case clyde: img = gcnew Bitmap("c.jpg");break;
	}
}
ghost::ghost(type tt, int speed, char eated)
{
	t = tt;
	sp = speed;
	ea = eated;
	switch (tt)
	{
		case blinky: img = gcnew Bitmap("b.jpg");break;
		case pinky: img = gcnew Bitmap("p.jpg");break;
		case inky: img = gcnew Bitmap("i.jpg");break;
		case clyde: img = gcnew Bitmap("c.jpg");break;
	}
}
ghost::ghost(ghost %g)
	{
		
		t = g.t;
		sp = g.sp;
		ea = g.ea;
		img = g.img;
	}
ghost::~ghost()
	{
		delete img;
	}
void ghost::Ghost_change_speed(int speed)
	{
		if(speed/100 == 0)
			this->sp = speed%100;
		else 
			this->sp = 100;
	}
void ghost::Ghost_change_type(type tt)
	{
		this->t = tt;
	}
void ghost::Ghost_change_eated()
	{
		this->ea = !this->ea;
	}
void ghost::changeXY(int X, int Y)
	{
		x = X; 
		y = Y;
	}
void ghost::print(Graphics ^g)
	{
		g->DrawImage(img, x, y);
	}