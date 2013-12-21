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
	int j, x, y, dx, dy, usenot, way, super_time;		//����������, ���������
	Point p;											//����������
	int **a;											//������ �������� ����
	bool super_pacman_mode;								//����� ���������
public:
	pman(void);
	~pman();
	bool draw(int w, level^ lev, int% points);			//���������� ���������
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
	int retway() {return way;}						//���������� ����
	void only_draw(Graphics ^g, int i);				//������ �������
	void st(int i);									//���������� � �������� i-�� ������
	void death(Graphics ^g, int i);					//������
	int super(){return (--super_time);}				//��������� ����� ������ ���������
	void super_puper_mode_off() {super_pacman_mode = false;}		//�������� ����� ���������
};
