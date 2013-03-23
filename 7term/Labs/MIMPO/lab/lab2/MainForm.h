#pragma once
#include "Function.h"
#include "ParsingTools.h"
#include "CombinedPenaltyMeth.h"
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
				if(t){
					t->Abort();
					delete t;
				}
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RichTextBox^  Out;
	protected: 

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  Start;

	private: System::Windows::Forms::RichTextBox^  Cons;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::NumericUpDown^  PenC;
	private: System::Windows::Forms::NumericUpDown^  PenVal;
	private: System::Windows::Forms::NumericUpDown^  PenAcc;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
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
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->Cons = (gcnew System::Windows::Forms::RichTextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->PenC = (gcnew System::Windows::Forms::NumericUpDown());
			this->PenVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->PenAcc = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PenC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PenVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PenAcc))->BeginInit();
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
			this->Start->Dock = System::Windows::Forms::DockStyle::Bottom;
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
			this->panel1->Controls->Add(this->radioButton3);
			this->panel1->Controls->Add(this->radioButton2);
			this->panel1->Controls->Add(this->radioButton1);
			this->panel1->Controls->Add(this->Cons);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(3, 96);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(293, 195);
			this->panel1->TabIndex = 1;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(105, 163);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(185, 17);
			this->radioButton3->TabIndex = 3;
			this->radioButton3->Tag = L"3";
			this->radioButton3->Text = L"Задача 2 (изменённое условие)";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(9, 163);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(70, 17);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->Tag = L"2";
			this->radioButton2->Text = L"Задача 2";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(9, 140);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(70, 17);
			this->radioButton1->TabIndex = 3;
			this->radioButton1->TabStop = true;
			this->radioButton1->Tag = L"1";
			this->radioButton1->Text = L"Задача 1";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
			// 
			// Cons
			// 
			this->Cons->Dock = System::Windows::Forms::DockStyle::Top;
			this->Cons->Location = System::Drawing::Point(0, 0);
			this->Cons->Name = L"Cons";
			this->Cons->Size = System::Drawing::Size(293, 134);
			this->Cons->TabIndex = 2;
			this->Cons->Text = L"log(x1)-x2\nx1^2+x2^2-4=0\nx1-1<=0";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->PenC);
			this->panel2->Controls->Add(this->PenVal);
			this->panel2->Controls->Add(this->PenAcc);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(3, 16);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(293, 80);
			this->panel2->TabIndex = 4;
			// 
			// PenC
			// 
			this->PenC->DecimalPlaces = 1;
			this->PenC->Location = System::Drawing::Point(186, 54);
			this->PenC->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->PenC->Name = L"PenC";
			this->PenC->Size = System::Drawing::Size(104, 20);
			this->PenC->TabIndex = 1;
			this->PenC->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			// 
			// PenVal
			// 
			this->PenVal->DecimalPlaces = 1;
			this->PenVal->Location = System::Drawing::Point(186, 28);
			this->PenVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->PenVal->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->PenVal->Name = L"PenVal";
			this->PenVal->Size = System::Drawing::Size(104, 20);
			this->PenVal->TabIndex = 1;
			this->PenVal->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// PenAcc
			// 
			this->PenAcc->DecimalPlaces = 4;
			this->PenAcc->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->PenAcc->Location = System::Drawing::Point(186, 2);
			this->PenAcc->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->PenAcc->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 262144});
			this->PenAcc->Name = L"PenAcc";
			this->PenAcc->Size = System::Drawing::Size(104, 20);
			this->PenAcc->TabIndex = 1;
			this->PenAcc->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 56);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(166, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Параметр уменьшения штрафа";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Начальный штраф";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 4);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Точность";
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PenC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PenVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PenAcc))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		;
		;
		;
	public:
		CombinedPenaltyMeth^ cpm;
		ParameterizedThreadStart^ pts;
		Thread^ t;
	private: 
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			if(t)
				t->Abort();
			array<String^>^ consLt = gcnew array<String^>(Cons->Lines->Length), ^consEq = gcnew array<String^>(Cons->Lines->Length); 
			int lenLt = 0, lenEq = 0;
			String^ f = Cons->Lines[0]->ToString()->Trim();
			String^ temp;
			for(int i = 1; i < Cons->Lines->Length; i++){
				temp = ParsingTools::delSpaces( Cons->Lines[i]->ToString() );
				
				if(temp->Length != 0){
					if(temp[temp->Length-3] == '<'){
						consLt[lenLt] = temp->Substring(0, temp->Length-3);
						lenLt++;
					}
					else{
						consEq[lenEq] = temp->Substring(0, temp->Length-2);
						lenEq++;
					}
				}
			}
			Array::Resize(consEq, lenEq);
			Array::Resize(consLt, lenLt);
			int numarg = 0;
			for(int i = 1; i < 1000; i++){
				if(f->IndexOf("x"+i) >= 0)
					numarg = i;
				else break;
			}
			cpm = gcnew CombinedPenaltyMeth(f, numarg, consEq, consLt, Decimal::ToDouble(PenVal->Value), Decimal::ToDouble(PenC->Value));
			pts = gcnew ParameterizedThreadStart(cpm, &CombinedPenaltyMeth::sol);
			t = gcnew Thread(pts);
			t->Start();
			timer1->Start();
			Out->Text = "";
			/*array<double>^ res = cpm->solve(Decimal::ToDouble(PenAcc->Value));
			Out->Text = cpm->getLog() + "\n" +"Конечная точка:\n\t"+ParsingTools::arrayToString(res)+"\n";
			Function^ fu = gcnew Function(f);
			Out->Text += "Значение функции:\n\t"+fu->getValue(res);*/
			
		}

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				String^s = cpm->getLog();
				if(s->Length == 0)
					return;
				if(Out->Text->Length == s->Length)
					return;
				if(Out->Text->Length == 0)
					1;
				else
					s = s->Substring(Out->Text->Length);
				Out->Text += s;
				if(cpm->isComplete()){
					Out->Text += "\n\n" +"Конечная точка:\n\t"+ParsingTools::arrayToString( cpm->getResult() )+"\n";
					Out->Text += "Значение функции:\n\t"+ParsingTools::evalf(cpm->getValue());
					t->Abort();
					timer1->Stop();
				}
			}
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				RadioButton^ rb = dynamic_cast<RadioButton^>(sender);
				int tag =  Convert::ToInt32(dynamic_cast<String^>(rb->Tag));
				switch(tag){
				case 1: Cons->Text = "log(x1)-x2\nx1^2+x2^2-4=0\nx1-1<=0";
					break;
				case 2: Cons->Text = "5*x1^4+2*x2^2-3*x3^2+2*x4^2+3*x5\n\
-5*x1-6*x2-4*x3+2*x4-3*x5+11<=0\n\
-5*x1-5*x2-7*x3-3*x5+10<=0\n\
2*x1+2*x2+2*x3+3*x5-4=0\n\
-x1<=0\n-x2<=0\n-x3<=0\n-x4<=0\n-x5<=0";
					break;
				case 3: Cons->Text = "5*x1^4+2*x2^2-3*x3^2+4-2*x1-2*x2-2*x3\n-3*x1-4*x2-2*x3-7<=0\n\
-3*x1-3*x2-5*x3-6<=0\n\
-x1<=0\n\
-x2<=0\n\
-x3<=0\n\
x1+x2+x3-2<=0";
					break;
				}
			}
};//endOfClassForm

}
