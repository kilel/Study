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


struct car
{
	char year[9];
	char cost[10];
	char name[20];
	char color[20];
	car *next;
};

void sort_and_output(car **beg);
void add(FILE *fp, car **end)
{
	int i = 0;
	char now;
	car *p = (car*)calloc (1, sizeof(car));
	(*end)->next = p;
	p->next = 0;
	*end = p;
	while((now = getc(fp)) != 10)
		1;
	while((now = getc(fp)) != 10)
	{
		p->name[i] = now;
		i++;
	}
	p->name[i] = '\0';
	i = 0;
	while((now = getc(fp)) != 10)
	{
		p->year[i] = now;
		i++;
	}
	p->year[i] = '\0';
	i = 0;
	while((now = getc(fp)) != 10)
	{
		p->color[i] = now;
		i++;
	}
	p->color[i] = '\0';
	i = 0;
	while((now = getc(fp)) != 10)
	{
		p->cost[i] = now;
		i++;
	}
	p->cost[i] = '\0';
}

void sort_and_output(car **beg)
{
	
	car *p = (*beg)->next, *pv = *beg, *prev = *beg;
	int max = 0, tyear = 0;
	while(p != 0)
	{
		if(atoi(p->year) > max)
		{
			max = atoi(p->year);
			prev = pv;
			pv = p;
		}
		p = p->next;
	}
	if(pv->next == 0)
		prev->next = 0;
	else
		prev->next = pv->next;
	pv->next = (*beg)->next;
	(*beg)->next = pv;
	system("CLS");
	printf("\t\tCar\n \tModel name: %s\n\t Avalible color: \n%s\n\tCost:\n%s\
		   \n\tYear of realise:\n%s\
		   \nPress any key to look at next car...\n", pv->name, pv->color, pv->cost, pv->year);
	getch();
 	if(pv->next != 0)
		sort_and_output(&pv);
}

void clean(car **beg)
{
	car *p = *beg, *pv = (*beg)->next;
	while(pv->next != 0)
	{
		free(p);
		p = pv;
		pv = pv->next;
	}
	free(p);
	free(pv);
	return;
}
int main()
{
	car *beg, *end;
	beg = (car*)calloc(1, sizeof(car));
	beg->next = 0;
	end = beg;
	system("CLS");
	FILE *fp; 
	int f = 1, f2 = 1, read = 1;
	char prev = NULL, now, prev2 = NULL;

	char fname[20];	
	puts("Enter file name: \n");
	gets(fname);
	
	if((fp = fopen(fname, "r")) == NULL)
	{
		perror(fname);
		return 1;
	}
	while((now = getc(fp)) != EOF)
	{
		if((now == '/') && (prev == '/'))
		{
			read = 0;
			continue;
		}
		if(now == 10)
		{
			read = 1;
			continue;
		}
		if((((now == 'r') && (prev == 'a')) && (prev2 == 'c'))&& read)
			add(fp, &end);
		prev2 = prev;
		prev = now;
	}
	fclose(fp);

	sort_and_output(&beg);
	
	clean(&beg);
	return 0;
}
