// lab4_EVM.cpp: ���������� ����� ����� ��� ����������� ����������.
//
/*
������� 12
��������� �������� �������, ������ �� ��� ������ � �������, ����������� ������. 
����� ����� ������ �� �����, ���������� ���� �� ���� ������������� �������.
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
	printf("������� ������� �������\n");
	scanf("%d%d", &n, &m);
	printf("������ ������ ������� ������� ��� ��������� ���������� ���������� � ��������� (-k,k)?\n");
	do
	{
		scanf("%S", &str);
		if (((!strcmp(str, "������ �������")) ||(!strcmp(str, "������ �������"))) || ((!strcmp(str, "Ddtcnb dhexye.")) || (!strcmp(str, "ddtcnb dhexye."))))
		{
			f = 0;
			printf("������� �������� ����� ������� ������ ����\n");
			for (istr = 0; istr < n; istr++)
			{
				for (istb = 0; istb < m; istb++)
					scanf("%lf", &mat[istr][istb]);
			}
		}
		else if (((!strcmp(str, "��������� ��������")) ||(!strcmp(str, "��������� ��������"))) || ((!strcmp(str, "Pfgjkybnm ckexfqyj")) || (!strcmp(str, "pfgjkybnm ckexfqyj"))))
		{
			f = 0;
			printf("������� ������ ��������� (k)\n");
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
			printf("�� ����� ���-�� �� ��. ������� \"������ �������\" ��� \"��������� ��������\"\n");
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
				a[i][j]=rnd*2 ;  	// �������� �� �5 �� 5
				printf("%d%c", a[i][j], (j==m-1)?'\n':'  '); 
			}
		}
		while (1);   */
		getch();
	}
