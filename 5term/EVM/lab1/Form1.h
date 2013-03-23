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
			//
			//TODO: добавьте код конструктора
			//
			//g = CreateGraphics();
			//canvas = gcnew Bitmap(this->Width, this->Height);
			//g = g->FromImage(canvas);
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
			y[0] = 1.09;
			y[1] = 0.98;
			y[2] = 0.94;
			y[3] = 0.87;
			y[4] = 0.76;
			y[5] = 0.65;
			y[6] = 0.51;
			y[7] = 0.33;
			y[8] = 0.21;
			y[9] = 0.09;
			/*y[0] = 1;
			y[1] = 2;
			y[2] = 4;
			y[3] = 4;*/
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
			interpolate();
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
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;

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
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(557, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(244, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Заполнить случайно";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(557, 41);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(244, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Интерполировать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(557, 70);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(244, 23);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Интерполировать сплайнами";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(557, 99);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(244, 23);
			this->button4->TabIndex = 1;
			this->button4->Text = L"Аппроксимировать";
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
			// numericUpDown1
			// 
			this->numericUpDown1->DecimalPlaces = 9;
			this->numericUpDown1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 589824});
			this->numericUpDown1->Location = System::Drawing::Point(662, 161);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(139, 20);
			this->numericUpDown1->TabIndex = 5;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(554, 163);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Введите аргумент";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 499);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 7;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(662, 187);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(139, 20);
			this->textBox1->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(554, 190);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Значение в точке:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(554, 209);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(111, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Формула полинома:";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(568, 229);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(224, 182);
			this->richTextBox1->TabIndex = 9;
			this->richTextBox1->Text = L"";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(557, 128);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(244, 23);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Совместить графики";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(557, 424);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Точки:";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(568, 440);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(224, 72);
			this->richTextBox2->TabIndex = 9;
			this->richTextBox2->Text = L"";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(804, 522);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown1);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
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
	void draw_polinom(array<double>^p, double s, double f, Pen ^pen)
	{//отрисовка полинома
		double temp;
		int l = Math::Abs((f-s)*2);
		if(l < 1)
			l = 1;
		array<Point>^res = gcnew array<Point>(l+1);
		for(int i = 0; i <= l; i++)
			if(i != l)
				res[i].X = c + (i/2.0 + s)*m*10/max;
			else
				res[l].X = c + (f+0.1)*m*10/max;
		//res[l].X = c+ f*m*10/max;
		for(int i = 0; i <= l; i++)
		{
			temp = 0;
			for(int  j = 0; j < p->Length; j++)
				temp = temp + Math::Pow(i/2.0 + s, j)*p[j];
			res[i].Y = c - temp*m*10/may;
		}	
		g->DrawLines(pen, res);
	}
	void draw_spline(array<double>^p, double s, double f, Pen ^pen)
	{//отрисовка сплайна
		double temp;
		int l = 10;
		array<Point>^res = gcnew array<Point>(l);
		for(int i = 0; i < l; i++)
			if(i != l)
				res[i].X = c + (i/((double)l-1)*(f-s) + s)*m*10/max;
		for(int i = 0; i < l; i++)
		{
			temp = 0;
			for(int  j = 0; j < p->Length; j++)
				temp = temp + Math::Pow(i/((double)l-1)*(f-s) + s, j)*p[j];
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
			g->DrawString(""+2*i*max/10.,this->Font, Brushes::Black, c + 2*i*m + 5, c + 7); 
			g->DrawLine(Pens::Black, c +2*i*m, c + 2, c +2*i*m, c - 2);
			if(i)
			g->DrawString(""+2*i*(-may/10.),this->Font, Brushes::Black, c +4 , c + 2*i*m + 5); 
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
		draw_polinom(p, x[0] - 3, x[n-1] + 3,Pens::Green);
		richTextBox1->Text = "" + p[0];
		for(int i = 1; i < n; i++)
			richTextBox1->Text = richTextBox1->Text + " + \n" + p[i] + "*x^" + i;
	}
	void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		numericUpDown1->Enabled = true;
		numericUpDown1->Maximum = static_cast<Decimal>(max*1000);
		numericUpDown1->Minimum = static_cast<Decimal>(-max*1000);
		g->Clear(Color::White);
		draw_coord();
		draw_array();
		interpolate();
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
			draw_spline(get_polinom_from_slu(i), x[i], x[i+1], Pens::Red);
		draw_spline(get_polinom_from_slu(0), x[0]-1, x[0], Pens::Red);
		draw_spline(get_polinom_from_slu(n-2), x[n-1], x[n-1]+5, Pens::Red);
	}
	void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		g->Clear(Color::White);
		draw_coord();
		draw_array();
		spline();
	}
	void approximate()
	{
		array<double>^b = gcnew array<double>(3);
		double a[3][3], temp, temp2;
		for(int k = 0; k < 3; k++)
			for(int j = 0; j < 3; j++)
			{
				temp = 0; temp2 = 0;
				for(int i = 0; i < n; i++)
				{
					temp += Math::Pow(x[i], k+j);
					temp2 += y[i]*Math::Pow(x[i], k);
				}
				a[k][j] = temp;
				b[k] = temp2;
			}
		for(int k = 0; k < 2; k++)
		{
			for(int j = k+1; j < 3; j++)
			{
				temp = a[j][k];
				for(int s = k; s < 3; s++)
					a[j][s] =a[j][s] - a[k][s]*temp/a[k][k];
				b[j] = b[j] - b[k]*temp/a[k][k];
			}
		}
		b[2] = b[2]/a[2][2];
		b[1] = (b[1] - b[2]*a[1][2])/a[1][1];
		b[0] = (b[0] - b[2]*a[0][2] - b[1]*a[0][1])/a[0][0];
		draw_polinom(b, x[0] - 1, x[n-1] + 1, Pens::Blue);
	}
	void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		g->Clear(Color::White);
		draw_coord();
		draw_array();
		approximate();
	}
	void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//numericUpDown1->Enabled = false;
		Random^ rand = gcnew Random();
		n = rand->Next(3, 10);
		max = rand->Next(10, 100);
		may = rand->Next(10, 100);
		pr = gcnew array<double>(n);
		p = gcnew array<double>(n);
		x = gcnew array<double>(n);
		y = gcnew array<double>(n);
		for(int i = 0; i < n; i++)
		{
			p[i] = 0;
			pr[i] = 0;
			y[i] = rand->NextDouble()*may*2 - may;
			x[i] = rand->NextDouble()*max*2 - max;
		}
		may = may * 1.25;
		max = max * 1.25;
		x->Sort(x);
		richTextBox2->Text = "Количество точек: "+n;
		for(int i = 0; i < n; i++)
		{
			richTextBox2->Text += "\nx["+i+"] = "+x[i]+"\ny["+i+"] = "+y[i];
		}
		button5_Click(sender,e);
	}
	void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		double arg = static_cast<double>(numericUpDown1->Value), temp = 0;
		for(int  j = 0; j < p->Length; j++)
				temp = temp + Math::Pow(arg, j)*p[j];
		textBox1->Text = "" + temp;
	}
	void button5_Click(System::Object^  sender, System::EventArgs^  e) 
	{//вывод всего и сразу
		g->Clear(Color::White);
		draw_coord();
		draw_array();
		interpolate();
		approximate();
		spline();
	}
};
}

