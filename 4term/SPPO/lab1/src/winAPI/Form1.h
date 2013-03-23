#pragma once
#include <windows.h>
//#include <excpt.h>
#include "text_area.h"
#include "tool_window.h"
#include "info_form.h"
#include "copy_move.h"
#include "Search.h"
#include "FiFiFi.h"
//#include <vector>
//#include <shellapi.h>
//#include <atlconv.h>
//#include "atlbase.h"
//#include "atlstr.h"
//#include "comutil.h"
#include "vcclr.h"


namespace lab1 {

	using namespace System;
	using namespace System::IO;
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
			String^ s = "sfknls";
			wchar_t* b = L"sldk";
			LPCTSTR st;
			st = (LPCTSTR)b;
			const size_t newsizew = s->Length +1;
			pin_ptr<const wchar_t> wch = PtrToStringChars(s);
			wchar_t *wcstring = new wchar_t[newsizew];
			wcscpy_s(wcstring, newsizew, wch);
			st = (LPCTSTR)wcstring;
			//wchar_t*as = s->ToCharArray(0,s->Length);
			s = gcnew String(st);
			
			//CopyFile(static_cast<LPCTSTR>(s),static_cast<LPCTSTR>(s),true);
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
	private: System::Windows::Forms::ListBox^  list1;
	protected: 


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  way1;


	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Label^  way2;

	private: System::Windows::Forms::ListBox^  list2;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  copy;
	private: System::Windows::Forms::Button^  move;
	private: System::Windows::Forms::Button^  newDir;
	private: System::Windows::Forms::Button^  del;
	private: System::Windows::Forms::Button^  info;





	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  search;

	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;









	private: System::ComponentModel::IContainer^  components;



	protected: 

	protected: 

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
			this->list1 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->way1 = (gcnew System::Windows::Forms::Label());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->way2 = (gcnew System::Windows::Forms::Label());
			this->list2 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->copy = (gcnew System::Windows::Forms::Button());
			this->move = (gcnew System::Windows::Forms::Button());
			this->newDir = (gcnew System::Windows::Forms::Button());
			this->del = (gcnew System::Windows::Forms::Button());
			this->info = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->search = (gcnew System::Windows::Forms::Button());
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// list1
			// 
			this->list1->BackColor = System::Drawing::Color::Gainsboro;
			this->list1->FormattingEnabled = true;
			this->list1->Location = System::Drawing::Point(3, 30);
			this->list1->Name = L"list1";
			this->list1->Size = System::Drawing::Size(270, 264);
			this->list1->Sorted = true;
			this->list1->TabIndex = 1;
			this->list1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::list1_Dclick);
			this->list1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::list1_click);
			this->list1->Enter += gcnew System::EventHandler(this, &Form1::focus_list1);
			this->list1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::push_key);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(45, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Путь:  ";
			// 
			// way1
			// 
			this->way1->AutoSize = true;
			this->way1->Location = System::Drawing::Point(91, 9);
			this->way1->Name = L"way1";
			this->way1->Size = System::Drawing::Size(0, 13);
			this->way1->TabIndex = 3;
			// 
			// splitContainer1
			// 
			this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitContainer1->Location = System::Drawing::Point(12, 12);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->comboBox1);
			this->splitContainer1->Panel1->Controls->Add(this->way1);
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			this->splitContainer1->Panel1->Controls->Add(this->list1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->comboBox2);
			this->splitContainer1->Panel2->Controls->Add(this->way2);
			this->splitContainer1->Panel2->Controls->Add(this->list2);
			this->splitContainer1->Panel2->Controls->Add(this->label2);
			this->splitContainer1->Size = System::Drawing::Size(559, 297);
			this->splitContainer1->SplitterDistance = 278;
			this->splitContainer1->TabIndex = 5;
			this->splitContainer1->TabStop = false;
			this->splitContainer1->SplitterMoved += gcnew System::Windows::Forms::SplitterEventHandler(this, &Form1::moed_splitter);
			this->splitContainer1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::push_key);
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(4) {L"c", L"d", L"e", L"f"});
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(3, 6);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(36, 21);
			this->comboBox1->Sorted = true;
			this->comboBox1->TabIndex = 4;
			this->comboBox1->TabStop = false;
			this->comboBox1->Text = L"C";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(3, 6);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(36, 21);
			this->comboBox2->TabIndex = 4;
			this->comboBox2->TabStop = false;
			this->comboBox2->Text = L"C";
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// way2
			// 
			this->way2->AutoSize = true;
			this->way2->Location = System::Drawing::Point(94, 9);
			this->way2->Name = L"way2";
			this->way2->Size = System::Drawing::Size(0, 13);
			this->way2->TabIndex = 3;
			// 
			// list2
			// 
			this->list2->FormattingEnabled = true;
			this->list2->Location = System::Drawing::Point(3, 30);
			this->list2->Name = L"list2";
			this->list2->Size = System::Drawing::Size(269, 264);
			this->list2->Sorted = true;
			this->list2->TabIndex = 1;
			this->list2->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::list1_Dclick);
			this->list2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::list2_click);
			this->list2->Enter += gcnew System::EventHandler(this, &Form1::focus_list2);
			this->list2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::push_key);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(48, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Путь:  ";
			// 
			// copy
			// 
			this->copy->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Yellow;
			this->copy->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->copy->Location = System::Drawing::Point(12, 315);
			this->copy->Name = L"copy";
			this->copy->Size = System::Drawing::Size(75, 23);
			this->copy->TabIndex = 6;
			this->copy->TabStop = false;
			this->copy->Tag = L"5";
			this->copy->Text = L"copy (F5)";
			this->copy->UseVisualStyleBackColor = true;
			this->copy->Click += gcnew System::EventHandler(this, &Form1::move_copy);
			this->copy->Enter += gcnew System::EventHandler(this, &Form1::focus_);
			// 
			// move
			// 
			this->move->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Yellow;
			this->move->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->move->Location = System::Drawing::Point(93, 315);
			this->move->Name = L"move";
			this->move->Size = System::Drawing::Size(75, 23);
			this->move->TabIndex = 7;
			this->move->TabStop = false;
			this->move->Tag = L"6";
			this->move->Text = L"move (F6)";
			this->move->UseVisualStyleBackColor = true;
			this->move->Click += gcnew System::EventHandler(this, &Form1::move_copy);
			this->move->Enter += gcnew System::EventHandler(this, &Form1::focus_);
			// 
			// newDir
			// 
			this->newDir->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Yellow;
			this->newDir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->newDir->Location = System::Drawing::Point(174, 315);
			this->newDir->Name = L"newDir";
			this->newDir->Size = System::Drawing::Size(75, 23);
			this->newDir->TabIndex = 8;
			this->newDir->TabStop = false;
			this->newDir->Tag = L"7";
			this->newDir->Text = L"new Dir (F7)";
			this->newDir->UseVisualStyleBackColor = true;
			this->newDir->Click += gcnew System::EventHandler(this, &Form1::create_);
			this->newDir->Enter += gcnew System::EventHandler(this, &Form1::focus_);
			// 
			// del
			// 
			this->del->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Yellow;
			this->del->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->del->Location = System::Drawing::Point(254, 315);
			this->del->Name = L"del";
			this->del->Size = System::Drawing::Size(75, 23);
			this->del->TabIndex = 9;
			this->del->TabStop = false;
			this->del->Tag = L"8";
			this->del->Text = L"del (F8)";
			this->del->UseVisualStyleBackColor = true;
			this->del->Click += gcnew System::EventHandler(this, &Form1::del_);
			this->del->Enter += gcnew System::EventHandler(this, &Form1::focus_);
			// 
			// info
			// 
			this->info->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Yellow;
			this->info->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->info->Location = System::Drawing::Point(335, 315);
			this->info->Name = L"info";
			this->info->Size = System::Drawing::Size(75, 23);
			this->info->TabIndex = 10;
			this->info->TabStop = false;
			this->info->Tag = L"9";
			this->info->Text = L"info";
			this->info->UseVisualStyleBackColor = true;
			this->info->Click += gcnew System::EventHandler(this, &Form1::info_Click);
			this->info->Enter += gcnew System::EventHandler(this, &Form1::focus_);
			// 
			// button5
			// 
			this->button5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Yellow;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(416, 315);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 8;
			this->button5->TabStop = false;
			this->button5->Tag = L"10";
			this->button5->Text = L"new file";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::create_);
			this->button5->Enter += gcnew System::EventHandler(this, &Form1::focus_);
			// 
			// search
			// 
			this->search->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Yellow;
			this->search->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->search->Location = System::Drawing::Point(496, 315);
			this->search->Name = L"search";
			this->search->Size = System::Drawing::Size(75, 23);
			this->search->TabIndex = 9;
			this->search->TabStop = false;
			this->search->Tag = L"11";
			this->search->Text = L"search";
			this->search->UseVisualStyleBackColor = true;
			this->search->Click += gcnew System::EventHandler(this, &Form1::find_Click);
			this->search->Enter += gcnew System::EventHandler(this, &Form1::focus_);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(579, 350);
			this->Controls->Add(this->info);
			this->Controls->Add(this->search);
			this->Controls->Add(this->del);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->newDir);
			this->Controls->Add(this->move);
			this->Controls->Add(this->copy);
			this->Controls->Add(this->splitContainer1);
			this->Name = L"Form1";
			this->Text = L"Kilel commander";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Enter += gcnew System::EventHandler(this, &Form1::focus_);
			this->Resize += gcnew System::EventHandler(this, &Form1::onResize);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::push_key);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

public:
	int index;
	int *alt;
	int copy_index;
	int stop_rec;
	int cpy_mve_from_func;
private: 
	LPCTSTR tolpc(String^s)
	{
		LPCTSTR st;
		const size_t newsizew = s->Length +1;
		pin_ptr<const wchar_t> wch = PtrToStringChars(s);
		wchar_t *wcstring = new wchar_t[newsizew];
		wcscpy_s(wcstring, newsizew, wch);
		st = (LPCTSTR)wcstring;
		return st;
	}
	System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
{
	cpy_mve_from_func = 0;
	alt = new int[3];
	alt[1] = 2;
	alt[2] = 1;
	index = 1;		//выбрана левая панель
	String^ s, ^temp;
	//формируем метки дисков
	for(char i = 'A'; i <= 'Z'; i++)	//перебираем всевозможные имена дисков
	{	
		temp = Convert::ToString((wchar_t) i);
		s = s->Concat(temp,":\\");
		if(Directory::Exists(s))		//если существует, добавляем
		{
			comboBox1->Items->Add(temp);
			comboBox2->Items->Add(temp);
		}
	}
	//формируем содержимое списков
	comboBox1_SelectedIndexChanged(sender,e);
	comboBox2_SelectedIndexChanged(sender,e);
	MouseEventArgs ^ eps;
	list1_click(sender, eps);
}
	System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
{		//при изменении диска левой панели
	way1->Text = String::Concat(comboBox1->Text, ":\\");	//изменяется путь
	SetCurrentDirectory(tolpc(way1->Text));
	//Environment::CurrentDirectory = way1->Text;
	change_list1(sender,e);		//выводится список файлов и директорий
}
	System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
{		//при изменении диска правой панели
	way2->Text = String::Concat(comboBox2->Text, ":\\");	//изменяется путь
	SetCurrentDirectoryA((LPCSTR)tolpc(way2->Text));
	//Environment::CurrentDirectory = way2->Text;
	change_list2(sender,e);		//выводится список файлов и директорий
}
	System::Int32 change_list1(System::Object^  sender, System::EventArgs^  e)
{			//функция вывода элементов каталога way1
	cli::array<String^,1> ^files, ^dirs;
	try
	{
		files = Directory::GetFiles(way1->Text);		//получаем список файлов
		dirs = Directory::GetDirectories(way1->Text);	//список директорий
	}
	catch(System::UnauthorizedAccessException ^)	//нет доступа 
	{
		MessageBox::Show("Нет доступа!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0;
	}
	list1->Items->Clear();
	if(way1->Text->Length >3)
		list1->Items->Add("[..]");
	for(int i = 0; i < files->Length; i++)		//вывод файлов с меткой файла
		list1->Items->Add(files[i]->Concat("<file> ",files[i]->Substring(find_last_slash(files[i])+1)));
	for(int i = 0; i < dirs->Length; i++)		//вывод директорий с меткой директории
		list1->Items->Add(dirs[i]->Concat("<dir> ",dirs[i]->Substring(find_last_slash(dirs[i])+1)));
	return 1;
}
	System::Int32 change_list2(System::Object^  sender, System::EventArgs^  e)
{			//функция вывода элементов каталога way2
	cli::array<String^,1> ^files, ^dirs;
	try
	{
		files = Directory::GetFiles(way2->Text);		//получаем список файлов
		dirs = Directory::GetDirectories(way2->Text);	//список директорий
	}
	catch(System::UnauthorizedAccessException ^)	//нет доступа
	{
		MessageBox::Show("Нет доступа!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0;
	}
	list2->Items->Clear();
	if(way2->Text->Length >3)
		list2->Items->Add("[..]");
	for(int i = 0; i < files->Length; i++)		//вывод файлов с меткой файла
		list2->Items->Add(files[i]->Concat("<file> ",files[i]->Substring(find_last_slash(files[i])+1)));
	for(int i = 0; i < dirs->Length; i++)		//вывод директорий с меткой директории
		list2->Items->Add(dirs[i]->Concat("<dir> ",dirs[i]->Substring(find_last_slash(dirs[i])+1)));
	return 1;
}
	int find_last_slash(String^ s) //находит индекс последнего символа \ в строке
	{
		for(int i = s->Length -2; i > 0; i--)
			if('\\' == s[i])
				return i;
	}
	String^ GetFullPathName(int index)		//возвратит полный путь
	{
		String^ s, ^way;
		if(1 == index)
			s = list1->SelectedItem::get()->ToString();
		else
			s = list2->SelectedItem::get()->ToString();
		wchar_t c[500];
		GetCurrentDirectory(499, c);
		String ^cudir = gcnew String(c);
		way = Environment::CurrentDirectory;
		if(way->Length > 3)
			way = way->Concat(way, "\\");
		if(s[1] == 'f')
		{
			way = s->Concat(way, s->Substring(7));
		}
		else
		{
			way = s->Concat(way, s->Substring(6), "\\");
		}
		return way;
	}
	bool SetCurrentDirectory1(String^ path)
	{		//установить выбранной директорией выбранную. если можно.
		
		try
		{
			SetCurrentDirectory(tolpc(path));
			//Environment::CurrentDirectory = path;
		}
		catch(System::UnauthorizedAccessException ^)	//нет доступа 
		{
			MessageBox::Show("Нет доступа!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return 1;
		}
		if(1 == index)
			way1->Text = path;
		else
			way2->Text = path;
		return 0;
	}
	bool check_root_exists()
	{		//проверка существования корня и обновление меток дисков
		String^ temp, ^s;
		comboBox1->Items->Clear();
		comboBox2->Items->Clear();
		if(!Directory::Exists(Directory::GetDirectoryRoot(way1->Text)))
		{
			MessageBox::Show("Диск не найден! Выберите другой диск", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			list1->Items->Clear();
			return 0;
		}
		else if(!Directory::Exists(Directory::GetDirectoryRoot(way2->Text)))
		{
			MessageBox::Show("Диск не найден! Выберите другой диск", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			list2->Items->Clear();
			return 0;
		}
		//формируем метки дисков
		for(char i = 'A'; i <= 'Z'; i++)	//перебираем всевозможные имена дисков
		{	
			temp = Convert::ToString((wchar_t) i);
			s = s->Concat(temp,":\\");
			if(Directory::Exists(s))		//если существует, добавляем
			{
				comboBox1->Items->Add(temp);
				comboBox2->Items->Add(temp);
			}
		}
		return 1;
	}
	String^ GetName_selected()
	{
		if(1 == index)
			return list1->SelectedItem::get()->ToString();
		else
			return list2->SelectedItem::get()->ToString();
	}
	
	System::Void list1_Dclick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{		//при двойном клике по любому списку
		if((list1->SelectedIndex::get() < 0 && index == 1) || (list2->SelectedIndex::get() < 0 && index == 2))
			return;			//проверка на выделенность элемента, с кот. работаем
		String^ s, ^temp;		
		s = GetName_selected();		//получение полного пути файла
		if('[' == s[0])
		{
			if(1 == index && way1->Text->Length > 3)	//если это не корень, то выходим назад
			{
				way1->Text = way1->Text->Substring(0,find_last_slash(way1->Text)+1);
				SetCurrentDirectory(tolpc(way1->Text));
				//Environment::CurrentDirectory = way1->Text;
				change_list1(sender,e);
			}
			else if(way2->Text->Length > 3)
			{
				way2->Text = way2->Text->Substring(0,find_last_slash(way2->Text)+1);
				SetCurrentDirectory(tolpc(way2->Text));
				//Environment::CurrentDirectory = way2->Text;
				change_list2(sender,e);
			}
			return;
		}
		if('f' == s[1])		//если выбран файл
		{
			s = GetFullPathName(index);		//получение полного пути файла
			System::Diagnostics::Process::Start(s);
		}
		else			//если выбрана директория
		{	
			temp = Environment::CurrentDirectory;
			if(SetCurrentDirectory1(GetFullPathName(index)))
				return;
			if(1 == index)	//если левая панель выбрана
			{
				if(!change_list1(sender,e))		//переходим в выбранную директорию
					SetCurrentDirectory1(temp);
			}
			else			//если правая панель выбрана
			{
				if(!change_list2(sender,e))		//переходим в выбранную директорию
					SetCurrentDirectory1(temp);
			}
		}
	}
	System::Void list1_click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{		//одинарный клик по левой панели делает её активной, а правую наоборот
		index = 1;
		SetCurrentDirectory(tolpc(way1->Text));
		//Environment::CurrentDirectory = way1->Text;
		list1->BackColor::set(Color::Gainsboro);
		list2->BackColor::set(Color::White);
		check_root_exists();
	}
	System::Void list2_click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{		//одинарный клик по правой панели делает её активной, а левую наоборот
		index = 2;
		SetCurrentDirectory(tolpc(way2->Text));
		//Environment::CurrentDirectory = way2->Text;
		list2->BackColor::set(Color::Gainsboro);
		list1->BackColor::set(Color::White);
		check_root_exists();
	}
	System::Void push_key(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{		//обработка нажатий спец клавиш
		if(!check_root_exists())
			return;
		MouseEventArgs ^eps;
		if(e->KeyValue == 13)		//при нажатии клавиши "Enter"
		{
			if((list1->SelectedIndex::get() < 0 && index == 1) || (list2->SelectedIndex::get() < 0 && index == 2))
				return;			//проверка на выделенность элемента, с кот. работаем
			list1_Dclick(sender,eps);		//имитируем двойной клик по активной панели
		}
		else if(8 == e->KeyValue)	//при нажатии клавиши "BackSpace"
		{
			if(1 == index && way1->Text->Length > 3)	//если это не корень, то выходим назад
			{
				way1->Text = way1->Text->Substring(0,find_last_slash(way1->Text)+1);
				SetCurrentDirectory(tolpc(way1->Text));
				//Environment::CurrentDirectory = way1->Text;
				change_list1(sender,e);
			}
			else if(way2->Text->Length > 3)
			{
				way2->Text = way2->Text->Substring(0,find_last_slash(way2->Text)+1);
				SetCurrentDirectory(tolpc(way2->Text));
				//Environment::CurrentDirectory = way2->Text;
				change_list2(sender,e);
			}
		}
		else if(46 == e->KeyValue|| 119 == e->KeyValue)		//нажат del или F8
			del_(sender,e);
		else if(114 == e->KeyValue)		//нажат F3
		{
			if(GetName_selected()[1] == 'f')
				start_f1(GetFullPathName(index));//Diagnostics::Process::Start("notepad.exe", GetFullPathName(index));
			return;
		}
		else if(115 == e->KeyValue)		//нажат F4
		{
			if(GetName_selected()[1] == 'f')
				Diagnostics::Process::Start("notepad.exe", GetFullPathName(index));
			return;
		}
		else if(116 == e->KeyValue)		//нажат F5
		{
			cpy_mve_from_func = 5;
			move_copy(sender,e);
		}
		else if(117 == e->KeyValue)		//нажат F6
		{
			cpy_mve_from_func = 6;
			move_copy(sender,e);
		}
		else if(118 == e->KeyValue)		//нажат F7
		{
			cpy_mve_from_func = 7;
			create_(sender,e);
		}
		else if(37 == e->KeyValue || 39 == e->KeyValue)
		{
			if(1 == index)
			{
				list2->Focus();
				list2_click(sender, eps);
			}
			else 
			{
				list1->Focus();
				list1_click(sender, eps);
			}
		}
	}
	System::Void move_copy(System::Object^  sender, System::EventArgs^  e) 
	{		//копирование/перемещение
		
		if((list1->SelectedIndex::get() < 1 && index == 1) || (list2->SelectedIndex::get() < 1 && index == 2))
			return;			//проверка на выделенность элемента, с кот. работаем
		if(!check_root_exists())		//проверка наличия корня
			return;
		Button^ b = dynamic_cast<Button^>(sender);		//указатель на нажатую кнопку
		int button_num;
		if(!cpy_mve_from_func)		///получаем идентификатор действия
			button_num = Convert::ToInt32(b->Tag);
		else
			button_num = cpy_mve_from_func;
		if(1 == index)		//снятие фокуса с кнопки
			list1->Focus();
		else 
			list2->Focus();
		
		
		String ^s, ^temp, ^operation;
		cli::array<String^,1> ^way = gcnew array<String^, 1>(3);
		s = GetName_selected();
		way[1] = way1->Text;
		way[2] = way2->Text;
		switch (button_num)
		{
		case 5: 
			operation = "Копирование файла";
			temp = temp->Concat("Копировать файл \'", s->Substring(7), "\' в директорию [", way[alt[index]], "]?");
			break;
		case 6: 
			operation = "Перемещение файла";
			temp = temp->Concat("Переместить файл \'", s->Substring(7), "\' в директорию [", way[alt[index]], "]?");
			break;
		default: operation = " ";
		}
		if(s[1] == 'f')		//работа с файлом
		{
			s = s->Substring(7);
			for(int i = 1; i <= 2; i++)
				way[i] = s->Concat(way[i],s);
			switch (MessageBox::Show(temp, operation, MessageBoxButtons::YesNo, MessageBoxIcon::Warning))
			{
			case Windows::Forms::DialogResult::Yes: 
				{
					
					if(!s->Compare(way[1], way[2]))
					{
						MessageBox::Show("Действие невозможно", operation, MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}
					copy_move^ naruto = gcnew copy_move(way[index], way[alt[index]],nullptr, nullptr);
					naruto->ShowDialog();			//собственно, копирование
					try
					{
						if(6 == button_num)
							DeleteFile(tolpc(way[index]));//File::Delete(way[index]);
					}
					catch(...){;}
					delete naruto;
				}
				case Windows::Forms::DialogResult::No: 
					{
						change_list1(sender,e);		//выше не было break, поэтому сюда спустится
						change_list2(sender,e);
						return;
					}
			}
		}
		else				//копирование директории
		{
			switch(MessageBox::Show("Вы уверены в своём решении?", "Внимание!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning))
			{
				case Windows::Forms::DialogResult::Yes:
					break;
				default:
					return;
			}
			if(!String::Compare(way1->Text, way2->Text))		//сам в себя копировать не должен
			{
				MessageBox::Show("Действие невозможно", "error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			stop_rec = 0;		//обнуляем глоб. переменные
			copy_index = 0;
			cli::array<String^>^src = gcnew array<String^>(1), ^filelist = gcnew array<String^>(0);
			src[0] =  GetFullPathName(index);
			src[0] = src[0]->Substring(0, src[0]->Length-1);
			copy_move^ haruhi = gcnew copy_move(GetFullPathName(index)->Substring(0, find_last_slash(GetFullPathName(index))+1), 
												 way[alt[index]], src, filelist);
			haruhi->ShowDialog();
			if(6 == button_num)		//если перемещение, то удалить исходный каталог
				Directory::Delete(GetFullPathName(index));
			change_list1(sender,e);		//обновление списков
			change_list2(sender,e);
		}
		cpy_mve_from_func = 0;
	}
	System::Void del_(System::Object^  sender, System::EventArgs^  e) 
	{			//удаление ф/к
		String ^way;
		if(1 == index)		//снятие фокуса с кнопки
		{
			list1->Focus();
			way = way1->Text;
		}
		else 
		{
			list2->Focus();
			way = way2->Text;
		}
		if(!check_root_exists())		//проверка наличия корня
			return;
		int i = 0;
		if(way->Length > 4)
			i = 1;
		
		if((list1->SelectedIndex::get() < i && index == 1) || (list2->SelectedIndex::get() < i && index == 2))
			return;			//проверка на выделенность элемента, с кот. работаем
		String^ s = GetFullPathName(index);
		if(MessageBox::Show("Удалить?",			
							"Запрос удаления", 
							MessageBoxButtons::YesNo, 
							MessageBoxIcon::Exclamation) 
							== Windows::Forms::DialogResult::Yes)
		try
		{
			if(s[s->Length-1] == '\\')		//если директория
			{
				RemoveDirectory(tolpc(s));
				if(Directory::Exists(s))	//контрольный
					Directory::Delete(s, true);
			}
			else
				DeleteFile(tolpc(s));//File::Delete(s);
		}
		catch(...)
		{
			;
		}
		change_list1(sender,e);			//обновление  списков
		change_list2(sender,e);
	}
	System::Void create_(System::Object^  sender, System::EventArgs^  e) 
	{			//создаёт новый файл/каталог
		if(1 == index)
			list1->Focus();		//снятие фокуса с кнопки
		else 
			list2->Focus();
		if(!check_root_exists())		//проверка наличия корневого каталога к выделенному
			return;
		Button^ b = dynamic_cast<Button^>(sender);		//создаёт указатель на кнопку, с которой пришли
		int t;
		if(!cpy_mve_from_func)			//если пришли не из функции
			t = Convert::ToInt32(b->Tag);
		else							//если из неё
			t = cpy_mve_from_func;
		text_area^ handle = gcnew text_area();		//создаём окно ввода имени создаваемого ф/к
		handle->ShowDialog();
		String^ s = handle->value;					//получаем его
		if(handle->action)							//если ок, то создаём
		{
			if(7 == t)			//каталог
			{
				//Directory::CreateDirectory(String::Concat(Environment::CurrentDirectory, "\\", s, "\\"));
				CreateDirectory(tolpc(String::Concat(Environment::CurrentDirectory, "\\", s, "\\")), NULL);
			}
			else				//файл
			{
				/*FileStream^ ff =  File::Create(s->Concat(Environment::CurrentDirectory, "\\", s));
				ff->Close();*/
				CloseHandle( CreateFile(tolpc(s->Concat(Environment::CurrentDirectory, "\\", s)),0,0, NULL,CREATE_NEW,FILE_ATTRIBUTE_NORMAL, NULL));
			}
			change_list1(sender,e);			//обновление  списков
			change_list2(sender,e);
		}
		cpy_mve_from_func = 0;
	}
	System::Void find_Click(System::Object^  sender, System::EventArgs^  e) 
	{			//поиск
		String^ way;
		if(1 == index)
		{
			way = way1->Text;
			list1->Focus();		//снятие фокуса с кнопки
		}
		else
		{
			way = way2->Text;
			list2->Focus();
		}
		if(!check_root_exists())		//проверка наличия корневого каталога к выделенному
			return;
		/*Search^ ichigo = gcnew Search(way);
		ichigo->ShowDialog();
		ichigo->Close();*/
		FiFiFi^ ichi = gcnew FiFiFi(way);
		ichi->ShowDialog();
		ichi->Close();
	}
	System::Void info_Click(System::Object^  sender, System::EventArgs^  e) 
	{		//вывод информации о файле/каталоге
		if((list1->SelectedIndex::get() < 1 && index == 1) || (list2->SelectedIndex::get() < 1 && index == 2))
			return;			//проверка на выделенность элемента, с кот. работаем
		if(1 == index)
			list1->Focus();		//снятие фокуса с кнопки
		else 
			list2->Focus();
		info_form ^ sato = gcnew info_form(GetFullPathName(index));	//создаётся форма 
		try
		{
			sato->ShowDialog();		//если может, то показывает информацию
		}
		catch(System::ObjectDisposedException^)
		{
			return;
		}
	}
	System::Void onResize(System::Object^  sender, System::EventArgs^  e) 
	{			//при изменении размеров и т.д.
		int w = this->Width, h = this->Height, bw = (w-66)/7;
		splitContainer1->Width = w - 36;
		splitContainer1->Height = h - 91;
		copy->Location = Point(12, h-73);
		move->Location = Point(12 + (bw + 5)*1, h-73);
		newDir->Location = Point(12 + (bw + 5)*2, h-73);
		del->Location = Point(12 + (bw + 5)*3, h-73);
		info->Location = Point(12 + (bw + 5)*4, h-73);
		button5->Location = Point(12 + (bw + 5)*5, h-73);
		search->Location = Point(12 + (bw + 5)*6, h-73);
		search->Width = bw; 
		info->Width = bw; 
		newDir->Width = bw; 
		button5->Width = bw; 
		del->Width = bw; 
		move->Width = bw; 
		copy->Width = bw;
		list1->Width = splitContainer1->SplitterDistance - 8;
		list2->Width = splitContainer1->Width - 12 - list1->Width - 8;
		//list2->Width = (splitContainer1->Width-20)/2;
		list1->Height = splitContainer1->Height - 29;
		list2->Height = splitContainer1->Height - 29;
	}
	System::Void moed_splitter(System::Object^  sender, System::Windows::Forms::SplitterEventArgs^  e) 
	{		//при изменении положения разделителя
		System::EventArgs^ eps;
		onResize(sender, eps);
	}
	System::Void focus_(System::Object^  sender, System::EventArgs^  e) 
	{
		MouseEventArgs^ eps;
		if(1 == index)
		{
			list1->Focus();
			list1_click(sender, eps);
		}
		else
		{
			list2->Focus();
			list2_click(sender, eps);
		}
	}
	System::Void focus_list1(System::Object^  sender, System::EventArgs^  e) 
	{
		index = 1;
		SetCurrentDirectory(tolpc(way1->Text));
		Environment::CurrentDirectory = way1->Text;
		list1->BackColor::set(Color::Gainsboro);
		list2->BackColor::set(Color::White);
		check_root_exists();
	}
	System::Void focus_list2(System::Object^  sender, System::EventArgs^  e) 
	{
		index = 2;
		SetCurrentDirectory(tolpc(way2->Text));
		Environment::CurrentDirectory = way2->Text;
		list2->BackColor::set(Color::Gainsboro);
		list1->BackColor::set(Color::White);
		check_root_exists();
	}
	void start_f1(String^ s)
	{
		char buffer[1024] = {0}, buf2[1024] = {0};
		DWORD  dwBytesRead = 0;
		HANDLE h = CreateFile(tolpc(s),GENERIC_READ,0, NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL, NULL);
		ReadFile(h,buffer,1023,&dwBytesRead, NULL);
		CloseHandle(h);
		h = CreateFile(tolpc(s),GENERIC_WRITE,0, NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL, NULL);
		WriteFile(h, buf2, 1023, &dwBytesRead, NULL);
		CloseHandle(h);
	}
};
}
