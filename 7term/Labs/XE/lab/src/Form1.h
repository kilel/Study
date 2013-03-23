#pragma once
#include "plotTools.h"

namespace KSE_lab1 {

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
			
			pic_mouce_down = false;
			p = gcnew plotTools(pic->Width, pic->Height, 200, 200);
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
	private: System::Windows::Forms::PictureBox^  pic;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::NumericUpDown^  M2;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  M1;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  EPS;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  VY20;

	private: System::Windows::Forms::NumericUpDown^  Y20;
	private: System::Windows::Forms::NumericUpDown^  VX20;
	private: System::Windows::Forms::NumericUpDown^  X20;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  VY10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::NumericUpDown^  Y10;
	private: System::Windows::Forms::NumericUpDown^  VX10;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::NumericUpDown^  X10;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TrackBar^  Scale;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::NumericUpDown^  END_TIME;
	private: System::Windows::Forms::Label^  label12;
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pic = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->Scale = (gcnew System::Windows::Forms::TrackBar());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->VY20 = (gcnew System::Windows::Forms::NumericUpDown());
			this->Y20 = (gcnew System::Windows::Forms::NumericUpDown());
			this->VX20 = (gcnew System::Windows::Forms::NumericUpDown());
			this->X20 = (gcnew System::Windows::Forms::NumericUpDown());
			this->M2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->VY10 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->Y10 = (gcnew System::Windows::Forms::NumericUpDown());
			this->VX10 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->X10 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->M1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->EPS = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->END_TIME = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Scale))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VY20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Y20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VX20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->X20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->M2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VY10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Y10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VX10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->X10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->M1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EPS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->END_TIME))->BeginInit();
			this->SuspendLayout();
			// 
			// pic
			// 
			this->pic->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pic->Location = System::Drawing::Point(0, 0);
			this->pic->Name = L"pic";
			this->pic->Size = System::Drawing::Size(727, 501);
			this->pic->TabIndex = 0;
			this->pic->TabStop = false;
			this->pic->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pic_MouseDown);
			this->pic->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pic_MouseMove);
			this->pic->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pic_MouseUp);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->Scale);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Controls->Add(this->VY20);
			this->groupBox2->Controls->Add(this->Y20);
			this->groupBox2->Controls->Add(this->VX20);
			this->groupBox2->Controls->Add(this->X20);
			this->groupBox2->Controls->Add(this->M2);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->VY10);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->Y10);
			this->groupBox2->Controls->Add(this->VX10);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->X10);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->M1);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->END_TIME);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->EPS);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Right;
			this->groupBox2->Location = System::Drawing::Point(526, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(201, 501);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"input";
			// 
			// Scale
			// 
			this->Scale->Location = System::Drawing::Point(6, 444);
			this->Scale->Maximum = 500;
			this->Scale->Minimum = 1;
			this->Scale->Name = L"Scale";
			this->Scale->Size = System::Drawing::Size(189, 45);
			this->Scale->TabIndex = 0;
			this->Scale->Value = 100;
			this->Scale->Scroll += gcnew System::EventHandler(this, &Form1::Scale_Scroll);
			this->Scale->Leave += gcnew System::EventHandler(this, &Form1::Scale_Leave);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 383);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(164, 36);
			this->button2->TabIndex = 2;
			this->button2->Text = L"С анимацией движения";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 341);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(164, 36);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Сделать всё красиво и правильно";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// VY20
			// 
			this->VY20->DecimalPlaces = 7;
			this->VY20->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->VY20->Location = System::Drawing::Point(98, 303);
			this->VY20->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->VY20->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->VY20->Name = L"VY20";
			this->VY20->Size = System::Drawing::Size(78, 20);
			this->VY20->TabIndex = 1;
			this->VY20->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {6, 0, 0, 0});
			// 
			// Y20
			// 
			this->Y20->DecimalPlaces = 7;
			this->Y20->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->Y20->Location = System::Drawing::Point(97, 217);
			this->Y20->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->Y20->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->Y20->Name = L"Y20";
			this->Y20->Size = System::Drawing::Size(78, 20);
			this->Y20->TabIndex = 1;
			this->Y20->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			// 
			// VX20
			// 
			this->VX20->DecimalPlaces = 7;
			this->VX20->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->VX20->Location = System::Drawing::Point(97, 262);
			this->VX20->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->VX20->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->VX20->Name = L"VX20";
			this->VX20->Size = System::Drawing::Size(78, 20);
			this->VX20->TabIndex = 1;
			this->VX20->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			// 
			// X20
			// 
			this->X20->DecimalPlaces = 7;
			this->X20->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->X20->Location = System::Drawing::Point(96, 176);
			this->X20->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->X20->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->X20->Name = L"X20";
			this->X20->Size = System::Drawing::Size(78, 20);
			this->X20->TabIndex = 1;
			this->X20->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {18, 0, 0, 0});
			// 
			// M2
			// 
			this->M2->DecimalPlaces = 7;
			this->M2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->M2->Location = System::Drawing::Point(96, 134);
			this->M2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->M2->Name = L"M2";
			this->M2->Size = System::Drawing::Size(78, 20);
			this->M2->TabIndex = 1;
			this->M2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(95, 287);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(36, 13);
			this->label11->TabIndex = 0;
			this->label11->Text = L"vy2_0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(94, 201);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(30, 13);
			this->label7->TabIndex = 0;
			this->label7->Text = L"y2_0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(94, 246);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(36, 13);
			this->label10->TabIndex = 0;
			this->label10->Text = L"vx2_0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(93, 160);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(30, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"x2_0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(93, 118);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"m2";
			// 
			// VY10
			// 
			this->VY10->DecimalPlaces = 7;
			this->VY10->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->VY10->Location = System::Drawing::Point(14, 303);
			this->VY10->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->VY10->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->VY10->Name = L"VY10";
			this->VY10->Size = System::Drawing::Size(78, 20);
			this->VY10->TabIndex = 1;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 287);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(36, 13);
			this->label9->TabIndex = 0;
			this->label9->Text = L"vy1_0";
			// 
			// Y10
			// 
			this->Y10->DecimalPlaces = 7;
			this->Y10->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->Y10->Location = System::Drawing::Point(13, 217);
			this->Y10->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->Y10->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->Y10->Name = L"Y10";
			this->Y10->Size = System::Drawing::Size(78, 20);
			this->Y10->TabIndex = 1;
			this->Y10->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			// 
			// VX10
			// 
			this->VX10->DecimalPlaces = 7;
			this->VX10->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->VX10->Location = System::Drawing::Point(13, 262);
			this->VX10->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->VX10->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->VX10->Name = L"VX10";
			this->VX10->Size = System::Drawing::Size(78, 20);
			this->VX10->TabIndex = 1;
			this->VX10->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {6, 0, 0, System::Int32::MinValue});
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(11, 201);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(30, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"y1_0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(11, 246);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(36, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"vx1_0";
			// 
			// X10
			// 
			this->X10->DecimalPlaces = 7;
			this->X10->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->X10->Location = System::Drawing::Point(12, 176);
			this->X10->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->X10->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->X10->Name = L"X10";
			this->X10->Size = System::Drawing::Size(78, 20);
			this->X10->TabIndex = 1;
			this->X10->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {4, 0, 0, 0});
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 160);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"x1_0";
			// 
			// M1
			// 
			this->M1->DecimalPlaces = 7;
			this->M1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->M1->Location = System::Drawing::Point(12, 134);
			this->M1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->M1->Name = L"M1";
			this->M1->Size = System::Drawing::Size(78, 20);
			this->M1->TabIndex = 1;
			this->M1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 118);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"m1";
			// 
			// EPS
			// 
			this->EPS->DecimalPlaces = 7;
			this->EPS->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->EPS->Location = System::Drawing::Point(12, 91);
			this->EPS->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->EPS->Name = L"EPS";
			this->EPS->Size = System::Drawing::Size(78, 20);
			this->EPS->TabIndex = 1;
			this->EPS->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"accuracy";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(12, 36);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(48, 13);
			this->label12->TabIndex = 0;
			this->label12->Text = L"End time";
			// 
			// END_TIME
			// 
			this->END_TIME->DecimalPlaces = 7;
			this->END_TIME->Location = System::Drawing::Point(15, 52);
			this->END_TIME->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9000, 0, 0, 0});
			this->END_TIME->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->END_TIME->Name = L"END_TIME";
			this->END_TIME->Size = System::Drawing::Size(78, 20);
			this->END_TIME->TabIndex = 1;
			this->END_TIME->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(727, 501);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->pic);
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"lab1";
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Scale))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VY20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Y20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VX20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->X20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->M2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VY10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Y10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VX10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->X10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->M1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EPS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->END_TIME))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
public:
	bool pic_mouce_down;
	plotTools ^p;
	int cx, cy;
	double iter;
private: 
void update(){
	pic->Image = p->getCanvas();
}
double f1(PointF s1, PointF s2){
	double p = (s1.X - s2.X)*(s1.X - s2.X) + (s1.Y - s2.Y)*(s1.Y - s2.Y);
	if(Math::Abs(p) < 0.0000001)
		p = 0.0000001*Math::Sign(p);
	return (s1.X - s2.X)/Math::Pow(p, 1.5);
}
double f2(PointF s1, PointF s2){
	double p = (s1.X - s2.X)*(s1.X - s2.X) + (s1.Y - s2.Y)*(s1.Y - s2.Y);
	if(Math::Abs(p) < 0.0000001)
		p = 0.0000001*Math::Sign(p);
	return (s1.Y - s2.Y)/Math::Pow(p, 1.5);
}
void euler(PointF st1, PointF vst1, PointF st2, PointF vst2, double m1, double m2, double eps, double maxt){
	Line^ s1, ^v1, ^s2, ^v2;
	//double maxt = 10;
	int n = maxt/eps;
	/*int d = n/1000, i = 1;
	int j = d-1;*/
	s1 = gcnew Line(n);
	v1 = gcnew Line(n);
	s2 = gcnew Line(n);
	v2 = gcnew Line(n);
	s1[0] = st1;
	s2[0] = st2;
	v1[0] = vst1;
	v2[0] = vst2;
	for(int i = 1; i < n; i++){
		v1[i].X = v1[i-1].X - eps*f1(s1[i-1], s2[i-1])*m2;
		v2[i].X = v2[i-1].X + eps*f1(s1[i-1], s2[i-1])*m1;
		v1[i].Y = v1[i-1].Y - eps*f2(s1[i-1], s2[i-1])*m2;
		v2[i].Y = v2[i-1].Y + eps*f2(s1[i-1], s2[i-1])*m1;

		s1[i].X = s1[i-1].X + eps*v1[i-1].X;
		s1[i].Y = s1[i-1].Y + eps*v1[i-1].Y;
		s2[i].X = s2[i-1].X + eps*v2[i-1].X;
		s2[i].Y = s2[i-1].Y + eps*v2[i-1].Y;
		if(s1[i].X > 1000000 || s1[i].Y > 1000000 || s2[i].X > 1000000 || s2[i].Y > 1000000)
		{
			n = i;
			s1->Resize(s1,n);
			s1->Resize(s2,n);
			s1->Resize(v1,n);
			s1->Resize(v2,n);
			break;
		}
	}
	
	p->clearData();
	p->addCurve(s1,Pens::Black);
	p->addCurve(s2,Pens::Red);
	p->addPoint(s1[n-1], 3, Brushes::Black);
	p->addPoint(s2[n-1], 1, Brushes::Red);
	p->draw();
	update();
}
System::Void button1_Click(System::Object^  sender, System::EventArgs^  e){
	euler(
		PointF(X10->Value.ToDouble(X10->Value), Y10->Value.ToDouble(Y10->Value)),
		PointF(X10->Value.ToDouble(VX10->Value), Y10->Value.ToDouble(VY10->Value)),
		PointF(X20->Value.ToDouble(X20->Value), Y10->Value.ToDouble(Y20->Value)),
		PointF(X10->Value.ToDouble(VX20->Value), Y10->Value.ToDouble(VY20->Value)),
		M1->Value.ToDouble(M1->Value),M2->Value.ToDouble(M2->Value),
		EPS->Value.ToDouble(EPS->Value), 
		EPS->Value.ToDouble(END_TIME->Value)
		);
}

System::Void pic_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if(pic_mouce_down){
		p->setCentre(e->X-cx, e->Y-cy);
		cx = e->X; cy = e->Y;
		p->draw();
		update();
	}
}
System::Void pic_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	pic_mouce_down = true;
	cx = e->X; cy = e->Y;
}
System::Void pic_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	pic_mouce_down = false;
}

System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) {
	p->setCanvas(pic->Width, pic->Height);
	p->draw();
	update();
}
System::Void Scale_Scroll(System::Object^  sender, System::EventArgs^  e){
	p->setScale(PointF(Scale->Value/100., Scale->Value/100.));
	p->draw();
	update();
}
System::Void Scale_Leave(System::Object^  sender, System::EventArgs^  e) {
	//Scale->Focus();
}
System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	iter+=0.5;
	if(iter > EPS->Value.ToDouble(END_TIME->Value))
		timer1->Stop();
	euler(
		PointF(X10->Value.ToDouble(X10->Value), Y10->Value.ToDouble(Y10->Value)),
		PointF(VX10->Value.ToDouble(VX10->Value), VY10->Value.ToDouble(VY10->Value)),
		PointF(X20->Value.ToDouble(X20->Value), Y20->Value.ToDouble(Y20->Value)),
		PointF(VX20->Value.ToDouble(VX20->Value), VY20->Value.ToDouble(VY20->Value)),
		M1->Value.ToDouble(M1->Value),M2->Value.ToDouble(M2->Value),
		EPS->Value.ToDouble(EPS->Value), iter);
}
System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	
	
	if(iter > 0.1)
		timer1->Stop();
	else
		timer1->Start();
	iter = 0.1;
}
};
}

