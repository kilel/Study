// lab4.cpp: определяет точку входа для консольного приложения.
//
/*
Вариант 12
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
#include <malloc.h>
#include <time.h>
#define rnd (rand()/32768.0)	

int main()
{	setlocale(LC_ALL, "Russian");
	int n, m, i, j, f = 2, k, c;
	printf("Введите размеры матрицы\n");
	scanf_s("%d%d", &n, &m);
	double **mat;
	char str[5];
	mat = (double**) calloc (n, sizeof(double*));
	for (i = 0; i < n; i++)
		mat[i] = (double*) malloc (m*sizeof(double));

	//-----------------------------------------------//

	printf("Хотите ввести матрицу вручную или заполнить случайными элементами\nв интервале (-k,k)(V/S)?\n");
	while (f)
	{
		gets_s(str);
		if ((strstr(str, "V\0")) || (strstr(str, "v\0")))
		{
			f = 0;
			printf("Вводите элементы слева направо сверху вниз\n");
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
					scanf_s("%lf", &mat[i][j]);
			}
		}
		else if ((strstr(str, "s\0")) || (strstr(str, "S\0")))
		{
			f = 0;
			printf("Введите радиус интервала (k)\n");
			scanf_s("%d", &k);	
			srand( (unsigned)time( NULL ) );
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
					mat[i][j] = rnd*2*k - k;
			}

		}
		else 
		{
			if (f == 1) 
				printf("Вы ввели что-то не то. Введите \"V\" или \"S\"\n");
			if (f !=1) 
				f = 1;
		}
	}
	printf("\n \nПолучилась матрица размером %d х %d  с элементами\n", n, m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			printf("%+10.4lf ", mat[i][j]);
		}
		printf("\n");
	}
	//----------------------------
	int ind = -1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if (mat[i][j] > 0)
			{
				ind = i;
				break;
			}
		}
		if (ind >= 0)
			break;
	}
	if (ind < 0)
		printf("\nCтрок, содержащих положительные элементы, нет\n \n");
	else	
		printf("\nПервая из строк, содержащих хотя бы один положительный элемент,\nнаходится под номером  %d\n \n", ind+1);
	//---------------------------
	double pgr = 0.00001;

	for(i = 0; i < n; i++)
	{		
		f = 0;
		for(j = 0; j < m; j++)
		{
			if (fabs(mat[i][j]) < pgr)
				f++;
		}
		if (f == m)
		{
			for(c = i + 1; c < n; c++)
			{
				for(j = 0; j < m; j++)
					mat[c - 1][j] = mat[c][j];
			}
			free(mat[n-1]);
			n--;
			i--;
		}
	}
	//--------------------------

	for (j = 0; j < m; j++)
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
				for(c = j + 1; c < m; c++ )
				mat[i][c-1] = mat[i][c];
				realloc(mat[i], (m - 1)*sizeof(double));
			}
			m--;
			j--;
		}
	}
	printf("\n \nПолучилась матрица размером %d х %d  с элементами\n", n, m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			printf("%+10.4lf ", mat[i][j]);
		}
		printf("\n");
	}

	_getch();
	for (int i = 0; i < n; i++)
		free(mat[i]);
	free(mat);
	return 0;
}
