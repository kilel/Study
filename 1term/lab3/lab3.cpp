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
	int i, ind, ind2, n, c;
	const int j = 50;
	double massiv[j], max, S = 0, a, b, min;
		
	puts("������������! ��� ������������ ��������� ����������:\n1)������ ������������� �� ������ �������� �������;");
	puts("2)����� ��������� �������, ������������� ����� ������� �������������� ��������;");
	puts("� ��� �� ������������ �� �������������� ������� ����� �������, ����� c������ \n\
		 ������������� ��� �������� �������, ����� ����� ������� ����� � ��������� [a,b],� ����� � ��� ���������.");
	printf("\n������� ����� ������� (�� ����� %d)\n", j);
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
	printf("������� ��������� ����� ��������� ���� �����:\n \n");
	for (i = 0; i < n; i++)
	{
		
		printf("n%d = %0.5lf\n", i, massiv[i]);
	}
	
	_getch();
	return 0;
}