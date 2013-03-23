// lab2 EVM.cpp: определяет точку входа для консольного приложения.
//

#include <stdafx.h>
#include <stdio.h> 
#include <conio.h> 
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Russian");
	float Xn, Xk, dX, x, a, b, c, F;
	int Ac, Bc, Cc;
	printf("Введите Xn, Xk, dX\n"); //Ввод начального, конечного и изменения Х
	scanf_s("%f%f%f", &Xn, &Xk, &dX);
	printf("Введите a, b, c\n"); //Ввод чисел a, b, c
	scanf_s("%f%f%f", &a, &b, &c);
    Ac = (int) a;					// выделяем целую часть чисел а, b, c
	Bc = (int) b;
    Cc = (int) c;
	F = 0;							//обнуляем F
	x = Xn;
	printf("Для a=%0.3f, b=%0.3f, c=%0.3f:", a, b, c,'\n');
	do
	{
		if ((x < 0.6) && (b+c != 0))			//первое условие
			F = a*x*x*x + b*b + c; 
		else if ((x > 0.6) && (b+c == 0))		//иначе
			F = (x - a)/(x - c);
		else									//иначе
			F = x/c + x/a;
		
		if (((Ac | Bc) & Cc) == 0)
			
				printf("\nЗначение F равно %d при x равном %0.3f", (int) F, x);	//вывод целой части F при выполн. усл-я

		else	printf("\nЗначение F равно %0.3f при x равном %0.3f", F, x);			//иначе - вывод полного значения F

		x = x + dX;								//увеличение х на dX


	}
	while (x <= Xk);

	printf("\nPress any key to exit...");
	_getch( );

	return 0;
}

