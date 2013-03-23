#pragma once
#define pi 3.14159265358979323

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
			canvas = gcnew Bitmap(pic->Height, pic->Width+10);
		//	g = pic->CreateGraphics();;
			g = g->FromImage(canvas);
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
			c = gcnew Point(0,0);
			last_m = 1;
			ch_c = false;
			c->X = pic->Height/6.0;
			c->Y = pic->Height*(5/6.);
			y1 = gcnew array<double>(n);
			y2 = gcnew array<double>(n);
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





	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::NumericUpDown^  B;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  epsilon;
	private: System::Windows::Forms::CheckBox^  checkBox1;

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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->B = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->epsilon = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
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
			this->button1->Text = L"Метод стрельбы 1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(557, 41);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(244, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Метод сеток 1";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(557, 70);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(244, 23);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Метод стрельбы 2";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(557, 99);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(244, 23);
			this->button4->TabIndex = 1;
			this->button4->Text = L"Метод сеток 2";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// pic
			// 
			this->pic->Location = System::Drawing::Point(0, 0);
			this->pic->Name = L"pic";
			this->pic->Size = System::Drawing::Size(537, 524);
			this->pic->TabIndex = 4;
			this->pic->TabStop = false;
			this->pic->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pic_MouseMove);
			this->pic->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pic_MouseDown);
			this->pic->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pic_MouseUp);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(593, 156);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Масштаб";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 499);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(556, 183);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Точки:";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(568, 202);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(224, 310);
			this->richTextBox2->TabIndex = 9;
			this->richTextBox2->Text = L"";
			// 
			// B
			// 
			this->B->DecimalPlaces = 1;
			this->B->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->B->Location = System::Drawing::Point(652, 154);
			this->B->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, 0});
			this->B->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->B->Name = L"B";
			this->B->Size = System::Drawing::Size(84, 20);
			this->B->TabIndex = 11;
			this->B->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->B->ValueChanged += gcnew System::EventHandler(this, &Form1::B_ValueChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(556, 130);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(90, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Погрешность до";
			// 
			// epsilon
			// 
			this->epsilon->DecimalPlaces = 9;
			this->epsilon->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 458752});
			this->epsilon->Location = System::Drawing::Point(652, 128);
			this->epsilon->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, 0});
			this->epsilon->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, System::Int32::MinValue});
			this->epsilon->Name = L"epsilon";
			this->epsilon->Size = System::Drawing::Size(115, 20);
			this->epsilon->TabIndex = 5;
			this->epsilon->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(685, 179);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(107, 17);
			this->checkBox1->TabIndex = 12;
			this->checkBox1->Text = L"Выводить точки";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(804, 522);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->B);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->epsilon);
			this->Controls->Add(this->pic);
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
	Bitmap^canvas;
	Graphics^ g;
	bool ch_c;
	int n;
	double last_m;
	array<double>^x, ^y, ^y1, ^y2, ^y3, ^y4;
	Point^ c;	//центр 
	int m;
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
			g->DrawEllipse(Pens::Blue, c->X + x[i]*m*10/max - 2, c->Y - y[i]*m*10/may - 2 , 4, 4);
		pic->Image = canvas;
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
		max *= 1.25/last_m;
		may *= 1.25/last_m;
	}
	void draw_polinom(array<double>^p, int s, int f, Pen ^pen)
	{//отрисовка полинома
		double temp;
		int l = 2;
		array<Point>^res = gcnew array<Point>(l);
		for(int i = 0; i < l; i++)
			res[i].X = c->X + (x[s]+ i*(x[f]-x[s]))*m*10/max;
		for(int i = 0; i < l; i++)
		{
			temp = 0;
			for(int  j = 0; j < p->Length; j++)
				temp = temp + Math::Pow(x[s]+ i*(x[f]-x[s]), j)*p[j];
			res[i].Y = c->Y - temp*m*10/may;
		}
		g->DrawLines(pen, res);
		pic->Image = canvas;
	}
	void draw_coord()
	{//отрисовка осей
		m = 22;
		
		g->DrawLine(Pens::Black, c->X, pic->Width - 40, c->X, 10); 
		g->DrawLine(Pens::Black, c->X + 5, 20, c->X, 10);
		g->DrawLine(Pens::Black, c->X - 5, 20, c->X, 10);
		g->DrawLine(Pens::Black, 10, c->Y, pic->Width - 20, c->Y);
		g->DrawLine(Pens::Black, pic->Width - 30, c->Y + 5, pic->Width - 20, c->Y);
		g->DrawLine(Pens::Black, pic->Width - 30, c->Y - 5, pic->Width - 20, c->Y);
		for(int i = (-c->X/m)*2; i <= 2*(pic->Width-c->X)/m; i++)
		{
			g->DrawString(""+evalf(2*i*max/10.),this->Font, Brushes::Black, c->X + 2*i*m + 5, c->Y + 7); 
			g->DrawLine(Pens::Black, c->X + i*m, c->Y + 2, c->X +i*m, c->Y - 2);
			g->DrawLine(Pens::Black, c->X + 2*i*m, c->Y + 4, c->X + 2*i*m, c->Y - 4);
			
		}
		for(int i = - c->Y/m; i <= (pic->Width-c->Y)/m; i++)
		{
			if(i)
			g->DrawString(""+evalf(2*i*(-may/10.)),this->Font, Brushes::Black, c->X +4 , c->Y + 2*i*m + 5); 
			g->DrawLine(Pens::Black, c->X + 2, c->Y + 2*i*m, c->X - 2, c->Y + 2*i*m);
		}
		pic->Image = canvas;
	}
	void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		button2_Click(sender,e);
	}
	
	double f1(double x, double y, double p)
	{
		return (2*x - x*p - y);
	}
	double f2(double x, double  y, double p)
	{
		return (2*x - x*x - y);
	}
	double f2_true(double x)
	{
		return (2/3.*Math::Exp(2*x)-11/9.*Math::Exp(2*x)*x+1/9.*Math::Exp(-x));
	}
	double solve_rk4(int num_f, double angle_0, double h)
	{
		double k[5];
		double _m[5];
		double p1 = angle_0;
		x[0] = 0;
		y[0] = 1;
		if(num_f == 1)
			for(int i = 1; i< n; i++)
			{
				x[i] = 0+h*i;
				k[1] = h*f1(x[i-1],y[i-1], p1);
				_m[1] = h*p1;
				k[2] = h*f1(x[i-1] + h/2, y[i-1]+k[1]/2, p1 + _m[1]/2);
				_m[2] = h*(p1 + _m[1]/2);
				k[3] = h*f1(x[i-1] + h/2, y[i-1]+k[2]/2, p1 + _m[2]/2);
				_m[3] = h*(p1 + _m[2]/2);
				k[4] = h*f1(x[i-1] + h, y[i-1]+k[3], p1 + _m[3]);
				_m[4] = h*(p1 + _m[3]);
				y[i] = y[i-1] + 1/6.0*(_m[1] + 2*_m[2] + 2*_m[3] + _m[4]);
				p1 = p1 + 1/6.0*(k[1] + 2*k[2] + 2*k[3] + k[4]);
			}
		else
			for(int i = 1; i< n; i++)
			{
				x[i] = 0+h*i;
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
		return y[n-1];
	}
	void draw_y()
	{
		if(n > 100)
		for(int i = 0; i+n/20. < n; i+=n/20.)
		{
			g->DrawLine(Pens::Red, (int)(c->X + (double)x[i]*m*10/max), c->Y - y[i]*m*10/may, c->X+ x[i+n/20.]*m*10/max, c->Y - y[i+n/20.]*m*10/may);
			g->DrawLine(Pens::Green, (int)(c->X + (double)x[i]*m*10/max), c->Y - y1[i]*m*10/may, c->X+ x[i+n/20.]*m*10/max, c->Y - y1[i+n/20.]*m*10/may);
			g->DrawLine(Pens::Blue, (int)(c->X + (double)x[i]*m*10/max), c->Y - y2[i]*m*10/may, c->X+ x[i+n/20.]*m*10/max, c->Y - y2[i+n/20.]*m*10/may);
		}
		else
			for(int i = 0; i < n-1; i++)
			{
				g->DrawLine(Pens::Red, (int)(c->X + (double)x[i]*m*10/max), c->Y - y[i]*m*10/may, c->X+ x[i+1]*m*10/max, c->Y - y[i+1]*m*10/may);
				g->DrawLine(Pens::Green, (int)(c->X + (double)x[i]*m*10/max), c->Y - y2[i]*m*10/may, c->X+ x[i+1]*m*10/max, c->Y - y2[i+1]*m*10/may);
				g->DrawLine(Pens::Blue, (int)(c->X + (double)x[i]*m*10/max), c->Y - y1[i]*m*10/may, c->X+ x[i+1]*m*10/max, c->Y - y1[i+1]*m*10/may);
			}
			g->DrawLine(Pens::Gray, (int)(c->X + (double)m*10/max), c->Y + 6*m*10/may, c->X+ m*10/max, c->Y - 6*m*10/may);
	}
	void runge_kutta_4deg(int num_f, int a, int b, double eps)
	{
		if(x)
			delete x;
		if(y)
			delete y;
		if(y1)
			delete y1;
		if(y2)
			delete y2;
		double h = Math::Pow(eps, 0.5);	//погрешность метода рунге-кутты 4 порядка ~ шаг^4
		n = Math::Abs(b-a)/h + 1;
		if(n < 7)
		{
			n = 7;
			h = Math::Abs(b-a)/6.0;
		}
		x = gcnew array<double>(n);
		y = gcnew array<double>(n);
		y1 = gcnew array<double>(n);
		y2 = gcnew array<double>(n);
		y3 = gcnew array<double>(n);
		y4 = gcnew array<double>(n);
		double angle1 = 0, angle2 = 0, angle = 0;
		
		{
			solve_rk4(num_f,0,h);
			for(int i = 0; i < n; i++)
				y1[i] = y[i];
			for(int i = 60; i > -60; i--)
			{
				if(solve_rk4(num_f,i,h)*y1[n-1] < 0)
				{
					angle2 = i;
					for(int i = 0; i < n; i++)
					{
						y4[i] = y2[i] = y[i];
						y3[i] = y1[i];
					}
					break;
				}
			}
			int k = 0;
			for(int i = 0; i < n; i++)
				if(Math::Abs(x[i]-1) < Math::Abs(x[k]-1))
					k = i;
			while(Math::Abs(y3[k] - y4[k]) > eps)
			{
				angle = (angle1+angle2)/2.;
				solve_rk4(num_f,angle,h);
				if(y[k]*y3[k] < 0)
				{
					angle2 = angle;
					for(int i = 0; i < n; i++)
						y4[i] = y[i];
				}
				else
				{
					angle1 = angle;
					for(int i = 0; i < n; i++)
						y3[i] = y[i];
				}
			}
			angle = (angle1+angle2)/2.;
			solve_rk4(num_f,angle,h);
			draw_y();
		}
		
		richTextBox2->Text = "Количество точек: "+n;
		if(checkBox1->Checked == true)
			for(int i = 0; i < n; i++)
				richTextBox2->Text += "\nx["+i+"] = "+x[i]+"\ny["+i+"] = "+y[i];
		max = 2/last_m;
		may = 2/last_m;
		pic->Image = canvas;
		
		
		
	}
	void grid_meth(int num_f, int a, int b, double eps)
	{
		if(x)
			delete x;
		if(y)
			delete y;
		if(y1)
			delete y1;
		if(y2)
			delete y2;
		if(y3)
			delete y3;
		if(y4)
			delete y4;
		double h = eps;	//погрешность метода сеток такая
		n = Math::Abs(b-a)/h + 1;
		if(n < 7)
		{
			n = 7;
			h = Math::Abs(b-a)/6.0;
		}
		x = gcnew array<double>(n);
		y = gcnew array<double>(n);
		y1 = gcnew array<double>(n);
		y2 = gcnew array<double>(n);
		y3 = gcnew array<double>(n);
		y4 = gcnew array<double>(n);
		double*P,*Q;
		P = new double[n];
		Q = new double[n];
		for(int i = 0; i < n; i++)
		{
			P[i] = Q[i] = 0;
			x[i] = h*i;
			if(num_f == 1)
			{
				y3[i] = 1/(h*h) + i/2.;
				y1[i] = 1/(h*h) - i/2.;
				y4[i] = 2*x[i];
			}
			else
			{
				y1[i] = 1/(h*h);
				y3[i] = 1/(h*h);
				y4[i] = 2*x[i] - x[i]*x[i];
			}
			y2[i] = 2/(h*h) - 1;
			
		}
		y4[1] -= y1[0]*1;
		y1[0] = 0;
		y3[n-1] = 0;
		P[1] = y3[1]/y2[1];
		Q[1] = -y4[1]/y2[1];
		for(int i = 2; i < n; i++)
		{
			P[i] = y3[i]/(y2[i] - y1[i]*P[i-1]);
			Q[i] = (y1[i]*Q[i-1]-y4[i])/(y2[i] - y1[i]*P[i-1]);
		}
		y[n-1] = Q[n-1];
		for(int i = n-2; i > 0; i--)
			y[i] = P[i]*y[i+1] + Q[i];
		y[0] = 1;
		draw_y();
		richTextBox2->Text = "Количество точек: "+n;
		if(checkBox1->Checked == true)
			for(int i = 0; i < n; i++)
				richTextBox2->Text += "\nx["+i+"] = "+x[i]+"\ny["+i+"] = "+y[i];
		max = 2/last_m;
		may = 2/last_m;
		pic->Image = canvas;
	}
	void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		draw_coord();
		g->Clear(Color::White);
		runge_kutta_4deg(1,0,2, Convert::ToDouble(epsilon->Value.ToString()));
		g->Clear(Color::White);
		runge_kutta_4deg(1,0,2, Convert::ToDouble(epsilon->Value.ToString()));
		draw_coord();
		
	}
	void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		draw_coord();
		g->Clear(Color::White);
		grid_meth(1,0,1, Convert::ToDouble(epsilon->Value.ToString()));
		g->Clear(Color::White);
		grid_meth(1,0,1, Convert::ToDouble(epsilon->Value.ToString()));
		draw_coord();
		
		
	}
	void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		draw_coord();
		g->Clear(Color::White);
		runge_kutta_4deg(2,0,2, Convert::ToDouble(epsilon->Value.ToString()));
		g->Clear(Color::White);
		runge_kutta_4deg(2,0,2, Convert::ToDouble(epsilon->Value.ToString()));
		draw_coord();
	}
	void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		draw_coord();
		g->Clear(Color::White);
		grid_meth(2,0,1, Convert::ToDouble(epsilon->Value.ToString()));
		g->Clear(Color::White);
		grid_meth(2,0,1, Convert::ToDouble(epsilon->Value.ToString()));
		draw_coord();
		
		
	}


	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		g->Clear(Color::White);
		
	}
	void B_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		max = max*last_m;
		may = may*last_m;
		last_m = Convert::ToDouble( (B->Value.ToString()));
		max = max/last_m;
		may = may/last_m;
		g->Clear(Color::White);
		draw_coord();
		draw_y();
	}
private: System::Void pic_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
				ch_c = true;
			}
private: System::Void pic_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
				if(ch_c)
				{
					c->X = e->X;
					c->Y = e->Y;
				}
				g->Clear(Color::White);
			draw_coord();
			draw_y();
			}
private: System::Void pic_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
				ch_c = false;
			}
};
}

