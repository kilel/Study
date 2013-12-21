#pragma once

#include <math.h>
#define pi 3.14159265358979323
#define k pi/4
#define deg pi/180

namespace ghost {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 200;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlText;
			this->ClientSize = System::Drawing::Size(873, 817);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		Graphics^ g;
		array <Point> ^p, ^t;
		int i;
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	/*
	array <Point> ^p, ^t;
	p = gcnew array <Point>(72);
	t = gcnew array <Point>(6);
	Graphics^ g;
	g = CreateGraphics();
	double fi = 0;
	int i;
	for(fi = 0, i = 0; fi < 7*pi + pi/10; i++, fi += pi/10)
	{
		p[i].X = fi*10;
		p[i].Y = (20 + 4*sin(sin(sin(fi))))*10;
	}
	p[71] = Point(100, 100);
	t[0] = p[0];
	t[3] = Point(180, 40);
	t[2] = Point(100, 0);
	t[1] = Point(20, 40);
	t[4] = p[70];
	t[5] = Point(100, 120);
	for(i = 0; i < 72; i++)
	{
		p[i].X = 300 + (p[i].X);
		p[i].Y = 300 + (p[i].Y);
	}
	for(i = 0; i < 6; i++)
	{
		t[i].X = 300 + (t[i].X);
		t[i].Y = 300 + (t[i].Y);
	}
	g->FillPolygon(Brushes::Red, p);
	g->FillClosedCurve(Brushes::Red, t);
	g->FillEllipse(Brushes::White, 60 - 20 + 300, 60 - 20 + 300, 40, 40);
	g->FillEllipse(Brushes::White, 200 -60 - 20 + 300, 60 - 20 + 300, 40, 40);

	*/
	/*array <Point> ^p, ^t;
	p = gcnew array <Point>(72);
	t = gcnew array <Point>(6);
	g = CreateGraphics();
	double fi = 0;
	for(fi = 0, i = 0; fi < 7*pi + pi/10; i++, fi += pi/10)
	{
		p[i].X = fi*10;
		p[i].Y = (20 + 4*cos(cos(sin(fi))))*10;
	}
	p[71] = Point(100, 100);
	t[0] = p[0];
	t[3] = Point(180, 40);
	t[2] = Point(100, 0);
	t[1] = Point(20, 40);
	t[4] = p[70];
	t[5] = Point(100, 120);
	for(i = 0; i < 72; i++)
	{
		p[i].X = 300 + (p[i].X)/10;
		p[i].Y = 300 + (p[i].Y)/10;
	}
	for(i = 0; i < 6; i++)
	{
		t[i].X = 300 + (t[i].X)/10;
		t[i].Y = 300 + (t[i].Y)/10;
	}
	g->FillPolygon(Brushes::Red, p);
	g->FillClosedCurve(Brushes::Red, t);
	g->FillEllipse(Brushes::White, (60 - 20)/10 + 300, (60 - 20 )/10+ 300, 4, 4);
	g->FillEllipse(Brushes::White, (200 -60 - 20 )/10 + 300, (60 - 20 )/10+ 300, 4, 4);
	delete p;
	delete t;*/
	i = 1;
	timer1->Start();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	if(i == 1)
	{
		Form1::Refresh();
		array <Point> ^p, ^t;
		p = gcnew array <Point>(72);
		t = gcnew array <Point>(6);
		g = CreateGraphics();
		double fi = 0;
		for(fi = 0, i = 0; fi < 7*pi + pi/10; i++, fi += pi/10)
		{
			p[i].X = fi*10;
			p[i].Y = (20 + 4*cos(cos((fi))))*10;
		}
		p[71] = Point(100, 100);
		t[0] = p[0];
		t[3] = Point(180, 40);
		t[2] = Point(100, 0);
		t[1] = Point(20, 40);
		t[4] = p[70];
		t[5] = Point(100, 120);
		for(i = 0; i < 72; i++)
		{
			p[i].X = 256 + (p[i].X)/10;
			p[i].Y = 256 + (p[i].Y)/10;
		}
		for(i = 0; i < 6; i++)
		{
			t[i].X = 256 + (t[i].X)/10;
			t[i].Y = 256 + (t[i].Y)/10;
		}
		g->FillPolygon(Brushes::Red, p);
		g->FillClosedCurve(Brushes::Red, t);
		g->FillEllipse(Brushes::White, (60 - 30)/10 + 256, (80 - 30 )/10+ 256, 5, 5);
		g->FillEllipse(Brushes::White, (200 - 60 - 30 )/10 + 256, (80 - 30 )/10+ 256, 5, 5);
		g->FillEllipse(Brushes::Blue, 6-1 + 256, 8-2 + 256, 3, 3);
			g->FillEllipse(Brushes::Blue, 20-6-1 + 256, 8-2 + 256, 3, 3);
		/*
		g->FillEllipse(Brushes::White, (60 - 20)/10 + 300, (60 - 20 )/10+ 300, 4, 4);
		g->FillEllipse(Brushes::White, (200 -60 - 20 )/10 + 300, (60 - 20 )/10+ 300, 4, 4);
		*/
		delete p;
		delete t;
		i = 2;
	}
	else
	{
		Form1::Refresh();
		array <Point> ^p, ^t;
		p = gcnew array <Point>(72);
		t = gcnew array <Point>(6);
		g = CreateGraphics();
		double fi = 0;
		for(fi = 0, i = 0; fi < 7*pi + pi/10; i++, fi += pi/10)
		{
			p[i].X = fi*10;
			p[i].Y = (20 + 4*cos(sin(fi)))*10;
		}
		p[71] = Point(100, 100);
		t[0] = p[0];
		t[3] = Point(180, 40);
		t[2] = Point(100, 0);
		t[1] = Point(20, 40);
		t[4] = p[70];
		t[5] = Point(100, 120);
		for(i = 0; i < 72; i++)
		{
			p[i].X = 256 + (p[i].X)/10;
			p[i].Y = 256 + (p[i].Y)/10;
		}
		for(i = 0; i < 6; i++)
		{
			t[i].X = 256 + (t[i].X)/10;
			t[i].Y = 256 + (t[i].Y)/10;
		}
		g->FillPolygon(Brushes::Red, p);
		g->FillClosedCurve(Brushes::Red, t);
		/*
		g->FillEllipse(Brushes::White, (60 - 30)/10 + 300, (80 - 30 )/10+ 300, 5, 5);
		g->FillEllipse(Brushes::White, (200 - 60 - 30 )/10 + 300, (80 - 30 )/10+ 300, 5, 5);
		*/
		g->FillEllipse(Brushes::White, (60 - 20)/10 + 256, (60 - 20 )/10+ 256, 4, 4);
		g->FillEllipse(Brushes::White, (200 -60 - 20 )/10 + 256, (60 - 20 )/10+ 256, 4, 4);
		g->FillEllipse(Brushes::Blue, 6-1 + 256, 8-3 + 256, 3, 3);
		g->FillEllipse(Brushes::Blue, 20-6-1 + 256, 8-3 + 256, 3, 3);
		delete p;
		delete t;
		i = 1;
	}
}
};
}

