// lab4_EVM.cpp: определяет точку входа для консольного приложения.
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
#include <locale.h>
#include <string.h>
#define rnd (rand()/32768.0)	
int main()
{	setlocale(LC_ALL, "Russian");
	int n, m, istr, istb, k, f;
	const int i = 80, j = 80;
	char str[80];
	double mat[i][j];
	printf("Введите размеры матрицы\n");
	scanf("%d%d", &n, &m);
	printf("Хотите ввести матрицу вручную или заполнить случайными элементами в интервале (-k,k)?\n");
	do
	{
		scanf("%S", &str);
		if (((!strcmp(str, "Ввести вручную")) ||(!strcmp(str, "ввести вручную"))) || ((!strcmp(str, "Ddtcnb dhexye.")) || (!strcmp(str, "ddtcnb dhexye."))))
		{
			f = 0;
			printf("Вводите элементы слева направо сверху вниз\n");
			for (istr = 0; istr < n; istr++)
			{
				for (istb = 0; istb < m; istb++)
					scanf("%lf", &mat[istr][istb]);
			}
		}
		else if (((!strcmp(str, "Заполнить случайно")) ||(!strcmp(str, "заполнить случайно"))) || ((!strcmp(str, "Pfgjkybnm ckexfqyj")) || (!strcmp(str, "pfgjkybnm ckexfqyj"))))
		{
			f = 0;
			printf("Введите радиус интервала (k)\n");
			scanf("%d", &k);	
			for (istr = 0; istr < n; istr++)
			{
				for (istb = 0; istb < m; istb++)
					mat[istr][istb] = rnd*2*k - k;
			}

		}
		else 
		{
			f = 1;
			printf("Вы ввели что-то не то. Введите \"ввести вручную\" или \"заполнить случайно\"\n");
		}
	}
	while (f);
	/*  {	int i, j, n, m, a[50][50];
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
		getch();
	}
