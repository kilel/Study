// lab4.cpp: определяет точку входа для консольного приложения.
//
/*Вариант 12
Уплотнить заданную матрицу, удаляя из нее строки и столбцы, заполненные нулями. 
Найти номер первой из строк, содержащих хотя бы один положительный элемент.
*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#define rnd (rand()/32768.0)	

int main()
{	setlocale(LC_ALL, "Russian");
	int n, m, i, j, k, f = 2, c, fl = 1, nn, mm, ind = -1;
	const int istr = 80, jstb = 80;
	char str[80];
	double mat[istr][jstb], pgr = 0.00001;
	printf("Введите размеры матрицы\n");
	scanf_s("%d%d", &n, &m);
	nn = n;
	mm = m;
	printf("Хотите ввести матрицу вручную или заполнить случайными элементами в интервале (-k,k)(Vvesti/Sluchaino)?\n");
	while (f)
	{
		gets_s(str);
		if ((strstr(str, "Vvesti\0")) || (strstr(str, "vvesti\0")))
		{
			f = 0;
			printf("Вводите элементы слева направо сверху вниз\n");
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
					scanf_s("%lf", &mat[i][j]);
			}
		}
		else if ((strstr(str, "sluchaino\0")) || (strstr(str, "Sluchaino\0")))
		{
			f = 0;
			printf("Введите радиус интервала (k)\n");
			scanf_s("%d", &k);	
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
					mat[i][j] = rnd*2*k - k;
			}

		}
		else 
		{
			if (f == 1) 
				printf("Вы ввели что-то не то. Введите \"Vvesti\" или \"Sluchaino\"\n");
			if (f !=1) 
				f = 1;
		}
	}
	printf("В итоге получилась матрица размером %d х %d  с элементами\n", n, m);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			printf("%+0.4lf ", mat[i][j]);
		}
		printf("\n");
	}
	//------------------------------------------------------// ищем первую из строк с положительным эл-том
	for(i = 0; i < nn; i++)
	{
		for(j = 0; j < mm; j++)
		{
			if ((mat[i][j]) > 0)
			{
				ind = i;
				break;
			}
		}
		if (ind > 0)
			break;
	}
	if (ind < 0)
		printf("\nCтрок, содержащих положительные элементы, нет\n \n");
	else	
		printf("\nПервая из строк, содержащих хотя бы один положительный элемент,\nнаходится под номером  %d\n \n", ind);
	//------------------------------------------------------// Ищем 0-ую строку и удаляем

	for(i = 0; i < n; i++)
	{
		fl = 1;
		while (fl)
		{
			f = 0;
			for(j = 0; j < m; j++)
			{
				if (fabs(mat[i][j]) < pgr)
					f++;
			}
			if (f == m)
			{
				for(c = i; c < n; c++ )
				{
					for(j = 0; j < m; j++)
						mat[c][j] = mat[c + 1][j];
				}
				n--;
			}
			else 
				fl = 0;
		}
	}
	f = 0;
	fl = 1;
	//------------------------------------------------------// Ищем 0-ой столец и удаляем
	for (j = 0; j < m; j++)
	{
		fl = 1;
		while(fl)
		{
			f = 0;
			for(i = 0; i < n; i++)
			{
				if (fabs(mat[i][j]) < pgr)
					f++;
			}
			if (f == n)
				{
					for(i = 0; i < n; i++)
					{
						for(c = j; c < m; c++ )
							mat[i][c] = mat[i][c + 1];
					}
					m--;
				}
			else fl = 0;
		}

	}
	printf("\nПосле преобразований получилась матрица размером %d х %d  с элементами\n", n, m);
	for(i = 0; i < n; i++)
		{
			for(j = 0; j < m; j++)
			{
				printf("%+0.4lf ", mat[i][j]);
			}
			printf("\n");
		}
	/*for(i = 0; i < nn; i++)
	{
		for(j = 0; j < nn; j++)
		{
			if (mat[i][j] > 0)
			{
				ind = i;
				break;
			}
		}
		if (ind > 0)
			break;
	}
	if (ind < 0)
		printf("\nCтрок, содержащих положительные элементы, нет");
	else	
		printf("\nНомер первой из строк, содержащих хотя бы один положительный элемент, - %d", ind);

	  {	int i, j, n, m, a[50][50];
		puts("\n Input n, m:");
		scanf("%d %d", &n, &m);
		do
		{	clearerr;
			printf("\n Array a \n");
			for(i=0; i<n; i++) 
				for(j=0; j<m; j++) 
			{
				a[i][j]=rnd*2 ;  	// диапазон от –5 до 5
				printf("%d%c", a[i][j], (j==m-1)?'\n':'  '); 
			}
		}
		while (1);   */
		_getch();
	}
