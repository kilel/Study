// goolel.cpp: ������� ���� �������.

#include "stdafx.h"
#include "main_form.h"

using namespace goolel;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew main_form());
	return 0;
}
