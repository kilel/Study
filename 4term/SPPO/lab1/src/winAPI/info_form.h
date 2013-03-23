#pragma once
#include "a3boot.h"
#include <sys/types.h>
#include <sys/stat.h>

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace lab1 {

	/// <summary>
	/// Сводка для info_form
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class info_form : public System::Windows::Forms::Form
	{
	public:
		info_form(String^ s)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			ss = s;
			try
			{
				if(File::Exists(s))
				{
					label2->Text = s;
					label4->Text = String::Concat("Дата создания файла: ", File::GetCreationTime(s));
					label5->Text = String::Concat("Дата последней модификации файла: ", File::GetLastWriteTime(s));
					label6->Text = String::Concat("Дата последнего обращния к файлу: ", File::GetLastAccessTime(s));
					//FileInfo^ ff = gcnew FileInfo(s);
					HANDLE hfile = CreateFile(tolpc(s),0,0, NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL, NULL);

					
					label3->Text = String::Concat("Размер файла: ",  GetFileSize(hfile, NULL)," байт");
					
				}
				else
				{
					label2->Text = s;
					label4->Text = String::Concat("Дата создания каталога: ", Directory::GetCreationTime(s));
					label5->Text = String::Concat("Дата последней модификации каталога: ", Directory::GetLastWriteTime(s));
					label6->Text = String::Concat("Дата последнего обращния к каталогу: ", Directory::GetLastAccessTime(s));
					label3->Text = String::Concat("Содержит файлов: ", Directory::GetFiles(s)->Length, " ,каталогов: ", Directory::GetDirectories(s)->Length );
				}
			}
			catch(...)	//нет доступа 
			{
				MessageBox::Show("Нет доступа!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->Close();
			}
			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~info_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button2;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Инрформация о файле:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"label2";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 93);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 1;
			this->label4->Text = L"label2";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 115);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"label2";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(67, 160);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"ОК";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &info_form::button1_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 138);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"label2";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(197, 160);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Атрибуты";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &info_form::button2_Click);
			// 
			// info_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(361, 195);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"info_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Информация";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		String^ ss;
private: 
	LPCTSTR tolpc(String^s)
	{
		LPCTSTR st;
		const size_t newsizew = s->Length +1;
		pin_ptr<const wchar_t> wch = PtrToStringChars(s);
		wchar_t *wcstring = new wchar_t[newsizew];
		wcscpy_s(wcstring, newsizew, wch);
		st = (LPCTSTR)wcstring;
		return st;
	}
	System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
			 this->Close();
	}
	System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		a3boot^ mikuru = gcnew a3boot(ss);
		mikuru->ShowDialog();
		delete mikuru;
	}
};
}
