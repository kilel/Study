#pragma once
#include "lab6_superclass.h"
#include <stdlib.h>
#include <time.h>

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
			srand(time(0));
			
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
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected: 
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	private: System::Windows::Forms::RichTextBox^  richTextBox4;

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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(4, 3);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(222, 109);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"input";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(4, 112);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(222, 118);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"result";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(4, 232);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(447, 41);
			this->button1->TabIndex = 2;
			this->button1->Text = L"запуск";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(229, 3);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(222, 109);
			this->richTextBox3->TabIndex = 0;
			this->richTextBox3->Text = L"input";
			// 
			// richTextBox4
			// 
			this->richTextBox4->Location = System::Drawing::Point(229, 112);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->Size = System::Drawing::Size(222, 118);
			this->richTextBox4->TabIndex = 1;
			this->richTextBox4->Text = L"result";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(456, 276);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox4);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
private: 
	lab6_superclass^ l;
void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if(File::Exists("input"))
		File::Delete("input");
	File::Create("input")->Close();
	FileStream^ f = File::OpenWrite("input");
	int n = 5;//rand()%500 + 100;
	for(int i = 0; i < n; i++)
	{
		f->WriteByte(rand()%255+1);
	}
	f->Close();
	EventWaitHandle^ eva = gcnew EventWaitHandle(false,EventResetMode::AutoReset);
	l = gcnew lab6_superclass(eva);
	Thread^ thread1 = gcnew Thread( gcnew ThreadStart( l,&lab6_superclass::print_data) );
	Thread^ thread2 = gcnew Thread( gcnew ThreadStart( l,&lab6_superclass::process_data) );
	Thread^ thread3 = gcnew Thread( gcnew ThreadStart( l,&lab6_superclass::read_data) );
	thread1->Start();
	thread2->Start();
	thread3->Start();
	while(l->stop != 7)
	{
		eva->WaitOne();
		if(l->stop == 6)
			l->stop = 7;
		richTextBox1->Text = l->in;
		richTextBox2->Text = l->out;
	}
	richTextBox3->Text = L"input:\n";
	richTextBox4->Text = L"result:\n";
	for(int i = 0; i < l->input->Length; i++)
		{
			richTextBox4->Text = richTextBox4->Text->Concat(richTextBox4->Text,l->accum[i], " ");
			richTextBox3->Text = richTextBox3->Text->Concat(richTextBox3->Text,l->input[i], " ");
			if(i != l->input->Length-1)
			{
				richTextBox3->Text = richTextBox3->Text->Concat(richTextBox3->Text,",");
				richTextBox4->Text = richTextBox4->Text->Concat(richTextBox4->Text, ",");
			}
		}
	delete l;
	delete thread1;
	delete thread2;
	delete thread3;
}

};
}

