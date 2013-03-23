#pragma once
#include "dyn_pr.h"
namespace lab2 {

	using namespace System;
	using namespace std;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	
	
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			set_row_col();
		}
#pragma region Windows Form Designer generated code
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
	private: System::Windows::Forms::RichTextBox^  rtb;
	protected: 

	private: System::Windows::Forms::DataGridView^  grid;
	private: System::Windows::Forms::DataGridView^  vect;
	protected: 


	private: System::Windows::Forms::NumericUpDown^  N;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  M;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  start_by_timer;


















	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  VAL;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  col1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  col2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  col_vect;









	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;


		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->rtb = (gcnew System::Windows::Forms::RichTextBox());
			this->grid = (gcnew System::Windows::Forms::DataGridView());
			this->col1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->vect = (gcnew System::Windows::Forms::DataGridView());
			this->col_vect = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->N = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->M = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->start_by_timer = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->VAL = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->grid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vect))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->N))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->M))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VAL))->BeginInit();
			this->SuspendLayout();
			// 
			// rtb
			// 
			this->rtb->Location = System::Drawing::Point(-1, -1);
			this->rtb->Name = L"rtb";
			this->rtb->ReadOnly = true;
			this->rtb->Size = System::Drawing::Size(299, 380);
			this->rtb->TabIndex = 1000;
			this->rtb->Text = L"";
			this->rtb->WordWrap = false;
			// 
			// grid
			// 
			this->grid->AllowUserToAddRows = false;
			this->grid->AllowUserToDeleteRows = false;
			this->grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->col1, this->col2});
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->grid->DefaultCellStyle = dataGridViewCellStyle1;
			this->grid->Location = System::Drawing::Point(6, 37);
			this->grid->MultiSelect = false;
			this->grid->Name = L"grid";
			this->grid->RowHeadersVisible = false;
			this->grid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->grid->Size = System::Drawing::Size(226, 308);
			this->grid->TabIndex = 2;
			// 
			// col1
			// 
			this->col1->HeaderText = L"f1";
			this->col1->Name = L"col1";
			this->col1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->col1->Width = 30;
			// 
			// col2
			// 
			this->col2->HeaderText = L"f2";
			this->col2->Name = L"col2";
			this->col2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->col2->Width = 30;
			// 
			// vect
			// 
			this->vect->AllowUserToAddRows = false;
			this->vect->AllowUserToDeleteRows = false;
			this->vect->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->vect->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) {this->col_vect});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->vect->DefaultCellStyle = dataGridViewCellStyle2;
			this->vect->Location = System::Drawing::Point(238, 37);
			this->vect->Name = L"vect";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->vect->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->vect->RowHeadersVisible = false;
			this->vect->Size = System::Drawing::Size(66, 308);
			this->vect->TabIndex = 2;
			// 
			// col_vect
			// 
			this->col_vect->HeaderText = L"X";
			this->col_vect->Name = L"col_vect";
			this->col_vect->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->col_vect->Width = 45;
			// 
			// N
			// 
			this->N->Location = System::Drawing::Point(114, 12);
			this->N->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->N->Name = L"N";
			this->N->Size = System::Drawing::Size(61, 20);
			this->N->TabIndex = 30;
			this->N->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			this->N->ValueChanged += gcnew System::EventHandler(this, &Form1::N_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Размеры матрицы";
			// 
			// M
			// 
			this->M->Location = System::Drawing::Point(184, 12);
			this->M->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->M->Name = L"M";
			this->M->Size = System::Drawing::Size(61, 20);
			this->M->TabIndex = 30;
			this->M->TabStop = false;
			this->M->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->M->ValueChanged += gcnew System::EventHandler(this, &Form1::N_ValueChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->grid);
			this->groupBox1->Controls->Add(this->M);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->N);
			this->groupBox1->Controls->Add(this->vect);
			this->groupBox1->Location = System::Drawing::Point(5, 13);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(310, 351);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Входные данные";
			// 
			// start_by_timer
			// 
			this->start_by_timer->Location = System::Drawing::Point(11, 370);
			this->start_by_timer->Name = L"start_by_timer";
			this->start_by_timer->Size = System::Drawing::Size(83, 23);
			this->start_by_timer->TabIndex = 5;
			this->start_by_timer->Text = L"Решить";
			this->start_by_timer->UseVisualStyleBackColor = true;
			this->start_by_timer->Click += gcnew System::EventHandler(this, &Form1::start_by_timer_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->VAL);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Controls->Add(this->start_by_timer);
			this->panel1->Location = System::Drawing::Point(298, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(317, 411);
			this->panel1->TabIndex = 1001;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(116, 375);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Средства";
			// 
			// VAL
			// 
			this->VAL->Location = System::Drawing::Point(177, 373);
			this->VAL->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->VAL->Name = L"VAL";
			this->VAL->Size = System::Drawing::Size(130, 20);
			this->VAL->TabIndex = 6;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightYellow;
			this->ClientSize = System::Drawing::Size(617, 411);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->rtb);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"lab4";
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->grid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vect))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->N))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->M))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VAL))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
	int n,m;
	private:
	double evalf(double a, int n)
	{
		int sign = Math::Sign(a);
		a = Math::Abs(a);
		double b = Math::Floor(a);
		a = a-b;
		a*=Math::Pow(10.,n);;
		a = Math::Floor(a);
		a/= Math::Pow(10.,n);
		return (a+b)*sign;
	}
	void set_row_col()
	{
		n = N->Value.ToInt32(N->Value);
		m = M->Value.ToInt32(M->Value);
		while(grid->ColumnCount > m)
			grid->Columns->RemoveAt(m);
		while(grid->ColumnCount < m)
		{
			grid->Columns->Add("col"+(grid->ColumnCount+1),"f"+(grid->ColumnCount+1));
			grid->Columns[grid->ColumnCount-1]->Width = 30;
		}
		while(grid->RowCount > n)
		{
			grid->Rows->RemoveAt(n);
			vect->Rows->RemoveAt(n);
		}
		while(grid->RowCount < n)
		{
			grid->Rows->Add(n-grid->Rows->Count);
			vect->Rows->Add(n-vect->Rows->Count);
		}
	}
	
	void N_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		set_row_col();
	}
	
	void start_by_timer_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		vi X = vi(n,0);
		vvi G = vvi(n,vi(m,0));
		int V = VAL->Value.ToInt32(VAL->Value);
		rep(i,0,n)
			X[i] = Convert::ToInt32( vect[0,i]->Value);
		rep(i,0,n)
			rep(j,0,m)
				G[i][j] = Convert::ToInt32( grid[j,i]->Value);
		dyn_pr *me = new dyn_pr(X,G,V);
		rtb->Text = me->solve();
	}
	double dr(double a)
	{
		if(a < 0)
		{
			a = a - Math::Floor(a);
		}
		else a = a - Math::Floor(a);
		return a;
	}
	void next_step_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		;
	}
	void init_args(System::Object^  sender, System::EventArgs^  e) 
	{
		;
	}
	void Form1_Resize(System::Object^  sender, System::EventArgs^  e) 
	{
		panel1->Location = Point(this->Width - 633 + 298+8,1);
		rtb->Width = this->Width - panel1->Width-9;
		rtb->Height = this->Height-35;
	}
};
}

