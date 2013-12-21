#pragma once
#include "level.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class pman
{
	int j, x, y, dx, dy, usenot, way, super_time;		//координаты, параметры
	Point p;											//координаты
	int **a;											//массив хлопанья ртом
	bool super_pacman_mode;								//режим сверхсилы
public:
	pman(void);
	~pman();
	bool draw(int w, level^ lev, int% points);			//вычисление координат
	int retx()
	{
		if(dx >= 7)
			return (x+1);
		else if(dx <= -7)
			return (x-1);
		else 
			return x;
	}
	int rety() 
	{
		if(dx >= 6)
			return (y+1);
		else if(dx <= -6)
			return (y-1);
		else 
			return y;
	}
	int retway() {return way;}						//возвращает путь
	void only_draw(Graphics ^g, int i);				//рисует пакмена
	void st(int i);									//отправляет в стандарт i-го уровня
	void death(Graphics ^g, int i);					//смерть
	int super(){return (--super_time);}				//уменьшает время режима суперсилы
	void super_puper_mode_off() {super_pacman_mode = false;}		//отменяет режим суперсилы
};
