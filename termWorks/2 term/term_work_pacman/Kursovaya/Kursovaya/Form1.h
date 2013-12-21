#pragma once

#include "pman.h"
#include "level.h"
#include "ghost.h"
#include <time.h>
#include <stdlib.h>

namespace Kursovaya {

	using namespace System::IO; 
	using namespace System::Text;
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
			srand((unsigned)time(NULL));
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
			delete canvas;
			delete g;
		}
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  pic;
	private: System::Windows::Forms::Timer^  timer2;

	private: System::Windows::Forms::CheckBox^  god;
	private: System::Windows::Forms::CheckBox^  wsad;
	private: System::Windows::Forms::TextBox^  NAME;

	protected: 

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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pic = (gcnew System::Windows::Forms::PictureBox());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->god = (gcnew System::Windows::Forms::CheckBox());
			this->wsad = (gcnew System::Windows::Forms::CheckBox());
			this->NAME = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 4;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// pic
			// 
			this->pic->BackColor = System::Drawing::SystemColors::ControlText;
			this->pic->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pic->Location = System::Drawing::Point(0, 0);
			this->pic->Name = L"pic";
			this->pic->Size = System::Drawing::Size(500, 600);
			this->pic->TabIndex = 0;
			this->pic->TabStop = false;
			this->pic->Click += gcnew System::EventHandler(this, &Form1::Click);
			// 
			// timer2
			// 
			this->timer2->Interval = 1;
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
			// 
			// god
			// 
			this->god->AutoSize = true;
			this->god->BackColor = System::Drawing::SystemColors::ControlText;
			this->god->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->god->ForeColor = System::Drawing::Color::White;
			this->god->Location = System::Drawing::Point(39, 186);
			this->god->Name = L"god";
			this->god->Size = System::Drawing::Size(414, 35);
			this->god->TabIndex = 1;
			this->god->Text = L"Активировать режим бессметрия";
			this->god->UseVisualStyleBackColor = false;
			this->god->Visible = false;
			this->god->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::key);
			// 
			// wsad
			// 
			this->wsad->AutoSize = true;
			this->wsad->BackColor = System::Drawing::SystemColors::ControlText;
			this->wsad->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->wsad->ForeColor = System::Drawing::Color::White;
			this->wsad->Location = System::Drawing::Point(39, 286);
			this->wsad->Name = L"wsad";
			this->wsad->Size = System::Drawing::Size(448, 35);
			this->wsad->TabIndex = 1;
			this->wsad->Text = L"Активировать передвижение WSAD";
			this->wsad->UseVisualStyleBackColor = false;
			this->wsad->Visible = false;
			this->wsad->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::key);
			// 
			// NAME
			// 
			this->NAME->BackColor = System::Drawing::Color::Red;
			this->NAME->Font = (gcnew System::Drawing::Font(L"Times New Roman", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->NAME->ForeColor = System::Drawing::Color::White;
			this->NAME->Location = System::Drawing::Point(114, 227);
			this->NAME->Multiline = true;
			this->NAME->Name = L"NAME";
			this->NAME->Size = System::Drawing::Size(268, 53);
			this->NAME->TabIndex = 999;
			this->NAME->TabStop = false;
			this->NAME->Visible = false;
			this->NAME->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::key);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 600);
			this->Controls->Add(this->NAME);
			this->Controls->Add(this->wsad);
			this->Controls->Add(this->god);
			this->Controls->Add(this->pic);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Form1";
			this->Text = L"PAC-MAN";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::key);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	Graphics^ g;
	Bitmap^ canvas;
	int i, j, mode;
	Image^ main;
	Image^ level1;
	Image^ level2;
	Image^ level3;
	level^ lev;
	pman^ pacman;
	int gh_i;
	ghost^ gh1;
	ghost^ gh2;
	ghost^ gh3;
	ghost^ gh4;
	bool paused;
	SolidBrush^ brush1;
	int start_pause_5_sec;
	int timer_value;
	int points;
	int lifes;
	bool death_of_pacman;
	bool if_super_constant_there_are_no_points_more;
	int levnum;
	bool super_pacman_mode_enabled;
	int parametr;
	int temp;
	
void addtext(FileStream^ fs, String^ value)
{
	array<Byte>^ info = (gcnew UTF8Encoding(true))->GetBytes(value);
	fs->Write(info, 0, info->Length);
}
String^ READ(FileStream^ fsr, int &i, int max)
{
	String^ s;
	array<Byte>^c = gcnew array<Byte>(1);
	UTF8Encoding^ temp = gcnew UTF8Encoding( true );
	c[0] = 1;
	fsr->Read(c, 0, c->Length);
	i++;
	while(c[0] != 13)
	{
		if(i >= max)
			return s;
		s += temp->GetString( c );
		fsr->Read(c, 0, c->Length);
		i++;
	}
	fsr->Read(c, 0, c->Length);
	i++;
	return s;
}
void recordraw(String^s)
{
	String^ input = "records.in";
	FileInfo^ fi = gcnew FileInfo(input);
	FileStream^ fs;
	int k = 11, i = 0, max = 0;
	array<String^>^r, ^n;
	r = gcnew array<String^>(k);
	n = gcnew array<String^>(k);
	fs = fi->OpenRead();
	max = fi->Length + 1;
	for(int y = 0; y < k; y++)
	{
		r[y] = READ(fs, i, max);
		n[y] = READ(fs, i, max);
	}
	if(fs)
		delete (IDisposable^)fs;
	r[10] = s;
	n[10] = Convert::ToString(points*7 + points/6);
	for(int y = 0; y < k; y++)
		for(int u = y; u < k; u++)
		{
			if(Convert::ToInt32(n[y]) < Convert::ToInt32(n[u]))
			{
				s = n[y];
				n[y] = n[u];
				n[u] = s;
				s = r[y];
				r[y] = r[u];
				r[u] = s;
			}
		}
	g->DrawImage(main, 0, 0, 500, 600);
	g->DrawString("TOP 10", gcnew Drawing::Font("Arial", 20), Brushes::White, 160 , 160);
	for(int y = 0; y < k-1; y++)
	{	
		g->DrawString(r[y] + " " + n[y], gcnew Drawing::Font("Times", 20), Brushes::Yellow, 90 , 200 + 30*y);
	}
	fi->Delete();
	fs = fi->OpenWrite();
	for(int y = 0; y < k-1; y++)
	{	
		g->DrawString(r[y] + " " + n[y], gcnew Drawing::Font("Times", 20), Brushes::Yellow, 90 , 200 + 30*y);
		addtext(fs, r[y]);
		addtext(fs, "\r\n");
		addtext(fs, n[y]);
		addtext(fs, "\r\n");
	}

	pic->Image = canvas;
	if(fs)
		delete (IDisposable^)fs;
}
void menu_draw(int i)
{
	switch(i)
	{
	case 1: 
		g->DrawImage(main, 0, 0, 500, 600);
		g->DrawString("Новая игра", gcnew Drawing::Font("Times", 20), Brushes::Red, 90, 175);
		g->DrawString("Справка", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 250);
		g->DrawString("Параметры", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 325);
		g->DrawString("Лучшие результаты", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 400);
		g->DrawString("Выход", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 475); 
		break;
	case 2: 
		g->DrawImage(main, 0, 0, 500, 600);
		g->DrawString("Новая игра", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 175);
		g->DrawString("Справка", gcnew Drawing::Font("Times", 20), Brushes::Red, 90, 250);
		g->DrawString("Параметры", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 325);
		g->DrawString("Лучшие результаты", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 400);
		g->DrawString("Выход", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 475); 
		break;
	case 3: 
		g->DrawImage(main, 0, 0, 500, 600);
		g->DrawString("Новая игра", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 175);
		g->DrawString("Справка", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 250);
		g->DrawString("Параметры", gcnew Drawing::Font("Times", 20), Brushes::Red, 90, 325);
		g->DrawString("Лучшие результаты", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 400);
		g->DrawString("Выход", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 475); 
		break;
	case 4: 
		g->DrawImage(main, 0, 0, 500, 600);
		g->DrawString("Новая игра", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 175);
		g->DrawString("Справка", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 250);
		g->DrawString("Параметры", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 325);
		g->DrawString("Лучшие результаты", gcnew Drawing::Font("Times", 20), Brushes::Red, 90, 400);
		g->DrawString("Выход", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 475); 
		break;
	case 5: 
		g->DrawImage(main, 0, 0, 500, 600);
		g->DrawString("Новая игра", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 175);
		g->DrawString("Справка", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 250);
		g->DrawString("Параметры", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 325);
		g->DrawString("Лучшие результаты", gcnew Drawing::Font("Times", 20), Brushes::White, 90, 400);
		g->DrawString("Выход", gcnew Drawing::Font("Times", 20), Brushes::Red, 90, 475); 
		break;
	}
	pic->Image = canvas;
}
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		brush1 = gcnew SolidBrush(Color::Yellow);
		paused = false;
		gh_i = 1;
		canvas = gcnew Drawing::Bitmap(pic->Width, pic->Height);
		g = Graphics::FromImage(canvas);
		//g = pic->CreateGraphics();
		mode = 1;
		main = Image::FromFile("main.jpg");
		level1 = Image::FromFile("level1_prog.gif");
		level2 = Image::FromFile("level2_prog.gif");
		level3 = Image::FromFile("level3_prog.gif");
		i = 1;
		menu_draw(i);
		mode = 1;
		//Form1::BackgroundImage = main1;
		timer2->Start();
	}
private: System::Void Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if(mode == 1)
			{
			Point p = Point(0,0);
			p = PointToClient(Cursor->Position);
			if((p.X >= 80) && (p.X <= 350))
			{
				if((p.Y >= 150)&&( p.Y < 225))
					i = 1;
				else if ((p.Y >= 225)&&( p.Y < 300))
					i = 2;
				else if ((p.Y >= 300)&&( p.Y < 375))
					i = 3;
				else if ((p.Y >= 375)&&( p.Y <= 450))
					i = 4;
				else if ((p.Y >= 450)&&( p.Y <= 525))
					i = 5;
				menu_draw(i);
				switch(i)
				{
					case 1:
						super_pacman_mode_enabled = false;
						levnum = 1;
						if_super_constant_there_are_no_points_more = false;
						death_of_pacman = false;
						i = 3;
						j = 3;
						mode = 2;
						points = 0;
						lifes = 3;
						lev = gcnew level();
						pacman = gcnew pman();
						gh1 = gcnew ghost(1);
						gh2 = gcnew ghost(2);
						gh3 = gcnew ghost(3);
						gh4 = gcnew ghost(4);
						lev->next();
						levnum = lev->retln();
						pacman->st(levnum);
						gh1->st(levnum);
						gh2->st(levnum);
						gh3->st(levnum);
						gh4->st(levnum);
						start_pause_5_sec = 0;
						timer_value = 1;
						timer2->Stop();
						timer1->Start();
						break;
					case 2: 
						mode = 3;
						g->DrawImage(main, 0, 0, 500, 600);
						g->DrawString("Для управления в главном меню\nиспользуйте клавиши-стрелки и клавишу Enter,\
						\nа так же манипулятор мышь.\nДля управления в игре \nиспользуйте клавиши-стрелки.\
						\nДля включения режима паузы нажмите клавишу P\
						\nДля выхода в главное меню нажмите Escape\nДля выхода из игры нажмите Escape в главном меню", gcnew Drawing::Font("Times", 16), Brushes::White,10, 200);
						pic->Image = canvas;
						break;
					case 3: 
						mode = 4;
						g->DrawImage(main, 0, 0, 500, 600);
						god->Visible = true;
						wsad->Visible = true;
						pic->Image = canvas;
						break;
					case 5: 
						Close();
						break;
					case 4: 
						points = 0;
						recordraw("1");
						mode = 5;
						break;
				}
			}
		}
	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		switch(levnum)
		{
		case 0:
			g->DrawImage(level1, 0, 0, 500, 600);
			break;
		case 1:
			g->DrawImage(level2, 0, 0, 500, 600);
			break;
		case 2: 
			g->DrawImage(level3, 0, 0, 500, 600);
			break;
		}											//рисуется уровень
		for(int o = 1; o < 31; o++)					//рисуются точки
			for(int r = 1; r < 28; r++)
			{
				if(lev->retc(o,r) == 2)
					g->FillEllipse(brush1, 45 + r*15 - 2, 45 + o*15 - 2, 4, 4);
				else if(lev->retc(o,r) == 3)
					g->FillEllipse(brush1, 45 + r*15 - 4, 45 + o*15 - 4, 8, 8);
			}
		if((super_pacman_mode_enabled)&&(!paused))		//если пакмен полон сил
		{
			temp = pacman->super();			//сколько осталось сил
			if(temp < 150)					//если меньше 150, то мигать начинают призраки
				parametr = 1;
			if(temp == 0)					//если нет сил, то всех опять сделать сильными
			{
				super_pacman_mode_enabled = false;
				gh1->unsick();
				gh2->unsick();
				gh3->unsick();
				gh4->unsick();
				pacman->super_puper_mode_off();
			}
		}
		if(if_super_constant_there_are_no_points_more)		//если нет больше точек, то начать следующий уровень
		{	
			if(timer_value++ > 150)
				if_super_constant_there_are_no_points_more = false;
			g->FillRectangle(Brushes::White, 250 - 70, 300 - 65, 175, 65);
			g->DrawString(" Next level", gcnew Drawing::Font("Times", 20), Brushes::Red, 250 - 70, 300 - 65);
			g->DrawString("Очков: " + (points*7 + points/6), gcnew Drawing::Font("Times", 20), Brushes::Black, 250 - 70, 300 - 30);
			pic->Image = canvas;
			return;
		}
		if(death_of_pacman)			//пакмен умер, рисуется стандартная штуковина
		{
			if(timer_value > 150)
			{
				death_of_pacman = 0;
				pacman->st(levnum);
				gh1->st(levnum);
				gh2->st(levnum);
				gh3->st(levnum);
				gh4->st(levnum);
				start_pause_5_sec = 0;
			}
			if(timer_value++ < 19)
				return;
			if(timer_value%5 == 1)
				return;
			pacman->death(g, (timer_value - 20)/5);
			pic->Image = canvas;
			return;
		}
		if(lifes == 0)		//если жизней нет, то гейм овер
		{
			if(++timer_value >= 80)
			{
				timer_value = 0;
			}
			g->FillRectangle(Brushes::White, 250 - 70, 300 - 65, 175, 65);
			g->DrawString("   Game over", gcnew Drawing::Font("Times", 20), Brushes::Red, 250 - 70, 300 - 65);
			g->DrawString("Очков: " + (points*7 + points/6), gcnew Drawing::Font("Times", 20), Brushes::Black, 250 - 70, 300 - 30);
			if((timer_value/40)%2 == 0)
				g->DrawString("Для выхода нажмите Escape", gcnew Drawing::Font("Times", 20), Brushes::White, 50, 530);
			else
				g->DrawString("Для выхода нажмите Escape", gcnew Drawing::Font("Times", 20), Brushes::Black, 50, 530);
			pic->Image = canvas;
			return;
		}
		switch(levnum)
		{
		case 0:
			g->DrawImage(level1, 0, 0, 500, 600);
			break;
		case 1:
			g->DrawImage(level2, 0, 0, 500, 600);
			break;
		case 2: 
			g->DrawImage(level3, 0, 0, 500, 600);
			break;
		}
		if(timer_value%10 == 0)		//смена типа картинки призрака
		{
			timer_value = 0;
			gh1->change_icon();
			gh2->change_icon();
			gh3->change_icon();
			gh4->change_icon();
		}
		
		if((!paused)&&((start_pause_5_sec >= 150)||(start_pause_5_sec == 1)))		//проверка паузы и начала уровня
		{
			////////////////////////////////////////////////призраки вычисляют координаты
			if(timer_value%11 != 0)					
				if(gh1->draw(lev, pacman, gh1, points, god->Checked))
					death_of_pacman = true;					//убили пакмена
			if(timer_value%5 != 0) 
				if(gh3->draw(lev, pacman, gh1, points, god->Checked))
					death_of_pacman = true;
			if(timer_value%4 != 0)
					if(gh2->draw(lev, pacman, gh1, points, god->Checked))
						death_of_pacman = true;
			if(timer_value%3 != 0) 
					if(gh4->draw(lev, pacman, gh1, points, god->Checked))
						death_of_pacman = true;
			////////////////////////////////////////////////////
			if(pacman->draw(i, lev, points))		//пакмен вычисляется
			{
				gh1->do_sick();			//съел энерджайзер
				gh2->do_sick();
				gh3->do_sick();
				gh4->do_sick();
				parametr = 0;
				super_pacman_mode_enabled = true;
				return;
			}
		}
		if(death_of_pacman)		//убили пакмена
		{
			timer_value = 0;
			lifes--;
			return;
		}
		else
			pacman->only_draw(g, pacman->retway());		//если еще жив, то рисуется
		for(int o = 1; o < 31; o++)				//рисуются точки
			for(int r = 1; r < 28; r++)
			{
				if(lev->retc(o,r) == 2)
				{
					g->FillEllipse(brush1, 45 + r*15 - 2, 45 + o*15 - 2, 4, 4);
					if_super_constant_there_are_no_points_more = true;
				}
				else if(lev->retc(o,r) == 3)
				{
					g->FillEllipse(brush1, 45 + r*15 - 4, 45 + o*15 - 4, 8, 8);
					if_super_constant_there_are_no_points_more = true;
				}
			}
		///////////////////////////////////////////////////////////////логический блок конца уровня
		if_super_constant_there_are_no_points_more = !if_super_constant_there_are_no_points_more;
		if(if_super_constant_there_are_no_points_more)
		{
			super_pacman_mode_enabled = false;				//сброс параметров
			lev->next();
			levnum = lev->retln();
			start_pause_5_sec = 0;
			timer_value = 1;
			death_of_pacman = false;
			pacman->super_puper_mode_off();
			pacman->st(levnum);
			gh1->st(levnum);
			gh2->st(levnum);
			gh3->st(levnum);
			gh4->st(levnum);
			gh1->unsick();
			gh2->unsick();
			gh3->unsick();
			gh4->unsick();
			return;
		}
		gh1->drawgh(g, parametr);
		gh2->drawgh(g, parametr);
		gh3->drawgh(g, parametr);
		gh4->drawgh(g, parametr);
		///////////////////////////////////////////////////////////////логический блок паузы и стандартных надписей
		timer_value++;
		if(paused)
		{
			g->FillRectangle(Brushes::White, 250 - 40, 300 - 65, 80, 30);
			g->DrawString("Пауза", gcnew Drawing::Font("Times", 20), Brushes::Black, 250 - 40, 300 - 65);
		}
		g->DrawString("Очки: " + (points*7 + points/6), gcnew Drawing::Font("Times", 20), Brushes::White, 50, 530);
		g->DrawString("Жизни:", gcnew Drawing::Font("Times", 20), Brushes::Red, 280, 530);
		for(int joe = 0; joe < lifes; joe++)
		{
			g->FillEllipse(Brushes::Yellow, 400 + 30*joe - 10, 545 - 10 ,20, 20);
			g->FillPie(Brushes::Black, 400 + 30*joe - 18, 545 - 15 ,30, 30, -22, 45); 
		}
		if(start_pause_5_sec < 200)		//////пауза в начале уровня
			start_pause_5_sec++;
		pic->Image = canvas;
	}
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		if(mode == 1)
		{
			Point p = Point(0,0);
			p = PointToClient(Cursor->Position);
			if((p.X >= 80) && (p.X <= 350))
			{
				if((p.Y >= 150)&&( p.Y < 225))
					i = 1;
				else if ((p.Y >= 225)&&( p.Y < 300))
					i = 2;
				else if ((p.Y >= 300)&&( p.Y < 375))
					i = 3;
				else if ((p.Y >= 375)&&( p.Y <= 450))
					i = 4;
				else if ((p.Y >= 450)&&( p.Y <= 525))
					i = 5;
			}
			menu_draw(i);
		}
		else if(mode == 6)
		{
			if((god->Checked)||(points == 0))
			{
				points = 0;
				mode = 5;
				recordraw("1");
				return;
			}
			if(!NAME->Visible)
				NAME->Visible = true;
			if((timer_value/40)%2 == 0)
				g->DrawString("Введите имя и нажмите Enter", gcnew Drawing::Font("Times", 20), Brushes::White, 50, 500);
			else
				g->DrawString("Введите имя и нажмите Enter", gcnew Drawing::Font("Times", 20), Brushes::Black, 50, 500);
			timer_value++;
			if(timer_value == 2000)
				timer_value = 0;
			pic->Image = canvas;
		}
	}

private: System::Void key(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		int t = (int) e->KeyCode;
		if(wsad->Checked)
		{
			switch (t)
			{
			case 87: 
				t = 38;
				break;
			case 83: 
				t = 40;
				break;
			case 65: 
				t = 37;

			case 68: 
				t = 39;
				break;
			}
		}
		if(mode == 1)
		{
			switch (t)
			{
			case 38: 
				if(i > 1)
					i--; 
				menu_draw(i);
				break;
			case 40: 
				if(i < 5)
					i++;
				menu_draw(i);
				break;
			case 13:
				switch(i)
				{
				case 1: 
					super_pacman_mode_enabled = false;
					if_super_constant_there_are_no_points_more = false;
					death_of_pacman = false;
					i = 3;
					j = 3;
					mode = 2;
					points = 0;
					lifes = 3;
					lev = gcnew level();
					pacman = gcnew pman();
					gh1 = gcnew ghost(1);
					gh2 = gcnew ghost(2);
					gh3 = gcnew ghost(3);
					gh4 = gcnew ghost(4);
					lev->next();
					levnum = lev->retln();
					pacman->st(levnum);
					gh1->st(levnum);
					gh2->st(levnum);
					gh3->st(levnum);
					gh4->st(levnum);
					start_pause_5_sec = 0;
					timer_value = 1;
					timer2->Stop();
					timer1->Start();
					break;
				case 2: 
					mode = 3;
					g->DrawImage(main, 0, 0, 500, 600);
					g->DrawString("Для управления в главном меню\nиспользуйте клавиши-стрелки и клавишу Enter,\
					\nа так же манипулятор мышь.\nДля управления в игре \nиспользуйте клавиши-стрелки.\
					\nДля включения режима паузы нажмите клавишу P\
					\nДля выхода в главное меню нажмите Escape\nДля выхода из игры нажмите Escape в главном меню", gcnew Drawing::Font("Times", 16), Brushes::White,10, 200);
					pic->Image = canvas;
					break;
				case 3: 
					mode = 4;
					g->DrawImage(main, 0, 0, 500, 600);
					god->Visible = true;
					wsad->Visible = true;
					pic->Image = canvas;
					return;
				case 5: 
					Close();
					break;
				case 4: 
					points = 0;
					recordraw("1");
					mode = 5;
					break;
				}break;
			case 27: Close();
			}
		}
		if(mode == 2)
		{
			switch (t)
			{
			case 80:
				paused = !paused;
				break;
			case 38: i = 1; break;
			case 40: i = 2; break;
			case 37: i = 3; break;
			case 39: i = 4; break;
			case 27: 
				mode = 1;
				i = 1;
				delete gh1;
				delete gh2;
				delete gh3;
				delete gh4;
				delete lev;
				timer1->Stop();
				timer2->Start();
				mode = 6;
				g->DrawImage(main, 0, 0, 500, 600);
				break;
			}
		}
		else if(mode != 6)
		{
			if (t == 27)
			{	
				mode = 1;
				if(god->Visible)
					god->Visible = false;
				if(wsad->Visible)
					wsad->Visible = false;
			}
		}
		else if(mode == 6)
		{
			if(t == 13)
			{
				String^ tempo = Convert::ToString(NAME->Text);
				if(tempo == "")
					tempo = "Player";
				mode = 5;
				NAME->Visible = false;
				recordraw(tempo);
			}
		}
	}

};
};
