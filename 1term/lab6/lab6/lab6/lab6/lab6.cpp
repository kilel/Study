// lab6.cpp: определ€ет точку входа дл€ консольного приложени€.
//

// lab4.cpp: определ€ет точку входа дл€ консольного приложени€.
//
/*
¬ариант 12
1.)	ќписать структуру с именем NOTE, содержащую следующие пол€:
Х	фамили€, им€;
Х	номер телефона;
Х	день рождени€ (массив из трех чисел).
2.)	Ќаписать программу, выполн€ющую следующие действи€:
Х	ввод с клавиатуры данных в массив, состо€щий из восьми элементов типа NOTE, 
	записи должны быть упор€дочены по датам дней рождени€;
Х	вывод на дисплей информации о человеке, номер телефона которого введен с клавиатуры;
Х	если такого нет, выдать на дисплей соответствующее сообщение

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
#include <windows.h>
#define rnd (rand()/32768.0)
#define N 8


int main()
{	
	system("CLS");
	setlocale(LC_ALL, "Russian");
	struct NOTE
	{
		char sur[30];
		char name[20];
		unsigned long int telno;
		unsigned int dr[3];
	}stry[N], n;
	int i, j, k = 0, f = 0, z, y = 0, p, v;
	for(i = 0; i < N; i++)
	{
		system("CLS");
		printf("¬ведите данные дл€ структуры є %d\n\n", i + 1);
		printf("\t¬ведите фамилию\n");
		scanf("%s", &stry[i].sur);
		printf("\t¬ведите им€\n");
		scanf("%s", &stry[i].name);							//ввод структуры
		printf("\t¬ведите номер телефона\n");
		scanf("%d", &stry[i].telno);
		printf("\t¬ведите дату рождени€:\n");
		printf("\t\t¬ведите день рождени€:\n");
		scanf_s("%d", &stry[i].dr[0]);
		printf("\t\t¬ведите мес€ц рождени€:\n");
		scanf_s("%d", &stry[i].dr[1]);
		printf("\t\t¬ведите год рождени€:\n");
		scanf_s("%d", &stry[i].dr[2]);
	}
	system("CLS");
	for(i = 0; i < N; i++)
		for(j = i + 1; j < N; j++)
		{
			if(stry[i].dr[2]*10000 + stry[i].dr[1]*100 + stry[i].dr[0] > stry[j].dr[2]*10000 + stry[j].dr[1]*100 + stry[j].dr[0])
				{
					n = stry[i];
					stry[i] = stry[j];
					stry[j] = n;
				}
		}

							//ввод и поиск по номеру телефона
	system("CLS");
	printf("\t\tѕоиск данных по номеру телефона\n\t¬ведите номер телефона\n");
	scanf("%d", &z);
	f = 0;
	for(i = 0; i < N; i++)
	{
		f++;
		if (stry[i].telno == z)
		{
			printf("\t\t»м€:\n%s\n", stry[i].name);
			printf("\t\t‘амили€:\n%s\n", stry[i].sur);
			printf("\t\tƒата рождени€:\n%d.%d.%d\n", stry[i].dr[0], stry[i].dr[1], stry[i].dr[2]);
			f--;

		}
	}
	if(f == N)
	{
		system("CLS");
		printf("ќшибка, данных с таким номером телефона не найдено");
	}
	_getch();
	return 0;
}
