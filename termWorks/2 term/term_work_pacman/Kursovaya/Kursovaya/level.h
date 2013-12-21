#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class level
{
	int levnum;
	array <String^>^c;
	int **sub;
public:
	level();
	~level();
	int retc(int i, int j) 
	{
		if(j <= -1)
			j = 0;
		if(j >= 28)
			j = 27;
		return (c[i][j] - sub[i][j]);
	}
	void changec(int i, int j) {sub[i][j]++;}
	void tost();
	void next();
	int retln() {return levnum;}
};
