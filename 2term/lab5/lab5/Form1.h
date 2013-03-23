#pragma once

#include "point.h"

namespace lab5 {

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
	private: System::Windows::Forms::TextBox^  tb1;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  tb2;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RadioButton^  rb1;
	private: System::Windows::Forms::RadioButton^  rb2;
	private: System::Windows::Forms::RadioButton^  rb3;
	private: System::Windows::Forms::RadioButton^  rb4;
	private: System::Windows::Forms::RadioButton^  rb5;
	private: System::Windows::Forms::RadioButton^  rb6;

	private: System::Windows::Forms::TextBox^  tb;







	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tb1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tb2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tb = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->rb1 = (gcnew System::Windows::Forms::RadioButton());
			this->rb2 = (gcnew System::Windows::Forms::RadioButton());
			this->rb3 = (gcnew System::Windows::Forms::RadioButton());
			this->rb4 = (gcnew System::Windows::Forms::RadioButton());
			this->rb5 = (gcnew System::Windows::Forms::RadioButton());
			this->rb6 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tb1
			// 
			this->tb1->Location = System::Drawing::Point(9, 19);
			this->tb1->Name = L"tb1";
			this->tb1->Size = System::Drawing::Size(87, 20);
			this->tb1->TabIndex = 10;
			this->tb1->TabStop = false;
			this->tb1->Text = L"0;0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Формат записи a;b";
			// 
			// tb2
			// 
			this->tb2->Location = System::Drawing::Point(6, 19);
			this->tb2->Name = L"tb2";
			this->tb2->Size = System::Drawing::Size(123, 20);
			this->tb2->TabIndex = 20;
			this->tb2->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->tb);
			this->groupBox1->Controls->Add(this->tb1);
			this->groupBox1->Location = System::Drawing::Point(2, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 65);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Входные данные";
			// 
			// tb
			// 
			this->tb->Location = System::Drawing::Point(102, 19);
			this->tb->Name = L"tb";
			this->tb->Size = System::Drawing::Size(85, 20);
			this->tb->TabIndex = 10;
			this->tb->TabStop = false;
			this->tb->Text = L"0;0";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tb2);
			this->groupBox2->Location = System::Drawing::Point(210, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(135, 65);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Результат";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 175);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Операция";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// rb1
			// 
			this->rb1->AutoSize = true;
			this->rb1->Checked = true;
			this->rb1->Location = System::Drawing::Point(12, 83);
			this->rb1->Name = L"rb1";
			this->rb1->Size = System::Drawing::Size(144, 17);
			this->rb1->TabIndex = 4;
			this->rb1->TabStop = true;
			this->rb1->Text = L"Перемещение по оси Х";
			this->rb1->UseVisualStyleBackColor = true;
			this->rb1->CheckedChanged += gcnew System::EventHandler(this, &Form1::rb1_CheckedChanged);
			// 
			// rb2
			// 
			this->rb2->AutoSize = true;
			this->rb2->Location = System::Drawing::Point(194, 83);
			this->rb2->Name = L"rb2";
			this->rb2->Size = System::Drawing::Size(145, 17);
			this->rb2->TabIndex = 4;
			this->rb2->Text = L"Перемещение по оси У";
			this->rb2->UseVisualStyleBackColor = true;
			this->rb2->CheckedChanged += gcnew System::EventHandler(this, &Form1::rb1_CheckedChanged);
			// 
			// rb3
			// 
			this->rb3->AutoSize = true;
			this->rb3->Location = System::Drawing::Point(13, 106);
			this->rb3->Name = L"rb3";
			this->rb3->Size = System::Drawing::Size(194, 17);
			this->rb3->TabIndex = 4;
			this->rb3->Text = L"Расстояние до начала координат";
			this->rb3->UseVisualStyleBackColor = true;
			this->rb3->CheckedChanged += gcnew System::EventHandler(this, &Form1::rb1_CheckedChanged);
			// 
			// rb4
			// 
			this->rb4->AutoSize = true;
			this->rb4->Location = System::Drawing::Point(13, 129);
			this->rb4->Name = L"rb4";
			this->rb4->Size = System::Drawing::Size(166, 17);
			this->rb4->TabIndex = 4;
			this->rb4->Text = L"Расстояние между точками";
			this->rb4->UseVisualStyleBackColor = true;
			this->rb4->CheckedChanged += gcnew System::EventHandler(this, &Form1::rb1_CheckedChanged);
			// 
			// rb5
			// 
			this->rb5->AutoSize = true;
			this->rb5->Location = System::Drawing::Point(11, 152);
			this->rb5->Name = L"rb5";
			this->rb5->Size = System::Drawing::Size(232, 17);
			this->rb5->TabIndex = 4;
			this->rb5->Text = L"Преобразование в полярные координаы";
			this->rb5->UseVisualStyleBackColor = true;
			this->rb5->CheckedChanged += gcnew System::EventHandler(this, &Form1::rb1_CheckedChanged);
			// 
			// rb6
			// 
			this->rb6->AutoSize = true;
			this->rb6->Location = System::Drawing::Point(194, 129);
			this->rb6->Name = L"rb6";
			this->rb6->Size = System::Drawing::Size(158, 17);
			this->rb6->TabIndex = 4;
			this->rb6->Text = L"Сравнение на совпадение";
			this->rb6->UseVisualStyleBackColor = true;
			this->rb6->CheckedChanged += gcnew System::EventHandler(this, &Form1::rb1_CheckedChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(357, 206);
			this->Controls->Add(this->rb6);
			this->Controls->Add(this->rb5);
			this->Controls->Add(this->rb4);
			this->Controls->Add(this->rb3);
			this->Controls->Add(this->rb2);
			this->Controls->Add(this->rb1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	
	/*int i, j = -1, k = -1, t = -1, p = -1, g = -1, f = -1, u = -1, l = s->Length::get(), a, b, c, d, h = 0 , uncorr = 0, uncorrect_input = 0;
	for(i = 0; i < l ; i++)
	{
		if( s[i] == ';')
			j = i;
		if((s[i] == '(')&&(k != -1))
			t = i;
		if((s[i] == '(')&&(k == -1))
			k = i;
		if((s[i] == ')')&&(p != -1))
			g = i;
		if((s[i] == ')')&&(p == -1))
			p = i;
		if((s[i] == ',')&&(f != -1))
			u = i;
		if((s[i] == ',')&&(f == -1))
			f = i;
	}
	for(i = k+1; i < f ; i++)
	{
		if(s[i] == ' ')
			continue;
		if((s[i] > '9') || (s[i] < '0'))
		{
			uncorr = 1;
			a = 0;
			h = 0;
			break;
		}
		if(s[i] == '-')
			h = 1;
		else
			a = a*10 + s[i] - '0';
	}
	if(h == 1)
		a = -a;
	h = 0;
	for(i = f+1; i < p ; i++)
	{
		if(s[i] == ' ')
			continue;
		if((s[i] > '9') || (s[i] < '0'))
		{
			uncorr = 1;
			b = 0;
			h = 0;
			break;
		}
		if(s[i] == '-')
			h = 1;
		else
			b = b*10 + s[i] - '0';
	}
	if(h == 1)
		b = -b;
	h = 0;
	for(i = t+1; i < u ; i++)
	{
		if(s[i] == ' ')
			continue;
		if((s[i] > '9') || (s[i] < '0'))
		{
			uncorr = 1;
			c = 0;
			h = 0;
			break;
		}
		if(s[i] == '-')
			h = 1;
		else
			c = c*10 + s[i] - '0';
	}
	if(h == 1)
		c = -c;
	h = 0;
	for(i = u+1; i < g ; i++)
	{
		if(s[i] == ' ')
			continue;
		if((s[i] > '9') || (s[i] < '0'))
		{
			uncorr = 1;
			d = 0;
			h = 0;
			break;
		}
		if(s[i] == '-')
			h = 1;
		else
			d = d*10 + s[i] - '0';
	}
	if(h == 1)
		d = -d;
	h = 0;
	if((((((((j == -1) ||  (k == -1)) || (t == -1)) || (p == -1)) || (g == -1)) || (f == -1)) || (u == -1)))
	{
		tb2->Text = "Некорр. ввод";
	}
	else
		tb2->Text = "";
	first = new point(a, b);
	second = new point(c, d);
	third = new point(0,0);
	if(rb1->Checked)
		i = 1;
	else if(rb2->Checked)
		i = 2;
	else if(rb3->Checked)
		i = 3;
	else if(rb4->Checked)
		i = 4;
	else if(rb5->Checked)
		i = 5;
	else i = 6;
	switch (i)
	{
	case 1:
		++first;
		break;
	case 2:
		first++;
		break;
	case 3:
		&first;
		break;
	case 4:
		first/second;
		break;
	case 5:
		first = -first;
		break;
	case 6:
		if(first == second)
			;///
		else
			;///
		break;
	}*/
	point* first, *second;
	String^ s = Convert::ToString(tb1->Text);
	int a = 0, b = 0, c = 0, d = 0, i, j = 0, l = s->Length::get(), z = -1, f, t;
	for(i = 0; i < l; i++)
	{
		if(s[i] == ';')
			z = i;
	}
	if(z == -1)
	{
		tb2->Text = "Некорректный ввод";
		return;
	}
	for(i = 0; i < z; i++)
	{
		if(s[i] == ' ')
				continue;
		if((s[i] >= '0') && (s[i] <= '9'))			
			a = a*10 + s[i] - '0';
		else if ((s[i] == '-') && ( i == 0))
		{
			j = 1;
		}
		else
		{
			tb2->Text = "Некорректный ввод";
			return;
		}
	}
	if(j)
	{
		j = 0;
		a = -a;
	}
	for(i = z+1; i < l; i++)
	{
		if(s[i] == ' ')
				continue;
		if((s[i] >= '0') && (s[i] <= '9'))		
			b = b*10 + s[i] - '0';
		else if ((s[i] == '-') && ( i == z+1))
		{
			j = 1;
		}
		else
		{
			tb2->Text = "Некорректный ввод";
			return;
		}
	}
	if(j)
	{
		j = 0;
		b = -b;
	}
	s = tb->Text;
	l = s->Length::get();
	if(rb1->Checked)
		i = 1;
	else if(rb2->Checked)
		i = 2;
	else if(rb3->Checked)
		i = 3;
	else if(rb4->Checked)
		i = 4;
	else if(rb5->Checked)
		i = 5;
	else i = 6;
	switch (i)
	{
	case 1:
		first = new point(a,b);
		if((s[0] == '-')|| ((s[0] <= 9)&&(s[0] >= 0)))
		for(j = 1; j < l; j++)
		{
			if((s[j] >= '0') && (s[j] <= '9'))
				;
			else
			{
				tb2->Text = "Некорректный ввод";
				return;
			}
		}
		l = Convert::ToInt32(tb->Text);
		second = new point(l,0);
		*first += *second;
		//tb2->Text = Convert::ToString(first->getx()) + Convert::ToString(';') + Convert::ToString(first->gety());
		tb2->Text = "";
		tb2->AppendText(Convert::ToString(first->getx()) + ";" + Convert::ToString(first->gety()));
		delete first;
		delete second;
		return;
	case 2:
		first = new point(a,b);
		if((s[0] == '-')|| ((s[0] <= '9')&&(s[0] >= '0')))
		for(j = 1; j < l; j++)
		{
			if((s[j] >= '0') && (s[j] <= '9'))
				;
			else
			{
				tb2->Text = "Некорректный ввод";
				return;
			}
		}
		l = Convert::ToInt32(tb->Text);
		second = new point(0,l);
		*first += *second;
		//tb2->Text = Convert::ToString(first->getx()) + ";" + Convert::ToString(first->gety());
		tb2->Text = "";
		tb2->AppendText(Convert::ToString(first->getx()) + ";" + Convert::ToString(first->gety()));
		delete first;
		delete second;
		return;
	case 3:
		first = new point(a,b);
		tb2->Text = Convert::ToString(&(*first));
		delete first;
		return;
	case 4:
		z = -1;
		j = 0;
		for(i = 0; i < l; i++)
		{
			if(s[i] == ';')
				z = i;
		}
		if(z == -1)
		{
			tb2->Text = "Некорректный ввод";
			return;
		}
		for(i = 0; i < z; i++)
		{
			if(s[i] == ' ')
				continue;
			if((s[i] >= '0') && (s[i] <= '9'))		
				c = c*10 + s[i] - '0';
			else if ((s[i] == '-') && ( i == 0))
			{
				j = 1;
			}
			else
			{
				tb2->Text = "Некорректный ввод";
				return;
			}
		}
		if(j)
		{
			j = 0;
			c = -c;
		}
		for(i = z+1; i < l; i++)
		{
			if(s[i] == ' ')
				continue;
			if((s[i] >= '0') && (s[i] <= '9'))			
				d = d*10 + s[i] - '0';
			else if ((s[i] == '-') && ( i == z+1))
			{
				j = 1;
			}
			else
			{
				tb2->Text = "Некорректный ввод";
				return;
			}
		}
		if(j)
		{
			j = 0;
			d = -d;
		}
		first = new point(a,b);
		second = new point(c, d);
		tb2->Text = Convert::ToString((*first)/(*second));
		delete first;
		delete second;
		return;
	case 5:
		first = new point(a,b);
		-(*first);
		//tb2->Text = Convert::ToString(first->getx()) + ';' + Convert::ToString(first->gety());
		tb2->Text = "";
		tb2->AppendText(Convert::ToString(first->getx()) + ";" + Convert::ToString(first->gety()));
		delete first;
		return;
	case 6:
		z = -1;
		j = 0;
		for(i = 0; i < l; i++)
		{
			if(s[i] == ';')
				z = i;
		}
		if(z == -1)
		{
			tb2->Text = "Некорректный ввод";
			return;
		}
		for(i = 0; i < z; i++)
		{
			if(s[i] == ' ')
				continue;
			if((s[i] >= '0') && (s[i] <= '9'))		
				c = c*10 + s[i] - '0';
			else if ((s[i] == '-') && ( i == 0))
			{
				j = 1;
			}
			else
			{
				tb2->Text = "Некорректный ввод";
				return;
			}
		}
		if(j)
		{
			j = 0;
			c = -c;
		}
		for(i = z+1; i < l; i++)
		{
			if(s[i] == ' ')
				continue;
			if((s[i] >= '0') && (s[i] <= '9'))		
				d = d*10 + s[i] - '0';
			else if ((s[i] == '-') && ( i == z+1))
			{
				j = 1;
			}
			else
			{
				tb2->Text = "Некорректный ввод";
				return;
			}
		}
		if(j)
		{
			j = 0;
			d = -d;
		}
		first = new point(a,b);
		second = new point(c, d);
		if( (*first) == (*second))
			tb2->Text = "Равны";
		else tb2->Text = "Не равны";
		delete first;
		delete second;
		return;
	}

}

private: System::Void rb1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
 {
	int i;
	if(rb1->Checked)
		i = 1;
	else if(rb2->Checked)
		i = 2;
	else if(rb3->Checked)
		i = 3;
	else if(rb4->Checked)
		i = 4;
	else if(rb5->Checked)
		i = 5;
	else i = 6;

	tb->Visible = true;
	switch (i)
	{
	case 1:
		tb->Text = "Величина";
		break;
	case 2:
		tb->Text = "Величина";
		break;
	case 3:
		tb->Visible = false;
		break;
	case 4:
		tb->Text = "0;0";
		break;
	case 5:
		tb->Visible = false;
		break;
	case 6:
		tb->Text = "0;0";
		break;
	}
}
};
}

