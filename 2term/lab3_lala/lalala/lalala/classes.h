#include <math.h>
#include <time.h>
#include <stdlib.h>

#define X_ST 200
#define Y_ST 200

enum type{blinky, pinky, inky, clyde};

enum mode{agro, walk, sick};

class pman
{
private:
	int sp;
	bool agro;
public:
	~pman()
	{
		sp = -1;
		agro = false;
	}
	pman()
	{
		agro = 0;
		sp = 100;
	}
	void change_speed(int speed)
	{
		if(speed/100 == 0)
			sp = speed%100;
		else 
			sp = 100;
	}
	void change_agro()
	{
		agro = !agro;
	}
};

class ghost
{
private:
	type t;
	int sp;
	mode m;
	bool ea;
public:
	~ghost()
	{
		sp = -1;
		ea = false;
		m = agro;
		t = blinky;
	}
	ghost()
	{
		t = blinky;
		sp = 80;
		m = walk;
		ea = false;
	}
	ghost(type tt)
	{
		t = tt;
		m = walk;
		sp = 80;
		ea = false;
	}
	ghost(type tt, mode mo, int speed, char eated)
	{
		t = tt;
		m = mo;
		sp = speed;
		ea = eated;
	}
	void change_mode(mode mo)
	{
		m = mo;
	}
	void change_speed(int speed)
	{
		if(speed/100 == 0)
			sp = speed%100;
		else 
			sp = 100;
	}
	void change_type(type tt)
	{
		t = tt;
	}
	void change_eated()
	{
		ea = !ea;
	}



};

class coord:public ghost, public pman
{
private:
	int x, y, to_x, to_y;
public:
	coord()
	{
		x = X_ST;
		y = Y_ST;
		to_x = 1;
		to_y = 1;
	}
	coord(int X, int Y, int to_X, int to_Y)
	{
		x = X;
		y = Y;
		to_x = to_X;
		to_y = to_Y;
	}
	void changeXY(int X, int Y)
	{
		x = X; 
		y = Y;
	}
};