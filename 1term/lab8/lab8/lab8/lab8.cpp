// lab8.cpp: определяет точку входа для консольного приложения.
//
/*
Вариант 12
Написать программу, которая считывает текст из файла и выводит на экран только предложения, начинающиеся с тире, перед которым могут находиться только пробельные символы.
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
#include <errno.h>


int main()
{
	system("CLS");
	
	FILE * fp; 
	int f = -1, d = -1, s = 0;
	char c, a = NULL;
	char fname[20];	
	puts("Enter file name: \n");
	gets(fname);
	if((fp = fopen(fname, "r")) == NULL)
	{
		perror(fname);
		return 1;
	}
	while((c = getc(fp)) != EOF)
	{
		if((a == 32) && (c == '-'))
		{	
			f = 0;
			d = 0;
			s = 1;
			continue;
		}
		if(c == '.') 
		{
			f = -1; 
			d = -1;
			if(s)
			{
				puts("\n");
				s = 0;
			}
		}

		if(!(f+d))
			putch(c);
		a = c; 
	}
	putchar(c);
	fclose(fp);
	getch();
	return 0;
}

