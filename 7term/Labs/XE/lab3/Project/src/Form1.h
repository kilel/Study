#pragma once
#include "plotTools.h"
#include "KseLab3.h"
namespace lab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

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
			st = 0;
			lab = gcnew KseLab3(
				Decimal::ToDouble(A1->Value),
				Decimal::ToDouble(A2->Value),
				Decimal::ToDouble(B->Value),
				Decimal::ToDouble(F->Value),
				Decimal::ToDouble(RO->Value),
				Decimal::ToDouble(X10->Value),
				Decimal::ToDouble(X20->Value),
				Decimal::ToDouble(END_TIME->Value),
				Decimal::ToDouble(EPS->Value)
				);
			lab->addStopIter(Decimal::ToDouble(END_TIME->Value)*10);
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
			if(t){
				t->Abort();
				delete t;
			}
			
		}
	private: System::Windows::Forms::PictureBox^  pic;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::NumericUpDown^  A2;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  A1;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  EPS;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  RO;


	private: System::Windows::Forms::NumericUpDown^  X20;
	private: System::Windows::Forms::Label^  label7;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  F;
	private: System::Windows::Forms::NumericUpDown^  B;



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
			this->SPEED = (gcnew System::Windows::Forms::TrackBar());
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->EPS = (gcnew System::Windows::Forms::NumericUpDown());
			this->END_TIME = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->RO = (gcnew System::Windows::Forms::NumericUpDown());
			this->A1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->X20 = (gcnew System::Windows::Forms::NumericUpDown());
			this->X10 = (gcnew System::Windows::Forms::NumericUpDown());
			this->A2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->B = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->F = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->Scale = (gcnew System::Windows::Forms::TrackBar());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SPEED))->BeginInit();
			this->panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EPS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->END_TIME))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RO))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->A1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->X20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->X10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->A2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->F))->BeginInit();
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
			this->groupBox2->Text = L"Входные данные";
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
			// panel
			// 
			this->panel->Controls->Add(this->label12);
			this->panel->Controls->Add(this->label1);
			this->panel->Controls->Add(this->EPS);
			this->panel->Controls->Add(this->END_TIME);
			this->panel->Controls->Add(this->label2);
			this->panel->Controls->Add(this->RO);
			this->panel->Controls->Add(this->A1);
			this->panel->Controls->Add(this->label4);
			this->panel->Controls->Add(this->X20);
			this->panel->Controls->Add(this->X10);
			this->panel->Controls->Add(this->A2);
			this->panel->Controls->Add(this->label8);
			this->panel->Controls->Add(this->label7);
			this->panel->Controls->Add(this->label6);
			this->panel->Controls->Add(this->B);
			this->panel->Controls->Add(this->label5);
			this->panel->Controls->Add(this->F);
			this->panel->Controls->Add(this->label3);
			this->panel->Location = System::Drawing::Point(6, 19);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(189, 305);
			this->panel->TabIndex = 4;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(3, 1);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(158, 13);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Конец интервала вычисления";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Точность";
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
			this->EPS->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
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
			this->label2->Size = System::Drawing::Size(19, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"a1";
			// 
			// RO
			// 
			this->RO->DecimalPlaces = 7;
			this->RO->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->RO->Location = System::Drawing::Point(91, 181);
			this->RO->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->RO->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->RO->Name = L"RO";
			this->RO->Size = System::Drawing::Size(78, 20);
			this->RO->TabIndex = 1;
			this->RO->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {173, 0, 0, 131072});
			// 
			// A1
			// 
			this->A1->DecimalPlaces = 7;
			this->A1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->A1->Location = System::Drawing::Point(6, 98);
			this->A1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->A1->Name = L"A1";
			this->A1->Size = System::Drawing::Size(78, 20);
			this->A1->TabIndex = 1;
			this->A1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {4, 0, 0, 0});
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(4, 124);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(24, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"x(0)";
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
			this->X10->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			// 
			// A2
			// 
			this->A2->DecimalPlaces = 7;
			this->A2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->A2->Location = System::Drawing::Point(90, 98);
			this->A2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->A2->Name = L"A2";
			this->A2->Size = System::Drawing::Size(78, 20);
			this->A2->TabIndex = 1;
			this->A2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {9, 0, 0, 131072});
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(5, 209);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(13, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"b";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(88, 165);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(16, 13);
			this->label7->TabIndex = 0;
			this->label7->Text = L"ro";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(5, 165);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(10, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"f";
			// 
			// B
			// 
			this->B->DecimalPlaces = 7;
			this->B->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->B->Location = System::Drawing::Point(7, 226);
			this->B->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->B->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->B->Name = L"B";
			this->B->Size = System::Drawing::Size(78, 20);
			this->B->TabIndex = 1;
			this->B->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(87, 124);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(26, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"x\'(0)";
			// 
			// F
			// 
			this->F->DecimalPlaces = 7;
			this->F->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->F->Location = System::Drawing::Point(7, 181);
			this->F->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->F->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, System::Int32::MinValue});
			this->F->Name = L"F";
			this->F->Size = System::Drawing::Size(78, 20);
			this->F->TabIndex = 1;
			this->F->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {6, 0, 0, 65536});
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(87, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"a2";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(133, 328);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(55, 13);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Скорость";
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SPEED))->EndInit();
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EPS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->END_TIME))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RO))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->A1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->X20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->X10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->A2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->F))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Scale))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
public:
	bool pic_mouce_down;
	plotTools ^p;
	KseLab3^ lab;
	int cx, cy;
	int iter, st, end;
	bool caclCompleted;
	Thread^ t;
private: 
void update(){
	if(st == 0)
		p->draw();
	if(st != lab->getCurrIter()-1){
		p->drawOverCurve(lab->x, Pens::Red, st, lab->getCurrIter() );
		st = lab->getCurrIter()-1;
	}
	pic->Image = p->getCanvas();
	
}

System::Void button1_Click(System::Object^  sender, System::EventArgs^  e){
	if(t)
		t->Abort();
	lab = gcnew KseLab3(
		Decimal::ToDouble(A1->Value),
		Decimal::ToDouble(A2->Value),
		Decimal::ToDouble(B->Value),
		Decimal::ToDouble(F->Value),
		Decimal::ToDouble(RO->Value),
		Decimal::ToDouble(X10->Value),
		Decimal::ToDouble(X20->Value),
		Decimal::ToDouble(END_TIME->Value),
		Decimal::ToDouble(EPS->Value)
		);
	st = 0;
	lab->addStopIter(Decimal::ToDouble(END_TIME->Value)*10);
	ParameterizedThreadStart^ pts = gcnew ParameterizedThreadStart(lab, &KseLab3::run);
	t = gcnew Thread(pts);
	t->Start();
	timer1->Start();
}
System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if(panel->Enabled == false){
		timer1->Stop();
		if(t)
			t->Abort();
		panel->Enabled = true;
		delete lab;
	}
	else{
		panel->Enabled = false;
		st = 0;
		lab = gcnew KseLab3(
			Decimal::ToDouble(A1->Value),
			Decimal::ToDouble(A2->Value),
			Decimal::ToDouble(B->Value),
			Decimal::ToDouble(F->Value),
			Decimal::ToDouble(RO->Value),
			Decimal::ToDouble(X10->Value),
			Decimal::ToDouble(X20->Value),
			Decimal::ToDouble(END_TIME->Value),
			Decimal::ToDouble(EPS->Value)
			);
		ParameterizedThreadStart^ pts = gcnew ParameterizedThreadStart(lab, &KseLab3::run);
		t = gcnew Thread(pts);
		t->Start();
		timer1->Start();
	}
}
System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	int maxCountIter = Decimal::ToDouble(END_TIME->Value)*10;
	update();
	if(lab->getCurrIter() >= maxCountIter){
		timer1->Stop();
		t->Abort();
		panel->Enabled = true;
		return;
	}
	else{
		lab->addStopIter(SPEED->Value);
	}
	
}
System::Void pic_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if(pic_mouce_down){
		p->setCentre(e->X-cx, e->Y-cy);
		cx = e->X; cy = e->Y;
		p->draw();
		st = 0;
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
	st = 0;
	p->draw();
	update();
}
System::Void Scale_Scroll(System::Object^  sender, System::EventArgs^  e){
	p->setScale(PointF(Scale->Value/100., Scale->Value/100.));
	st = 0;
	p->draw();
	update();
}
System::Void Scale_Leave(System::Object^  sender, System::EventArgs^  e) {
	//Scale->Focus();
}


};
}

