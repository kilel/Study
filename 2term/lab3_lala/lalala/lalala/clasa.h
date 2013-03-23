#pragma once
using namespace System::Drawing;

enum type{blinky, pinky, inky, clyde};
ref class ghost
{
	type t;
	int sp;
	bool ea;
	int x, y;
	Bitmap^ img;
public:
	~ghost();
	ghost();
	ghost(type tt);
	ghost(type tt, int speed, char eated);
	ghost(ghost %g);
	void Ghost_change_speed(int speed);
	void Ghost_change_type(type tt);
	void Ghost_change_eated();
	void changeXY(int X, int Y);
	void print(Graphics ^g);
};
