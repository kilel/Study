#pragma once

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace lab1 {

	/// <summary>
	/// Сводка для tool_window
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class tool_window : public System::Windows::Forms::Form
	{
	public:
		tool_window(String^ s, String^ d)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			FileStream^ f = File::Open(s, FileMode::Open);
			label4->Text = String::Concat(Convert::ToString(f->Length)," байт, посл. модиф.:", File::GetLastWriteTime(s));
			f->Close();
			f = File::Open(d,  FileMode::Open);
			label5->Text = String::Concat(Convert::ToString(f->Length)," байт, посл. модиф.:", File::GetLastWriteTime(d));
			f->Close();
			label2->Text = s;
			label3->Text = d;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~tool_window()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  yes;

	private: System::Windows::Forms::Button^  no;
	private: System::Windows::Forms::Button^  cancel;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;




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
			this->yes = (gcnew System::Windows::Forms::Button());
			this->no = (gcnew System::Windows::Forms::Button());
			this->cancel = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(334, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Обнаружен файл с таким же именем. Заменить\?";
			// 
			// yes
			// 
			this->yes->Location = System::Drawing::Point(15, 154);
			this->yes->Name = L"yes";
			this->yes->Size = System::Drawing::Size(104, 23);
			this->yes->TabIndex = 0;
			this->yes->Tag = L"1";
			this->yes->Text = L"Да";
			this->yes->UseVisualStyleBackColor = true;
			this->yes->Click += gcnew System::EventHandler(this, &tool_window::bc);
			// 
			// no
			// 
			this->no->Location = System::Drawing::Point(125, 154);
			this->no->Name = L"no";
			this->no->Size = System::Drawing::Size(104, 23);
			this->no->TabIndex = 0;
			this->no->Tag = L"-1";
			this->no->Text = L"Нет";
			this->no->UseVisualStyleBackColor = true;
			this->no->Click += gcnew System::EventHandler(this, &tool_window::bc);
			// 
			// cancel
			// 
			this->cancel->Location = System::Drawing::Point(235, 154);
			this->cancel->Name = L"cancel";
			this->cancel->Size = System::Drawing::Size(104, 23);
			this->cancel->TabIndex = 0;
			this->cancel->Tag = L"0";
			this->cancel->Text = L"Отмена";
			this->cancel->UseVisualStyleBackColor = true;
			this->cancel->Click += gcnew System::EventHandler(this, &tool_window::bc);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 125);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 23);
			this->button1->TabIndex = 0;
			this->button1->Tag = L"10";
			this->button1->Text = L"Да для всех";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &tool_window::bc);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(125, 125);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(104, 23);
			this->button2->TabIndex = 0;
			this->button2->Tag = L"-10";
			this->button2->Text = L"Нет для всех";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &tool_window::bc);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 80);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 56);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 93);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"label5";
			// 
			// tool_window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(358, 196);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cancel);
			this->Controls->Add(this->no);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->yes);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"tool_window";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Запрос замещения";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		int answer;
		String^ s,^d;
	private: 
		System::Void bc(System::Object^  sender, System::EventArgs^  e) 
		{
			Button^ b = dynamic_cast<Button^>(sender);
			answer = Convert::ToInt32(b->Tag);
			this->Close();
		}
};
}
