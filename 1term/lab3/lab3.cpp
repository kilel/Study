// lab3_EVM.cpp: определяет точку входа для консольного приложения.
//
/*
Вариант 12
В одномерном массиве, состоящем из n вещественных элементов, вычислить:
1.)	номер максимального по модулю элемента массива;
2.)	сумму элементов массива, расположенных после первого положительного элемента.
Преобразовать массив таким образом, чтобы сначала располагались все элементы массива, 
целая часть которых лежит в интервале [a,b], а потом – все остальные.
*/

#include <stdafx.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <string.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	int i, ind, ind2, n, c;
	const int j = 50;
	double massiv[j], max, S = 0, a, b, min;
		
	puts("Здравствуйте! Вас приветствует программа вычисления:\n1)номера максимального по модулю элемента массива;");
	puts("2)суммы элементов массива, расположенных после первого положительного элемента;");
	puts("а так же направленная на преобразование массива таким образом, чтобы cначала \n\
		 располагались все элементы массива, целая часть которых лежит в интервале [a,b],а потом – все остальные.");
	printf("\nВведите длину массива (не более %d)\n", j);
	scanf_s("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("n%d = ", i + 1);
		scanf_s("%lf", &massiv[i]);
	}
	
	max = fabs(massiv[0]);
	ind = 0;
	for (i = 0; i < n; i++)
	{
		if (fabs(massiv[i]) > max) 
		{
			max = fabs(massiv[i]);
			ind = i;
		}
	}
	printf("1)Самый большой по модулю элемент находится под номером %d\n \n",ind + 1);
	for (i = 0; i < n; i++)
	{
		if (massiv[i] > 0)
		{
			ind2 = i;
			break;
		}
	}
	for (i = ind2 + 1; i < n; i++)
		S +=massiv[i];
	printf("2)Сумма элементов массива, расположенных после первого положительного элемента составляет %0.5lf\n \n",S);
	printf("Введите числа a и b\n");
	scanf_s("%lf%lf", &a, &b);
	if (a > b) 
	{
		max = a;
		min = b;
	}
	else 
	{
		min = a;
		max = b;
	}
	
	ind = 0;
	for (i = 0; i < n; i++)
	{
		if (((int)massiv[i] < max) && ((int)massiv[i] > min)) 
		{ 
			b = massiv[i];
			/*for(c = i; c < ind + 1; c--);
			{
				b = massiv[ind2];
				massiv[ind2] = massiv[ind2 - 1];
				massiv[ind2 - 1] = b;
				ind2 = ind2 - 1;
			}
			ind++;*/
			/*while(ind2 != ind)
			{
				b = massiv[ind2];
				massiv[ind2] = massiv[ind2 - 1];
				massiv[ind2 - 1] = b;
				ind2 = ind2 - 1;
			}*/
			for (c = i; c > ind; c--)
			{
				massiv[c] = massiv[c - 1];
			}
			massiv[ind] = b;
			ind++;
		}
	}
	printf("Порядок элементов после изменения стал таким:\n \n");
	for (i = 0; i < n; i++)
	{
		
		printf("n%d = %0.5lf\n", i, massiv[i]);
	}
	
	_getch();
	return 0;
}