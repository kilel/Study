#pragma once
#include <windows.h>
#include "vcclr.h"

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace lab1 {

	/// <summary>
	/// Сводка для a3boot
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class a3boot : public System::Windows::Forms::Form
	{
	public:
		a3boot(String^ s)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			ss = s;
			DWORD kri = GetFileAttributes(tolpc(s));
			if(kri&FILE_ATTRIBUTE_ARCHIVE)
				checkBox5->Checked = true;
			if(kri&FILE_ATTRIBUTE_READONLY)
				checkBox1->Checked = true;
			if(kri&FILE_ATTRIBUTE_SYSTEM)
				checkBox3->Checked = true;
			if(kri&FILE_ATTRIBUTE_HIDDEN)
				checkBox2->Checked = true;
			if(kri&FILE_ATTRIBUTE_DIRECTORY)
				checkBox4->Checked = true;
			if(kri&FILE_ATTRIBUTE_DEVICE)
				checkBox14->Checked = true;
			if(kri&FILE_ATTRIBUTE_NORMAL)
				checkBox7->Checked = true;
			if(kri&FILE_ATTRIBUTE_TEMPORARY)
				checkBox6->Checked = true;
			if(kri&FILE_ATTRIBUTE_SPARSE_FILE)
				checkBox9->Checked = true;
			if(kri&FILE_ATTRIBUTE_REPARSE_POINT)
				checkBox12->Checked = true;
			if(kri&FILE_ATTRIBUTE_COMPRESSED)
				checkBox8->Checked = true;
			if(kri&FILE_ATTRIBUTE_OFFLINE)
				checkBox11->Checked = true;
			if(kri&FILE_ATTRIBUTE_ENCRYPTED)
				checkBox10->Checked = true;
			if(kri&FILE_ATTRIBUTE_NOT_CONTENT_INDEXED)
				checkBox13->Checked = true;
			/*FileAttributes^ k = File::GetAttributes(s);
			Array^ d = k->GetValues(k::typeid);
			String^ u = k->Format(k::typeid,k,"G");
			if(u->Contains("Archive"))
				checkBox5->Checked = true;
			if(u->Contains("ReadOnly"))
				checkBox1->Checked = true;
			if(u->Contains("System"))
				checkBox3->Checked = true;
			if(u->Contains("Hidden"))
				checkBox2->Checked = true;
			if(u->Contains("Directory"))
				checkBox4->Checked = true;
			if(u->Contains("Device"))
				checkBox14->Checked = true;
			if(u->Contains("Normal"))
				checkBox7->Checked = true;
			if(u->Contains("Temporary"))
				checkBox6->Checked = true;
			if(u->Contains("SparseFile"))
				checkBox9->Checked = true;
			if(u->Contains("ResparsePoint"))
				checkBox12->Checked = true;
			if(u->Contains("Compressed"))
				checkBox8->Checked = true;
			if(u->Contains("Offline"))
				checkBox11->Checked = true;
			if(u->Contains("Encrypted"))
				checkBox10->Checked = true;
			if(u->Contains("NotContentIndexed"))
				checkBox13->Checked = true;
				*/
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~a3boot()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  checkBox1;
	protected: 
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::CheckBox^  checkBox7;
	private: System::Windows::Forms::CheckBox^  checkBox8;
	private: System::Windows::Forms::CheckBox^  checkBox9;
	private: System::Windows::Forms::CheckBox^  checkBox10;
	private: System::Windows::Forms::CheckBox^  checkBox11;
	private: System::Windows::Forms::CheckBox^  checkBox12;
	private: System::Windows::Forms::CheckBox^  checkBox13;
	private: System::Windows::Forms::CheckBox^  checkBox14;
	private: System::Windows::Forms::Button^  button1;
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
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox11 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox12 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox13 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox14 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(13, 13);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(121, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Только для чтения";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(167, 12);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(72, 17);
			this->checkBox2->TabIndex = 0;
			this->checkBox2->Text = L"Скрытый";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Enabled = false;
			this->checkBox3->Location = System::Drawing::Point(13, 48);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(84, 17);
			this->checkBox3->TabIndex = 0;
			this->checkBox3->Text = L"Системный";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Enabled = false;
			this->checkBox4->Location = System::Drawing::Point(167, 47);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(67, 17);
			this->checkBox4->TabIndex = 0;
			this->checkBox4->Text = L"Каталог";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Enabled = false;
			this->checkBox5->Location = System::Drawing::Point(13, 84);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(56, 17);
			this->checkBox5->TabIndex = 0;
			this->checkBox5->Text = L"Архив";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Enabled = false;
			this->checkBox6->Location = System::Drawing::Point(167, 83);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(85, 17);
			this->checkBox6->TabIndex = 0;
			this->checkBox6->Text = L"Временный";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Enabled = false;
			this->checkBox7->Location = System::Drawing::Point(13, 119);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(92, 17);
			this->checkBox7->TabIndex = 0;
			this->checkBox7->Text = L"Нормальный";
			this->checkBox7->UseVisualStyleBackColor = true;
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->Enabled = false;
			this->checkBox8->Location = System::Drawing::Point(13, 154);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(66, 17);
			this->checkBox8->TabIndex = 0;
			this->checkBox8->Text = L"Сжатый";
			this->checkBox8->UseVisualStyleBackColor = true;
			// 
			// checkBox9
			// 
			this->checkBox9->AutoSize = true;
			this->checkBox9->Enabled = false;
			this->checkBox9->Location = System::Drawing::Point(13, 190);
			this->checkBox9->Name = L"checkBox9";
			this->checkBox9->Size = System::Drawing::Size(70, 17);
			this->checkBox9->TabIndex = 0;
			this->checkBox9->Text = L"SpareFile";
			this->checkBox9->UseVisualStyleBackColor = true;
			// 
			// checkBox10
			// 
			this->checkBox10->AutoSize = true;
			this->checkBox10->Enabled = false;
			this->checkBox10->Location = System::Drawing::Point(167, 118);
			this->checkBox10->Name = L"checkBox10";
			this->checkBox10->Size = System::Drawing::Size(111, 17);
			this->checkBox10->TabIndex = 0;
			this->checkBox10->Text = L"Зашифрованный";
			this->checkBox10->UseVisualStyleBackColor = true;
			// 
			// checkBox11
			// 
			this->checkBox11->AutoSize = true;
			this->checkBox11->Enabled = false;
			this->checkBox11->Location = System::Drawing::Point(167, 153);
			this->checkBox11->Name = L"checkBox11";
			this->checkBox11->Size = System::Drawing::Size(56, 17);
			this->checkBox11->TabIndex = 0;
			this->checkBox11->Text = L"Offline";
			this->checkBox11->UseVisualStyleBackColor = true;
			// 
			// checkBox12
			// 
			this->checkBox12->AutoSize = true;
			this->checkBox12->Enabled = false;
			this->checkBox12->Location = System::Drawing::Point(167, 189);
			this->checkBox12->Name = L"checkBox12";
			this->checkBox12->Size = System::Drawing::Size(90, 17);
			this->checkBox12->TabIndex = 0;
			this->checkBox12->Text = L"ReparsePoint";
			this->checkBox12->UseVisualStyleBackColor = true;
			// 
			// checkBox13
			// 
			this->checkBox13->AutoSize = true;
			this->checkBox13->Enabled = false;
			this->checkBox13->Location = System::Drawing::Point(13, 226);
			this->checkBox13->Name = L"checkBox13";
			this->checkBox13->Size = System::Drawing::Size(118, 17);
			this->checkBox13->TabIndex = 0;
			this->checkBox13->Text = L"NotContentIndexed";
			this->checkBox13->UseVisualStyleBackColor = true;
			// 
			// checkBox14
			// 
			this->checkBox14->AutoSize = true;
			this->checkBox14->Enabled = false;
			this->checkBox14->Location = System::Drawing::Point(167, 225);
			this->checkBox14->Name = L"checkBox14";
			this->checkBox14->Size = System::Drawing::Size(60, 17);
			this->checkBox14->TabIndex = 0;
			this->checkBox14->Text = L"Device";
			this->checkBox14->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(148, 307);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Сохранить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &a3boot::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(236, 307);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &a3boot::button2_Click);
			// 
			// a3boot
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(323, 342);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox14);
			this->Controls->Add(this->checkBox12);
			this->Controls->Add(this->checkBox6);
			this->Controls->Add(this->checkBox11);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox10);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox13);
			this->Controls->Add(this->checkBox9);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->checkBox8);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox7);
			this->Controls->Add(this->checkBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"a3boot";
			this->Text = L"a3boot";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	String^ ss;
private: 
	System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		/*FileAttributes^ d = FileAttributes::Archive;
		FileAttributes^ k = File::GetAttributes(ss);
		String ^t = k->ToString();
		if(checkBox1->Checked == true)
			File::SetAttributes(ss, File::GetAttributes(ss)|FileAttributes::ReadOnly); 
		if(checkBox1->Checked == false)
			File::SetAttributes(ss, File::GetAttributes(ss)^FileAttributes::ReadOnly); 
		if(checkBox2->Checked == true)
			File::SetAttributes(ss, File::GetAttributes(ss)|FileAttributes::Hidden);
		if(checkBox2->Checked == false)
			File::SetAttributes(ss, File::GetAttributes(ss)^FileAttributes::Hidden);
			*/
		DWORD kri = GetFileAttributes(tolpc(ss));
		if(checkBox1->Checked == true)
			SetFileAttributes(tolpc(ss), kri|FILE_ATTRIBUTE_READONLY);
		if(checkBox1->Checked == false)
			SetFileAttributes(tolpc(ss), kri^FILE_ATTRIBUTE_READONLY);
		if(checkBox2->Checked == true)
			SetFileAttributes(tolpc(ss), kri|FILE_ATTRIBUTE_HIDDEN);
		if(checkBox2->Checked == false)
			SetFileAttributes(tolpc(ss), kri^FILE_ATTRIBUTE_HIDDEN);		
		this->Close();
	}
	System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
			 this->Close();
	}
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
	int find_last_slash(String^ s) //находит индекс последнего символа \ в строке
	{
		for(int i = s->Length -2; i > 0; i--)
			if('\\' == s[i])
				return i;
	}


}
;
}
