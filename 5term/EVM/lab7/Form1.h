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
			n_t = 10;
			max = n*1.25;
			may = 0;
			y = new double*[n_t];
			for(int i = 0; i < n_t; i++)
				y[i] = new double[n];
		
			c = gcnew Point(0,0);
			last_m = 1;
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
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::PictureBox^  pic;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::NumericUpDown^  B;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  epsilon;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::TrackBar^  track;
	private: System::Windows::Forms::NumericUpDown^  delta;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pic = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->B = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->epsilon = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->track = (gcnew System::Windows::Forms::TrackBar());
			this->delta = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->epsilon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->track))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->delta))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(557, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(244, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Явная схема";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(557, 41);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(244, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Неявная хема";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(557, 70);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(244, 23);
			this->button4->TabIndex = 1;
			this->button4->Text = L"Пройти сквозь время";
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
			this->label1->Location = System::Drawing::Point(554, 156);
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
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(554, 210);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(106, 13);
			this->label19->TabIndex = 10;
			this->label19->Text = L"Функция для Maple";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(568, 226);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(224, 286);
			this->richTextBox2->TabIndex = 9;
			this->richTextBox2->Text = L"";
			// 
			// B
			// 
			this->B->DecimalPlaces = 1;
			this->B->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->B->Location = System::Drawing::Point(662, 154);
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
			this->label6->Location = System::Drawing::Point(554, 130);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(33, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Шаги";
			// 
			// epsilon
			// 
			this->epsilon->DecimalPlaces = 9;
			this->epsilon->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 458752});
			this->epsilon->Location = System::Drawing::Point(593, 128);
			this->epsilon->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, 0});
			this->epsilon->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, System::Int32::MinValue});
			this->epsilon->Name = L"epsilon";
			this->epsilon->Size = System::Drawing::Size(86, 20);
			this->epsilon->TabIndex = 5;
			this->epsilon->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->epsilon->ValueChanged += gcnew System::EventHandler(this, &Form1::epsilon_ValueChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(716, 206);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(76, 17);
			this->checkBox1->TabIndex = 12;
			this->checkBox1->Text = L"Выводить";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &Form1::timer_Tick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(11, 463);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 6;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(557, 99);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(244, 23);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Стоп!";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(557, 183);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(185, 17);
			this->checkBox2->TabIndex = 12;
			this->checkBox2->Text = L"Результат - кривая во времени";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// track
			// 
			this->track->LargeChange = 1;
			this->track->Location = System::Drawing::Point(0, 479);
			this->track->Name = L"track";
			this->track->Size = System::Drawing::Size(537, 45);
			this->track->TabIndex = 13;
			this->track->Scroll += gcnew System::EventHandler(this, &Form1::track_Scroll);
			// 
			// delta
			// 
			this->delta->DecimalPlaces = 9;
			this->delta->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 458752});
			this->delta->Location = System::Drawing::Point(706, 128);
			this->delta->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, 0});
			this->delta->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, System::Int32::MinValue});
			this->delta->Name = L"delta";
			this->delta->Size = System::Drawing::Size(86, 20);
			this->delta->TabIndex = 5;
			this->delta->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->delta->ValueChanged += gcnew System::EventHandler(this, &Form1::epsilon_ValueChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(804, 522);
			this->Controls->Add(this->track);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->B);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->delta);
			this->Controls->Add(this->epsilon);
			this->Controls->Add(this->pic);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->epsilon))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->track))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->delta))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	Bitmap^canvas;
	double tau,h;
	Graphics^ g;
	bool ch_c;
	int n, n_t;
	int index;
	double last_m;
	array<double>^x, ^t, ^y1, ^y2, ^y3, ^y4;
	double **y;
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
	String^ dbl(double d)
	{
		String^s; 
		long long k = d;
		long long p = d*100 - k*100;
		s = "" + k + ".";
		if(p< 10)
			s += "0";
		s+= ""+p;
		return s;
	}
	
	int pow_one(int n)
	{
		if(n%2 == 0)
			return 1;
		else return -1;
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
	void draw_y(int i_t)
	{
		if(checkBox2->Checked == true)
		{
			g->Clear(Color::White);
			draw_coord();
		}
		if(n > 100)
		for(int i = 0; i+n/40. < n; i+=n/40.)
		{
			g->DrawLine(Pens::Red, (int)(c->X + (double)h*(i)*m*10/max), c->Y - y[i_t][i]*m*10/may, c->X+ h*(i+n/40)*m*10/max, c->Y - y[i_t][i+n/40]*m*10/may);
		}
		else
			for(int i = 0; i < n-1; i++)
			{
				g->DrawLine(Pens::Red, (int)(c->X + (double)h*(i)*m*10/max), c->Y - y[i_t][i]*m*10/may, c->X+ h*(i+1)*m*10/max, c->Y - y[i_t][i+1]*m*10/may);
			}
			g->DrawLine(Pens::Gray, (int)(c->X + (double)2*m*10/max), c->Y - 20*m*10/may, c->X + 2*m*10/max, c->Y );
		pic->Image = canvas;
	}
	void expl(double eps, double delta)
	{
		if(x)
			delete x;
		if(y)
			delete y;
		if(y1)
			delete y1;
		if(y2)
			delete y2;
		h = eps;
		tau = delta;		//не из устойчивости, а просто так
		double alpha = tau*tau/(h*h);
		n = 2/h + 1;
		n_t = 1/tau + 1;
		x = gcnew array<double>(n);
		y = new double*[n_t];
		t = gcnew array<double>(n);
		y1 = gcnew array<double>(n);
		y2 = gcnew array<double>(n);
		y3 = gcnew array<double>(n);
		y4 = gcnew array<double>(n);
		for(int i = 0; i < n_t; i++)
			y[i] = new double[n];
		for(int i = 0; i < n_t; i++)
			for(int j = 0; j < n; j++)
			{
				y[0][j] = h*j*h*j + 1;
				y[i][0] = Math::Sin(tau*i) + 1;
				y[i][n-1] = 5*Math::Cos(tau*i);
			}
		for(int j = 1; j < n-1; j++)
			y[1][j] = tau*(j*j*h*h/2.+6) + y[0][j];//y[1][j] = (1-2*alpha)*y[0][j] + alpha*(y[0][j-1] + y[0][j+1]) + tau*(j*j*h*h/2.+6) + tau*tau*0*j*tau*h;
		for(int i = 2; i < n_t; i++)
			for(int j = 1; j < n-1; j++)
				y[i][j] = (2-2*alpha)*y[i-1][j] + alpha*(y[i-1][j-1] + y[i-1][j+1]) - y[i-2][j] + tau*tau*(i-1)*j*tau*h;
		
		if(checkBox1->Checked == true)
		{
			String^ s = "INTERFACE_PLOT3D(GRID(0. .. 2.,0. .. 1.,Array(1.." + n + ", 1.." + n_t +", [";

				for(int i = 0; i < n-1; i++)
				{
					s+= "[";
					for(int j = 0; j < n_t-1; j++)
						s += "" + dbl(evalf(y[j][i])) + ", ";
					s += "" + dbl(evalf(y[n_t-1][i]));
						s += "],\n";
				}
				s+= "[";
				for(int j = 0; j < n_t-1; j++)
					s += "" + dbl(evalf(y[j][n-1])) + ", ";
				s += "" + dbl(evalf(y[n_t-1][n-1]));
					s += "]\n";
			s += "], datatype = float[8], order = C_order)),AXESLABELS(x,t,\"\"));";
			richTextBox2->Text = s;
		}
		max = 2/last_m;
		may = 5/last_m;
		track->Maximum = n_t-1;
		draw_y(0);
		pic->Image = canvas;
		
		
		
	}
	void impl(double eps, double delta)
	{
		if(x)
			delete x;
		if(y)
			delete y;
		if(y1)
			delete y1;
		if(y2)
			delete y2;
		h = eps;
		tau = delta;		
		double alpha = tau*tau/(h*h);
		n = 2/h + 1;
		n_t = 1/tau + 1;
		
		x = gcnew array<double>(n);
		y = new double*[n_t];
		t = gcnew array<double>(n);
		y1 = gcnew array<double>(n);
		y2 = gcnew array<double>(n);
		y3 = gcnew array<double>(n);
		y4 = gcnew array<double>(n);
		for(int i = 0; i < n_t; i++)
			y[i] = new double[n];
		
		for(int i = 0; i < n_t; i++)
			for(int j = 0; j < n; j++)
			{
				y[0][j] = h*j*h*j + 1;
				y[i][0] = Math::Sin(tau*i) + 1;
				y[i][n-1] = 5*Math::Cos(tau*i);
			}
		array<double> ^P,^Q;
		P = gcnew array<double>(n);
		Q = gcnew array<double>(n);
		for(int j = 1; j < n_t; j++)
		{
			for(int i = 1; i < n-1; i++)
				if(j == 1)
					y4[i] = -y[j-1][i] - tau*(i*i*h*h/2.0+6) - h*tau*tau*tau*i*j;
				else
					y4[i] = -2*y[j-1][i] + y[j-2][i] - h*tau*tau*tau*i*j;
			y4[1] -= y[j][0]*alpha;
			y4[n-2] -= y[j][n-1]*alpha;
			P[1] = alpha/(1+2*alpha);
			Q[1] = -y4[1]/(1+2*alpha);
			for(int i = 2; i < n-1; i++)
			{
				P[i] = alpha/((1+2*alpha) - alpha*P[i-1]);
				Q[i] = (alpha*Q[i-1]-y4[i])/((1+2*alpha) - alpha*P[i-1]);
			}
			y[j][n-2] = Q[n-2];
			for(int i = n-3; i > 0; i--)
				y[j][i] = P[i]*y[j][i+1] + Q[i];
		}
		if(checkBox1->Checked == true)
		{
			String^ s = "INTERFACE_PLOT3D(GRID(0. .. 2.,0. .. 1.,Array(1.." + n + ", 1.." + n_t +", [";

				for(int i = 0; i < n-1; i++)
				{
					s+= "[";
					for(int j = 0; j < n_t-1; j++)
						s += "" + dbl(evalf(y[j][i])) + ", ";
					s += "" + dbl(evalf(y[n_t-1][i]));
						s += "],\n";
				}
				s+= "[";
				for(int j = 0; j < n_t-1; j++)
					s += "" + dbl(evalf(y[j][n-1])) + ", ";
				s += "" + dbl(evalf(y[n_t-1][n-1]));
					s += "]\n";
			s += "], datatype = float[8], order = C_order)),AXESLABELS(x,t,\"\"));";
			richTextBox2->Text = s;
		}
		max = 2/last_m;
		may = 5/last_m;
		track->Maximum = n_t-1;
		draw_y(0);
		pic->Image = canvas;
	}
	void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		g->Clear(Color::White);
		
		draw_coord();
		expl(Convert::ToDouble(epsilon->Value.ToString()),Convert::ToDouble(delta->Value.ToString()));
		draw_coord();
		track->Value = 0;
	}
	void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		draw_coord();
		g->Clear(Color::White);
		
		draw_coord();
		impl(Convert::ToDouble(epsilon->Value.ToString()),Convert::ToDouble(delta->Value.ToString()));
		track->Value = 0;
	}
	void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		timer->Stop();
	}
	void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		index = 0;
		timer->Start();
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
		draw_y(index);
	}
	void pic_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		ch_c = true;
	}
	void pic_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		if(ch_c)
		{
			c->X = e->X;
			c->Y = e->Y;
		}
		g->Clear(Color::White);
	draw_coord();
	draw_y(index);
	}
	void pic_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		ch_c = false;
	}
	void timer_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		
		if(n_t > 200)
			index += n_t/200;
		else
			index++;
		if(index >= n_t)
		{
			index = n_t-1;
			timer->Stop();
			return;
		}
		draw_y(index);
		label3->Text = "t = " + (tau*(index));
		track->Value = index;
	}
	void track_Scroll(System::Object^  sender, System::EventArgs^  e) 
	{
		index = track->Value;
		draw_y(index);
		label3->Text = "t = " + (tau*(index));
	}
private: System::Void epsilon_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

