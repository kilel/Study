#pragma once

#include "SwarmOptimization.h"
#include "OptimizationProblem.h"
namespace lab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;


	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			
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
				t->Abort();
				delete t;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RichTextBox^  Out;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  Start;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::NumericUpDown^  C1;


	private: System::Windows::Forms::NumericUpDown^  nMax;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::NumericUpDown^  C2;

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
			this->Start = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->C2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->C1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->nMax = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->C2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->C1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nMax))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Out);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Right;
			this->groupBox1->Location = System::Drawing::Point(299, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(338, 331);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Вывод";
			// 
			// Out
			// 
			this->Out->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Out->Location = System::Drawing::Point(3, 16);
			this->Out->Name = L"Out";
			this->Out->Size = System::Drawing::Size(332, 312);
			this->Out->TabIndex = 0;
			this->Out->TabStop = false;
			this->Out->Text = L"";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->Start);
			this->groupBox2->Controls->Add(this->panel1);
			this->groupBox2->Controls->Add(this->panel2);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(0, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(299, 331);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Ввод";
			// 
			// Start
			// 
			this->Start->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Start->Location = System::Drawing::Point(3, 291);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(293, 37);
			this->Start->TabIndex = 3;
			this->Start->Text = L"Старт";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->radioButton2);
			this->panel1->Controls->Add(this->radioButton1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(3, 96);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(293, 195);
			this->panel1->TabIndex = 1;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(10, 82);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(125, 17);
			this->radioButton2->TabIndex = 0;
			this->radioButton2->Text = L"Редукцией задачу 2";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(10, 4);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(184, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Роевой оптимизацией задачу 1";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->C2);
			this->panel2->Controls->Add(this->C1);
			this->panel2->Controls->Add(this->nMax);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(3, 16);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(293, 80);
			this->panel2->TabIndex = 4;
			// 
			// C2
			// 
			this->C2->DecimalPlaces = 2;
			this->C2->Location = System::Drawing::Point(186, 54);
			this->C2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->C2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
			this->C2->Name = L"C2";
			this->C2->Size = System::Drawing::Size(104, 20);
			this->C2->TabIndex = 2;
			this->C2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// C1
			// 
			this->C1->DecimalPlaces = 2;
			this->C1->Location = System::Drawing::Point(186, 28);
			this->C1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->C1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
			this->C1->Name = L"C1";
			this->C1->Size = System::Drawing::Size(104, 20);
			this->C1->TabIndex = 1;
			this->C1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// nMax
			// 
			this->nMax->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->nMax->Location = System::Drawing::Point(186, 2);
			this->nMax->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, 0});
			this->nMax->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->nMax->Name = L"nMax";
			this->nMax->Size = System::Drawing::Size(104, 20);
			this->nMax->TabIndex = 1;
			this->nMax->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 56);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"c2";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(19, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"c1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 4);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Количество шагов";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(637, 331);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->C2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->C1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nMax))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		;
		;
		;
	public:
		OptimizationProblem^ cso;
		SwarmOptimization^ cpm;
		ParameterizedThreadStart^ pts;
		Thread^ t;
	private: 
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			if(t)
				t->Abort();
			
			if(radioButton1->Checked){
				cpm = gcnew SwarmOptimization(
						Decimal::ToDouble(C1->Value), 
						Decimal::ToDouble(C2->Value), 
						Decimal::ToInt32(nMax->Value)
					);
				pts = gcnew ParameterizedThreadStart(cpm, &SwarmOptimization::run);
				t = gcnew Thread(pts);
			}
			else{
				cso = gcnew OptimizationProblem(
						Decimal::ToDouble(C1->Value), 
						Decimal::ToDouble(C2->Value), 
						Decimal::ToInt32(nMax->Value)
					);
				pts = gcnew ParameterizedThreadStart(cso, &OptimizationProblem::run);
				t = gcnew Thread(pts);
			}
			t->Start();
			timer1->Start();
			Out->Text = "";
		
			
		}

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 String^s;
			 bool isC = false;
			 if(radioButton1->Checked){ 
				s = cpm->getLog();
				isC = cpm->isComplete();
			 }
			 else{
				 s = cso->getLog();
				 isC = cso->isComplete();
			 }
				if(isC){
					if(Out->Text->Length != s->Length){
						s = s->Substring(Out->Text->Length);
						Out->Text += s;
					}
					t->Abort();
					timer1->Stop();
					return;
				}
				if(s->Length == 0)
					return;
				if(Out->Text->Length == s->Length)
					return;
				if(Out->Text->Length == 0)
					1;
				else
					s = s->Substring(Out->Text->Length);
				Out->Text += s;
				
			}
};//endOfClassForm

}
