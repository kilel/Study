#pragma once


#include "clasa.h"

namespace lalala {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Form1
	///
	/// ��������! ��� ��������� ����� ����� ������ ���������� ����� ��������
	///          �������� ����� ����� �������� ("Resource File Name") ��� �������� ���������� ������������ �������,
	///          ���������� �� ����� ������� � ����������� .resx, �� ������� ������� ������ �����. � ��������� ������,
	///          ������������ �� ������ ��������� �������� � ���������������
	///          ���������, ��������������� ������ �����.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  ff;
	private: System::Windows::Forms::Button^  button;
	protected: 

	protected: 

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ff = (gcnew System::Windows::Forms::ComboBox());
			this->button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ff
			// 
			this->ff->FormattingEnabled = true;
			this->ff->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Blinky", L"Inky", L"Pinky", L"Clyde"});
			this->ff->Location = System::Drawing::Point(13, 13);
			this->ff->Name = L"ff";
			this->ff->Size = System::Drawing::Size(121, 21);
			this->ff->TabIndex = 10;
			this->ff->TabStop = false;
			this->ff->Text = L"�������� ���";
			// 
			// button
			// 
			this->button->Location = System::Drawing::Point(12, 403);
			this->button->Name = L"button";
			this->button->Size = System::Drawing::Size(28, 23);
			this->button->TabIndex = 11;
			this->button->Text = L"C";
			this->button->UseVisualStyleBackColor = true;
			this->button->Click += gcnew System::EventHandler(this, &Form1::button_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(506, 438);
			this->Controls->Add(this->button);
			this->Controls->Add(this->ff);
			this->Name = L"Form1";
			this->Text = L"Window";
			this->Click += gcnew System::EventHandler(this, &Form1::Form1_Click);
			this->ResumeLayout(false);

		}
#pragma endregion
public:
	Point h;
	Graphics ^g;
private: System::Void Form1_Click(System::Object^  sender, System::EventArgs^  e) 
	 {
		ghost ^gg;
		g = CreateGraphics();  
		h = PointToClient(Cursor->Position);
		switch(ff->SelectedIndex)
		{
			case -1: g->DrawString("�������� ��������!", gcnew Drawing::Font("Times", 30), Brushes::Red, 12, 60);break;
			case 0: gg = gcnew ghost(blinky);break;
			case 1: gg = gcnew ghost(inky);break;
			case 2: gg = gcnew ghost(pinky);break;
			case 3: gg = gcnew ghost(clyde);break;
		}
		if(ff->SelectedIndex >= 0)
		{
			gg->changeXY(h.X - 21, h.Y - 22);
			gg->print(g);
		}
		delete g;
		delete gg;

	 }
private: System::Void button_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Form1::Refresh();
	}
};
}

