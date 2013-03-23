#pragma once
#include "plot_tools.h"
#include <vector>
#include <algorithm>
#define rep(i,k,n) for(int (i) = (k); (i) < (n); (i)++)
typedef std::vector<double> vd;
typedef std::pair<double,int> di;
typedef std::vector<di> vdi;
namespace lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

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
			canvas = gcnew Bitmap(pic->Height*2, pic->Width*2);
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
			rtb->Text = "Количество точек: "+n;
			for(int i = 0; i < n; i++)
			{
				rtb->Text += "\nx["+i+"] = "+x[i]+"\ny["+i+"] = "+y[i];
			}
			c = Point(0,0);
			st = Point(0,0);
			last_m = 1;
			ch_c = false;
			c.X = pic->Height/6.0;
			c.Y = pic->Height*(5/6.);
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





	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::IContainer^  components;
				System::Windows::Forms::Button^  button2;
				System::Windows::Forms::Button^  button3;
				System::Windows::Forms::Button^  button4;
				System::Windows::Forms::Button^  button5;
				System::Windows::Forms::Button^  button6;
				System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Timer^  click_watch;
	private: System::Windows::Forms::PictureBox^  pic;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
				System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::RichTextBox^  rtb;

	private: System::Windows::Forms::NumericUpDown^  Scale;

	private: System::Windows::Forms::NumericUpDown^  epsilon;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::NumericUpDown^  A;
	private: System::Windows::Forms::NumericUpDown^  B;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  epsilon2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  X0_oX;
				//private: System::ComponentModel::IContainer^  components;

	private: System::Windows::Forms::CheckBox^  checkBox1;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->click_watch = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pic = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->rtb = (gcnew System::Windows::Forms::RichTextBox());
			this->Scale = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->epsilon = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->A = (gcnew System::Windows::Forms::NumericUpDown());
			this->B = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->epsilon2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->X0_oX = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Scale))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->epsilon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->A))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->epsilon2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->X0_oX))->BeginInit();
			this->SuspendLayout();
			// 
			// click_watch
			// 
			this->click_watch->Interval = 1;
			this->click_watch->Tick += gcnew System::EventHandler(this, &Form1::click_watch_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(557, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 23);
			this->button1->TabIndex = 1;
			this->button1->Tag = L"1";
			this->button1->Text = L"Метод Свенна";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button_click);
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
			this->label1->Location = System::Drawing::Point(548, 187);
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
			this->label5->Location = System::Drawing::Point(554, 219);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Лог:";
			// 
			// rtb
			// 
			this->rtb->Location = System::Drawing::Point(568, 235);
			this->rtb->Name = L"rtb";
			this->rtb->Size = System::Drawing::Size(224, 277);
			this->rtb->TabIndex = 9;
			this->rtb->Text = L"";
			// 
			// Scale
			// 
			this->Scale->DecimalPlaces = 1;
			this->Scale->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->Scale->Location = System::Drawing::Point(605, 185);
			this->Scale->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, 0});
			this->Scale->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->Scale->Name = L"Scale";
			this->Scale->Size = System::Drawing::Size(84, 20);
			this->Scale->TabIndex = 11;
			this->Scale->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->Scale->ValueChanged += gcnew System::EventHandler(this, &Form1::B_ValueChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(548, 130);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Погрешности";
			// 
			// epsilon
			// 
			this->epsilon->DecimalPlaces = 9;
			this->epsilon->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 458752});
			this->epsilon->Location = System::Drawing::Point(629, 128);
			this->epsilon->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, 0});
			this->epsilon->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 655360});
			this->epsilon->Name = L"epsilon";
			this->epsilon->Size = System::Drawing::Size(84, 20);
			this->epsilon->TabIndex = 5;
			this->epsilon->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(696, 212);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(96, 17);
			this->checkBox1->TabIndex = 12;
			this->checkBox1->Text = L"Выводить лог";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(676, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(116, 23);
			this->button2->TabIndex = 1;
			this->button2->Tag = L"2";
			this->button2->Text = L"Метод равн. поиска";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button_click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(557, 41);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(116, 23);
			this->button3->TabIndex = 1;
			this->button3->Tag = L"3";
			this->button3->Text = L"Метод д. пополам";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button_click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(676, 41);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(116, 23);
			this->button4->TabIndex = 1;
			this->button4->Tag = L"4";
			this->button4->Text = L"Метод дихотомии";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button_click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(557, 70);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(235, 23);
			this->button8->TabIndex = 13;
			this->button8->Tag = L"5";
			this->button8->Text = L"Метод з. сечения";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button_click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(676, 70);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(114, 23);
			this->button9->TabIndex = 13;
			this->button9->Tag = L"6";
			this->button9->Text = L"Метод Фибоначчи";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Visible = false;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button_click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(557, 99);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(233, 23);
			this->button10->TabIndex = 13;
			this->button10->Tag = L"7";
			this->button10->Text = L"Метод квадратичной интерполяции";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button_click);
			// 
			// A
			// 
			this->A->DecimalPlaces = 2;
			this->A->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
			this->A->Location = System::Drawing::Point(641, 154);
			this->A->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {999999, 0, 0, 0});
			this->A->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {999999, 0, 0, System::Int32::MinValue});
			this->A->Name = L"A";
			this->A->Size = System::Drawing::Size(48, 20);
			this->A->TabIndex = 11;
			this->A->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {4, 0, 0, 0});
			this->A->ValueChanged += gcnew System::EventHandler(this, &Form1::B_ValueChanged);
			// 
			// B
			// 
			this->B->DecimalPlaces = 2;
			this->B->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
			this->B->Location = System::Drawing::Point(719, 154);
			this->B->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {999999, 0, 0, 0});
			this->B->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {999999, 0, 0, System::Int32::MinValue});
			this->B->Name = L"B";
			this->B->Size = System::Drawing::Size(48, 20);
			this->B->TabIndex = 11;
			this->B->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->B->ValueChanged += gcnew System::EventHandler(this, &Form1::B_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(548, 156);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"На отрезке";
			// 
			// epsilon2
			// 
			this->epsilon2->DecimalPlaces = 9;
			this->epsilon2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 458752});
			this->epsilon2->Location = System::Drawing::Point(719, 128);
			this->epsilon2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, 0});
			this->epsilon2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 655360});
			this->epsilon2->Name = L"epsilon2";
			this->epsilon2->Size = System::Drawing::Size(84, 20);
			this->epsilon2->TabIndex = 5;
			this->epsilon2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(695, 187);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"x0 = ";
			// 
			// X0_oX
			// 
			this->X0_oX->DecimalPlaces = 6;
			this->X0_oX->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 327680});
			this->X0_oX->Location = System::Drawing::Point(725, 185);
			this->X0_oX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, 0});
			this->X0_oX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {999999, 0, 0, System::Int32::MinValue});
			this->X0_oX->Name = L"X0_oX";
			this->X0_oX->Size = System::Drawing::Size(78, 20);
			this->X0_oX->TabIndex = 11;
			this->X0_oX->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->X0_oX->ValueChanged += gcnew System::EventHandler(this, &Form1::B_ValueChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(804, 522);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->B);
			this->Controls->Add(this->A);
			this->Controls->Add(this->X0_oX);
			this->Controls->Add(this->Scale);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->rtb);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->epsilon2);
			this->Controls->Add(this->epsilon);
			this->Controls->Add(this->pic);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Location = System::Drawing::Point(679, 12);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Scale))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->epsilon))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->A))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->epsilon2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->X0_oX))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	Bitmap^canvas;
	Graphics^ g;

public: 
	bool ch_c;
	int n;
	double last_m;
	array<double>^x, ^y, ^y1, ^y2, ^y3, ^y4;
	Point c;	//центр 
	Point st,st_last;
	int m;
	double max, may;		//max по  x  и  y 
	array<double>^p;				//полином итоговый
	array<double>^pr;

public: 
	array<double>^_a,^_b,^_c;

public: 
private:
	
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
	
	
	void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		g->Clear(Color::White);
		draw_coord(g,pic->Width,pic->Height, this->Font);
		svenn(0,1);
		pic->Image = canvas;
	}
	

	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		g->Clear(Color::White);
		
	}
	void B_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		mult_scale(last_m, last_m, 1/last_m);
		max = max*last_m;
		may = may*last_m;
		last_m = Convert::ToDouble( (Scale->Value.ToString()));
		mult_scale(1/last_m, 1/last_m, last_m);
		max = max/last_m;
		may = may/last_m;
		g->Clear(Color::White);
		draw_coord(g,pic->Width,pic->Height, this->Font);
		draw_func(x,y,g, Pens::Green);
		draw_array(y1,y2,g);
		pic->Image = canvas;
	}
private: System::Void pic_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
				ch_c = true;
			}
private: System::Void pic_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
				st_last = c;
				st = Point(System::Windows::Forms::Cursor::Current->Position.X - this->Location.X, System::Windows::Forms::Cursor::Current->Position.Y - this->Location.Y) ;
				click_watch->Start();
			}
private: System::Void pic_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
				click_watch->Stop();
			}
private: System::Void click_watch_Tick(System::Object^  sender, System::EventArgs^  e) 
			{
				c = Point(System::Windows::Forms::Cursor::Current->Position.X - this->Location.X - st.X + st_last.X, System::Windows::Forms::Cursor::Current->Position.Y - this->Location.Y - st.Y + st_last.Y);
				set_centre(c);
				g->Clear(Color::White);
				draw_coord(g,pic->Width,pic->Height, this->Font);
				draw_func(x,y,g, Pens::Green);
				draw_array(y1,y2,g);
				pic->Image = canvas;
			}
	double f(double x)
	{
		return ((x-7)*(x-7));
	}
	void draw_func_4_me(double a, double b, int n)
	{
		if(x)
			delete x;
		if(y)
			delete y;
		x = gcnew array<double>(n);
		y = gcnew array<double>(n);
		double d = (b - a + 2)/n;
		x[0] = a-1;
		y[0] = f(x[0]);
		int i = 0;
		while(i<n-1)
		{
			x[i+1] = x[i] + d;
			y[i+1] = f(x[i+1]);
			i++;
		}
		draw_func(x,y,g,Pens::Green);
	}
	void svenn(double x0, double r)
	{
		r = Math::Abs(r);
		if(y1)
			delete y1;
		if(y2)
			delete y2;
		y1 = gcnew array<double>(2);
		y2 = gcnew array<double>(2);
		int i;
		rtb->Text = L"";
		rtb->AppendText("Начальная точка "+evalf(x0) + ", t = " + r + "\n");
		double xi,xk, d, k = 0;
		if(f(x0-r) > f(x0) && f(x0) < f(x0+r))
		{
			y1[0] = x0-r;
			y1[1] = x0+r;
			y2[0] = f(y1[0]);
			y2[1] = f(y1[1]);
			rtb->AppendText("Найден интервал неопределённости, ("+ y1[0] + "," + y1[1]+")\n");
			draw_array(y1,y2,g);
			d = (y1[1] - y1[0]+2)/20;
			x[0] = y1[0]-1;
			y[0] = f(x[0]);
			i = 0;
			while(i<19)
			{
				x[i+1] = x[i] + d;
				y[i+1] = f(x[i+1]);
				i++;
			}
			draw_func(x,y,g,Pens::Green);
			return;
		}
		else if(f(x0-r) < f(x0) && f(x0) > f(x0+r))
			rtb->AppendText("Ошибка, выберите другую начальную точку и/или радиус");
		else if(f(x0-r) < f(x0) && f(x0) < f(x0+r))
		{
			rtb->AppendText("f(x0-t) < f(x0) < f(x0+t)\n" + f(x0-r)+" < "+f(x0)+" < "+f(x0+r)+"\n");
			d = -r; 
			y1[1] = x0;
			xi = x0 - r;
			k = 1;
			
		}
		else
		{
			rtb->AppendText("f(x0-t) > f(x0) > f(x0+t)\n" + f(x0-r)+" > "+f(x0)+" > "+f(x0+r)+"\n");
			d = r;
			y1[0] = x0;
			xi = x0 + r;
			k = 0;
		}
		rtb->AppendText("d = "+ d +"\n");
		xk = Math::Pow(x0,k+1)+Math::Pow(2,k+1)*d;
		rtb->AppendText("x"+k+" = "+ xi +"\n");
		while(f(xi) > (f(xk)))
		{
			rtb->AppendText("f(x"+k+") > f(x"+(k+1)+"), считаем следующий x\n" + f(xi)+" > "+f(xk)+"\n");
			k++;
			rtb->AppendText("x"+k+" = "+ xk +"\n");	
			if(d < 0)	y1[1] = xi;
			else			y1[0] = xi;
			xi = xk;
			xk = Math::Pow(x0,k+1)+Math::Pow(2,k+1)*d;
		}
		rtb->AppendText("f(x"+k+") < f(x"+(k+1)+"), завершаю итерацию\n" + f(xi)+" < "+f(xk)+"\n");
		if(d < 0)	y1[0] = xk;
		else			y1[1] = xk;
		
		y2[0] = f(y1[0]);
		y2[1] = f(y1[1]);
		rtb->AppendText("Найден интервал неопределённости, ("+ y1[0] + "," + y1[1]+")\n");
		draw_array(y1,y2,g);
		d = (y1[1] - y1[0]+2)/20;
		draw_func_4_me(y1[0],y1[1],20);
	}

	void ravnom(double a, double b, double eps)
	{
		if(eps < 1e-12)
		{
			rtb->Text = L"Некорректная погрешность";
			return;
		}
		if(y1)
			delete y1;
		if(y2)
			delete y2;
		y1 = gcnew array<double>(1);
		y2 = gcnew array<double>(1);
		draw_func_4_me(a,b,20);
		double h = Math::Abs(b-a)/10.;	
		n = 11;
		rtb->Text = L"Начинаю выполнение метода равномерного поиска на отрезке["+evalf(a)+" ; "+evalf(b)+"]\nC точностью "+evalf(eps)+"\n\n";
		vd ax;
		vdi ay;
		do
		{
			rep(i,0,n)
			{
				ax.push_back(a+h*i);
				ay.push_back(pair<double,int>(f(ax[i]),i));
			}
			sort(ay.begin(),ay.begin() +ay.size()-1);
			if(ay[0].second)
				a = ax[ay[0].second-1];
			if(ay[0].second != 10)
				b = ax[ay[0].second+1];
			rtb->AppendText("Отрезок сужен до ["+evalf(a)+" ; "+evalf(b)+"]\n");
			if(2*h < eps)
				break;
			h = Math::Abs(b-a)/10.;	
			ax.erase(ax.begin(),ax.begin() + ax.size() - 1);
			ay.erase(ay.begin(),ay.begin() + ay.size() - 1);
		}while(1);
		y1[0] = ax[ay[0].second];
		y2[0] = f(y1[0]);
		rtb->AppendText("\nТочка минимума с заданной точностью - ("+y1[0]+" ; "+y2[0]+")");
		draw_array(y1,y2,g);
	}

	void half_div(double a, double b, double eps)
	{
		if(eps < 1e-12)
		{
			rtb->Text = L"Некорректная погрешность";
			return;
		}
		if(y1)
			delete y1;
		if(y2)
			delete y2;
		y1 = gcnew array<double>(1);
		y2 = gcnew array<double>(1);
		draw_func_4_me(a,b,20);
		double h = Math::Abs(b-a)/10.;	
		n = 11;
		rtb->Text = L"Начинаю выполнение метода делением пополам на отрезке["+evalf(a)+" ; "+evalf(b)+"]\nC точностью "+evalf(eps)+"\n\n";
		double hc[4] = {0};
		hc[0] = (a+b)/2.;
		do
		{
			hc[1] = (a+hc[0])/2.;
			hc[2] = (b+hc[0])/2.;
			if(f(hc[1]) < f(hc[0]))
			{
				b = hc[0];
				hc[0] = hc[1];
			}
			else if(f(hc[2]) < f(hc[0]))
			{
				a = hc[0];
				hc[0] = hc[2];
			}
			else
			{
				a = hc[1];
				b = hc[2];
			}
			rtb->AppendText("Отрезок сужен до ["+evalf(a)+" ; "+evalf(b)+"]\n");
			if(b-a < eps)
				break;
		}while(1);
		y1[0] = (b+a)/2.;
		y2[0] = f(y1[0]);
		rtb->AppendText("\nТочка минимума с заданной точностью - ("+y1[0]+" ; "+y2[0]+")");
		draw_array(y1,y2,g);
	}

	void dihot(double a, double b, double eps, double eps2)
	{
		if(eps < 1e-12)
		{
			rtb->Text = L"Некорректная погрешность";
			return;
		}
		if(y1)
			delete y1;
		if(y2)
			delete y2;
		y1 = gcnew array<double>(1);
		y2 = gcnew array<double>(1);
		draw_func_4_me(a,b,20);
		double h = eps2;	
		n = 11;
		rtb->Text = L"Начинаю выполнение метода дихотомии на отрезке["+evalf(a)+" ; "+evalf(b)+"]\nC точностью "+evalf(eps)+", где EPS="+h+"\n\n";
		if(h > 9.*eps/10.)
		{
			rtb->AppendText("Некорректное значение EPS. Метод расходится.");
			return;
		}
		do
		{
			if(f((a+b+h)/2.) < f((a+b-h)/2.))
				a = (a+b-h)/2.;
			else
				b = (a+b+h)/2.;
			rtb->AppendText("Отрезок сужен до ["+evalf(a)+" ; "+evalf(b)+"]\n");
			if(b-a < eps)
				break;
		}while(1);
		y1[0] = (b+a)/2.;
		y2[0] = f(y1[0]);
		rtb->AppendText("\nТочка минимума с заданной точностью - ("+y1[0]+" ; "+y2[0]+")");
		draw_array(y1,y2,g);
	}
	void gold_sec(double a, double b, double eps)
	{
		if(eps < 1e-12)
		{
			rtb->Text = L"Некорректная погрешность";
			return;
		}
		if(y1)
			delete y1;
		if(y2)
			delete y2;
		y1 = gcnew array<double>(1);
		y2 = gcnew array<double>(1);
		draw_func_4_me(a,b,20);
		double h = eps/2.;	
		n = 11;
		rtb->Text = L"Начинаю выполнение метода золотого сечения на отрезке["+evalf(a)+" ; "+evalf(b)+"]\nC точностью "+evalf(eps)+"\n\n";
		double l,r;
		l = a + (3-Math::Sqrt(5.0))/2.*(b-a);
		r = a + b - l;
		do
		{
			
			if(f(l) < f(r))
			{
				b = r;
				r = l;
				l = a+b-l;
			}
			else
			{
				a = l;
				l = r;
				r = a+b-r;
			}
			rtb->AppendText("Отрезок сужен до ["+evalf(a)+" ; "+evalf(b)+"]\n");
			if(b-a < eps)
				break;
		}while(1);
		y1[0] = (b+a)/2.;
		y2[0] = f(y1[0]);
		rtb->AppendText("\nТочка минимума с заданной точностью - ("+y1[0]+" ; "+y2[0]+")");
		draw_array(y1,y2,g);
	}
	void sq(double a, double b, double eps, double delta, double x0_0)
	{
		if(eps < 1e-12)
		{
			rtb->Text = L"Некорректная погрешность";
			return;
		}
		if(y1)
			delete y1;
		if(y2)
			delete y2;
		y1 = gcnew array<double>(1);
		y2 = gcnew array<double>(1);
		draw_func_4_me(a,b,20);
		double h = eps/2.;	
		n = 11;
		rtb->Text = L"Начинаю выполнение метода квадратичной интерполяции на отрезке["+evalf(a)+" ; "+evalf(b)+"]\nC точностями eps1 и eps2 = "+eps+"\ndelta = "+delta+"\n\n";
		double l,r,xc, xcc, min;
		xc = x0_0;		//начальная точка
		do
		{
			rtb->AppendText("x1 = "+xc+"\n");
			r = xc+delta;
			rtb->AppendText("x2 = "+r+"\n");
			if(f(r) > f(xc))
			{
				l = xc-delta;
				min = xc;
			}
			else
			{
				l = xc+2*delta;
				min = r;
			}
			rtb->AppendText("x3 = "+l+"\n");
			if(f(min)>f(l))
				min = l;
			rtb->AppendText("x_min = "+min+"\n");
			xcc = 2*(f(xc)*(r-l) + f(r)*(l-xc) + f(l)*(xc-r));
			rtb->AppendText("знаменатель ~x = "+xcc+"\n");
			if(Math::Abs(xcc) < 0.000001)
			{
				rtb->AppendText("он очень мал, беру x1 = x_min и начинаю заново\n\n\n");
				xc = min;
				continue;
			}
			xcc = (f(xc)*(r*r-l*l) + f(r)*(l*l-xc*xc) + f(l)*(xc*xc-r*r))/xcc;
			rtb->AppendText("~x = "+xcc+"\n");
			rtb->AppendText("f(x_min) = "+f(min)+"\n");
			rtb->AppendText("f(~x) = "+f(xcc)+"\n");
			if(Math::Abs((xcc-min))<eps && Math::Abs((f(xcc)-f(min))) < eps)
			{
				rtb->AppendText("условие выхода выполнено\n");
				break;
			}
			else
			{
				rtb->AppendText("условие выхода не выполнено, беру x1 = ~x и начинаю заново\n\n\n");
				xc = min;
				continue;
			}
		}while(1);
		y1[0] = xcc;
		y2[0] = f(y1[0]);
		rtb->AppendText("\nТочка минимума с заданной точностью - ("+y1[0]+" ; "+y2[0]+")");
		draw_array(y1,y2,g);
	}
	
private: System::Void button_click(System::Object^  sender, System::EventArgs^  e) 
	{
		g->Clear(Color::White);
		draw_coord(g,pic->Width,pic->Height, this->Font);
		Button^ b = dynamic_cast<Button^>(sender);
		double a[5]={0};
		a[0] = A->Value.ToDouble(A->Value);
		a[1] = B->Value.ToDouble(B->Value);
		a[2] = epsilon->Value.ToDouble(epsilon->Value);
		a[3] = epsilon2->Value.ToDouble(epsilon2->Value);
		a[4] = X0_oX->Value.ToDouble(X0_oX->Value);
		switch(Convert::ToInt32(b->Tag->ToString()))
		{
		case 1:svenn(0,1);break;
		case 2:ravnom(a[0],a[1],a[2]);break;
		case 3: half_div(a[0],a[1],a[2]);break;
		case 4: dihot(a[0],a[1],a[2], a[3]);break;
		case 5: gold_sec(a[0],a[1],a[2]);break;
		case 7: sq(a[0],a[1],a[2], a[3], a[4]);break;
		}
		pic->Image = canvas;
	}
};
}

