#pragma once
#include "pman.h"
ref class ghost
{
	int way,nextway, x, y, dx, dy, type, icon, hx1, hx2, hy1, hy2, fhcx, fhcy;  //путь, следубщий путь, координаты, тип, тип рисовки
	SolidBrush^ br;								//кисть, которой рисуется призрак
	bool sick_mode, eated;						//режим слабости, режим съеденности
public:
	ghost(int t);
	~ghost();
	bool draw(level^ lev, pman^ pacman, ghost ^binky, int %points, bool god); // функция вычисления координат
	void change_icon() {icon = (icon+1)%2;}							//смена типа рисовки
	int retx()														
	{
		if(dx >= 4)
			return (x+1);
		else if(dx <= -4)
			return (x-1);
		else 
			return x;
	}																//возвращает x
	int rety() 
	{
		if(dx >= 3)
			return (y+1);
		else if(dx <= -3)
			return (y-1);
		else 
			return y;
	}																//возвращает y
	void drawgh(Graphics ^g, int par);								//рисует призрака
	void do_sick(){sick_mode = true;}								//ослабить
	void st(int i);													//отправить в стд координаты i-го уровня
	void unsick()													//убрать слабость
	{
		sick_mode = false; 
		///eated = false;
	}
};
