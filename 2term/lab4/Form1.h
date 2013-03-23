#pragma once
#include "xora.h"
#include "sorta.h"
#include "Array.h"
#include <stdlib.h>
#include <time.h>

namespace lab4 {

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
			srand((unsigned)time(NULL));
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
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TextBox^  atext;
	private: System::Windows::Forms::RichTextBox^  rtba;
	private: System::Windows::Forms::Button^  start;
	private: System::Windows::Forms::RadioButton^  xorar;

	private: System::Windows::Forms::RadioButton^  sortar;
	protected: 





	private: System::Windows::Forms::RichTextBox^  result;
	private: System::Windows::Forms::RadioButton^  summa;
	private: System::Windows::Forms::RadioButton^  foreacha;






	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::TextBox^  btext;
	private: System::Windows::Forms::RichTextBox^  rtbb;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  index;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  gener;
	private: System::Windows::Forms::GroupBox^  ggg;

	private: System::Windows::Forms::RadioButton^  mas2;
	private: System::Windows::Forms::RadioButton^  mas1;
	private: System::Windows::Forms::Label^  label4;





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
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->atext = (gcnew System::Windows::Forms::TextBox());
			this->rtba = (gcnew System::Windows::Forms::RichTextBox());
			this->start = (gcnew System::Windows::Forms::Button());
			this->xorar = (gcnew System::Windows::Forms::RadioButton());
			this->sortar = (gcnew System::Windows::Forms::RadioButton());
			this->result = (gcnew System::Windows::Forms::RichTextBox());
			this->summa = (gcnew System::Windows::Forms::RadioButton());
			this->foreacha = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->btext = (gcnew System::Windows::Forms::TextBox());
			this->rtbb = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->index = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->gener = (gcnew System::Windows::Forms::Button());
			this->ggg = (gcnew System::Windows::Forms::GroupBox());
			this->mas2 = (gcnew System::Windows::Forms::RadioButton());
			this->mas1 = (gcnew System::Windows::Forms::RadioButton());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->ggg->SuspendLayout();
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(12, 12);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(143, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Пересоздать массив 1";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// atext
			// 
			this->atext->Location = System::Drawing::Point(12, 35);
			this->atext->Name = L"atext";
			this->atext->Size = System::Drawing::Size(100, 20);
			this->atext->TabIndex = 1;
			this->atext->Text = L"0";
			// 
			// rtba
			// 
			this->rtba->Location = System::Drawing::Point(12, 61);
			this->rtba->Name = L"rtba";
			this->rtba->Size = System::Drawing::Size(100, 96);
			this->rtba->TabIndex = 2;
			this->rtba->Text = L"";
			// 
			// start
			// 
			this->start->Location = System::Drawing::Point(12, 181);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(75, 23);
			this->start->TabIndex = 3;
			this->start->Text = L"Старт";
			this->start->UseVisualStyleBackColor = true;
			this->start->Click += gcnew System::EventHandler(this, &Form1::start_Click);
			// 
			// xorar
			// 
			this->xorar->AutoSize = true;
			this->xorar->Checked = true;
			this->xorar->Location = System::Drawing::Point(6, 27);
			this->xorar->Name = L"xorar";
			this->xorar->Size = System::Drawing::Size(65, 17);
			this->xorar->TabIndex = 4;
			this->xorar->TabStop = true;
			this->xorar->Text = L"XorArray";
			this->xorar->UseVisualStyleBackColor = true;
			// 
			// sortar
			// 
			this->sortar->AutoSize = true;
			this->sortar->Location = System::Drawing::Point(6, 50);
			this->sortar->Name = L"sortar";
			this->sortar->Size = System::Drawing::Size(71, 17);
			this->sortar->TabIndex = 4;
			this->sortar->Text = L"Sort Array";
			this->sortar->UseVisualStyleBackColor = true;
			// 
			// result
			// 
			this->result->Location = System::Drawing::Point(15, 246);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(100, 96);
			this->result->TabIndex = 2;
			this->result->Text = L"";
			// 
			// summa
			// 
			this->summa->AutoSize = true;
			this->summa->Checked = true;
			this->summa->Location = System::Drawing::Point(6, 23);
			this->summa->Name = L"summa";
			this->summa->Size = System::Drawing::Size(54, 17);
			this->summa->TabIndex = 5;
			this->summa->TabStop = true;
			this->summa->Text = L"Summ";
			this->summa->UseVisualStyleBackColor = true;
			// 
			// foreacha
			// 
			this->foreacha->AutoSize = true;
			this->foreacha->Location = System::Drawing::Point(6, 46);
			this->foreacha->Name = L"foreacha";
			this->foreacha->Size = System::Drawing::Size(64, 17);
			this->foreacha->TabIndex = 5;
			this->foreacha->Text = L"Foreach";
			this->foreacha->UseVisualStyleBackColor = true;
			this->foreacha->CheckedChanged += gcnew System::EventHandler(this, &Form1::f);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Location = System::Drawing::Point(170, 12);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(143, 17);
			this->checkBox2->TabIndex = 0;
			this->checkBox2->Text = L"Пересоздать массив 2";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// btext
			// 
			this->btext->Location = System::Drawing::Point(170, 32);
			this->btext->Name = L"btext";
			this->btext->Size = System::Drawing::Size(100, 20);
			this->btext->TabIndex = 1;
			this->btext->Text = L"0";
			// 
			// rtbb
			// 
			this->rtbb->Location = System::Drawing::Point(170, 61);
			this->rtbb->Name = L"rtbb";
			this->rtbb->Size = System::Drawing::Size(100, 96);
			this->rtbb->TabIndex = 2;
			this->rtbb->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(118, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Размер";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->sortar);
			this->groupBox1->Controls->Add(this->xorar);
			this->groupBox1->Location = System::Drawing::Point(317, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(116, 76);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Метод работы";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->foreacha);
			this->groupBox2->Controls->Add(this->summa);
			this->groupBox2->Location = System::Drawing::Point(439, 13);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(131, 75);
			this->groupBox2->TabIndex = 8;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Метод воздействия";
			// 
			// index
			// 
			this->index->Location = System::Drawing::Point(69, 28);
			this->index->Name = L"index";
			this->index->Size = System::Drawing::Size(68, 20);
			this->index->TabIndex = 1;
			this->index->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Индекс";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 229);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Результат";
			// 
			// gener
			// 
			this->gener->Location = System::Drawing::Point(170, 181);
			this->gener->Name = L"gener";
			this->gener->Size = System::Drawing::Size(91, 23);
			this->gener->TabIndex = 3;
			this->gener->Text = L"Генерировать";
			this->gener->UseVisualStyleBackColor = true;
			this->gener->Click += gcnew System::EventHandler(this, &Form1::generate);
			// 
			// ggg
			// 
			this->ggg->Controls->Add(this->mas2);
			this->ggg->Controls->Add(this->mas1);
			this->ggg->Controls->Add(this->label4);
			this->ggg->Controls->Add(this->label2);
			this->ggg->Controls->Add(this->index);
			this->ggg->Location = System::Drawing::Point(317, 94);
			this->ggg->Name = L"ggg";
			this->ggg->Size = System::Drawing::Size(154, 85);
			this->ggg->TabIndex = 9;
			this->ggg->TabStop = false;
			this->ggg->Text = L"foreach";
			this->ggg->Visible = false;
			// 
			// mas2
			// 
			this->mas2->AutoSize = true;
			this->mas2->Location = System::Drawing::Point(106, 57);
			this->mas2->Name = L"mas2";
			this->mas2->Size = System::Drawing::Size(31, 17);
			this->mas2->TabIndex = 7;
			this->mas2->Text = L"2";
			this->mas2->UseVisualStyleBackColor = true;
			// 
			// mas1
			// 
			this->mas1->AutoSize = true;
			this->mas1->Checked = true;
			this->mas1->Location = System::Drawing::Point(69, 59);
			this->mas1->Name = L"mas1";
			this->mas1->Size = System::Drawing::Size(31, 17);
			this->mas1->TabIndex = 7;
			this->mas1->TabStop = true;
			this->mas1->Text = L"1";
			this->mas1->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 61);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Mассив";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(579, 354);
			this->Controls->Add(this->ggg);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->gener);
			this->Controls->Add(this->start);
			this->Controls->Add(this->result);
			this->Controls->Add(this->rtbb);
			this->Controls->Add(this->rtba);
			this->Controls->Add(this->btext);
			this->Controls->Add(this->atext);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Name = L"Form1";
			this->Text = L"lab4";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ggg->ResumeLayout(false);
			this->ggg->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	sorta^ ar;
	sorta^ br;
	xora^ ar1;
	xora^ br1;
	int n, m;
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
{
	n = 0; m = 0;
	ar = gcnew sorta(n);
	br = gcnew sorta(m);
	ar1 = gcnew xora(n);
	br1 = gcnew xora(m);
}

private: System::Void f(System::Object^  sender, System::EventArgs^  e) 
{
	if(foreacha->Checked)
	ggg->Visible = true;
	else
		ggg->Visible = false;
}
private: System::Void start_Click(System::Object^  sender, System::EventArgs^  e) 
{
	result->Clear();
	int ind;
	if(foreacha->Checked)
		ind = Convert::ToInt32(index->Text);
	if(sortar->Checked)
	{
		if(summa->Checked)
		{
			ar->summ(br->a, br->r);
			for(int i = 0; i < ar->r; i++)
				result->AppendText("\n" + ar->a[i]);
		}
		else
		{
			if(mas1->Checked)
			{
				if(ind <= ar->r)
				{
					ar->foreach(ind);
					for(int i = 0; i < ind; i++)
						result->AppendText("\n" + ar->a[i]);
				}
				else
					result->AppendText("Индекс задан неверно");
			}
			else
			{
				if(ind <= br->r)
				{
					br->foreach(ind);
					for(int i = 0; i < ind; i++)
						result->AppendText("\n" + ar->a[i]);
				}
				else
					result->AppendText("Индекс задан неверно");
			}
		}
	}
	else
	{
		if(summa->Checked)
		{
			ar1->summ(br1->a, br1->r);
			for(int i = 0; i < ar1->r; i++)
				result->AppendText("\n" + ar1->a[i]);
		}
		else
		{
			ind--;
			if((mas1->Checked)&&(ind != 0))
			{
				if(ind < ar1->r)
				{
					result->AppendText("\n" + ar1->foreach(ind));
				}
				else
					result->AppendText("Индекс задан неверно");
			}
			else
			{
				if((ind < br->r)&&(ind != 0))
				{
					result->AppendText("\n" + br1->foreach(ind));
				}
				else
					result->AppendText("Индекс задан неверно");
			}
		}
	}
}
private: System::Void generate(System::Object^  sender, System::EventArgs^  e) 
{
	int i;
	n = Convert::ToInt32(atext->Text);
	m = Convert::ToInt32(btext->Text);
	if(sortar->Checked)
	{
		delete ar;
		delete br;
		ar = gcnew sorta(n);
		br = gcnew sorta(m);
		rtba->Clear();
		rtbb->Clear();
		for(i = 0; i < n; i++)
			rtba->AppendText("\n" + ar->a[i]);
		for(i = 0; i < m; i++)
			rtbb->AppendText("\n" + br->a[i]);
	}
	else
	{
		delete ar1;
		delete br1;
		ar1 = gcnew xora(n);
		br1 = gcnew xora(m);
		rtba->Clear();
		rtbb->Clear();
		for(i = 0; i < n; i++)
			rtba->AppendText("\n" + ar1->a[i]);
		for(i = 0; i < m; i++)
			rtbb->AppendText("\n" + br1->a[i]);
	}
}
};
}

