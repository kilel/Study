#pragma once
#include <windows.h>
#include "vcclr.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "tool_window.h"
#include "vcclr.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace lab1 {

	/// <summary>
	/// ������ ��� copy_move
	///
	/// ��������! ��� ��������� ����� ����� ������ ���������� ����� ��������
	///          �������� ����� ����� �������� ("Resource File Name") ��� �������� ���������� ������������ �������,
	///          ���������� �� ����� ������� � ����������� .resx, �� ������� ������� ������ �����. � ��������� ������,
	///          ������������ �� ������ ��������� �������� � ���������������
	///          ���������, ��������������� ������ �����.
	/// </summary>
	public ref class copy_move : public System::Windows::Forms::Form
	{
	public:
		copy_move(String^ sour, String^ dest, cli::array<String^,1> ^ d, cli::array<String^,1> ^f)
		{
			isFile = 0;
			InitializeComponent();
			if(File::Exists(sour))
				isFile = 1;
			content_dir = d;
			content_file = f;
			source = sour;
			destination = dest;
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~copy_move()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Label^  label2;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &copy_move::do_background);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &copy_move::complete);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &copy_move::backgroundWorker1_ProgressChanged);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 45);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(316, 31);
			this->progressBar1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label1";
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->WorkerReportsProgress = true;
			this->backgroundWorker2->WorkerSupportsCancellation = true;
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &copy_move::copy_file);
			this->backgroundWorker2->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &copy_move::backgroundWorker2_RunWorkerCompleted);
			// 
			// timer1
			// 
			this->timer1->Interval = 200;
			this->timer1->Tick += gcnew System::EventHandler(this, &copy_move::timer_tick);
			// 
			// copy_move
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(340, 88);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progressBar1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"copy_move";
			this->Text = L"kilel commander";
			this->Load += gcnew System::EventHandler(this, &copy_move::copy_move_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	int isFile;
	LPCTSTR sou, de;
	String^ source, ^destination, ^tete;
	cli::array<String^,1> ^ content_dir, ^content_file;
	int count, all;
	int stop_rec, copy_index;
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
	int find_last_slash(String^ s) //������� ������ ���������� ������� \ � ������
	{
		for(int i = s->Length -2; i > 0; i--)
			if('\\' == s[i])
				return i;
	}
	void copy_dir(String^ source,		//�������, � ������� ��������� ���������� ������
				  String^ dest,			//���, ���� ������ �����������
				  cli::array<String^>^ src,		//����� ���������, ���. ��������
				  cli::array<String^>^ filelist,	//����� ������, ���. ��������
				  BackgroundWorker^ worker
				  )	

	{

		String^ s, ^temp;
		cli::array<String^>^ dir_dest, ^file_dest;
		for(int i = 0; i < src->Length; ++i)		//�������� �������� ����������
		{
			temp = src[i]->Substring(find_last_slash(src[i])+1);
			Directory::CreateDirectory(dest->Concat(dest, temp, "\\"));
			try
			{
				dir_dest = Directory::GetDirectories(dest->Concat(source, temp, "\\"));
				file_dest = Directory::GetFiles(dest->Concat(source, temp, "\\"));
			}
			catch(System::UnauthorizedAccessException ^)	//��� �������
			{
				MessageBox::Show("��� �������!", "������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				continue;
			}
			copy_dir(dest->Concat(source, temp, "\\"), dest->Concat(dest, temp, "\\"), dir_dest, file_dest, worker);
			if(stop_rec)
				return;
		}
		for(int i = 0; i < filelist->Length; ++i)		//�������� ������
		{
			temp = filelist[i]->Substring(find_last_slash(filelist[i])+1);
			s = dest->Concat(source, temp);		//������ ��� ��������� �����
			temp = dest->Concat(dest, temp);	//����. ��� ����������
			try
			{
				FileInfo^ k = gcnew FileInfo(s);
				count += k->Length;
				tete = s;
				worker->ReportProgress((int)((double)100*count/all));
			}
			catch(...)
			{
				;
			}
			if(!s->Compare(s,temp))
			{
				MessageBox::Show("�������� ����������", "error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			if(File::Exists(temp))		//���� ���������� ���
			{
				if(!copy_index)		//���� �� ����� ������ �� ��� ������ ���, ��
				{
					tool_window^ tt = gcnew tool_window(s,temp);	//����������
					tt->ShowDialog();
					switch(tt->answer)		//� ������
					{
					case 1: 
						//File::Copy(s,temp,1);
						CopyFile(tolpc(s), tolpc(temp), false);
						break;
					case -1:
						break;
					case 0: 
						stop_rec = 1;		//������ �����������		
						return;
					case 10: 
						copy_index = 1;
						break;
					case -10: 
						copy_index = -1;
						break;
					}
					delete tt;
				}
				else
					if(copy_index == 1)
						CopyFile(tolpc(s), tolpc(temp), false);//File::Copy(s, temp, 1);
			}
			File::Copy(s,temp, 1);
		}
	}
	void getSizeDir(String^ source,		//�������, � ������� ��������� ���������� ������
				  cli::array<String^>^ src,		
				  cli::array<String^>^ filelist	
				  )

	{
		String^ s, ^temp;
		cli::array<String^>^ dir_dest, ^file_dest;
		for(int i = 0; i < src->Length; ++i)		//�������� �������� ����������
		{
			temp = src[i]->Substring(find_last_slash(src[i])+1);
			try
			{
				dir_dest = Directory::GetDirectories(s->Concat(source, temp, "\\"));
				file_dest = Directory::GetFiles(s->Concat(source, temp, "\\"));
			}
			catch(...)	//��� �������
			{
				continue;
			}
			getSizeDir(s->Concat(source, temp, "\\"), dir_dest, file_dest);
		}
		for(int i = 0; i < filelist->Length; ++i)		//�������� ������
		{
			try
			{
				temp = filelist[i]->Substring(find_last_slash(filelist[i])+1);
				s = s->Concat(source, temp);		//������ ��� ��������� �����
				FileInfo^ k = gcnew FileInfo(s);
				all += k->Length;
			}
			catch(...)
			{
				;
			}
		}
	}
	System::Void copy_move_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		count = 0;
		stop_rec = 0;
		copy_index = 0;
		all = 0;
		if(isFile)
		{
			backgroundWorker2->RunWorkerAsync();
			timer1->Start();
		}
		else
		{
			getSizeDir(source, content_dir, content_file);
			backgroundWorker1->RunWorkerAsync();
		}

	}
	
	System::Void do_background(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
	{
		BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);
		copy_dir(source, destination, content_dir, content_file, worker);
	 }
	System::Void complete(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) 
	{
		Close();
	}
	System::Void backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) 
	{
		label1->Text = String::Concat("����: ", tete);
		label2->Text = String::Concat("��������: ", count, " �� ", all, " ����");
		progressBar1->Value = e->ProgressPercentage;
	}
	System::Void copy_file(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) 
	{
		if(File::Exists(destination))	//���� ����� �� ���� ���
		{
			switch (MessageBox::Show("� �������� �������� ���������� ���� � ����� ������. ������������?", "kilel commander", MessageBoxButtons::YesNoCancel, MessageBoxIcon::None))
			{			//������
			case Windows::Forms::DialogResult::Yes:			//������������
				{
					CopyFile(tolpc(source), tolpc(destination), false);//File::Copy(source, destination,1);
				}
			case Windows::Forms::DialogResult::Cancel:		//��������
				{
					return;
				}
			}
		}
		else
			CopyFile(tolpc(source), tolpc(destination), false);//File::Copy(source, destination, 1);	//����/��� �����
	}
	System::Void timer_tick(System::Object^  sender, System::EventArgs^  e) 
	{
		try
		{
			FileInfo^ s, ^d;
			s = gcnew FileInfo(source);
			//d = gcnew FileInfo(destination);
			progressBar1->Visible = false;
			label1->Text = source;
			label2->Text = String::Concat("�������� �����, ������:", Convert::ToString(s->Length), " ����");
		}
		catch(...)
		{
			;
		}
	}
	System::Void backgroundWorker2_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) 
	{
		this->Close();
	}
};
}
