#pragma once


namespace lab1 {

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
			
			g = pic->CreateGraphics();;
			n = 10;
			max = n*1.25;
			may = 0;
			pr = gcnew array<double>(n);
			p = gcnew array<double>(n);
			x = gcnew array<double>(n);
			y = gcnew array<double>(n);
			_a = gcnew array<double>(n);
			_b = gcnew array<double>(n);
			_c = gcnew array<double>(n);
			
			for(int i = 0; i < n; i++)
			{
				p[i] = 0;
				pr[i] = 0;
				if(i >= 10)
					y[i] = 100.0/i;
				x[i] = i+1;
				if(Math::Abs(y[i]) > may)
					may = Math::Abs(y[i]);
			}
			if(may < 10e-5)
				may = 10e-5;
			else may *= 1.25;
			richTextBox2->Text = "Количество точек: "+n;
			for(int i = 0; i < n; i++)
			{
				richTextBox2->Text += "\nx["+i+"] = "+x[i]+"\ny["+i+"] = "+y[i];
			}
			
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

	protected: 

	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::PictureBox^  pic;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Label^  label3;


	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::NumericUpDown^  B;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  epsilon;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pic = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->B = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->epsilon = (gcnew System::Windows::Forms::NumericUpDown());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->epsilon))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(557, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(244, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Функция 1 методом Эйлера";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(557, 41);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(244, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Функция 1 методом Рунге-Кутты 4 порядка";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(557, 70);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(244, 23);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Функция 2 методом Эйлера";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(557, 99);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(244, 23);
			this->button4->TabIndex = 1;
			this->button4->Text = L"Функция 2 методом Рунге-Кутты 4 порядка";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// pic
			// 
			this->pic->Location = System::Drawing::Point(0, 0);
			this->pic->Name = L"pic";
			this->pic->Size = System::Drawing::Size(551, 524);
			this->pic->TabIndex = 4;
			this->pic->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(554, 163);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"На интервале от x[0] ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 499);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(626, 190);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"до x[n] =";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(557, 128);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(244, 23);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Функция 2 двухшаговым методом Адамса";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(565, 242);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Точки:";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(568, 258);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(224, 254);
			this->richTextBox2->TabIndex = 9;
			this->richTextBox2->Text = L"";
			// 
			// B
			// 
			this->B->DecimalPlaces = 9;
			this->B->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 458752});
			this->B->Location = System::Drawing::Point(677, 188);
			this->B->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, 0});
			this->B->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->B->Name = L"B";
			this->B->Size = System::Drawing::Size(115, 20);
			this->B->TabIndex = 11;
			this->B->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(557, 217);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"С точностью";
			// 
			// epsilon
			// 
			this->epsilon->DecimalPlaces = 9;
			this->epsilon->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 458752});
			this->epsilon->Location = System::Drawing::Point(677, 217);
			this->epsilon->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, 0});
			this->epsilon->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, System::Int32::MinValue});
			this->epsilon->Name = L"epsilon";
			this->epsilon->Size = System::Drawing::Size(115, 20);
			this->epsilon->TabIndex = 5;
			this->epsilon->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(529, 11);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(22, 53);
			this->button6->TabIndex = 12;
			this->button6->Text = L"1+2";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(529, 70);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(22, 81);
			this->button7->TabIndex = 12;
			this->button7->Text = L"3+4+5";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 487);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(151, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Синий методом Рунге-Кутты";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 473);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(145, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Крастный методом Эйлера";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(11, 500);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(142, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Зелёный методом Адамса";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(804, 522);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->B);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->epsilon);
			this->Controls->Add(this->pic);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->epsilon))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	Graphics^ g;
	int n;
	array<double>^x, ^y;
	int c;	//центр 
	int m;
	Bitmap^ canvas;
	double max, may;		//max по  x  и  y 
	array<double>^p;				//полином итоговый
	array<double>^pr;
	array<double>^_a,^_b,^_c;
private:
	double evalf(double d)
	{
		return ((double)((int)(d*100))/100);
	}
	void draw_array()
	{//отрисовка массива точек
		for(int i = 0; i < n; i++)
		g->DrawEllipse(Pens::Blue, c + x[i]*m*10/max - 2, c - y[i]*m*10/may - 2 , 4, 4);
	}
	int pow_one(int n)
	{
		if(n%2 == 0)
			return 1;
		else return -1;
	}
	void fill_max_may()
	{
		max = may = 0;
		if(x&&y)
		{
			for(int i = 0; i < n; i++)
			{
				if(max < Math::Abs(x[i]))
					max = Math::Abs(x[i]);
				if(may < Math::Abs(y[i]))
					may = Math::Abs(y[i]);
			}
		}
		max *= 1.25;
		may *= 1.25;
	}
	void draw_polinom(array<double>^p, int s, int f, Pen ^pen)
	{//отрисовка полинома
		double temp;
		int l = 2;
		array<Point>^res = gcnew array<Point>(l);
		for(int i = 0; i < l; i++)
			res[i].X = c + (x[s]+ i*(x[f]-x[s]))*m*10/max;
		for(int i = 0; i < l; i++)
		{
			temp = 0;
			for(int  j = 0; j < p->Length; j++)
				temp = temp + Math::Pow(x[s]+ i*(x[f]-x[s]), j)*p[j];
			res[i].Y = c - temp*m*10/may;
		}
		g->DrawLines(pen, res);
	}
	void draw_coord()
	{//отрисовка осей
		m = 22;
		c = pic->Height/2;
		g->DrawLine(Pens::Black, c, c*2 - 40, c, 10); 
		g->DrawLine(Pens::Black, c + 5, 20, c, 10);
		g->DrawLine(Pens::Black, c - 5, 20, c, 10);
		g->DrawLine(Pens::Black, 10, c, c*2 - 20, c);
		g->DrawLine(Pens::Black, c*2 - 30, c + 5, c*2 - 20, c);
		g->DrawLine(Pens::Black, c*2 - 30, c - 5, c*2 - 20, c);
		for(int i = -5; i <= 5; i++)
		{
			g->DrawString(""+evalf(2*i*max/10.),this->Font, Brushes::Black, c + 2*i*m + 5, c + 7); 
			g->DrawLine(Pens::Black, c +2*i*m, c + 2, c +2*i*m, c - 2);
			if(i)
			g->DrawString(""+evalf(2*i*(-may/10.)),this->Font, Brushes::Black, c +4 , c + 2*i*m + 5); 
			g->DrawLine(Pens::Black, c + 2, c + 2*i*m, c - 2, c + 2*i*m);
		}
	}
	void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		button2_Click(sender,e);
	}
	double f_pr(int i, int j)
	{// i = pointA, j = pointB
		if(j == i+1)
			return((y[j] - y[i])/(x[j] - x[i]));
		return((f_pr(i+1, j) - f_pr(i, j-1))/(x[j] - x[i]));
	}
	void op_br(int i, int j,double k, int deg)
	{
		if(i == j)
		{
			p[deg] = p[deg] -x[i]*k;
			p[deg+1] = p[deg+1] + k;
			return;
		}
		op_br(i+1, j, k, deg+1);
		op_br(i+1, j, -k*x[i], deg);
	}
	void interpolate()
	{
		pr[0] = y[0];
		p[0] = 0;
		for(int i = 1; i < n; i++)
		{
			p[i] = 0;
			pr[i] = f_pr(0, i);		
		}
		p[0] += pr[0];
		for(int i = 0; i < n-1; i++)
			op_br(0, i, pr[i+1], 0);
		draw_polinom(p, x[0], x[n-1],Pens::Green);
		
	}
	double* gauss(double**a, double*b, int n)
	{
		double temp;
		for(int i = 0; i < n; i++)
		{
			if(a[i][i] == 0)
			{
				bool f = false;
				for(int j = i+1; j < n; j++)
					if(a[j][i] != 0)
					{
						f = true;
						for(int k = 0; k < n; k++)
						{
							temp = a[i][k];
							a[i][k] = a[j][k];
							a[j][k] = temp;
						}
					}
				if(f == false)
					a[i][i] = 0.00001;	//бред, так не бывает
			}
			for(int j = i+1; j < n; j++)
			{
				temp = a[j][i];
				for(int k = i; k < n; k++)
					a[j][k] = a[j][k] -  a[i][k]*temp/a[i][i];
				b[j] = b[j] - b[i]*temp/a[i][i];
			}
		}
		for(int i = n-1; i >= 0; i--)
		{
			b[i] = b[i]/a[i][i];
			a[i][i] = 1;
			for(int j = i-1; j >= 0; j--)
			{
				b[j] = b[j] - a[j][i]*b[i];
			}
		}
		return b;
	}
	void solve_sys()
	{
		double **a = new double*[6], *b = new double[6];;
		for(int i = 0; i < 6; i++)
		{
			a[i] = new double[6];
			b[i] = 0;
		}
		for(int i = 0; i < 6; i++)
			for(int j = 0; j < 6; j++)
				a[i][j] = 0;
		a[0][0] = 2*x[0];
		a[1][1] = a[0][1] = 1;
		a[1][0] = 2*x[1];
		a[1][4]  = -1;
		a[1][3] = -2*x[1];
		a[2][0] = x[0]*x[0];
		a[2][1] = x[0];
		a[2][2] = 1;
		b[2] = y[0];
		a[3][0] = x[1]*x[1];
		a[3][1] = x[1];
		a[3][2] = 1;
		b[3] = y[1];
		a[4][3] = x[1]*x[1];
		a[4][4] = x[1];
		a[4][5] = 1;
		b[4] = y[1];
		a[5][3] = x[2]*x[2];
		a[5][4] = x[2];
		a[5][5] = 1;
		b[5] = y[2];
		b = gauss(a,b,6);
		_a[0] = b[0];
		_a[1] = b[3];
		_b[0] = b[1];
		_b[1] = b[4];
		_c[0] = b[2];
		_c[1] = b[5];
		for(int i = 2; i < n-1; i++)
		{
			a[0][0] = 2*x[i];
			a[0][1] = 1;
			a[0][2] = 0;
			b[0] = _a[i-1]*2*x[i] + _b[i-1];
			a[1][0] = x[i]*x[i];
			a[1][1] = x[i];
			a[1][2] = 1;
			b[1] = y[i];
			a[2][0] = x[i+1]*x[i+1];
			a[2][1] = x[i+1];
			a[2][2] = 1;
			b[2] = y[i+1];
			b = gauss(a,b,3);
			_a[i] = b[0];
			_b[i] = b[1];
			_c[i] = b[2];
		}
	}
	array<double>^ get_polinom_from_slu(int i)
	{
		array<double>^b = gcnew array<double>(3);
		b[0] = _c[i];
		b[1] = _b[i];
		b[2] = _a[i];
		return b;
	}

	void spline()
	{
		solve_sys();
		for(int i = 0; i < n-1; i++)
			draw_polinom(get_polinom_from_slu(i), i, i+1, Pens::Red);
	}
	void eiler(int num_f, double a, double b, double eps)
	{
		if(x)
			delete x;
		if(y)
			delete y;
		if(p)
			delete p;
		if(pr)
			delete pr;
		
		double h = eps;	//погрешность метода эйлера ~ шаг
		n = Math::Abs(b-a)/h + 1;
		if(n < 7)
		{
			n = 7;
			h = Math::Abs(b-a)/6.0;
		}
		pr = gcnew array<double>(n);
		p = gcnew array<double>(n);
		x = gcnew array<double>(n);
		y = gcnew array<double>(n);
		_a = gcnew array<double>(n);
		_b = gcnew array<double>(n);
		_c = gcnew array<double>(n);
		if(num_f == 1)
		{
			if(b < a)
			{
				x[n-1] = 1;
				y[n-1] = 2;
				for(int i = n-2; i >= 0; i--)
				{
					x[i] = a - h*(n - 1 - i);
					y[i] = y[i+1] - h*((y[i+1]*y[i+1]*Math::Log(x[i+1]) - 2*y[i+1])/(2*x[i+1]));
				}
			}
			else
			{
				x[0] = 1;
				y[0] = 2;
				for(int i = 1; i< n; i++)
				{
					x[i] = a + h*i;
					y[i] = y[i-1] + h*((y[i-1]*y[i-1]*Math::Log(x[i-1]) - 2*y[i-1])/(2*x[i-1]));
				}
			}
		}
		else
		{
			x[0] = 0;
			y[0] = 7/9.0;
			double p1=0,p2=0;
			for(int i = 1; i < n; i++)
			{
				x[i] = a+h*i;
				p2 = p1 + h*(Math::Exp(-x[i-1])+4*p1 - 4*y[i-1]);
				y[i] = y[i-1] + h*(p1);
				p1=p2;
			}
		}
		richTextBox2->Text = "Количество точек: "+n;
		if(richTextBox2->Enabled==true)
			for(int i = 0; i < n; i++)
				richTextBox2->Text += "\nx["+i+"] = "+x[i]+"\ny["+i+"] = "+y[i];

		if(num_f == 1)
			fill_max_may();
		else
		{
			max = b*1.25;
			may = 150;
		}
		draw_coord();
		//draw_array();
		//interpolate();
		//spline();
		if(n> 100)
		for(int i = 0; i+n/20. < n; i+=n/20.)
			g->DrawLine(Pens::Red, (int)(c+ (double)x[i]*m*10/max), c - y[i]*m*10/may, c+ x[i+n/20.]*m*10/max, c - y[i+n/20.]*m*10/may);
		else
			for(int i = 0; i < n-1; i++)
				g->DrawLine(Pens::Red, (int)(c+ (double)x[i]*m*10/max), c - y[i]*m*10/may, c+ x[i+1]*m*10/max, c - y[i+1]*m*10/may);
	}
	double f1(double x, double  y)
	{
		return (y*y*Math::Log(x) - 2*y)/(2*x);
	}
	double f2(double x, double  y, double p)
	{
		return Math::Exp(-x)+4*p - 4*y;
	}
	double f2_true(double x)
	{
		return (2/3.*Math::Exp(2*x)-11/9.*Math::Exp(2*x)*x+1/9.*Math::Exp(-x));
	}
	void runge_kutta_4deg(int num_f, int a, int b, double eps)
	{
		if(x)
			delete x;
		if(y)
			delete y;
		if(p)
			delete p;
		if(pr)
			delete pr;
		if(num_f != 1)
			eps/=100;
		
		double h = Math::Pow(eps, 0.5);	//погрешность метода рунге-кутты 4 порядка ~ шаг^4
		n = Math::Abs(b-a)/h + 1;
		if(n < 7)
		{
			n = 7;
			h = Math::Abs(b-a)/6.0;
		}
		pr = gcnew array<double>(n);
		p = gcnew array<double>(n);
		x = gcnew array<double>(n);
		y = gcnew array<double>(n);
		_a = gcnew array<double>(n);
		_b = gcnew array<double>(n);
		_c = gcnew array<double>(n);
		double _m[5];
		double k[5];
		if(num_f == 1)
		{
			x[0] = 1;
			y[0] = 2;
			for(int i = 1; i< n; i++)
			{
				x[i] = a + h*i;
				k[1] = h*f1(x[i-1],y[i-1]);
				k[2] = h*f1(x[i-1] + h/2, y[i-1]+k[1]/2);
				k[3] = h*f1(x[i-1] + h/2, y[i-1]+k[2]/2);
				k[4] = h*f1(x[i-1] + h, y[i-1]+k[3]);
				y[i] = y[i-1] + 1/6.0*(k[1]+2*k[2]+2*k[3]+k[4]);
			}
		}
		else
		{
			x[0] = 0;
			y[0] = 7/9.0;
			double p1=0,p2=0;
			for(int i = 1; i < n; i++)
			{
				x[i] = a+h*i;
				k[1] = h*f2(x[i-1],y[i-1], p1);
				_m[1] = h*p1;
				k[2] = h*f2(x[i-1] + h/2, y[i-1]+k[1]/2, p1 + _m[1]/2);
				_m[2] = h*(p1 + _m[1]/2);
				k[3] = h*f2(x[i-1] + h/2, y[i-1]+k[2]/2, p1 + _m[2]/2);
				_m[3] = h*(p1 + _m[2]/2);
				k[4] = h*f2(x[i-1] + h, y[i-1]+k[3], p1 + _m[3]);
				_m[4] = h*(p1 + _m[3]);
				y[i] = y[i-1] + 1/6.0*(_m[1] + 2*_m[2] + 2*_m[3] + _m[4]);
				p1 = p1 + 1/6.0*(k[1] + 2*k[2] + 2*k[3] + k[4]);
			}
		}
			richTextBox2->Text = "Количество точек: "+n;
		if(richTextBox2->Enabled==true)
			for(int i = 0; i < n; i++)
				richTextBox2->Text += "\nx["+i+"] = "+x[i]+"\ny["+i+"] = "+y[i];
			if(num_f == 1)
			fill_max_may();
		else
		{
			max = b*1.25;
			may = 150;
		}
		draw_coord();
		//draw_array();
		//spline();
		if(n> 100)
		for(int i = 0; i+n/20. < n; i+=n/20.)
			g->DrawLine(Pens::Blue, (int)(c+ (double)x[i]*m*10/max), c - y[i]*m*10/may, c+ x[i+n/20.]*m*10/max, c - y[i+n/20.]*m*10/may);
		else
			for(int i = 0; i < n-1; i++)
				g->DrawLine(Pens::Blue, (int)(c+ (double)x[i]*m*10/max), c - y[i]*m*10/may, c+ x[i+1]*m*10/max, c - y[i+1]*m*10/may);
		
	}
	void adams(int a, int b, double eps)
	{
		if(x)
			delete x;
		if(y)
			delete y;
		if(p)
			delete p;
		if(pr)
			delete pr;		
		double h = Math::Pow(eps/2., 0.5);	//погрешность двухшагового метода адамса ~ шаг^2
		n = Math::Abs(b-a)/h + 2;
		if(n < 7)
		{
			n = 7;
			h = Math::Abs(b-a)/6.0;
		}
		pr = gcnew array<double>(n);
		p = gcnew array<double>(n);
		x = gcnew array<double>(n);
		y = gcnew array<double>(n);
		_a = gcnew array<double>(n);
		_b = gcnew array<double>(n);
		_c = gcnew array<double>(n);
		double p1 = 0, p2 = 0, temp = 0;
		x[0] = 0;
		y[0] = 7/9.0;
		x[1] = a+h;
		y[1] = y[0] + p2*h;//f2_true(x[1]);
		p1 = 0;//-2*h;		//найдено опытным путём
		for(int i = 2; i < n; i++)
		{
			x[i] = a + h*i;
			y[i] = y[i-1] + h/2*(3*p1 - p2);
			temp = p1 + h/2*(3*f2(x[i-1],y[i-1],p1) - f2(x[i-2],y[i-2],p2));
			p2 = p1;
			p1 = temp;
		}
			richTextBox2->Text = "Количество точек: "+n;
		if(richTextBox2->Enabled==true)
			for(int i = 0; i < n; i++)
				richTextBox2->Text += "\nx["+i+"] = "+x[i]+"\ny["+i+"] = "+y[i];
		//fill_max_may();
		max = b*1.25;
		may = 150;
		draw_coord();
		//draw_array();
		//spline();
		if(n> 100)
		for(int i = 0; i+n/20. < n; i+=n/20.)
			g->DrawLine(Pens::Green, (int)(c+ (double)x[i]*m*10/max), c - y[i]*m*10/may, c+ x[i+n/20.]*m*10/max, c - y[i+n/20.]*m*10/may);
		else
			for(int i = 0; i < n-1; i++)
				g->DrawLine(Pens::Green, (int)(c+ (double)x[i]*m*10/max), c - y[i]*m*10/may, c+ x[i+1]*m*10/max, c - y[i+1]*m*10/may);
	}
	void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		g->Clear(Color::White);
		eiler(1, 1, B->Value.ToDouble(B->Value),epsilon->Value.ToDouble(epsilon->Value));
		
	}
	void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		g->Clear(Color::White);
		runge_kutta_4deg(1, 1, B->Value.ToDouble(B->Value),epsilon->Value.ToDouble(epsilon->Value));
		
	}
	void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		g->Clear(Color::White);
		eiler(2, 0, B->Value.ToDouble(B->Value),epsilon->Value.ToDouble(epsilon->Value));
	}
	
	void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		g->Clear(Color::White);
		runge_kutta_4deg(2, 0, B->Value.ToDouble(B->Value),epsilon->Value.ToDouble(epsilon->Value));
	}


private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		g->Clear(Color::White);
		adams( 0, B->Value.ToDouble(B->Value),epsilon->Value.ToDouble(epsilon->Value));
	}
	void button6_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		richTextBox2->Enabled = false;
		g->Clear(Color::White);
		eiler(1, 1, B->Value.ToDouble(B->Value),epsilon->Value.ToDouble(epsilon->Value));
		runge_kutta_4deg(1, 1, B->Value.ToDouble(B->Value),epsilon->Value.ToDouble(epsilon->Value));
		richTextBox2->Enabled = true;
	}
	void button7_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		richTextBox2->Enabled = false;
		g->Clear(Color::White);
		eiler(2, 0, B->Value.ToDouble(B->Value),epsilon->Value.ToDouble(epsilon->Value));
		runge_kutta_4deg(2, 0, B->Value.ToDouble(B->Value),epsilon->Value.ToDouble(epsilon->Value));
		adams( 0, B->Value.ToDouble(B->Value),epsilon->Value.ToDouble(epsilon->Value));
		richTextBox2->Enabled = true;
	}
};
}

