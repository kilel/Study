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
			this->button1->Size = System::Drawing::Size(244, 110);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Решить интегральное уравнение";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
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
		button1_Click(sender,e);
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
	void draw_y()
	{
		if(n > 100)
		for(int i = 0; i+n/20. < n; i+=n/20.)
			g->DrawLine(Pens::Red, (int)(c->X + (double)x[i]*m*10/max), c->Y - y[i]*m*10/may, c->X+ x[i+n/20.]*m*10/max, c->Y - y[i+n/20.]*m*10/may);
		else
		for(int i = 0; i < n-1; i++)
			g->DrawLine(Pens::Red, (int)(c->X + (double)x[i]*m*10/max), c->Y - y[i]*m*10/may, c->X+ x[i+1]*m*10/max, c->Y - y[i+1]*m*10/may);
		g->DrawLine(Pens::Gray, (int)(c->X + (double)m*10/max), c->Y + 6*m*10/may, c->X+ m*10/max, c->Y - 6*m*10/may);
	}
	void solve_int(double eps)
	{
		if(x)
			delete x;
		if(y)
			delete y;
		double h = eps;
		n = 1./h + 1;
		double **a, *b;
		x = gcnew array<double>(n);
		y = gcnew array<double>(n);
		a = new double*[n];
		b = new double[n];
		for(int i = 0; i < n; i++)
		{
			a[i] = new double[n];
			b[i] = Math::Cos(2*i*h)*(n-1);
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i == j)
					a[i][j] = n-1 - 1/3.*(i*i*h*h + Math::Sin(i*i*h*h));
				else
					a[i][j] = - 1/3.*(i*i*h*h + Math::Sin(i*j*h*h));
		b = gauss(a,b,n);
		for(int i = 0; i < n; i++)
		{
			y[i] = b[i];
			x[i] = i*h;
		}
		richTextBox2->Text = "Количество точек: "+n;
		if(checkBox1->Checked == true)
			for(int i = 0; i < n; i++)
				richTextBox2->Text += "\nx["+i+"] = "+x[i]+"\ny["+i+"] = "+y[i];
		max = 1/last_m;
		may = 1/last_m;
		draw_y();
		pic->Image = canvas;
	}
	void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		
		g->Clear(Color::White);

		solve_int(Convert::ToDouble(epsilon->Value.ToString()));
		draw_coord();draw_coord();
		
	}
	void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		draw_coord();
		g->Clear(Color::White);
		//grid_meth(1,0,1, Convert::ToDouble(epsilon->Value.ToString()));
		g->Clear(Color::White);
		//grid_meth(1,0,1, Convert::ToDouble(epsilon->Value.ToString()));
		draw_coord();
		
		
	}
	void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		;
	}
	void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		;
		
		
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

