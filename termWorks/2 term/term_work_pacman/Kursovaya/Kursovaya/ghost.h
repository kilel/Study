#pragma once
#include "pman.h"
ref class ghost
{
	int way,nextway, x, y, dx, dy, type, icon, hx1, hx2, hy1, hy2, fhcx, fhcy;  //����, ��������� ����, ����������, ���, ��� �������
	SolidBrush^ br;								//�����, ������� �������� �������
	bool sick_mode, eated;						//����� ��������, ����� �����������
public:
	ghost(int t);
	~ghost();
	bool draw(level^ lev, pman^ pacman, ghost ^binky, int %points, bool god); // ������� ���������� ���������
	void change_icon() {icon = (icon+1)%2;}							//����� ���� �������
	int retx()														
	{
		if(dx >= 4)
			return (x+1);
		else if(dx <= -4)
			return (x-1);
		else 
			return x;
	}																//���������� x
	int rety() 
	{
		if(dx >= 3)
			return (y+1);
		else if(dx <= -3)
			return (y-1);
		else 
			return y;
	}																//���������� y
	void drawgh(Graphics ^g, int par);								//������ ��������
	void do_sick(){sick_mode = true;}								//��������
	void st(int i);													//��������� � ��� ���������� i-�� ������
	void unsick()													//������ ��������
	{
		sick_mode = false; 
		///eated = false;
	}
};
