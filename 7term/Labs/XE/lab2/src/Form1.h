#pragma once
#include "plotTools.h"

namespace lab2 {

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
			caclCompleted = true;
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
	private: System::Windows::Forms::NumericUpDown^  Epsilon;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  Lambda;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  EPS;

	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::NumericUpDown^  Y20;
	private: System::Windows::Forms::NumericUpDown^  Gamma2;

	private: System::Windows::Forms::NumericUpDown^  X20;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label5;


	private: System::Windows::Forms::NumericUpDown^  Y10;
	private: System::Windows::Forms::NumericUpDown^  Gamma1;

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
	private: System::Windows::Forms::RadioButton^  Op2;
	private: System::Windows::Forms::RadioButton^  Op1;
	private: System::Windows::Forms::Panel^  panel;
	private: System::Windows::Forms::TrackBar^  SPEED;
	private: System::Windows::Forms::Label^  label9;

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
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->SPEED = (gcnew System::Windows::Forms::TrackBar());
			this->Op2 = (gcnew System::Windows::Forms::RadioButton());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->Op1 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->EPS = (gcnew System::Windows::Forms::NumericUpDown());
			this->END_TIME = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Y20 = (gcnew System::Windows::Forms::NumericUpDown());
			this->Lambda = (gcnew System::Windows::Forms::NumericUpDown());
			this->Gamma2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->X20 = (gcnew System::Windows::Forms::NumericUpDown());
			this->X10 = (gcnew System::Windows::Forms::NumericUpDown());
			this->Epsilon = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->Gamma1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Y10 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Scale = (gcnew System::Windows::Forms::TrackBar());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SPEED))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EPS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->END_TIME))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Y20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Lambda))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Gamma2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->X20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->X10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Epsilon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Gamma1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Y10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Scale))->BeginInit();
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
			this->groupBox2->Controls->Add(this->SPEED);
			this->groupBox2->Controls->Add(this->panel);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->Scale);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Right;
			this->groupBox2->Location = System::Drawing::Point(526, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(201, 501);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"input";
			// 
			// panel
			// 
			this->panel->Controls->Add(this->Op2);
			this->panel->Controls->Add(this->label12);
			this->panel->Controls->Add(this->Op1);
			this->panel->Controls->Add(this->label1);
			this->panel->Controls->Add(this->EPS);
			this->panel->Controls->Add(this->END_TIME);
			this->panel->Controls->Add(this->label2);
			this->panel->Controls->Add(this->Y20);
			this->panel->Controls->Add(this->Lambda);
			this->panel->Controls->Add(this->Gamma2);
			this->panel->Controls->Add(this->label4);
			this->panel->Controls->Add(this->X20);
			this->panel->Controls->Add(this->X10);
			this->panel->Controls->Add(this->Epsilon);
			this->panel->Controls->Add(this->label8);
			this->panel->Controls->Add(this->label7);
			this->panel->Controls->Add(this->label6);
			this->panel->Controls->Add(this->label10);
			this->panel->Controls->Add(this->Gamma1);
			this->panel->Controls->Add(this->label5);
			this->panel->Controls->Add(this->Y10);
			this->panel->Controls->Add(this->label3);
			this->panel->Location = System::Drawing::Point(6, 19);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(189, 305);
			this->panel->TabIndex = 4;
			// 
			// SPEED
			// 
			this->SPEED->Location = System::Drawing::Point(150, 341);
			this->SPEED->Maximum = 1000;
			this->SPEED->Minimum = 3;
			this->SPEED->Name = L"SPEED";
			this->SPEED->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->SPEED->Size = System::Drawing::Size(45, 78);
			this->SPEED->SmallChange = 3;
			this->SPEED->TabIndex = 5;
			this->SPEED->Value = 3;
			// 
			// Op2
			// 
			this->Op2->AutoSize = true;
			this->Op2->Location = System::Drawing::Point(7, 275);
			this->Op2->Name = L"Op2";
			this->Op2->Size = System::Drawing::Size(145, 17);
			this->Op2->TabIndex = 3;
			this->Op2->Text = L"Vij = epsilon*sin(lambda*t)";
			this->Op2->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(133, 328);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(63, 13);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Paint speed";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(3, 1);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(48, 13);
			this->label12->TabIndex = 0;
			this->label12->Text = L"End time";
			// 
			// Op1
			// 
			this->Op1->AutoSize = true;
			this->Op1->Checked = true;
			this->Op1->Location = System::Drawing::Point(7, 252);
			this->Op1->Name = L"Op1";
			this->Op1->Size = System::Drawing::Size(69, 17);
			this->Op1->TabIndex = 3;
			this->Op1->TabStop = true;
			this->Op1->Text = L"V1=V2=0";
			this->Op1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"accuracy";
			// 
			// EPS
			// 
			this->EPS->DecimalPlaces = 7;
			this->EPS->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->EPS->Location = System::Drawing::Point(6, 56);
			this->EPS->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->EPS->Name = L"EPS";
			this->EPS->Size = System::Drawing::Size(78, 20);
			this->EPS->TabIndex = 1;
			this->EPS->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			// 
			// END_TIME
			// 
			this->END_TIME->DecimalPlaces = 7;
			this->END_TIME->Location = System::Drawing::Point(6, 18);
			this->END_TIME->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9000, 0, 0, 0});
			this->END_TIME->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->END_TIME->Name = L"END_TIME";
			this->END_TIME->Size = System::Drawing::Size(78, 20);
			this->END_TIME->TabIndex = 1;
			this->END_TIME->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"lambda";
			// 
			// Y20
			// 
			this->Y20->DecimalPlaces = 7;
			this->Y20->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->Y20->Location = System::Drawing::Point(91, 181);
			this->Y20->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->Y20->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->Y20->Name = L"Y20";
			this->Y20->Size = System::Drawing::Size(78, 20);
			this->Y20->TabIndex = 1;
			// 
			// Lambda
			// 
			this->Lambda->DecimalPlaces = 7;
			this->Lambda->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->Lambda->Location = System::Drawing::Point(6, 98);
			this->Lambda->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->Lambda->Name = L"Lambda";
			this->Lambda->Size = System::Drawing::Size(78, 20);
			this->Lambda->TabIndex = 1;
			this->Lambda->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 65536});
			// 
			// Gamma2
			// 
			this->Gamma2->DecimalPlaces = 7;
			this->Gamma2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->Gamma2->Location = System::Drawing::Point(91, 226);
			this->Gamma2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->Gamma2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->Gamma2->Name = L"Gamma2";
			this->Gamma2->Size = System::Drawing::Size(78, 20);
			this->Gamma2->TabIndex = 1;
			this->Gamma2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {6283184, 0, 0, 393216});
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(4, 124);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"x1_0";
			// 
			// X20
			// 
			this->X20->DecimalPlaces = 7;
			this->X20->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->X20->Location = System::Drawing::Point(90, 140);
			this->X20->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->X20->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->X20->Name = L"X20";
			this->X20->Size = System::Drawing::Size(78, 20);
			this->X20->TabIndex = 1;
			this->X20->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			// 
			// X10
			// 
			this->X10->DecimalPlaces = 7;
			this->X10->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->X10->Location = System::Drawing::Point(6, 140);
			this->X10->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->X10->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->X10->Name = L"X10";
			this->X10->Size = System::Drawing::Size(78, 20);
			this->X10->TabIndex = 1;
			this->X10->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// Epsilon
			// 
			this->Epsilon->DecimalPlaces = 7;
			this->Epsilon->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->Epsilon->Location = System::Drawing::Point(90, 98);
			this->Epsilon->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->Epsilon->Name = L"Epsilon";
			this->Epsilon->Size = System::Drawing::Size(78, 20);
			this->Epsilon->TabIndex = 1;
			this->Epsilon->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 65536});
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(5, 209);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(25, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Г_1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(88, 165);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(30, 13);
			this->label7->TabIndex = 0;
			this->label7->Text = L"y2_0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(5, 165);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(30, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"y1_0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(88, 210);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(25, 13);
			this->label10->TabIndex = 0;
			this->label10->Text = L"Г_2";
			// 
			// Gamma1
			// 
			this->Gamma1->DecimalPlaces = 7;
			this->Gamma1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->Gamma1->Location = System::Drawing::Point(7, 226);
			this->Gamma1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->Gamma1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->Gamma1->Name = L"Gamma1";
			this->Gamma1->Size = System::Drawing::Size(78, 20);
			this->Gamma1->TabIndex = 1;
			this->Gamma1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {6283184, 0, 0, 393216});
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(87, 124);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(30, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"x2_0";
			// 
			// Y10
			// 
			this->Y10->DecimalPlaces = 7;
			this->Y10->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->Y10->Location = System::Drawing::Point(7, 181);
			this->Y10->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->Y10->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->Y10->Name = L"Y10";
			this->Y10->Size = System::Drawing::Size(78, 20);
			this->Y10->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(87, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"epsilon";
			// 
			// Scale
			// 
			this->Scale->Location = System::Drawing::Point(6, 425);
			this->Scale->Maximum = 1000;
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
			this->button2->Size = System::Drawing::Size(132, 36);
			this->button2->TabIndex = 2;
			this->button2->Text = L"С анимацией движения";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 341);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(132, 36);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Сделать всё красиво и правильно";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
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
			this->Text = L"lab2";
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SPEED))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EPS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->END_TIME))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Y20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Lambda))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Gamma2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->X20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->X10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Epsilon))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Gamma1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Y10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Scale))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
public:
	bool pic_mouce_down;
	plotTools ^p;
	int cx, cy;
	int iter;
	bool caclCompleted;
private: 
void update(){
	pic->Image = p->getCanvas();
}
double f1(PointF s1, PointF s2){
	double p = (s1.X - s2.X)*(s1.X - s2.X) + (s1.Y - s2.Y)*(s1.Y - s2.Y);
	if(Math::Abs(p) < 0.0000001)
		p = 0.0000001;
	return (s1.X - s2.X)/p;
}
double f2(PointF s1, PointF s2){
	double p = (s1.X - s2.X)*(s1.X - s2.X) + (s1.Y - s2.Y)*(s1.Y - s2.Y);
	if(Math::Abs(p) < 0.0000001)
		p = 0.0000001;
	return (s1.Y - s2.Y)/p;
}
void rungeKuttMeth(double g1, double g2, double eps, double lambda, double h, int iterCount, double currTime){
	//
	PointF temps1, temps2;
	temps1.X = p->curve[0][p->limCurve[0]-1].X;
	temps1.Y = p->curve[0][p->limCurve[0]-1].Y; 
	temps2.X = p->curve[1][p->limCurve[1]-1].X; 
	temps2.Y = p->curve[1][p->limCurve[1]-1].Y;
	if(p->limCurve[0] == p->curve[0]->Length)
		return;
	double k[5][5] = {0};
	PointF fPoint1 = temps1, fPoint2 = temps2;
	double v = 0;
	double pi = 3.1415926535;
	pi*=2;
	g1/=pi;
	g2/=pi;
	for(int i = 0; i < iterCount; i++){
		fPoint1 = PointF(temps1.X, temps1.Y);
		fPoint2 = PointF(temps2.X, temps2.Y);
		v = eps*sin(lambda*(currTime + i*h));
		k[1][1] = h*(v	-	g2*f2(fPoint1,fPoint2));
		k[2][1] = h*(v	+	g2*f1(fPoint1,fPoint2));
		k[3][1] = h*(v	+	g1*f2(fPoint1,fPoint2));
		k[4][1] = h*(v	-	g1*f1(fPoint1,fPoint2));
		///2 step
		fPoint1 = PointF(temps1.X + 0.5*k[1][1], temps1.Y + 0.5*k[2][1]);
		fPoint2 = PointF(temps2.X + 0.5*k[3][1], temps2.Y + 0.5*k[4][1]);
		v = eps*sin(lambda*(currTime + i*h + 0.5*h));
		k[1][2] = h*(v	-	g2*f2(fPoint1,fPoint2));
		k[2][2] = h*(v	+	g2*f1(fPoint1,fPoint2));
		k[3][2] = h*(v	+	g1*f2(fPoint1,fPoint2));
		k[4][2] = h*(v	-	g1*f1(fPoint1,fPoint2));
		///
		fPoint1 = PointF(temps1.X + 0.5*k[1][2], temps1.Y + 0.5*k[2][2]);
		fPoint2 = PointF(temps2.X + 0.5*k[3][2], temps2.Y + 0.5*k[4][2]);
		k[1][3] = h*(v	-	g2*f2(fPoint1,fPoint2));
		k[2][3] = h*(v	+	g2*f1(fPoint1,fPoint2));
		k[3][3] = h*(v	+	g1*f2(fPoint1,fPoint2));
		k[4][3] = h*(v	-	g1*f1(fPoint1,fPoint2));
		///
		fPoint1 = PointF(temps1.X + k[1][3], temps1.Y + k[2][3]);
		fPoint2 = PointF(temps2.X + k[3][3], temps2.Y + k[4][3]);
		v = eps*sin(lambda*(currTime + i*h + h));
		k[1][4] = h*(v	-	g2*f2(fPoint1,fPoint2));
		k[2][4] = h*(v	+	g2*f1(fPoint1,fPoint2));
		k[3][4] = h*(v	+	g1*f2(fPoint1,fPoint2));
		k[4][4] = h*(v	-	g1*f1(fPoint1,fPoint2));
		///
		p->curve[0][p->limCurve[0]].X = temps1.X + (k[1][1] + k[1][2] + k[1][3] + k[1][4])/6.;
		p->curve[0][p->limCurve[0]].Y = temps1.Y + (k[2][1] + k[2][2] + k[2][3] + k[2][4])/6.;
		p->curve[1][p->limCurve[1]].X = temps2.X + (k[3][1] + k[3][2] + k[3][3] + k[3][4])/6.;
		p->curve[1][p->limCurve[1]].Y = temps2.Y + (k[4][1] + k[4][2] + k[4][3] + k[4][4])/6.;
		/*
		///x1
		k[1][1] = h*(eps*sin(lambda*(currTime + i*h))			-	g2*f2(temps1,temps2));
		k[1][2] = h*(eps*sin(lambda*(currTime + i*h + 0.5*h)) -	g2*f2(PointF(temps1.X + k[1]*0.5, temps1.Y), temps2));
		k[1][3] = h*(eps*sin(lambda*(currTime + i*h + 0.5*h)) -	g2*f2(PointF(temps1.X + k[2]*0.5, temps1.Y), temps2));
		k[1][4] = h*(eps*sin(lambda*(currTime + i*h + h))		-	g2*f2(PointF(temps1.X + k[3], temps1.Y), temps2));
		p->curve[0][p->limCurve[0]].X = temps1.X + (k[1] + k[2] + k[3] + k[4])/6.;
		///y1
		k[2][1] = h*(eps*sin(lambda*(currTime + i*h))			+	g2*f1(temps1,temps2));
		k[2][2] = h*(eps*sin(lambda*(currTime + i*h + 0.5*h)) +	g2*f1(PointF(temps1.X, temps1.Y + k[1]*0.5), temps2));
		k[2][3] = h*(eps*sin(lambda*(currTime + i*h + 0.5*h)) +	g2*f1(PointF(temps1.X, temps1.Y + k[2]*0.5), temps2));
		k[2][4] = h*(eps*sin(lambda*(currTime + i*h + h))		+	g2*f1(PointF(temps1.X, temps1.Y + k[3]), temps2));
		p->curve[0][p->limCurve[0]].Y = temps1.Y + (k[1] + k[2] + k[3] + k[4])/6.;
		///x2
		k[3][1] = h*(eps*sin(lambda*(currTime + i*h))			+	g1*f2(temps1,temps2));
		k[3][2] = h*(eps*sin(lambda*(currTime + i*h + 0.5*h)) +	g1*f2(temps1, PointF(temps2.X + k[1]*0.5, temps2.Y)));
		k[3][3] = h*(eps*sin(lambda*(currTime + i*h + 0.5*h)) +	g1*f2(temps1, PointF(temps2.X + k[2]*0.5, temps2.Y)));
		k[3][4] = h*(eps*sin(lambda*(currTime + i*h + h))		+	g1*f2(temps1, PointF(temps2.X + k[3], temps2.Y)));
		p->curve[1][p->limCurve[1]].X = temps2.X + (k[1] + k[2] + k[3] + k[4])/6.;
		///y2
		k[4][1] = h*(eps*sin(lambda*(currTime + i*h))			-	g1*f1(temps1,temps2));
		k[4][2] = h*(eps*sin(lambda*(currTime + i*h + 0.5*h)) +	g1*f1(temps1, PointF(temps2.X, temps2.Y + k[1]*0.5)));
		k[4][3] = h*(eps*sin(lambda*(currTime + i*h + 0.5*h)) +	g1*f1(temps1, PointF(temps2.X, temps2.Y + k[2]*0.5)));
		k[4][4] = h*(eps*sin(lambda*(currTime + i*h + h))		+	g1*f1(temps1, PointF(temps2.X, temps2.Y + k[3])));
		p->curve[0][p->limCurve[0]].Y = temps2.Y + (k[1] + k[2] + k[3] + k[4])/6.;
		///
		*/
		temps1.X = p->curve[0][p->limCurve[0]].X;
		temps1.Y = p->curve[0][p->limCurve[0]].Y;
		temps2.X = p->curve[1][p->limCurve[1]].X;
		temps2.Y = p->curve[1][p->limCurve[1]].Y;
	}
	p->limCurve[0]++;
	p->limCurve[1]++;
}
void vortex(PointF st1, PointF st2, int vType, double g1, double g2, double eps, double lambda, double accuracy, double maxT, int stopIterNum){
	Line^ s1, ^v1, ^s2, ^s3;
	int n = maxT/accuracy;
	int maxCountIter = 1, additionPerIter = 1;
	maxCountIter = maxT*10;
	additionPerIter = n/maxCountIter == 0 ? 1 : n/maxCountIter;
	if(vType == 0)
		lambda = 0;
	if(caclCompleted == true){//ещё нет ничего на вывод, создаём
		p->clearData();
		s1 = gcnew Line(maxCountIter+1);
		s2 = gcnew Line(maxCountIter+1);
		s3 = gcnew Line(maxCountIter+1);
		s1[0] = st1;
		s2[0] = st2;
		s3[0] = PointF(st1.X - st2.X, st1.Y - st2.Y);
		p->addCurve(s1,Pens::Black, 1);
		p->addCurve(s2,Pens::Red, 1);
		p->addCurve(s3,Pens::Green, 1);
	}//0011 0000 1001 1011   //  0x309B
	
	/*далее идёт вычисление векторов до следующей нужной.
	*/
	int currIterNum = p->limCurve[0];
	for(int i = currIterNum +1; i <= stopIterNum; i++){
		rungeKuttMeth(g1, g2, eps, lambda ,accuracy, additionPerIter, currIterNum*accuracy);
		p->curve[2][i-1] = PointF(p->curve[0][i-1].X - p->curve[1][i-1].X, p->curve[0][i-1].Y - p->curve[1][i-1].Y );
	}
	p->limCurve[2] = p->limCurve[1];
	// ну и вывод инфы
	p->draw();
	update();
	if(stopIterNum  >= maxCountIter){
		caclCompleted = true;
	}
}
System::Void button1_Click(System::Object^  sender, System::EventArgs^  e){
	int n = EPS->Value.ToDouble(END_TIME->Value);
	int maxCountIter = 1;
	maxCountIter = n*10;
	vortex(
		PointF(X10->Value.ToDouble(X10->Value), Y10->Value.ToDouble(Y10->Value)),
		PointF(X20->Value.ToDouble(X20->Value), Y10->Value.ToDouble(Y20->Value)),
		Op1->Checked == true ? 0 : 1,
		Gamma1->Value.ToDouble(Gamma1->Value),
		Gamma2->Value.ToDouble(Gamma2->Value),
		Epsilon->Value.ToDouble(Epsilon->Value),
		Lambda->Value.ToDouble(Lambda->Value),
		EPS->Value.ToDouble(EPS->Value), 
		EPS->Value.ToDouble(END_TIME->Value),
		maxCountIter
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
	int n = EPS->Value.ToDouble(END_TIME->Value);
	int maxCountIter = 1;
	maxCountIter = n*10;

	if(iter >= maxCountIter){
		iter = 3;
		timer1->Stop();
		panel->Enabled = true;
		return;
	}
	vortex(
		PointF(X10->Value.ToDouble(X10->Value), Y10->Value.ToDouble(Y10->Value)),
		PointF(X20->Value.ToDouble(X20->Value), Y10->Value.ToDouble(Y20->Value)),
		Op1->Checked == true ? 0 : 1,
		Gamma1->Value.ToDouble(Gamma1->Value),
		Gamma2->Value.ToDouble(Gamma2->Value),
		Epsilon->Value.ToDouble(Epsilon->Value),
		Lambda->Value.ToDouble(Lambda->Value),
		EPS->Value.ToDouble(EPS->Value), 
		EPS->Value.ToDouble(END_TIME->Value),
		iter
		);
	iter+=SPEED->Value;
	if(iter > maxCountIter)
		iter = maxCountIter;
}
System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	panel->Enabled = false;
	if(iter > 3){
		timer1->Stop();
		panel->Enabled = true;
	}
	else
		timer1->Start();
	iter = 3;
}
};
}

