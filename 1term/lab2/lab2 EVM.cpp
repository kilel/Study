// lab2 EVM.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <stdafx.h>
#include <stdio.h> 
#include <conio.h> 
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Russian");
	float Xn, Xk, dX, x, a, b, c, F;
	int Ac, Bc, Cc;
	printf("������� Xn, Xk, dX\n"); //���� ����������, ��������� � ��������� �
	scanf_s("%f%f%f", &Xn, &Xk, &dX);
	printf("������� a, b, c\n"); //���� ����� a, b, c
	scanf_s("%f%f%f", &a, &b, &c);
    Ac = (int) a;					// �������� ����� ����� ����� �, b, c
	Bc = (int) b;
    Cc = (int) c;
	F = 0;							//�������� F
	x = Xn;
	printf("��� a=%0.3f, b=%0.3f, c=%0.3f:", a, b, c,'\n');
	do
	{
		if ((x < 0.6) && (b+c != 0))			//������ �������
			F = a*x*x*x + b*b + c; 
		else if ((x > 0.6) && (b+c == 0))		//�����
			F = (x - a)/(x - c);
		else									//�����
			F = x/c + x/a;
		
		if (((Ac | Bc) & Cc) == 0)
			
				printf("\n�������� F ����� %d ��� x ������ %0.3f", (int) F, x);	//����� ����� ����� F ��� ������. ���-�

		else	printf("\n�������� F ����� %0.3f ��� x ������ %0.3f", F, x);			//����� - ����� ������� �������� F

		x = x + dX;								//���������� � �� dX


	}
	while (x <= Xk);

	printf("\nPress any key to exit...");
	_getch( );

	return 0;
}

