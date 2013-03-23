#pragma once
#include <vector>
#define EPS 1e-8
#define rep(i,k,n) for(int (i) = (k); (i) < (n); (i)++)
#define rrep(i,k,n) for(int (i) = (k); (i) >= (n); (i)--)
#define rtba(s) rtb->AppendText((s))

namespace lab2 {

	using namespace System;
	using namespace std;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	typedef vector<double> vd;
	typedef vector<vd> vvd;
	typedef vector<int> vi;
	vd re, fr;	//строка функции и свободный столбец
	vvd sm;		//симплексная матрица
	vd ans;		//вектор ответа
	vi basis;
	vi used_in_basis;
	double count;//экстр. найденное значение
	int n,m;
	
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




	private: System::Windows::Forms::DataGridViewTextBoxColumn^  col1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  col2;
	private: System::Windows::Forms::GroupBox^  groupBox2;





	private: System::Windows::Forms::Button^  next_step;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  col_vect;
	private: System::Windows::Forms::DataGridView^  formula;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  rol2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel1;




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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->formula = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->rol2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->next_step = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->grid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vect))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->N))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->M))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->formula))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// rtb
			// 
			this->rtb->Location = System::Drawing::Point(-1, -1);
			this->rtb->Name = L"rtb";
			this->rtb->ReadOnly = true;
			this->rtb->Size = System::Drawing::Size(299, 360);
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
			this->grid->Location = System::Drawing::Point(6, 47);
			this->grid->MultiSelect = false;
			this->grid->Name = L"grid";
			this->grid->RowHeadersVisible = false;
			this->grid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->grid->Size = System::Drawing::Size(239, 157);
			this->grid->TabIndex = 2;
			// 
			// col1
			// 
			this->col1->HeaderText = L"x1";
			this->col1->Name = L"col1";
			this->col1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->col1->Width = 30;
			// 
			// col2
			// 
			this->col2->HeaderText = L"x2";
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
			this->vect->Location = System::Drawing::Point(251, 48);
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
			this->vect->Size = System::Drawing::Size(53, 157);
			this->vect->TabIndex = 2;
			// 
			// col_vect
			// 
			this->col_vect->HeaderText = L"своб";
			this->col_vect->Name = L"col_vect";
			this->col_vect->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->col_vect->Width = 45;
			// 
			// N
			// 
			this->N->Location = System::Drawing::Point(114, 16);
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
			this->label2->Location = System::Drawing::Point(6, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Размеры матрицы";
			// 
			// M
			// 
			this->M->Location = System::Drawing::Point(184, 16);
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
			this->groupBox1->Size = System::Drawing::Size(310, 216);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Входные данные";
			// 
			// start_by_timer
			// 
			this->start_by_timer->Location = System::Drawing::Point(7, 328);
			this->start_by_timer->Name = L"start_by_timer";
			this->start_by_timer->Size = System::Drawing::Size(83, 23);
			this->start_by_timer->TabIndex = 5;
			this->start_by_timer->Text = L"Выполнить";
			this->start_by_timer->UseVisualStyleBackColor = true;
			this->start_by_timer->Click += gcnew System::EventHandler(this, &Form1::start_by_timer_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->formula);
			this->groupBox2->Location = System::Drawing::Point(6, 238);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(308, 84);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Функция";
			// 
			// formula
			// 
			this->formula->AllowUserToAddRows = false;
			this->formula->AllowUserToDeleteRows = false;
			this->formula->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->formula->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->dataGridViewTextBoxColumn1, 
				this->rol2});
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->formula->DefaultCellStyle = dataGridViewCellStyle4;
			this->formula->Location = System::Drawing::Point(9, 19);
			this->formula->Name = L"formula";
			this->formula->RowHeadersVisible = false;
			this->formula->Size = System::Drawing::Size(288, 59);
			this->formula->TabIndex = 3;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"x1";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->dataGridViewTextBoxColumn1->Width = 30;
			// 
			// rol2
			// 
			this->rol2->HeaderText = L"x2";
			this->rol2->Name = L"rol2";
			this->rol2->Width = 30;
			// 
			// next_step
			// 
			this->next_step->Enabled = false;
			this->next_step->Location = System::Drawing::Point(226, 328);
			this->next_step->Name = L"next_step";
			this->next_step->Size = System::Drawing::Size(82, 23);
			this->next_step->TabIndex = 5;
			this->next_step->Text = L"По шагам";
			this->next_step->UseVisualStyleBackColor = true;
			this->next_step->Click += gcnew System::EventHandler(this, &Form1::next_step_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(96, 328);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Инициализировать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::init_args);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Controls->Add(this->groupBox2);
			this->panel1->Controls->Add(this->start_by_timer);
			this->panel1->Controls->Add(this->next_step);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(298, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(317, 360);
			this->panel1->TabIndex = 1001;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightYellow;
			this->ClientSize = System::Drawing::Size(617, 361);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->rtb);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Symplex meth";
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->grid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vect))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->N))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->M))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->formula))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
	
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
		int n = N->Value.ToInt32(N->Value);
		int m = M->Value.ToInt32(M->Value);
		if(formula->RowCount < 1)
		{
			formula->Rows->Add();
		}
		while(grid->ColumnCount > m)
		{
			grid->Columns->RemoveAt(m);
			formula->Columns->RemoveAt(m);
		}
		while(grid->ColumnCount < m)
		{
			grid->Columns->Add("col"+(grid->ColumnCount+1),"x"+(grid->ColumnCount+1));
			grid->Columns[grid->ColumnCount-1]->Width = 30;
			formula->Columns->Add("rol"+(formula->ColumnCount+1),"x"+(formula->ColumnCount+1));
			formula->Columns[formula->ColumnCount-1]->Width = 30;
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
	void normalize(int i)
	{
		double nt = sm[i][basis[i]];
		rep(j,0,m)
			sm[i][j] = sm[i][j]/nt;
		fr[i] /= nt;
	}
	void create_basis()
	{
		rep(i,0,n)
			basis[i] = -1;
		int k = 0,f = 0, fi=0;
		rep(i,0,n)
			rep(j,0,m)
			{
				if(k==n)
					break;
				if(Math::Abs(sm[i][j]) < EPS)
					continue;
				f = 0;
				rep(p,0,n)
					if(Math::Abs(sm[p][j]) > EPS)
						f++;
				if(f == 1) { basis[i] = j; k++; used_in_basis[j] = 1; }
				if(k==n)
					break;
			}
		rep(i,0,n)
			if(basis[i] > 0)
				normalize(i);
		if(k == n)
		{
			rtba("\nБазис успешно сформирован\n");
			return;
		}
		else
		{
			rep(i,0,n)
			{
				if(basis[i] == -1)
					rep(j,0,m)
						if(!used_in_basis[j] && Math::Abs(sm[i][j]) > EPS)
						{
							change_basis(i,j);
							k++;
							j = 0;
							break;
						}
				if(k == n)
					break;
			}
			if(k == n)
			{
				rtba("\nБазис успешно сформирован\n");
				return;
			}
			//rtba("\nКритическая ошибка постоения базиса\n");
			return;
		}

	}
	void out()
	{
		n = grid->RowCount;
		m = grid->ColumnCount;
		rtba("\nСимплексная матрица:\n     ");
		
		rep(i,0,n)
		{
			rtba("\n");
			rtba("x"+(basis[i]+1)+" | ");
			rep(j,0,m)
				rtba("\t"+evalf(sm[i][j],2)+" ");
			rtba("\t| "+evalf(fr[i],2));
		}
		rtba("\nF:  | ");
		rep(i,0,m)
			rtba("\t"+evalf(re[i],2)+" ");
		rtba("\t| "+evalf(count,2));
		rtba("\n");
	}
	void initialize()
	{
		n = grid->RowCount;
		m = grid->ColumnCount;
		sm = vvd(n, vd(m,0));
		re = vd(m,0);
		used_in_basis = vi(m,0);
		basis = vi(n,0);
		fr = vd(n,0);
		ans = vd(m,0);
		count = 0;
		rep(i,0,n)
			rep(j,0,m) 
				sm[i][j] =  Convert::ToDouble(grid[j,i]->Value);
		rep(i,0,n)
			fr[i] = Convert::ToDouble(vect[0,i]->Value);
		rep(i,0,m)
			re[i] = Convert::ToDouble(formula[i,0]->Value);
		count = 0;
		rtb->Text = "";
		create_basis();
		
	}
	void N_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		set_row_col();
	}
	void get_ans()
	{
		rep(i,0,m)
			ans[i] = 0;
		rep(i,0,n)
			ans[basis[i]] = fr[i];
	}
	void print_ans()
	{
		rtba("\nВектор решения:\n(");
		rep(i,0,m-1)
			rtba(""+evalf(ans[i],4)+";  ");
		rtba(""+evalf(ans[m-1],4)+")\t F(x) = "+evalf(count,4)+"\n");
	}
	void change_basis(int i, int j)
	{
		if(basis[i] > 0)
			used_in_basis[basis[i]] = 0;
		used_in_basis[j] = 1;
		basis[i] = j;
		double temp;
		normalize(i);
		rep(k,0,n)
		{
			if(k == i)
				continue;
			temp = sm[k][j];
			rep(p,0,m)
				sm[k][p] -= sm[i][p]*temp;
			fr[k] -= fr[i]*temp;
		}
		temp = re[j];
		rep(p,0,m)
			re[p] -= sm[i][p]*temp;
		count -= fr[i]*temp;
	}
	int one_step()
	{
		get_ans();
		print_ans();
		rep(i,0,m)
			if(ans[i] < 0)
			{
				rtba("\nНедопустимое решение, переменная x"+(i+1)+"\n");
				rep(k,0,n)
					if(basis[k] == i)
					{//ищем базис в k-й строке.
						rep(p,0,m)
						{
							if(!used_in_basis[p] && sm[k][p] < 0)
							{
								rtba("\nCмена базиса x"+(basis[k]+1)+" <-> x"+(p+1)+"\n");
								change_basis(k,p);
								out();
								return 0;
							}
						}
						break;
					}
					rtba("\nНет решения\n");
					return 1;
			}
		int xmin = 0,xmin2=-1;
		double min = re[0],min2 =0;
		rep(i,0,m)
			if(re[i]<min){ min = re[i]; xmin = i;}
		if(min < 0)
		{
			rtba("\nРешение допустимо, но неоптимально. Меняю базис.\n");
			rep(i,0,n)
			{
				if(Math::Abs(sm[i][xmin]) < EPS)
					continue;
				if(fr[i]/sm[i][xmin] < 0)
					continue;
				else if(xmin2<0)
				{
					min2 = fr[i]/sm[i][xmin];
					xmin2 = i;
				}
				else if(fr[i]/sm[i][xmin] < min2)
				{
					min2 = fr[i]/sm[i][xmin];
					xmin2 = i;
				}
			}
			if(xmin2 < 0)
			{
				rtba("\nРешение бесконечно большое. Конец.\n");
				return 1;
			}
			rtba("\nCмена базиса x"+(basis[xmin2]+1)+" <-> x"+(xmin+1)+"\n");
			change_basis(xmin2,xmin);
			out();

		}
		else
		{
			rtba("\nРешение допустимо и оптимально");
			rep(i,0,m)
				if(!re[i] && !used_in_basis[i])
				{
					rtba(" (достигается в нескольких точках)\n");
					return 1;
				}
			rtba(" (достигается в одной точке)\n");
			return 1;
		}
		return 0;
	}
	void start_by_timer_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		initialize();
		if(rtb->Text->Length == 0)
		{
			rtb->Text = L"Недопустимая система";
			return;
		}
		out();
		while(one_step() == 0)
			;
		rtba("\nКонец метода, решение оптимально и допустимо\n");

	}
	void next_step_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if(one_step() == 1)
		{
			rtba("\nКонец метода, решение оптимально и допустимо\n");
		}
	}
	void init_args(System::Object^  sender, System::EventArgs^  e) 
	{
		initialize();
		if(rtb->Text->Length != 0)
		{
			next_step->Enabled = true;
			out();
		}
		else
			next_step->Enabled = false;
	}
	void Form1_Resize(System::Object^  sender, System::EventArgs^  e) 
	{
		panel1->Location = Point(this->Width - 633 + 298+8,1);
		rtb->Width = this->Width - panel1->Width-9;
		rtb->Height = this->Height-35;
	}
};
}

