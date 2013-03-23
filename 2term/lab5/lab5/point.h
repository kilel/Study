#pragma once
#define eps 1e-8

/*
Создать класс Point для работы с точками на плоскости. Координаты точки — декартовы.
Обязательно должны быть реализованы: 
+перемещение точки по оси X,
+перемещение по оси У, 
+определение расстояния до начала координат,
-расстояния между двумя точками, 
+преобразование в полярные координаты,
сравнение на совпадение и несовпадение.
*/

class point
{
	int x, y, p;
	double px, py;
public:
	point(int i, int j);
	double getx()
	{
		if(!p)
			return x;
		else return px;
	}
	int gety() 
	{
		if(!p)
			return y;
		else return py;
	}
	void changex(int k) {x = k;}
	void changey(int k) {y = k;}
	void changex(double k) {px = k;}
	void changey(double k) {py = k;}
	friend void operator +=(point %T, point %T2);
	friend double operator &(point %T);
	friend bool operator ==(point %T, point %T2);
	friend double operator /(point %T, point %T2);
	friend point% operator -(point %T);
};
