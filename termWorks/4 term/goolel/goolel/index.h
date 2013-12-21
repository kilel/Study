#pragma once
#include "index_list.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace goolel {

	public ref class index : public System::Windows::Forms::Form
	{
	public:
		index(void)
		{
			InitializeComponent();
		}

	protected:
		~index()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::RichTextBox^  rtb;
	public: System::ComponentModel::BackgroundWorker^  w;
			String^s;
	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->rtb = (gcnew System::Windows::Forms::RichTextBox());
			this->w = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// rtb
			// 
			this->rtb->Location = System::Drawing::Point(12, 13);
			this->rtb->Name = L"rtb";
			this->rtb->ReadOnly = true;
			this->rtb->Size = System::Drawing::Size(444, 323);
			this->rtb->TabIndex = 0;
			this->rtb->Text = L"";
			// 
			// w
			// 
			this->w->WorkerReportsProgress = true;
			this->w->WorkerSupportsCancellation = true;
			this->w->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &index::work);
			this->w->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &index::complete);
			this->w->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &index::step_changed);
			// 
			// index
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(468, 348);
			this->Controls->Add(this->rtb);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"index";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"���������� �������";
			this->Shown += gcnew System::EventHandler(this, &index::form_activated);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &index::closing);
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		int count;
		String ^search_value, ^temp;
		cli::array<String^,1> ^search_results;
private:
	void form_activated(System::Object^  sender, System::EventArgs^  e) 
	{
		search_value = ".txt";
		search_results = gcnew array<String^,1>(0);
		count = 0;
		w->RunWorkerAsync();
	}
	void work(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) 
	{
		try{

		///<������ ������ � ��������>
		change_status( L"������� ���������� �������. ��� ����� ������ ��������� �����.\n��������� ������� \"���������� ������� ���������\"\n");
		if(File::Exists("data\\index") || File::Exists("data\\index_list"))
		{
			change_status( L"��������� ����������� ������\n");
			switch(MessageBox::Show("������ ��� ��������. ��������?", "Goolel", MessageBoxButtons::YesNo))
			{
			case Windows::Forms::DialogResult::Yes:
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
				change_status(L"����������� ���������� �������\n");
				break;
			case Windows::Forms::DialogResult::No:
				change_status( L"���������� ���������: ������\n");
				w->CancelAsync();
				return;
			}
		}
		///</������ ������ � ��������>
		///<���������� ������ ��������� ������, � �������� ����� ������� ������>
		if(!File::Exists("data\\settings"))
		{
			change_status("���������� ���� ��������, ��������� ���������");
			return;
		}
		temp = File::ReadAllText("data\\settings");
		if(temp->Length > 2)
		{
			temp = temp->Substring(2);
			if(!Directory::Exists(temp))
			{
				change_status("���������� ���� ��������, ��������� ���������");
				return;
			}
			change_status( s->Concat(L"����� � ", temp, L"\n"));
			search_process(temp);
		}
		else
		{
			for(wchar_t i = 'A'; i <= 'Z'; i++)
			{
				temp = String::Concat(Convert::ToString(i),L":\\");
				if(Directory::Exists(temp))
				{
					change_status( s->Concat(L"����� � ", temp, L"\n"));
					search_process(temp);
				}
			}
		}
		/*for(int i = 0; i < count; i++)					//����� ��������� ������
			change_status( search_results[i]);*/
		File::Create("data\\index")->Close();
		change_status( L"�������� ������ �����...\n");
		try
		{
			File::WriteAllLines("data\\index", search_results); 
			change_status("������ ������ ������\n");
		}
		catch(...)
		{
			change_status("�� ����������� ������� �������� ������\n");
			if(File::Exists("data\\index"))
				File::Delete("data\\index");
			return;
		}
		///</���������� ������ ��������� ������, � �������� ����� ������� ������>
		///<�������� ������ ������>
		change_status( L"���������� ������ ����...\n");
		cli::array<index_list^> ^ word_list = gcnew array<index_list^>(0);
		int count_words = 0;
		String^ tmp;
		bool t = false;
		for(int i = 0; i < count; i++)
		{
			try
			{
				temp = String::Concat(File::ReadAllText(search_results[i]), " ");		//����� � �������� ����� ��� ��������� ��������� ������		
			}
			catch(...)
			{
				continue;
			}
			int j = 0;
			int k = 0;
			do
			{
				t = false;
				while(	(temp[j] == ' ' ||	temp[j] ==  ',' || temp[j] == '.' 
						|| temp[j] == '\n' || temp[j] == '\r' || temp[j] == '\'' 
						|| temp[j] == '\"' || temp[j] == '<' || temp[j] == '>' 
						|| temp[j] == '/' || temp[j] == '\\' || temp[j] == '|' 
						|| temp[j] == ';' || temp[j] == ':' || temp[j] == '(' 
						|| temp[j] == ')' || temp[j] == '{' || temp[j] == '}' 
						|| temp[j] == '[' || temp[j] == ']' || temp[j] == '\t'
						|| temp[j] == '=' || temp[j] == '!' || temp[j] == '?') && j < temp->Length-1) j++;
				if(j == temp->Length-1)
					break;
				k = j;
				while(	!(temp[j] == ' ' ||	temp[j] ==  ',' || temp[j] == '.' 
						|| temp[j] == '\n' || temp[j] == '\r' || temp[j] == '\'' 
						|| temp[j] == '\"' || temp[j] == '<' || temp[j] == '>' 
						|| temp[j] == '/' || temp[j] == '\\' || temp[j] == '|' 
						|| temp[j] == ';' || temp[j] == ':' || temp[j] == '(' 
						|| temp[j] == ')' || temp[j] == '{' || temp[j] == '}' 
						|| temp[j] == '[' || temp[j] == ']' || temp[j] == '\t'
						|| temp[j] == '=' || temp[j] == '!' || temp[j] == '?') && j < temp->Length-1) j++;
				
				tmp = temp->Substring(k, j-k);
				for(k = 0; k < count_words; k++)
				{
					t = t|word_list[k]->check(tmp, i);
					if(t)
					{
						word_list[k]->set(i);
						break;
					}
				}
				if(!t)
				{
					word_list->Resize(word_list, count_words+1);
					word_list[count_words] = gcnew index_list(tmp,count);
					word_list[count_words]->set(i);
					count_words++;
				}
			}while(j < temp->Length);
		}
		//������� ������ ����, ��������� � ����
		tmp = "";
		change_status( L"���������� ������ ����...\n");
		tmp = tmp->Concat(tmp, Convert::ToString(count_words), "\n");
		for(int i = 0; i < count_words; i++)
		{
			tmp = tmp->Concat(tmp, word_list[i]->s, L"\n");
			tmp = tmp->Concat(tmp, Convert::ToString(word_list[i]->count), "\n");
			for(int j = 0; j < count; j++)
				if(word_list[i]->get(j))
					tmp = tmp->Concat(tmp, Convert::ToString(j), "\n");
		}
		File::Create("data\\index_list")->Close();
		File::WriteAllText("data\\index_list", tmp);
		change_status( L"���������� ������� ���������\n");
		///</�������� ������ ������>
		File::SetAttributes("data\\index", File::GetAttributes("data\\index")|FileAttributes::ReadOnly);
		File::SetAttributes("data\\index_list", File::GetAttributes("data\\index_list")|FileAttributes::ReadOnly);
		delete search_results;
		delete word_list;
		}
		catch(...)
		{
			change_status( L"���������� ����������� ������.");
			return;
		}


		w->CancelAsync();
	}
	void change_status(String^g)
	{
		while(String::Compare(s,g))		//��, �� ������ ����������� �� � ������� ����
			s = g;
		while(s->Length > 0)			//� ���������
			w->ReportProgress(0);
	}
	void step_changed(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) 
	{
		while(!rtb->Text->Contains(s))	//� ��� ����. !@#$% ��
			rtb->Text += s;
		s = "";
	}

	void complete(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) 
	{
		;
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
		for(int i = 0; i < src->Length; ++i)		//�������� �������� ����������
		{
			temp = src[i]->Substring(find_last_slash(src[i])+1);
			search_process(temp->Concat(source, "\\", temp));
		}
		for(int i = 0; i < filelist->Length; ++i)		//����� ������
		{
				temp = filelist[i]->Substring(find_last_slash(filelist[i])+1);
				if((temp->ToLower())->Contains(search_value->ToLower()) || (search_value->ToLower())->Contains(temp->ToLower()))
				{
					
					search_results->Resize(search_results, count+1);
					search_results[count] = s->Concat(source,"\\",  temp);
					++count;
				}	
		}
	}
	public:
		int find_last_slash(String^ s) //������� ������ ���������� ������� \ � ������
	{
		for(int i = s->Length -2; i > 0; i--)
			if('\\' == s[i])
				return i;
	}
		
	void closing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	{
		try{w->CancelAsync();}
		catch(...){;}
	}
};
}
