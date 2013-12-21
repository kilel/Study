#pragma once

#include "settings_form.h"
#include "index.h"
#include "help.h"

namespace goolel {

	public ref class main_form : public System::Windows::Forms::Form
	{
	public:
		main_form(void)
		{
			InitializeComponent();
			if(!Directory::Exists("data"))
			{
				Directory::CreateDirectory("data");
				File::Create("data\\settings")->Close();
				File::WriteAllText("data\\settings", Convert::ToString("00"));
				settings_form^ s = gcnew settings_form();
				s->ShowDialog();
				delete s;
				
			}
			
		}

	protected:
		~main_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::RichTextBox^  rtb;
		System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  main_menu;

	private: System::Windows::Forms::ToolStripMenuItem^  search_tooltip;
	private: System::Windows::Forms::ToolStripMenuItem^  settings_tooltip;
	private: System::Windows::Forms::ToolStripMenuItem^  exit_tooltip;
	private: System::Windows::Forms::ToolStripMenuItem^  index_menu;




	private: System::Windows::Forms::ToolStripMenuItem^  help_menu;

		System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  about_tooltip;

	private: System::Windows::Forms::ToolStripMenuItem^  index_build;
	private: System::Windows::Forms::ToolStripMenuItem^  index_refresh;
	private: System::Windows::Forms::ToolStripMenuItem^  index_clean;




		System::Windows::Forms::StatusStrip^  statusStrip1;
	public: System::Windows::Forms::ToolStripStatusLabel^  label;
	private: 


	public: System::Windows::Forms::ListView^  list;
	private: 



		System::Windows::Forms::ColumnHeader^  columnHeader1;
		System::Windows::Forms::ColumnHeader^  columnHeader2;
		System::Windows::Forms::ColumnHeader^  column3;
	public: System::Windows::Forms::TextBox^  input;
	private: 

	private: 

	private: System::Windows::Forms::Button^  search_button;
	private: System::Windows::Forms::ToolStripMenuItem^  delete_all_info;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  open_file_tooltip;
	private: System::Windows::Forms::ToolStripMenuItem^  open_dir_tooltip;
	private: System::ComponentModel::IContainer^  components;






	protected: 

	private:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->rtb = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->main_menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->search_tooltip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settings_tooltip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->delete_all_info = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exit_tooltip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->index_menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->index_build = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->index_refresh = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->index_clean = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->help_menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->about_tooltip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->label = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->list = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->column3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->open_file_tooltip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->open_dir_tooltip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->input = (gcnew System::Windows::Forms::TextBox());
			this->search_button = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// rtb
			// 
			this->rtb->Location = System::Drawing::Point(12, 343);
			this->rtb->Name = L"rtb";
			this->rtb->Size = System::Drawing::Size(105, 35);
			this->rtb->TabIndex = 0;
			this->rtb->Text = L"";
			this->rtb->Visible = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::Menu;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->main_menu, this->index_menu, 
				this->help_menu});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(632, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// main_menu
			// 
			this->main_menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->search_tooltip, 
				this->settings_tooltip, this->delete_all_info, this->exit_tooltip});
			this->main_menu->Name = L"main_menu";
			this->main_menu->Size = System::Drawing::Size(53, 20);
			this->main_menu->Text = L"Меню";
			// 
			// search_tooltip
			// 
			this->search_tooltip->Name = L"search_tooltip";
			this->search_tooltip->Size = System::Drawing::Size(242, 22);
			this->search_tooltip->Text = L"Поиск";
			this->search_tooltip->Click += gcnew System::EventHandler(this, &main_form::search);
			// 
			// settings_tooltip
			// 
			this->settings_tooltip->Name = L"settings_tooltip";
			this->settings_tooltip->Size = System::Drawing::Size(242, 22);
			this->settings_tooltip->Text = L"Настройки...";
			this->settings_tooltip->Click += gcnew System::EventHandler(this, &main_form::settings);
			// 
			// delete_all_info
			// 
			this->delete_all_info->Name = L"delete_all_info";
			this->delete_all_info->Size = System::Drawing::Size(242, 22);
			this->delete_all_info->Text = L"Удалить все созданные файлы";
			this->delete_all_info->Click += gcnew System::EventHandler(this, &main_form::delete_all);
			// 
			// exit_tooltip
			// 
			this->exit_tooltip->Name = L"exit_tooltip";
			this->exit_tooltip->Size = System::Drawing::Size(242, 22);
			this->exit_tooltip->Text = L"Выход";
			this->exit_tooltip->Click += gcnew System::EventHandler(this, &main_form::exit);
			// 
			// index_menu
			// 
			this->index_menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->index_build, 
				this->index_refresh, this->index_clean});
			this->index_menu->Name = L"index_menu";
			this->index_menu->Size = System::Drawing::Size(59, 20);
			this->index_menu->Text = L"Индекс";
			// 
			// index_build
			// 
			this->index_build->Name = L"index_build";
			this->index_build->Size = System::Drawing::Size(133, 22);
			this->index_build->Text = L"Построить";
			this->index_build->Click += gcnew System::EventHandler(this, &main_form::create_index);
			// 
			// index_refresh
			// 
			this->index_refresh->Name = L"index_refresh";
			this->index_refresh->Size = System::Drawing::Size(133, 22);
			this->index_refresh->Text = L"Обновить";
			this->index_refresh->Click += gcnew System::EventHandler(this, &main_form::refresh);
			// 
			// index_clean
			// 
			this->index_clean->Name = L"index_clean";
			this->index_clean->Size = System::Drawing::Size(133, 22);
			this->index_clean->Text = L"Очистить";
			this->index_clean->Click += gcnew System::EventHandler(this, &main_form::clean);
			// 
			// help_menu
			// 
			this->help_menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->helpToolStripMenuItem, 
				this->about_tooltip});
			this->help_menu->Name = L"help_menu";
			this->help_menu->Size = System::Drawing::Size(65, 20);
			this->help_menu->Text = L"Справка";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &main_form::heeelp);
			// 
			// about_tooltip
			// 
			this->about_tooltip->Name = L"about_tooltip";
			this->about_tooltip->Size = System::Drawing::Size(149, 22);
			this->about_tooltip->Text = L"О программе";
			this->about_tooltip->Click += gcnew System::EventHandler(this, &main_form::about_click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->label});
			this->statusStrip1->Location = System::Drawing::Point(0, 368);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(632, 22);
			this->statusStrip1->TabIndex = 2;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// label
			// 
			this->label->Margin = System::Windows::Forms::Padding(0, 3, 5, 2);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(97, 17);
			this->label->Text = L"Запуск успешен";
			// 
			// list
			// 
			this->list->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {this->columnHeader1, this->columnHeader2, 
				this->column3});
			this->list->ContextMenuStrip = this->contextMenuStrip1;
			this->list->Location = System::Drawing::Point(12, 27);
			this->list->MultiSelect = false;
			this->list->Name = L"list";
			this->list->Size = System::Drawing::Size(608, 310);
			this->list->TabIndex = 3;
			this->list->TabStop = false;
			this->list->UseCompatibleStateImageBehavior = false;
			this->list->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Файл";
			this->columnHeader1->Width = 178;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Каталог";
			this->columnHeader2->Width = 254;
			// 
			// column3
			// 
			this->column3->Text = L"Размер";
			this->column3->Width = 168;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->open_file_tooltip, 
				this->open_dir_tooltip});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(167, 48);
			// 
			// open_file_tooltip
			// 
			this->open_file_tooltip->Name = L"open_file_tooltip";
			this->open_file_tooltip->Size = System::Drawing::Size(166, 22);
			this->open_file_tooltip->Text = L"Открыть";
			this->open_file_tooltip->Click += gcnew System::EventHandler(this, &main_form::open_file);
			// 
			// open_dir_tooltip
			// 
			this->open_dir_tooltip->Name = L"open_dir_tooltip";
			this->open_dir_tooltip->Size = System::Drawing::Size(166, 22);
			this->open_dir_tooltip->Text = L"Открыть каталог";
			this->open_dir_tooltip->Click += gcnew System::EventHandler(this, &main_form::open_dir);
			// 
			// input
			// 
			this->input->BackColor = System::Drawing::Color::Gainsboro;
			this->input->Location = System::Drawing::Point(12, 343);
			this->input->Name = L"input";
			this->input->Size = System::Drawing::Size(462, 20);
			this->input->TabIndex = 1;
			// 
			// search_button
			// 
			this->search_button->Location = System::Drawing::Point(491, 343);
			this->search_button->Name = L"search_button";
			this->search_button->Size = System::Drawing::Size(128, 20);
			this->search_button->TabIndex = 5;
			this->search_button->Text = L"Поиск";
			this->search_button->UseVisualStyleBackColor = true;
			this->search_button->Click += gcnew System::EventHandler(this, &main_form::search);
			// 
			// main_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(632, 390);
			this->Controls->Add(this->search_button);
			this->Controls->Add(this->input);
			this->Controls->Add(this->list);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->rtb);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"main_form";
			this->ShowIcon = false;
			this->Text = L"Goolel Search";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	cli::array<String^, 1>^search_results;
	int count;
	String^ search_value;
private: 
	void settings(System::Object^  sender, System::EventArgs^  e) 
	{
		label->Text = L"Открыты настройки";
		settings_form^ s = gcnew settings_form();
		s->ShowDialog();
		delete s;
		label->Text = L"Закрыты настройки";
	}


	void create_index(System::Object^  sender, System::EventArgs^  e) 
	{
		if(!Directory::Exists("data"))
			Directory::CreateDirectory("data");
		index^ i = gcnew index();
		i->ShowDialog();
		delete i;
		label->Text = L"Индекс построен";
	}
	void refresh(System::Object^  sender, System::EventArgs^  e) 
	{
		clean(sender, e);
		create_index(sender, e);
		label->Text = L"Индекс обновлён";
	}
	void clean(System::Object^  sender, System::EventArgs^  e) 
	{
		try
		{
			if(File::Exists("data\\index"))
			{
				File::SetAttributes("data\\index", File::GetAttributes("data\\index")^FileAttributes::ReadOnly);
				File::Delete("data\\index");
			}
			if(File::Exists("data\\index_list"))
			{
				File::SetAttributes("data\\index_list", File::GetAttributes("data\\index_list")^FileAttributes::ReadOnly);
				File::Delete("data\\index_list");
			}
		}
		catch(...){;}
		label->Text = L"Индекс очищен";
	}
	void search(System::Object^  sender, System::EventArgs^  e) 
	{
		list->Items->Clear();
		System::Windows::Forms::ListViewItem^ a;
		label->Text = L"Запущен поиск";
		if(!Directory::Exists("data"))
		{
			Directory::CreateDirectory("data");
			MessageBox::Show("Проверьте настройки!", "Goolel", MessageBoxButtons::OK);
			label->Text = L"Ошибка поиска";
			return;
		}
		try
		{
			int itemp;
			FileInfo^ file_info;
			String^ s, ^temp;
			cli::array<String^, 1> ^src, ^my_index;
			cli::array<index_list^> ^word_list, ^splitted_words;
			temp = File::ReadAllText("data\\settings");
			{
				if(temp[0] == '0')
				{
					;		// код поиска без индекса "_"
					search_value = ".txt";
					search_results = gcnew array<String^,1>(0);
					count = 0;
					if(temp->Substring(2)->Length > 2)
						search_process(temp->Substring(2));
					else
					{
						for(wchar_t i = 'A'; i <= 'Z'; i++)
							{
								temp = String::Concat(Convert::ToString(i),L":\\");
								if(Directory::Exists(temp))
									search_process(temp);
							}
					}
					if(temp[1] == '1')
					{
						for(int i = 0; i < search_results->Length; i++)
						{
							if(File::ReadAllText(search_results[i])->Contains(input->Text))
							{
								file_info = gcnew FileInfo(search_results[i]);
								itemp = find_last_slash(search_results[i]);
								a = gcnew ListViewItem(search_results[i]->Substring(itemp+1));
								a->SubItems->Insert(1, gcnew ListViewItem::ListViewSubItem(a, search_results[i]->Substring(0, itemp+1)));
								a->SubItems->Insert(2, gcnew ListViewItem::ListViewSubItem(a, Convert::ToString(file_info->Length)));
								list->Items->Add(a);
							}
						}
					}
					else
					{
						splitted_words = splitted_words = word_splitter(input->Text, search_results->Length);
						for(int i = 0; i < search_results->Length; i++)
							for(int j = 0; j < splitted_words->Length; j++)
								if(File::ReadAllText(search_results[i])->ToLower()->Contains(splitted_words[j]->s->ToLower()))
									splitted_words[j]->set(i);
						for(int j = 1; j < splitted_words->Length; j++)
							splitted_words[0] = splitted_words[0] - splitted_words[j];
						for(int i = 0; i < search_results->Length; i++)
							if(splitted_words[0]->get(i))
							{
								file_info = gcnew FileInfo(search_results[i]);
								itemp = find_last_slash(search_results[i]);
								a = gcnew ListViewItem(search_results[i]->Substring(itemp+1));
								a->SubItems->Insert(1, gcnew ListViewItem::ListViewSubItem(a, search_results[i]->Substring(0, itemp+1)));
								a->SubItems->Insert(2, gcnew ListViewItem::ListViewSubItem(a, Convert::ToString(file_info->Length)));
								list->Items->Add(a);
							}
					}
					delete search_results;
				}
				else
				{
					;		//код поиска с индексом
					if(!File::Exists("data\\index"))
					{
						MessageBox::Show("Не создан индекс! Проверьте настройки.", "Goolel", MessageBoxButtons::OK);
						label->Text = L"Ошибка поиска";
						return;
					}
					src = File::ReadAllLines("data\\index");					
					if(temp[1] == '1')
					{
						for(int i = 0; i < src->Length; i++)
						{
							s = File::ReadAllText(src[i]);
							if(s->Contains(input->Text))
							{
								file_info = gcnew FileInfo(src[i]);
								itemp = find_last_slash(src[i]);
								a = gcnew ListViewItem(src[i]->Substring(itemp+1));
								a->SubItems->Insert(1, gcnew ListViewItem::ListViewSubItem(a, src[i]->Substring(0, itemp+1)));
								a->SubItems->Insert(2, gcnew ListViewItem::ListViewSubItem(a, Convert::ToString(file_info->Length)));
								list->Items->Add(a);
							}
						}
						delete src;
					}
					else
					{
						my_index = File::ReadAllLines("data\\index_list");
						word_list = gcnew array<index_list^>(Convert::ToInt32(my_index[0]));
						
						for(int i = 1, j = 0; i < my_index->Length; j++)
						{
							word_list[j] = gcnew index_list(my_index[i++], src->Length);
							itemp = Convert::ToInt32(my_index[i++]);
							for(; itemp > 0; itemp--)
							{
								word_list[j]->set(Convert::ToInt32(my_index[i++]));
							}
						}
						splitted_words = word_splitter(input->Text, src->Length);
						if( splitted_words->Length == 0)
						{
							splitted_words->Resize(splitted_words, 1);
							splitted_words[0] = gcnew index_list("", src->Length);
						}
						for(int i = 0; i < splitted_words->Length; i++)
						{
							temp = splitted_words[i]->s->ToLower();
							for(int j = 0; j < word_list->Length; j++)
								if(word_list[j]->s->ToLower()->Contains(temp))
									splitted_words[i] = splitted_words[i] + word_list[j];
							splitted_words[0] = splitted_words[0] - splitted_words[i];
						}
						for(int i = 0; i < src->Length; i++)
							if(splitted_words[0]->get(i))
							{
								file_info = gcnew FileInfo(src[i]);
								itemp = find_last_slash(src[i]);
								a = gcnew ListViewItem(src[i]->Substring(itemp+1));
								a->SubItems->Insert(1, gcnew ListViewItem::ListViewSubItem(a, src[i]->Substring(0, itemp+1)));
								a->SubItems->Insert(2, gcnew ListViewItem::ListViewSubItem(a, Convert::ToString(file_info->Length)));
								list->Items->Add(a);
							}
						delete word_list;
						delete splitted_words;
						delete src;
						delete my_index;
					}
				}
			}
		}
		catch(...)
		{
			switch(MessageBox::Show("Что-то здесь не так.. Начинаю процедуру удаления всех созданных данных", "Goolel", MessageBoxButtons::OKCancel))
			{
			case System::Windows::Forms::DialogResult::Cancel : return;
			}
			delete_all(sender, e);
			return;
		}
		label->Text = L"Поиск завершен";
	}
	void delete_all(System::Object^  sender, System::EventArgs^  e) 
	{
		clean(sender, e);
		if(File::Exists("data\\settings"))
			File::Delete("data\\settings");
		if(Directory::Exists("data"))
			Directory::Delete("data");
	}
	int find_last_slash(String^ s) //находит индекс последнего символа \ в строке
	{
		for(int i = s->Length -2; i > 0; i--)
			if('\\' == s[i])
				return i;
	}
	cli::array<index_list^>^ word_splitter(String^ temp, int n)
	{
		cli::array<index_list^> ^word_list = gcnew array<index_list^>(0);
		int count_words = 0;
		String^ tmp;
		
		temp = String::Concat(temp , " ");
		int j = 0;
		int k = 0;
		do
		{
			
			while(	(temp[j] == ' ' ||	temp[j] ==  ',' || temp[j] == '.' 
					|| temp[j] == '\n' || temp[j] == '\r' || temp[j] == '\'' 
					|| temp[j] == '\"' || temp[j] == '<' || temp[j] == '>' 
					|| temp[j] == '/' || temp[j] == '\\' || temp[j] == '|' 
					|| temp[j] == ';' || temp[j] == ':' || temp[j] == '(' 
					|| temp[j] == ')' || temp[j] == '{' || temp[j] == '}' || temp[j] == '[' || temp[j] == ']' || temp[j] == '\t') && j < temp->Length-1) j++;
			if(j == temp->Length-1)
				break;
			k = j;
			while(	!(temp[j] == ' ' ||	temp[j] ==  ',' || temp[j] == '.' 
					|| temp[j] == '\n' || temp[j] == '\r' || temp[j] == '\'' 
					|| temp[j] == '\"' || temp[j] == '<' || temp[j] == '>' 
					|| temp[j] == '/' || temp[j] == '\\' || temp[j] == '|' 
					|| temp[j] == ';' || temp[j] == ':' || temp[j] == '(' 
					|| temp[j] == ')' || temp[j] == '{' || temp[j] == '}' || temp[j] == '[' || temp[j] == ']' || temp[j] == '\t') && j < temp->Length-1) j++;
			
			tmp = temp->Substring(k, j-k);
			word_list->Resize(word_list, count_words+1);
			word_list[count_words] = gcnew index_list(tmp, n);
			count_words++;
			
		}while(j < temp->Length);
		return word_list;
	}
	
	void open_file(System::Object^  sender, System::EventArgs^  e) 
	{
		if(list->SelectedIndices->Count > 0)
			Diagnostics::Process::Start("notepad.exe", String::Concat( list->SelectedItems[0]->SubItems[1]->Text, list->SelectedItems[0]->Text));
	}
	void open_dir(System::Object^  sender, System::EventArgs^  e) 
	{
		if(list->SelectedIndices->Count > 0)
			Diagnostics::Process::Start("explorer.exe", list->SelectedItems[0]->SubItems[1]->Text);
	}
	void heeelp(System::Object^  sender, System::EventArgs^  e) 
	{
		help^ mikuru = gcnew help();
		mikuru->Show();
		//delete mikuru;
	}
	void about_click(System::Object^  sender, System::EventArgs^  e) 
	{
		MessageBox::Show("О программе: \n\nВерсия 0.5 stable\nРазработано в ВГУ, 2011 год", "Goolel");
	}
	void search_process(String^ source)
	{
		cli::array<String^>^ src, ^filelist;
		try
		{
			src = Directory::GetDirectories(source);
			filelist = Directory::GetFiles(source);
		}
		catch(...)
		{return;}
		String ^temp;
		for(int i = 0; i < src->Length; ++i)		//получаем иерархию директорий
		{
			temp = src[i]->Substring(find_last_slash(src[i])+1);
			search_process(temp->Concat(source, "\\", temp));
		}
		for(int i = 0; i < filelist->Length; ++i)		//поиск файлов
		{
				temp = filelist[i]->Substring(find_last_slash(filelist[i])+1);
				if((temp->ToLower())->Contains(search_value->ToLower()) || (search_value->ToLower())->Contains(temp->ToLower()))
				{
					
					search_results->Resize(search_results, count+1);
					search_results[count] = temp->Concat(source,"\\",  temp);
					++count;
				}	
		}
	}
	void exit(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Close();
	}
};
}

