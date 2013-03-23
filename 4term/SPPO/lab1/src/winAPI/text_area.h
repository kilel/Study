#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace lab1 {

	/// <summary>
	/// Сводка для text_area
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class text_area : public System::Windows::Forms::Form
	{
	public:
		text_area(void)
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
		~text_area()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  text;
	private: System::Windows::Forms::Button^  b;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	protected: 



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
			this->text = (gcnew System::Windows::Forms::TextBox());
			this->b = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(200, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите имя создаваемого элемента";
			// 
			// text
			// 
			this->text->Location = System::Drawing::Point(16, 30);
			this->text->Name = L"text";
			this->text->Size = System::Drawing::Size(336, 20);
			this->text->TabIndex = 1;
			this->text->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &text_area::key_down);
			this->text->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &text_area::key_press);
			// 
			// b
			// 
			this->b->Location = System::Drawing::Point(105, 56);
			this->b->Name = L"b";
			this->b->Size = System::Drawing::Size(75, 23);
			this->b->TabIndex = 2;
			this->b->Tag = L"1";
			this->b->Text = L"Принять";
			this->b->UseVisualStyleBackColor = true;
			this->b->Click += gcnew System::EventHandler(this, &text_area::push_);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(273, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Имя не может включать символы <  >  /  \\  \"  :  \?  |  *";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(186, 56);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Tag = L"0";
			this->button1->Text = L"Отмена";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &text_area::push_);
			// 
			// text_area
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(364, 100);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->b);
			this->Controls->Add(this->text);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"text_area";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Окно ввода данных";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	String^ value;
	int action;
private: 
	System::Void key_down(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		wchar_t k = e->KeyValue;
		if(e->KeyValue == 13)		//при нажатии enter
		{
			action = 1;
			value = text->Text;
			this->Close();
		}
		else if(e->KeyValue == 27)	//при нажатии ecsape
		{
			action = 0;
			value = text->Text;
			this->Close();
		}
		
		
	}
	System::Void key_press(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		wchar_t k = e->KeyChar;
		if('<' == k || '>' == k || '|' == k || '\\' == k || '/' == k || '*' == k || '?' == k || '\"' == k || ':' == k)
			e->KeyChar = 0;
	}
	System::Void push_(System::Object^  sender, System::EventArgs^  e) 
	{
		Button^ b = dynamic_cast<Button^>(sender);
		if(1 == Convert::ToInt32(b->Tag))
			action = 1;
		else action = 0;
		value = text->Text;
		this->Close();
	}
};
}
