#pragma once
#include "work.h"

namespace lab5 {

	using namespace System;
	using namespace System::Threading;
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
	private: System::Windows::Forms::ProgressBar^  pb1;
	protected: 
	private: System::Windows::Forms::ProgressBar^  pb2;
	private: System::Windows::Forms::ProgressBar^  pb3;
	private: System::Windows::Forms::ProgressBar^  pb5;
	private: System::Windows::Forms::ProgressBar^  pb4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;



	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown5;
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
			this->pb1 = (gcnew System::Windows::Forms::ProgressBar());
			this->pb2 = (gcnew System::Windows::Forms::ProgressBar());
			this->pb3 = (gcnew System::Windows::Forms::ProgressBar());
			this->pb5 = (gcnew System::Windows::Forms::ProgressBar());
			this->pb4 = (gcnew System::Windows::Forms::ProgressBar());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->BeginInit();
			this->SuspendLayout();
			// 
			// pb1
			// 
			this->pb1->Location = System::Drawing::Point(12, 12);
			this->pb1->Name = L"pb1";
			this->pb1->Size = System::Drawing::Size(132, 23);
			this->pb1->TabIndex = 0;
			this->pb1->Click += gcnew System::EventHandler(this, &Form1::proc1_click);
			// 
			// pb2
			// 
			this->pb2->Location = System::Drawing::Point(12, 61);
			this->pb2->Name = L"pb2";
			this->pb2->Size = System::Drawing::Size(132, 23);
			this->pb2->TabIndex = 0;
			this->pb2->Click += gcnew System::EventHandler(this, &Form1::proc2_click);
			// 
			// pb3
			// 
			this->pb3->Location = System::Drawing::Point(177, 12);
			this->pb3->Name = L"pb3";
			this->pb3->Size = System::Drawing::Size(132, 23);
			this->pb3->TabIndex = 0;
			this->pb3->Click += gcnew System::EventHandler(this, &Form1::proc3_click);
			// 
			// pb5
			// 
			this->pb5->Location = System::Drawing::Point(338, 37);
			this->pb5->Name = L"pb5";
			this->pb5->Size = System::Drawing::Size(132, 23);
			this->pb5->TabIndex = 0;
			this->pb5->Click += gcnew System::EventHandler(this, &Form1::proc5_click);
			// 
			// pb4
			// 
			this->pb4->Location = System::Drawing::Point(177, 61);
			this->pb4->Name = L"pb4";
			this->pb4->Size = System::Drawing::Size(132, 23);
			this->pb4->TabIndex = 0;
			this->pb4->Click += gcnew System::EventHandler(this, &Form1::proc4_click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 149);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(457, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"start all";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::start_all);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(55, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"process 1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(55, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"process 2";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(219, 87);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"process 4";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(219, 37);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"process 3";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(380, 63);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 13);
			this->label5->TabIndex = 2;
			this->label5->Text = L"process 5";
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer_tick);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(335, 133);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(64, 13);
			this->label6->TabIndex = 2;
			this->label6->Text = L"total answer";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(13, 36);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(36, 20);
			this->numericUpDown1->TabIndex = 3;
			this->numericUpDown1->Tag = L"1";
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Form1::ch1);
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(13, 85);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(36, 20);
			this->numericUpDown2->TabIndex = 3;
			this->numericUpDown2->Tag = L"2";
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &Form1::ch1);
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(177, 35);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(36, 20);
			this->numericUpDown3->TabIndex = 3;
			this->numericUpDown3->Tag = L"3";
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			this->numericUpDown3->ValueChanged += gcnew System::EventHandler(this, &Form1::ch1);
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(177, 85);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->numericUpDown4->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(36, 20);
			this->numericUpDown4->TabIndex = 3;
			this->numericUpDown4->Tag = L"4";
			this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			this->numericUpDown4->ValueChanged += gcnew System::EventHandler(this, &Form1::ch1);
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Location = System::Drawing::Point(338, 61);
			this->numericUpDown5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->numericUpDown5->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(36, 20);
			this->numericUpDown5->TabIndex = 3;
			this->numericUpDown5->Tag = L"5";
			this->numericUpDown5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			this->numericUpDown5->ValueChanged += gcnew System::EventHandler(this, &Form1::ch1);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(481, 189);
			this->Controls->Add(this->numericUpDown5);
			this->Controls->Add(this->numericUpDown4);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pb4);
			this->Controls->Add(this->pb5);
			this->Controls->Add(this->pb2);
			this->Controls->Add(this->pb3);
			this->Controls->Add(this->pb1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"process";
			this->Load += gcnew System::EventHandler(this, &Form1::form_load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	int p1,p2,p3,p4,p5;
	int start;
	work^ w;
	ThreadStart ^threadDelegate1, ^threadDelegate2,^threadDelegate3,^threadDelegate4,^threadDelegate5;
	Thread ^thread1,^thread2,^thread3,^thread4,^thread5;
private: 
	ThreadPriority itopri(int i)
	{
		switch (i)
		{
		case 1: return ThreadPriority::Lowest;
		case 2: return ThreadPriority::BelowNormal;
		case 3: return ThreadPriority::Normal;
		case 4: return ThreadPriority::AboveNormal;
		case 5: return ThreadPriority::Highest;
		}
	}
	void form_load(System::Object^  sender, System::EventArgs^  e) {
	p1 = p2 = p3 = p4 = p5 = 0;
	start = 0;
	w = gcnew work();
	ThreadStart^ threadDelegate1 = gcnew ThreadStart( w, &work::proc1 );
	ThreadStart^ threadDelegate2 = gcnew ThreadStart( w, &work::proc2 );
	ThreadStart^ threadDelegate3 = gcnew ThreadStart( w, &work::proc3 );
	ThreadStart^ threadDelegate4 = gcnew ThreadStart( w, &work::proc4 );
	ThreadStart^ threadDelegate5 = gcnew ThreadStart( w, &work::proc5 );
	thread1 = gcnew Thread(threadDelegate1);
	thread2 = gcnew Thread(threadDelegate2);
	thread3 = gcnew Thread(threadDelegate3);
	thread4 = gcnew Thread(threadDelegate4);
	thread5 = gcnew Thread(threadDelegate5);
	thread1->Priority = itopri(numericUpDown1->Value.ToInt32(numericUpDown1->Value));
	thread2->Priority = itopri(numericUpDown2->Value.ToInt32(numericUpDown2->Value));
	thread3->Priority = itopri(numericUpDown3->Value.ToInt32(numericUpDown3->Value));
	thread4->Priority = itopri(numericUpDown4->Value.ToInt32(numericUpDown4->Value));
	thread5->Priority = itopri(numericUpDown5->Value.ToInt32(numericUpDown5->Value));

	timer1->Start();
}
void proc1_click(System::Object^  sender, System::EventArgs^  e) 
{
	if(thread1->ThreadState == ThreadState::Unstarted)
		thread1->Start();
	else if(thread1->ThreadState == ThreadState::Running)
		thread1->Suspend();
	else if(thread1->ThreadState == ThreadState::Suspended)
		thread1->Resume();
}
void proc2_click(System::Object^  sender, System::EventArgs^  e) 
{
	if(thread2->ThreadState == ThreadState::Unstarted)
		thread2->Start();
	else if(thread2->ThreadState == ThreadState::Running)
		thread2->Suspend();
	else if(thread2->ThreadState == ThreadState::Suspended)
		thread2->Resume();
}
void proc3_click(System::Object^  sender, System::EventArgs^  e) 
{
	if(thread3->ThreadState == ThreadState::Unstarted && thread1->ThreadState == ThreadState::Stopped && thread2->ThreadState == ThreadState::Stopped)
		thread3->Start();
	else if(thread3->ThreadState == ThreadState::Running)
		thread3->Suspend();
	else if(thread3->ThreadState == ThreadState::Suspended)
		thread3->Resume();
}
void proc4_click(System::Object^  sender, System::EventArgs^  e) 
{
	if(thread4->ThreadState == ThreadState::Unstarted && thread1->ThreadState == ThreadState::Stopped && thread2->ThreadState == ThreadState::Stopped)
		thread4->Start();
	else if(thread4->ThreadState == ThreadState::Running)
		thread4->Suspend();
	else if(thread4->ThreadState == ThreadState::Suspended)
		thread4->Resume();
}
void proc5_click(System::Object^  sender, System::EventArgs^  e) 
{
	if(thread5->ThreadState == ThreadState::Unstarted && thread3->ThreadState == ThreadState::Stopped && thread4->ThreadState == ThreadState::Stopped)
		thread5->Start();
	else if(thread5->ThreadState == ThreadState::Running)
		thread5->Suspend();
	else if(thread5->ThreadState == ThreadState::Suspended)
		thread5->Resume();
}

void start_all(System::Object^  sender, System::EventArgs^  e) 
{
	start = 1;
	if(thread1->ThreadState == ThreadState::Unstarted)
		thread1->Start();
	if(thread2->ThreadState == ThreadState::Unstarted)
		thread2->Start();
}
void timer_tick(System::Object^  sender, System::EventArgs^  e) 
{
	if(start)
	{
		if(thread3->ThreadState == ThreadState::Unstarted && thread1->ThreadState == ThreadState::Stopped && thread2->ThreadState == ThreadState::Stopped)
			thread3->Start();
		if(thread4->ThreadState == ThreadState::Unstarted && thread1->ThreadState == ThreadState::Stopped && thread2->ThreadState == ThreadState::Stopped)
			thread4->Start();
		if(thread5->ThreadState == ThreadState::Unstarted && thread3->ThreadState == ThreadState::Stopped && thread4->ThreadState == ThreadState::Stopped)
			thread5->Start();
	}
	pb1->Value = w->t1;
	pb2->Value = w->t2;
	pb3->Value = w->t3;
	pb4->Value = w->t4;
	pb5->Value = w->t5;
	if(w->w1)label1->Text = Convert::ToString((double)w->w1);
	if(w->w2)label2->Text = Convert::ToString((double)w->w2);
	if(w->w3)label3->Text = Convert::ToString((double)w->w3);
	if(w->w4)label4->Text = Convert::ToString((double)w->w4);
	if(w->w5)label5->Text = Convert::ToString((double)w->w5);
	if(thread5->ThreadState == ThreadState::Stopped)
		label6->Text = Convert::ToString((double)(w->w5 + w->w1 + w->w2 + w->w3 + w->w4));
}
void ch1(System::Object^  sender, System::EventArgs^  e) 
{
	if(!(thread1->ThreadState == ThreadState::Stopped))
		thread1->Priority = itopri(numericUpDown1->Value.ToInt32(numericUpDown1->Value));
	if(!(thread2->ThreadState == ThreadState::Stopped))
		thread2->Priority = itopri(numericUpDown2->Value.ToInt32(numericUpDown2->Value));
	if(!(thread3->ThreadState == ThreadState::Stopped))
		thread3->Priority = itopri(numericUpDown3->Value.ToInt32(numericUpDown3->Value));
	if(!(thread4->ThreadState == ThreadState::Stopped))
		thread4->Priority = itopri(numericUpDown4->Value.ToInt32(numericUpDown4->Value));
	if(!(thread5->ThreadState == ThreadState::Stopped))
		thread5->Priority = itopri(numericUpDown5->Value.ToInt32(numericUpDown5->Value));
}


};
}

