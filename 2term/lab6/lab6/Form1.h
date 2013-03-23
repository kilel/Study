#pragma once

#include "queue.h"
namespace lab6 {

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
	private: System::Windows::Forms::TextBox^  tb;
	private: System::Windows::Forms::RichTextBox^  rtb;
	private: System::Windows::Forms::RadioButton^  add;
	private: System::Windows::Forms::RadioButton^  del;
	private: System::Windows::Forms::RadioButton^  find;
	protected: 






	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  integ;
	private: System::Windows::Forms::RadioButton^  strin;
	private: System::Windows::Forms::RadioButton^  rats;




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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tb = (gcnew System::Windows::Forms::TextBox());
			this->rtb = (gcnew System::Windows::Forms::RichTextBox());
			this->add = (gcnew System::Windows::Forms::RadioButton());
			this->del = (gcnew System::Windows::Forms::RadioButton());
			this->find = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->integ = (gcnew System::Windows::Forms::RadioButton());
			this->strin = (gcnew System::Windows::Forms::RadioButton());
			this->rats = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(10, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"DOIT";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// tb
			// 
			this->tb->Location = System::Drawing::Point(148, 13);
			this->tb->Name = L"tb";
			this->tb->Size = System::Drawing::Size(100, 20);
			this->tb->TabIndex = 10;
			this->tb->TabStop = false;
			this->tb->Text = L"0";
			// 
			// rtb
			// 
			this->rtb->Location = System::Drawing::Point(9, 56);
			this->rtb->Name = L"rtb";
			this->rtb->Size = System::Drawing::Size(85, 191);
			this->rtb->TabIndex = 20;
			this->rtb->TabStop = false;
			this->rtb->Text = L"";
			// 
			// add
			// 
			this->add->AutoSize = true;
			this->add->Checked = true;
			this->add->Location = System::Drawing::Point(6, 19);
			this->add->Name = L"add";
			this->add->Size = System::Drawing::Size(75, 17);
			this->add->TabIndex = 3;
			this->add->TabStop = true;
			this->add->Text = L"Добавить";
			this->add->UseVisualStyleBackColor = true;
			// 
			// del
			// 
			this->del->AutoSize = true;
			this->del->Location = System::Drawing::Point(6, 42);
			this->del->Name = L"del";
			this->del->Size = System::Drawing::Size(68, 17);
			this->del->TabIndex = 3;
			this->del->Text = L"Удалить";
			this->del->UseVisualStyleBackColor = true;
			// 
			// find
			// 
			this->find->AutoSize = true;
			this->find->Location = System::Drawing::Point(6, 65);
			this->find->Name = L"find";
			this->find->Size = System::Drawing::Size(56, 17);
			this->find->TabIndex = 3;
			this->find->Text = L"Найти";
			this->find->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->add);
			this->groupBox1->Controls->Add(this->find);
			this->groupBox1->Controls->Add(this->del);
			this->groupBox1->Location = System::Drawing::Point(126, 56);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(132, 92);
			this->groupBox1->TabIndex = 21;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Функции";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->integ);
			this->groupBox2->Controls->Add(this->strin);
			this->groupBox2->Controls->Add(this->rats);
			this->groupBox2->Location = System::Drawing::Point(126, 154);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(132, 92);
			this->groupBox2->TabIndex = 21;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Тип переменной";
			// 
			// integ
			// 
			this->integ->AutoSize = true;
			this->integ->Checked = true;
			this->integ->Location = System::Drawing::Point(6, 19);
			this->integ->Name = L"integ";
			this->integ->Size = System::Drawing::Size(57, 17);
			this->integ->TabIndex = 3;
			this->integ->TabStop = true;
			this->integ->Text = L"Целое";
			this->integ->UseVisualStyleBackColor = true;
			// 
			// strin
			// 
			this->strin->AutoSize = true;
			this->strin->Location = System::Drawing::Point(6, 65);
			this->strin->Name = L"strin";
			this->strin->Size = System::Drawing::Size(61, 17);
			this->strin->TabIndex = 3;
			this->strin->Text = L"Строка";
			this->strin->UseVisualStyleBackColor = true;
			// 
			// rats
			// 
			this->rats->AutoSize = true;
			this->rats->Location = System::Drawing::Point(6, 42);
			this->rats->Name = L"rats";
			this->rats->Size = System::Drawing::Size(98, 17);
			this->rats->TabIndex = 3;
			this->rats->Text = L"Рациональное";
			this->rats->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 266);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->rtb);
			this->Controls->Add(this->tb);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"lab6";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	static queue<int> ^qi = gcnew queue<int>(), ^tempi;
	static queue<double> ^qd = gcnew queue<double>(), ^tempd;
	static queue<String^> ^qs = gcnew queue<String^>(), ^temps;

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	int ki;
	double kd;
	String^ ks;
	if(integ->Checked)
	{
		ki = Convert::ToInt32(tb->Text);
		if(add->Checked)
		{
			qi->add(ki);
			tempi = qi->retbeg();
			rtb->Text = L"";
			while(tempi != nullptr)
			{
				rtb->AppendText(Convert::ToString(tempi->reti())+ "\n");
				tempi = tempi->retpr();
			}
		}
		else if(del->Checked)
		{
			rtb->Text = L"Удалено элементов: ";
			rtb->AppendText(Convert::ToString(qi->del(ki)) + "\n");
			tempi = qi->retbeg();
			while(tempi != nullptr)
			{
				rtb->AppendText(Convert::ToString(tempi->reti()) + "\n");
				tempi = tempi->retpr();
			}
		}
		else
		{
			rtb->Text = L"Найдено элементов: ";
			rtb->AppendText(Convert::ToString(qi->find(ki)) + "\n");
			tempi = qi->retbeg();
			while(tempi != nullptr)
			{
				rtb->AppendText(Convert::ToString(tempi->reti()) + "\n");
				tempi = tempi->retpr();
			}
		}
	}
	else if(rats->Checked)
	{
		kd = Convert::ToDouble(tb->Text);
		if(add->Checked)
		{
			qd->add(kd);
			tempd = qd->retbeg();
			rtb->Text = L"";
			while(tempd != nullptr)
			{
				rtb->AppendText(Convert::ToString(tempd->reti())+ "\n");
				tempd = tempd->retpr();
			}
		}
		else if(del->Checked)
		{
			rtb->Text = L"Удалено элементов: ";
			rtb->AppendText(Convert::ToString(qd->del(kd)) + "\n");
			tempd = qd->retbeg();
			while(tempd != nullptr)
			{
				rtb->AppendText(Convert::ToString(tempd->reti())+ "\n");
				tempd = tempd->retpr();
			}
		}
		else
		{
			rtb->Text = L"Найдено элементов: ";
			rtb->AppendText(Convert::ToString(qd->find(kd)) + "\n");
			tempd = qd->retbeg();
			while(tempd != nullptr)
			{
				rtb->AppendText(Convert::ToString(tempd->reti())+ "\n");
				tempd = tempd->retpr();
			}
		}
	}
	else 
	{
		ks = Convert::ToString(tb->Text);
		if(add->Checked)
		{
			qs->add(ks);
			temps = qs->retbeg();
			rtb->Text = L"";
			while(temps != nullptr)
			{
				rtb->AppendText(Convert::ToString(temps->reti())+ "\n");
				temps = temps->retpr();
			}
		}
		else if(del->Checked)
		{
			rtb->Text = L"Удалено элементов: ";
			rtb->AppendText(Convert::ToString(qs->del(ks)) + "\n");
			temps = qs->retbeg();
			while(temps != nullptr)
			{
				rtb->AppendText(Convert::ToString(temps->reti())+ "\n");
				temps = temps->retpr();
			}
		}
		else
		{
			rtb->Text = L"Найдено элементов: ";
			rtb->AppendText(Convert::ToString(qs->find(ks)) + "\n");
			temps = qs->retbeg();
			while(temps != nullptr)
			{
				rtb->AppendText(Convert::ToString(temps->reti())+ "\n");
				temps = temps->retpr();
			}
		}
	}
}
};
}

