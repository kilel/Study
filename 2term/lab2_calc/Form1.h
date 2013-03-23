#pragma once

#include <math.h>
#include <string>

long double first = 0, tt = 0;
int point = 1, ptr2 = 0, act = 0, gg = 1, zn = 0, to = 0, pre = -1;


namespace calc1 {

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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  ChangeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  tb;
	private: System::Windows::Forms::Button^  ravno;


	private: System::Windows::Forms::Button^  plus;




	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  minus;

	private: System::Windows::Forms::Button^  b3;

	private: System::Windows::Forms::Button^  b2;

	private: System::Windows::Forms::Button^  b1;


	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  umn;

	private: System::Windows::Forms::Button^  b6;

	private: System::Windows::Forms::Button^  b5;

	private: System::Windows::Forms::Button^  b4;


	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  ydal;

	private: System::Windows::Forms::Button^  b9;

	private: System::Windows::Forms::Button^  b8;

	private: System::Windows::Forms::Button^  b7;
	internal: System::Windows::Forms::Button^  c;

	private: 







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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ChangeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tb = (gcnew System::Windows::Forms::TextBox());
			this->ravno = (gcnew System::Windows::Forms::Button());
			this->plus = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->minus = (gcnew System::Windows::Forms::Button());
			this->b3 = (gcnew System::Windows::Forms::Button());
			this->b2 = (gcnew System::Windows::Forms::Button());
			this->b1 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->umn = (gcnew System::Windows::Forms::Button());
			this->b6 = (gcnew System::Windows::Forms::Button());
			this->b5 = (gcnew System::Windows::Forms::Button());
			this->b4 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->ydal = (gcnew System::Windows::Forms::Button());
			this->b9 = (gcnew System::Windows::Forms::Button());
			this->b8 = (gcnew System::Windows::Forms::Button());
			this->b7 = (gcnew System::Windows::Forms::Button());
			this->c = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::Control;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->ChangeToolStripMenuItem, 
				this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->menuStrip1->Size = System::Drawing::Size(196, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ChangeToolStripMenuItem
			// 
			this->ChangeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->copyToolStripMenuItem, 
				this->pasteToolStripMenuItem});
			this->ChangeToolStripMenuItem->Name = L"ChangeToolStripMenuItem";
			this->ChangeToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->ChangeToolStripMenuItem->Text = L"Правка";
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->copyToolStripMenuItem->Size = System::Drawing::Size(185, 22);
			this->copyToolStripMenuItem->Text = L"Копировать";
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::copyToolStripMenuItem_Click);
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(185, 22);
			this->pasteToolStripMenuItem->Text = L"Вставить";
			this->pasteToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::pasteToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->aboutToolStripMenuItem});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(62, 20);
			this->helpToolStripMenuItem->Text = L"Справка";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// tb
			// 
			this->tb->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tb->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->tb->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->tb->Location = System::Drawing::Point(5, 27);
			this->tb->MaxLength = 25;
			this->tb->Name = L"tb";
			this->tb->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->tb->Size = System::Drawing::Size(184, 20);
			this->tb->TabIndex = 1;
			this->tb->TabStop = false;
			this->tb->Tag = L"111";
			this->tb->Text = L"0";
			this->tb->Click += gcnew System::EventHandler(this, &Form1::tb_Click);
			this->tb->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// ravno
			// 
			this->ravno->ForeColor = System::Drawing::Color::Blue;
			this->ravno->Location = System::Drawing::Point(157, 200);
			this->ravno->Name = L"ravno";
			this->ravno->Size = System::Drawing::Size(32, 30);
			this->ravno->TabIndex = 0;
			this->ravno->Text = L"=";
			this->ravno->UseVisualStyleBackColor = true;
			this->ravno->Click += gcnew System::EventHandler(this, &Form1::rav_Click);
			this->ravno->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// plus
			// 
			this->plus->ForeColor = System::Drawing::Color::Red;
			this->plus->Location = System::Drawing::Point(119, 200);
			this->plus->Name = L"plus";
			this->plus->Size = System::Drawing::Size(32, 30);
			this->plus->TabIndex = 2;
			this->plus->TabStop = false;
			this->plus->Tag = L"1";
			this->plus->Text = L"+";
			this->plus->UseVisualStyleBackColor = true;
			this->plus->Click += gcnew System::EventHandler(this, &Form1::act_Click);
			this->plus->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// button6
			// 
			this->button6->ForeColor = System::Drawing::Color::Blue;
			this->button6->Location = System::Drawing::Point(81, 200);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(32, 30);
			this->button6->TabIndex = 2;
			this->button6->TabStop = false;
			this->button6->Text = L",";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::zap_Click);
			this->button6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// button7
			// 
			this->button7->ForeColor = System::Drawing::Color::Blue;
			this->button7->Location = System::Drawing::Point(43, 200);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(32, 30);
			this->button7->TabIndex = 2;
			this->button7->TabStop = false;
			this->button7->Tag = L"3";
			this->button7->Text = L"+/-";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::act_2);
			this->button7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// button8
			// 
			this->button8->ForeColor = System::Drawing::Color::Blue;
			this->button8->Location = System::Drawing::Point(5, 200);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(32, 30);
			this->button8->TabIndex = 2;
			this->button8->TabStop = false;
			this->button8->Text = L"0";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::b1_Click);
			this->button8->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// button2
			// 
			this->button2->ForeColor = System::Drawing::Color::Blue;
			this->button2->Location = System::Drawing::Point(157, 164);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(32, 30);
			this->button2->TabIndex = 2;
			this->button2->TabStop = false;
			this->button2->Tag = L"2";
			this->button2->Text = L"1/x";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::act_2);
			this->button2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// minus
			// 
			this->minus->ForeColor = System::Drawing::Color::Red;
			this->minus->Location = System::Drawing::Point(119, 164);
			this->minus->Name = L"minus";
			this->minus->Size = System::Drawing::Size(32, 30);
			this->minus->TabIndex = 2;
			this->minus->TabStop = false;
			this->minus->Tag = L"2";
			this->minus->Text = L"-";
			this->minus->UseVisualStyleBackColor = true;
			this->minus->Click += gcnew System::EventHandler(this, &Form1::act_Click);
			this->minus->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// b3
			// 
			this->b3->ForeColor = System::Drawing::Color::Blue;
			this->b3->Location = System::Drawing::Point(81, 164);
			this->b3->Name = L"b3";
			this->b3->Size = System::Drawing::Size(32, 30);
			this->b3->TabIndex = 2;
			this->b3->TabStop = false;
			this->b3->Text = L"3";
			this->b3->UseVisualStyleBackColor = true;
			this->b3->Click += gcnew System::EventHandler(this, &Form1::b1_Click);
			this->b3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// b2
			// 
			this->b2->ForeColor = System::Drawing::Color::Blue;
			this->b2->Location = System::Drawing::Point(43, 164);
			this->b2->Name = L"b2";
			this->b2->Size = System::Drawing::Size(32, 30);
			this->b2->TabIndex = 2;
			this->b2->TabStop = false;
			this->b2->Text = L"2";
			this->b2->UseVisualStyleBackColor = true;
			this->b2->Click += gcnew System::EventHandler(this, &Form1::b1_Click);
			this->b2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// b1
			// 
			this->b1->ForeColor = System::Drawing::Color::Blue;
			this->b1->Location = System::Drawing::Point(5, 164);
			this->b1->Name = L"b1";
			this->b1->Size = System::Drawing::Size(32, 30);
			this->b1->TabIndex = 2;
			this->b1->TabStop = false;
			this->b1->Text = L"1";
			this->b1->UseVisualStyleBackColor = true;
			this->b1->Click += gcnew System::EventHandler(this, &Form1::b1_Click);
			this->b1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// button13
			// 
			this->button13->ForeColor = System::Drawing::Color::Blue;
			this->button13->Location = System::Drawing::Point(157, 128);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(32, 30);
			this->button13->TabIndex = 2;
			this->button13->TabStop = false;
			this->button13->Tag = L"5";
			this->button13->Text = L"%";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::act_Click);
			this->button13->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// umn
			// 
			this->umn->ForeColor = System::Drawing::Color::Red;
			this->umn->Location = System::Drawing::Point(119, 128);
			this->umn->Name = L"umn";
			this->umn->Size = System::Drawing::Size(32, 30);
			this->umn->TabIndex = 2;
			this->umn->TabStop = false;
			this->umn->Tag = L"3";
			this->umn->Text = L"*";
			this->umn->UseVisualStyleBackColor = true;
			this->umn->Click += gcnew System::EventHandler(this, &Form1::act_Click);
			this->umn->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// b6
			// 
			this->b6->ForeColor = System::Drawing::Color::Blue;
			this->b6->Location = System::Drawing::Point(81, 128);
			this->b6->Name = L"b6";
			this->b6->Size = System::Drawing::Size(32, 30);
			this->b6->TabIndex = 2;
			this->b6->TabStop = false;
			this->b6->Text = L"6";
			this->b6->UseVisualStyleBackColor = true;
			this->b6->Click += gcnew System::EventHandler(this, &Form1::b1_Click);
			this->b6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// b5
			// 
			this->b5->ForeColor = System::Drawing::Color::Blue;
			this->b5->Location = System::Drawing::Point(43, 128);
			this->b5->Name = L"b5";
			this->b5->Size = System::Drawing::Size(32, 30);
			this->b5->TabIndex = 2;
			this->b5->TabStop = false;
			this->b5->Text = L"5";
			this->b5->UseVisualStyleBackColor = true;
			this->b5->Click += gcnew System::EventHandler(this, &Form1::b1_Click);
			this->b5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// b4
			// 
			this->b4->ForeColor = System::Drawing::Color::Blue;
			this->b4->Location = System::Drawing::Point(5, 128);
			this->b4->Name = L"b4";
			this->b4->Size = System::Drawing::Size(32, 30);
			this->b4->TabIndex = 2;
			this->b4->TabStop = false;
			this->b4->Text = L"4";
			this->b4->UseVisualStyleBackColor = true;
			this->b4->Click += gcnew System::EventHandler(this, &Form1::b1_Click);
			this->b4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// button19
			// 
			this->button19->ForeColor = System::Drawing::Color::Blue;
			this->button19->Location = System::Drawing::Point(157, 92);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(32, 30);
			this->button19->TabIndex = 2;
			this->button19->TabStop = false;
			this->button19->Tag = L"1";
			this->button19->Text = L"sqrt";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &Form1::act_2);
			this->button19->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// ydal
			// 
			this->ydal->ForeColor = System::Drawing::Color::Red;
			this->ydal->Location = System::Drawing::Point(119, 92);
			this->ydal->Name = L"ydal";
			this->ydal->Size = System::Drawing::Size(32, 30);
			this->ydal->TabIndex = 2;
			this->ydal->TabStop = false;
			this->ydal->Tag = L"4";
			this->ydal->Text = L"/";
			this->ydal->UseVisualStyleBackColor = true;
			this->ydal->Click += gcnew System::EventHandler(this, &Form1::act_Click);
			this->ydal->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// b9
			// 
			this->b9->ForeColor = System::Drawing::Color::Blue;
			this->b9->Location = System::Drawing::Point(81, 92);
			this->b9->Name = L"b9";
			this->b9->Size = System::Drawing::Size(32, 30);
			this->b9->TabIndex = 2;
			this->b9->TabStop = false;
			this->b9->Text = L"9";
			this->b9->UseVisualStyleBackColor = true;
			this->b9->Click += gcnew System::EventHandler(this, &Form1::b1_Click);
			this->b9->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// b8
			// 
			this->b8->ForeColor = System::Drawing::Color::Blue;
			this->b8->Location = System::Drawing::Point(43, 92);
			this->b8->Name = L"b8";
			this->b8->Size = System::Drawing::Size(32, 30);
			this->b8->TabIndex = 2;
			this->b8->TabStop = false;
			this->b8->Text = L"8";
			this->b8->UseVisualStyleBackColor = true;
			this->b8->Click += gcnew System::EventHandler(this, &Form1::b1_Click);
			this->b8->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// b7
			// 
			this->b7->ForeColor = System::Drawing::Color::Blue;
			this->b7->Location = System::Drawing::Point(5, 92);
			this->b7->Name = L"b7";
			this->b7->Size = System::Drawing::Size(32, 30);
			this->b7->TabIndex = 2;
			this->b7->TabStop = false;
			this->b7->Text = L"7";
			this->b7->UseVisualStyleBackColor = true;
			this->b7->Click += gcnew System::EventHandler(this, &Form1::b1_Click);
			this->b7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// c
			// 
			this->c->ForeColor = System::Drawing::Color::Red;
			this->c->Location = System::Drawing::Point(5, 56);
			this->c->Name = L"c";
			this->c->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->c->Size = System::Drawing::Size(184, 30);
			this->c->TabIndex = 2;
			this->c->TabStop = false;
			this->c->Text = L"Clean All";
			this->c->UseVisualStyleBackColor = true;
			this->c->Click += gcnew System::EventHandler(this, &Form1::c_Click);
			this->c->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(196, 233);
			this->Controls->Add(this->c);
			this->Controls->Add(this->b7);
			this->Controls->Add(this->b4);
			this->Controls->Add(this->b1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->b8);
			this->Controls->Add(this->b5);
			this->Controls->Add(this->b2);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->b9);
			this->Controls->Add(this->b6);
			this->Controls->Add(this->b3);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->ydal);
			this->Controls->Add(this->umn);
			this->Controls->Add(this->minus);
			this->Controls->Add(this->plus);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->ravno);
			this->Controls->Add(this->tb);
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::Color::Blue;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Calc demo";
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::b1_KeyPress);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void b1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			Button^ b= dynamic_cast <Button^> (sender);
			if((!ptr2) && (gg))
			{
				act = 0;
				first = 0;
				ptr2 = 1;
				tt = 0;
				gg = 1;
				to = 0;
			}
			if(!point)
			{
				tb->Text =  L"0";
				gg = 1;
			}
			int n;
			
			n = Convert::ToDouble(tb->Text);
			if(pre == -1)
			{
				if((!n)&&(gg))
					tb->Text = b->Text;
				else if (b) 
					tb->Text = tb->Text + b->Text;
			}
			else
			{
				if((!n)&&(gg))
					tb->Text = Convert::ToString( pre );
				else 
					tb->Text = tb->Text + Convert::ToString( pre );
			}
			point = 1;
			zn = 0;
			 ravno->Focus();
		 }

private: System::Void act_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
				if(to)
					ptr2 = 1;
				if(!zn)
				{

					rav_Click(sender, e);
					if(!first)
						first = Convert::ToDouble(tb->Text);
					zn = 1;
					
				}
				int n, f;
				if(act)
					ptr2 = 1;
				if(pre)
				{
					Button^ b= dynamic_cast <Button^> (sender);
					act = Convert::ToInt32(b->Tag);
				}
				to = 0;
				 ravno->Focus();
				
		 }
private: System::Void rav_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			int f;
			double k;
			if(((tt)&&(!ptr2))||(to))
				first = Convert::ToDouble(tb->Text);
			if((!tt)||(!to))
				tt = Convert::ToDouble(tb->Text);
			
			switch (act)
			{
			case 1: k = first + tt; break;
			case 2: k = first - tt; break;
			case 3: k = first * tt; break;
			case 4: k = first / tt; break;
			case 5: k = first * 0.01 * tt; break;
			}
			if(act)
			{
				first = k;
				tb->Text = Convert::ToString(k);
			}
			point = 0;
			ptr2 = 1;
			if(act)
				ptr2 = 0;
			
			if(!ptr2)
				to = 1;
			zn = 1;	
			 ravno->Focus();
		}

private: System::Void zap_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(gg)
			 {
				 tb->Text = tb->Text + ",";
				 gg = 0;
			}
			 zn = 0;
			  ravno->Focus();
		 }


private: System::Void act_2(System::Object^  sender, System::EventArgs^  e) 
		 {
			long double n;
			Button^ b= dynamic_cast <Button^> (sender);
			switch (Convert::ToInt32(b->Tag))
			{
				case 1:	n = sqrt(Convert::ToDouble(tb->Text)); break;
				case 2: n = 1/(Convert::ToDouble(tb->Text)); break;
				case 3: n = -1*Convert::ToDouble(tb->Text); break;
			}
			tb->Text = Convert::ToString((double)n);
			 ravno->Focus();
		 }

private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 
			 MessageBox::Show("Проект Кислицына Ильи. ПМ-11, 2010",
				 "Калькулятор 1.0",MessageBoxButtons::OK,MessageBoxIcon::Information);
			  ravno->Focus();
		 }
private: System::Void copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 tb->SelectAll();
			 tb->Copy();
			  ravno->Focus();
		 }
private: System::Void pasteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 tb->Text = L"";
			 tb->Paste();
			  ravno->Focus();
		 }

private: System::Void b1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
		 {
			 char c = e->KeyChar;
			 if(!(((c >= '0') && (c <= '9')) || ((c == ',')||(c == 8))))
				 e->KeyChar = 0;
			 
			 else if((c >= '0') && (c <= '9')) 
			 {
				 pre = c - '0';
				 b1_Click(sender, e);
				 pre = -1;
			 }
			 else if(c == ',')
				 zap_Click(sender, e);
			 
			 switch (c)
			 {
				 case '+': 
					 {
						pre = 0;
						act = 1;
						act_Click(sender, e);
						pre = -1;
					 }break;
				 case '-': 
					 {
						pre = 0;
						act = 2;
						act_Click(sender, e);
						pre = -1;
					 }break;
				 case '*': 
					 {
						pre = 0;
						act_Click(sender, e);
						act = 3;
						pre = -1;
					 }break;
				 case '/': 
					 {
						pre = 0;			
						act_Click(sender, e);
						act = 4;
						pre = -1;
					 }break;
				 case 13: rav_Click(sender, e); break;
			 }			 	 
		}	 
private: System::Void c_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
				first = 0;
				tt = 0;
				point = 1;
				ptr2 = 0;
				act = 0;
				gg = 1;
				tb->Text = L"0";
				zn = 0;
				to = 0;
				ravno->Focus();
		 }


private: System::Void tb_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ravno->Focus();
		 }

};
}

