// lab6.cpp: ���������� ����� ����� ��� ����������� ����������.
//

// lab4.cpp: ���������� ����� ����� ��� ����������� ����������.
//
/*
������� 12
1.)	������� ��������� � ������ NOTE, ���������� ��������� ����:
�	�������, ���;
�	����� ��������;
�	���� �������� (������ �� ���� �����).
2.)	�������� ���������, ����������� ��������� ��������:
�	���� � ���������� ������ � ������, ��������� �� ������ ��������� ���� NOTE, 
	������ ������ ���� ����������� �� ����� ���� ��������;
�	����� �� ������� ���������� � ��������, ����� �������� �������� ������ � ����������;
�	���� ������ ���, ������ �� ������� ��������������� ���������

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
		printf("������� ������ ��� ��������� � %d\n\n", i + 1);
		printf("\t������� �������\n");
		scanf("%s", &stry[i].sur);
		printf("\t������� ���\n");
		scanf("%s", &stry[i].name);							//���� ���������
		printf("\t������� ����� ��������\n");
		scanf("%d", &stry[i].telno);
		printf("\t������� ���� ��������:\n");
		printf("\t\t������� ���� ��������:\n");
		scanf_s("%d", &stry[i].dr[0]);
		printf("\t\t������� ����� ��������:\n");
		scanf_s("%d", &stry[i].dr[1]);
		printf("\t\t������� ��� ��������:\n");
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

							//���� � ����� �� ������ ��������
	system("CLS");
	printf("\t\t����� ������ �� ������ ��������\n\t������� ����� ��������\n");
	scanf("%d", &z);
	f = 0;
	for(i = 0; i < N; i++)
	{
		f++;
		if (stry[i].telno == z)
		{
			printf("\t\t���:\n%s\n", stry[i].name);
			printf("\t\t�������:\n%s\n", stry[i].sur);
			printf("\t\t���� ��������:\n%d.%d.%d\n", stry[i].dr[0], stry[i].dr[1], stry[i].dr[2]);
			f--;

		}
	}
	if(f == N)
	{
		system("CLS");
		printf("������, ������ � ����� ������� �������� �� �������");
	}
	_getch();
	return 0;
}
