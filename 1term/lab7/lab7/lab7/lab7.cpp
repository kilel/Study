// lab7.cpp: определяет точку входа для консольного приложения.
//
/*
Вариант 15
Составить программу, которая содержит текущую информацию о заявках на авиабилеты.
Каждая заявка включает:
•	пункт назначения;
•	номер рейса;
•	фамилию и инициалы пассажира;
•	желаемую дату вылета.
Программа должна обеспечивать:
•	хранение всех заявок в виде двоичного дерева;
•	добавление и удаление заявок;
•	по заданному номеру рейса и дате вылета вывод заявок с их последующим удалением;
•	вывод всех заявок.
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

struct avia
{
	unsigned int tripn;
	char wayto[20];
	char fio[30];
	int date[3];
	avia* left;
	avia* right;
	avia* parent;
};

avia* first();
void add(avia **core);
void del(avia **core, int& f);
avia* search(avia **core);
void vivod(avia **core, int& f);
void vivodall(avia **core, int& f);

int main()
{	
	system("CLS");
	setlocale(LC_ALL, "Russian");
	avia *core;
	char vibor;
	int f = 1;
	system("CLS");
	printf("\t\tВас приветствует программа занесения заявок на авиабилеты!\n\nДля продолжения нажмите любую клавишу");
	getch();
	while(true)
	{
		system("CLS");
		vibor = NULL;
		printf("\t\tМеню:\n\n\t1)Создание новой заявки\n\n\t2)Удаление заявки\n\n\t3)Вывод заявки\n\n\t4)Вывод всех заявок\n\n\t5)Выход");
		vibor = getch();
		switch(vibor)
		{
		case '1': 
			{
				if(f)
				{
					core = first();
					f = 0;
				}
				else 
					add(&core);
			}
			break;
		case '2': 
			{
				if(f)
				{
					system("CLS");
					printf("Не создано ни одной записи!");
				}
				else
					del(&core, f);
			} break;
		case '3': {
				if(f)
				{
					system("CLS");
					printf("Не создано ни одной записи!");
				}
				else
					vivod(&core, f);
				  } break;
		case '4': {
				if(f)
				{
					system("CLS");
					printf("Не создано ни одной записи!");
				}
				else 
					vivodall(&core, f);
				  } break;
		case '5':
			{
				system("CLS");
				printf("Благодарим за использование нашей программы.\nХорошего дня!");
				getch();
				return 0;
			} 
		default: 
			{
				system("CLS");
				printf("\n\nНекорректный ввод, повторите попытку");
			}
		}
		printf("\n\nДля продолжения нажмите любую клавишу");
		getch();
	}
}
avia* first()
{
	system("CLS");
	avia *p = (avia*) calloc (1, sizeof(avia));
	p->parent = 0;
	p->left = 0;
	p->right = 0;
	printf("\t\tВведите данные для первой заявки\n\n");
	
	printf("\tВведите номер рейса\n");
	scanf_s("%d", &p->tripn);
	printf("\tВведите пункт назначения\n");
	scanf("%s", p->wayto);
	printf("\tВведите фамилию и инициалы\n");
	scanf("%s", p->fio);
	printf("\tВведите желаемую дату вылета (через пробел ввести день, месяц, год)\n");
	for(int i = 0; i < 3; i++)
		scanf_s("%d", &p->date[i]);
	return p;
}


void add(avia **core)
{
	int f = 1;
	system("CLS");
	avia *p = (avia*) calloc (1, sizeof(avia)), *pv = *core;
	printf("\t\tВведите данные для новой заявки\n\n");
	printf("\tВведите номер рейса\n");
	scanf_s("%d", &p->tripn);
	printf("\tВведите пункт назначения\n");
	scanf("%s", p->wayto);
	printf("\tВведите фамилию и инициалы\n");
	scanf("%s", p->fio);
	printf("\tВведите желаемую дату вылета(через пробел ввести день, месяц, год)\n");
	for(int i = 0; i < 3; i++)
		scanf_s("%d", &p->date[i]);
	p->left = 0;
	p->right = 0;

	while(f)
	{
		if((pv->right == 0) && (p->tripn > pv->tripn))
		{
			p->parent = pv;
			pv->right = p;
			return;
		}
		else if((pv->left == 0) && (p->tripn < pv->tripn))
		{
			p->parent = pv;
			pv->left = p;
			return;
		}
		else if((p->tripn == pv->tripn))
		{
			if (((p->date[2]*10000 + p->date[1]*100 + p->date[0]) > (pv->date[2]*10000 + pv->date[1]*100 + pv->date[0])) && (pv->right == 0))
			{
				p->parent = pv;
				pv->right = p;
				return;
			}
			else if (((p->date[2]*10000 + p->date[1]*100 + p->date[0]) < (pv->date[2]*10000 + pv->date[1]*100 + pv->date[0])) && (pv->left == 0))
				{
					p->parent = pv;
					pv->left = p;
					return;
				}
			else 
			{
				system("CLS");
				printf("\n\tТакая заявка уже есть. \nНажмите любую клавишу для продолжения");
				getch();
				return;
			}
		}
		else if(p->tripn < pv->tripn)
		{
			pv = pv->left;
		}
		else if(p->tripn > pv->tripn)
		{
			pv = pv->right;
		}
		else if((p->date[2]*10000 + p->date[1]*100 + p->date[0]) > (pv->date[2]*10000 + pv->date[1]*100 + pv->date[0]))
		{
			pv = pv->right;
		}
		else if((p->date[2]*10000 + p->date[1]*100 + p->date[0]) < (pv->date[2]*10000 + pv->date[1]*100 + pv->date[0]))
		{
			pv = pv->left;
		}
		else
		{
			printf("Ошибка добавления записи \nНажмите любую клавишу для продолжения");
			getch();
			return;
		}
	}
}
void del(avia **core, int& f)
{
	avia *p = search(core),
		*pv;
	if(p == NULL)
	{
		return;
	}
	if(((p->left != 0)&&(p->right != 0)) && (p->parent != 0))
	{
		pv = p->left;
		while(pv->right != 0)
			pv = pv->right;
		pv->right = p->right;
		(p->right)->parent = pv;
		if((p->parent)->left == p)
			(p->parent)->left = p->left;
		else
			(p->parent)->right = p->left;
		p->left = p->parent;
		free(p);
		printf("\n\t\tЗаявка была успешно удалена!\n");
		return;
	}
	else if(((p->left == 0) && (p->parent != 0)) && (p->right != 0))
	{
		(p->right)->parent = p->parent;
		if((p->parent)->left == p)
			(p->parent)->left = p->right;
		else
			(p->parent)->right = p->right;
		free(p);
		printf("\n\t\tЗаявка была успешно удалена!\n");
		return;
	}
	else if(((p->right == 0) && (p->parent != 0)) && (p->left != 0))
	{
		(p->left)->parent = p->parent;
		if((p->parent)->left == p)
			(p->parent)->left = p->left;
		else
			(p->parent)->right = p->left;
		free(p);
		printf("\n\t\tЗаявка была успешно удалена!\n");
		return;
	}
	else if(((p->left == 0) && (p->right == 0)) && (p->parent != 0))
	{
		if((p->parent)->left == p)
			(p->parent)->left = 0;
		else
			(p->parent)->right = 0;
		printf("\n\t\tЗаявка была успешно удалена!\n");
		free(p);
		return;
	}
	else if(p->parent == 0)
	{
		if((p->left == 0) && (p->right == 0))
		{
			free(p);
			f++;
			printf("\n\t\tЗаявка была успешно удалена!\n");
		}
		else if((p->left == 0) && (p->right != 0))
		{
			(*core) = p->right;
			(*core)->parent = 0;
			free(p);
			printf("\n\t\tЗаявка была успешно удалена!\n");
			return;
		}
		else if ((p->right == 0) && (p->left != 0))
		{
			(*core) = p->left;
			(*core)->parent = 0;
			free(p);
			printf("\n\t\tЗаявка была успешно удалена!\n");
			return;
		}
		else
		{
			pv = p->left;
			while(pv->right != 0)
				pv = pv->right;
			pv->right = p->right;
			(p->right)->parent = pv;
			(*core) = p->left;
			(*core)->parent = 0;
			free(p);
			printf("\n\t\tЗаявка была успешно удалена!\n");
			return;
		}
	}
	else
	{
		printf("\n\t\tЗаявка не найдена!\n");
	}
}
avia* search(avia **core)
{
	system("CLS");
	avia *p = (avia*) calloc (1, sizeof(avia)),
		*pv = *core;
	
	printf("\tВведите номер рейса\n");
	scanf("%d", &p->tripn);
	printf("\tВведите дату вылета\n");
	for(int i = 0; i < 3; i++)
		scanf("%d", &p->date[i]);
	while(true)
	{
		if((p->tripn == pv->tripn) && ((p->date[2]*10000 + p->date[1]*100 + p->date[0]) == (pv->date[2]*10000 + pv->date[1]*100 + pv->date[0])))
		{
			return pv; 
		}
		else if((p->tripn > pv->tripn) && (pv->right != 0))
		{
			pv = pv->right;
		}
		else if((p->tripn < pv->tripn) && (pv->left != 0))
		{
			pv = pv->left;
		}
		else if(p->tripn == pv->tripn)
		{
			if(((p->date[2]*10000 + p->date[1]*100 + p->date[0]) > (pv->date[2]*10000 + pv->date[1]*100 + pv->date[0])) && (pv->right != 0))
			{
				pv = pv->right;
			}
			else if(((p->date[2]*10000 + p->date[1]*100 + p->date[0]) < (pv->date[2]*10000 + pv->date[1]*100 + pv->date[0])) && (pv->left != 0))
			{
				pv = pv->left;
			}
			else
			{
				system("CLS");
				printf("Ошибка поиска записи. Проверьте входные данные. \n");
				return NULL;
			}
		}
		else
		{
			system("CLS");
			printf("Ошибка поиска записи. Запись не найдена \n");
			return NULL;
		}
	}
}
void vivod(avia **core, int& f)
{
	system("CLS");
	avia *p = search(core),
		*pv;
	if(p == NULL)
	{
		return;
	}
	system("CLS");
	printf("\t\tНайдена следующая заявка:\n\n");
	printf("\tФамилия И. О.:\n%s\n\tПуть назначения:\n\t%s\n\tРейс:\n%d\n\tДата вылета:\n%d.%d.%d.", p->fio, p->wayto, p->tripn, p->date[0], p->date[1], p->date[2]);
	
	if(((p->left != 0)&&(p->right != 0)) && (p->parent != 0))
	{
		pv = p->left;
		while(pv->right != 0)
			pv = pv->right;
		pv->right = p->right;
		(p->right)->parent = pv;
		if((p->parent)->left == p)
			(p->parent)->left = p->left;
		else
			(p->parent)->right = p->left;
		p->left = p->parent;
		free(p);
		return;
	}
	else if(((p->left == 0) && (p->parent != 0)) && (p->right != 0))
	{
		(p->right)->parent = p->parent;
		if((p->parent)->left == p)
			(p->parent)->left = p->right;
		else
			(p->parent)->right = p->right;
		free(p);
		return;
	}
	else if(((p->right == 0) && (p->parent != 0)) &&(p->left != 0))
	{
		(p->left)->parent = p->parent;
		if((p->parent)->left == p)
			(p->parent)->left = p->left;
		else
			(p->parent)->right = p->left;
		free(p);
		return;
	}
	else if(((p->left == 0) && (p->right == 0)) && (p->parent != 0))
	{
		if((p->parent)->left == p)
			(p->parent)->left = 0;
		else
			(p->parent)->right = 0;
		free(p);
		return;
	}
	else if(p->parent == 0)
	{
		if((p->left == 0) && (p->right == 0))
		{
			free(p);
			f++;
			return;
		}
		else if((p->left == 0)&& (p->right != 0))
		{
			(*core) = p->right;
			(*core)->parent = 0;
			free(p);
			return;
		}
		else if ((p->right == 0)&& (p->left != 0))
		{
			(*core) = p->left;
			(*core)->parent = 0;
			free(p);
			return;
		}
		else
		{
			pv = p->left;
			while(pv->right != 0)
				pv = pv->right;
			pv->right = p->right;
			(p->right)->parent = pv;
			(*core) = p->left;
			(*core)->parent = 0;
			free(p);
			return;
		}
	}
}
void vivodall(avia **core, int& f)
{
	system("CLS");
	avia *p = *core,
		*pv;
	while((p->left != 0) || (p->right != 0))
	{
		printf("\tФамилия И. О.:\n%s\n\tПуть назначения:\n%s\n\tРейс:\n%d\n\tДата вылета:\n%d.%d.%d.\n\nНажмите любую клавишу для просмотра следующей заявки", p->fio, p->wayto, p->tripn, p->date[0], p->date[1], p->date[2]);
		if(p->left == 0)
		{
			*core = p->right;
			(*core)->parent = 0;
			free(p);
		}
		else if (p->right == 0)
		{
			*core = p->left;
			(*core)->parent = 0;
			free(p);
		}
		else
		{
			pv = p->left;
			while(pv->right != 0)
				pv = pv->right;
			pv->right = p->right;
			(p->right)->parent = pv;
			*core = pv;
			(*core)->parent = 0;
			free(p);
		}
		p = *core;
		getch();
		system("CLS");
	}
	printf("\tФамилия И. О.:\n%s\n\tПуть назначения:\n%s\n\tРейс:\n%d\n\tДата вылета:\n%d.%d.%d.\n\nЭто была последняя запись. Для выхода в меню нажмите любую клавишу", p->fio, p->wayto, p->tripn, p->date[0], p->date[1], p->date[2]);
	free(p);
	f++;
	getch();
}