#pragma once
#include "Problem4.h"
namespace lab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace Problems4;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			isReadyToRun = false;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
				if(t){
					t->Abort();
					delete t;
				}
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RichTextBox^  Out;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  Start;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::NumericUpDown^  P1;

	private: System::Windows::Forms::NumericUpDown^  STEPS;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::NumericUpDown^  P2;

	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::NumericUpDown^  M;

	private: System::Windows::Forms::NumericUpDown^  N;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::IContainer^  components;
	private:

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Out = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Start = (gcnew System::Windows::Forms::Button());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->P2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->P1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->M = (gcnew System::Windows::Forms::NumericUpDown());
			this->N = (gcnew System::Windows::Forms::NumericUpDown());
			this->STEPS = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->P2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->P1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->M))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->N))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->STEPS))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Out);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(299, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(389, 331);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Вывод";
			// 
			// Out
			// 
			this->Out->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Out->EnableAutoDragDrop = true;
			this->Out->Location = System::Drawing::Point(3, 16);
			this->Out->Name = L"Out";
			this->Out->ReadOnly = true;
			this->Out->Size = System::Drawing::Size(383, 312);
			this->Out->TabIndex = 0;
			this->Out->TabStop = false;
			this->Out->Text = L"";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->panel1);
			this->groupBox2->Controls->Add(this->panel2);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Left;
			this->groupBox2->Location = System::Drawing::Point(0, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(299, 331);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Ввод";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->Start);
			this->panel1->Controls->Add(this->radioButton3);
			this->panel1->Controls->Add(this->radioButton2);
			this->panel1->Controls->Add(this->radioButton1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(3, 96);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(293, 205);
			this->panel1->TabIndex = 1;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(176, 126);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(111, 37);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Следующий шаг";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(74, 126);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(96, 37);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Приостановить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(0, 126);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(68, 37);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Стоп";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// Start
			// 
			this->Start->Location = System::Drawing::Point(0, 73);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(293, 37);
			this->Start->TabIndex = 9;
			this->Start->Text = L"Старт";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(10, 50);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(126, 17);
			this->radioButton3->TabIndex = 8;
			this->radioButton3->Text = L"Автомат Вайсборда";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(10, 27);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(119, 17);
			this->radioButton2->TabIndex = 7;
			this->radioButton2->Text = L"Атомат Кринского";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(10, 4);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(120, 17);
			this->radioButton1->TabIndex = 6;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Автомат Роббинса";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->P2);
			this->panel2->Controls->Add(this->P1);
			this->panel2->Controls->Add(this->M);
			this->panel2->Controls->Add(this->N);
			this->panel2->Controls->Add(this->STEPS);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(3, 16);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(293, 80);
			this->panel2->TabIndex = 0;
			// 
			// P2
			// 
			this->P2->DecimalPlaces = 3;
			this->P2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->P2->Location = System::Drawing::Point(186, 28);
			this->P2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->P2->Name = L"P2";
			this->P2->Size = System::Drawing::Size(104, 20);
			this->P2->TabIndex = 3;
			this->P2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {7, 0, 0, 65536});
			// 
			// P1
			// 
			this->P1->DecimalPlaces = 3;
			this->P1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->P1->Location = System::Drawing::Point(29, 28);
			this->P1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->P1->Name = L"P1";
			this->P1->Size = System::Drawing::Size(104, 20);
			this->P1->TabIndex = 2;
			this->P1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {9, 0, 0, 65536});
			// 
			// M
			// 
			this->M->Location = System::Drawing::Point(247, 54);
			this->M->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000000, 0, 0, 0});
			this->M->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->M->Name = L"M";
			this->M->Size = System::Drawing::Size(43, 20);
			this->M->TabIndex = 5;
			this->M->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			// 
			// N
			// 
			this->N->Location = System::Drawing::Point(91, 54);
			this->N->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000000, 0, 0, 0});
			this->N->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->N->Name = L"N";
			this->N->Size = System::Drawing::Size(45, 20);
			this->N->TabIndex = 4;
			this->N->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			// 
			// STEPS
			// 
			this->STEPS->Location = System::Drawing::Point(52, 2);
			this->STEPS->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000000, 0, 0, 0});
			this->STEPS->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->STEPS->Name = L"STEPS";
			this->STEPS->Size = System::Drawing::Size(67, 20);
			this->STEPS->TabIndex = 1;
			this->STEPS->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(151, 30);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"p2";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(151, 56);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Состояний (m)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(4, 56);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Автоматов (n)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(19, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"p1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 4);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Шагов";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(688, 331);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->MinimumSize = System::Drawing::Size(700, 350);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->P2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->P1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->M))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->N))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->STEPS))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		;
		;
		;
	public:
		bool isReadyToRun;
		Problem4^ problem;
		OutputWriter^ out;
		ParameterizedThreadStart^ pts;
		Thread^ t;
	private: 
void init(){
	AutomatType type;
	if(radioButton1->Checked)
		type = AutomatType::robbins;
	else if(radioButton2->Checked)
		type = AutomatType::krinsky;
	else type = AutomatType::waisbord;
	problem = gcnew Problem4(
		Decimal::ToDouble(P1->Value),
		Decimal::ToDouble(P2->Value),
		type,
		Decimal::ToDouble(N->Value),
		Decimal::ToDouble(M->Value),
		Decimal::ToDouble(STEPS->Value)
		);
	out = gcnew OutputWriter(problem);
	isReadyToRun = true;
}
System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {		
	if(!isReadyToRun)
		init();
	Out->Text = "";
	while(!problem->isDone())
		problem->nextStep();
	Out->Text = "" + out;
	isReadyToRun = false;		
}

System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	
}

};//endOfClassForm

}
