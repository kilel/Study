// lab3_EVM.cpp: ���������� ����� ����� ��� ����������� ����������.
//
/*
������� 12
� ���������� �������, ��������� �� n ������������ ���������, ���������:
1.)	����� ������������� �� ������ �������� �������;
2.)	����� ��������� �������, ������������� ����� ������� �������������� ��������.
������������� ������ ����� �������, ����� ������� ������������� ��� �������� �������, 
����� ����� ������� ����� � ��������� [a,b], � ����� � ��� ���������.
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
	int i, ind, ind2;
	const int n = 5;
	double massiv[n], max, S = 0, a, b, min;
	char c ;
	
	puts("������������! ��� ������������ ��������� ����������:\n1)������ ������������� �� ������ �������� �������;");
	puts("2)����� ��������� �������, ������������� ����� ������� �������������� ��������;");
	puts("� ��� �� ������������ �� �������������� ������� ����� �������, ����� c������ \n������������� ��� �������� �������, ����� ����� ������� ����� � ��������� [a,b],� ����� � ��� ���������.");
	puts(" \n");
	printf("�� ������ ������ ������ ������ %d (y/Y - ��, ����� - ���)?\n \n", n);
	c = getch();
	if ((c == -115) || (c == -83)) 
	{
			for (i = 0; i < n; i++)
		{
			printf("n%d = ", i+1);
			scanf("%lf", &massiv[i]);
		}
	}		
	else 
	{ 
		puts(" \n�������� n �� ������ � ������� �������");
		getch();
		return 0;
	}
	max = fabs(massiv[0]);
	for (i = 0; i < n; i++)
	{
		if (fabs(massiv[i]) > max) 
		{
			max = massiv[i];
			ind = i;
		}
	}
	printf("1)����� ������� �� ������ ������� ��������� ��� ������� %d\n \n",ind + 1);
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
	printf("2)����� ��������� �������, ������������� ����� ������� �������������� �������� ���������� %0.5lf\n \n",S);
	printf("������� ����� a � b\n");
	scanf("%lf%lf", &a, &b);
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
	
	ind2 = 0;
	for (i = 0; i < n; i++)
	{
		if (((int)massiv[i] < max) && ((int)massiv[i] > min)) 
		{
			a = massiv[ind2];
			massiv[ind2] = massiv[i];
			massiv[i] = a;
			ind2++;
		}
	}
	printf("������� ��������� ����� ��������� ���� �����:\n \n");
	for (i = 0; i < n; i++)
	{
		
		printf("n%d = %0.5lf", i, massiv[i]);
	}
	
	getch();
	return 0;
}

