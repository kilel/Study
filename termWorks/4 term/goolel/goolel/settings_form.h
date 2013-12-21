#pragma once
#include <windows.h>
#include "vcclr.h"
#include <tchar.h>
#include <string.h>
#include <psapi.h>
#include <strsafe.h>

#include <iostream>
#include <string>
using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace goolel {

	public ref class settings_form : public System::Windows::Forms::Form
	{
	public:
		settings_form(void)
		{
			String ^sett;
			InitializeComponent();
			try
			{
				if(!Directory::Exists("data"))
					Directory::CreateDirectory("data");
				if(!File::Exists("data\\settings"))
				{
					File::Create("data\\settings")->Close();
					File::WriteAllText("data\\settings", L"10");
				}
				sett = File::ReadAllText("data\\settings");
				use_index->Checked = sett[0]-'0';
				full_s_search->Checked = sett[1]-'0';
				if(sett->Length > 2)
				{
					if(Directory::Exists(sett->Substring(2)))
						where_to_search->Text = sett->Substring(2);
				}
			}
			catch(...)
			{
				this->Close();
			}
		}

	protected:
		~settings_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::CheckBox^  use_index;
		System::Windows::Forms::CheckBox^  full_s_search;
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::TextBox^  where_to_search;
		System::Windows::Forms::Button^  button1;
		System::Windows::Forms::FolderBrowserDialog^  openFD;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->use_index = (gcnew System::Windows::Forms::CheckBox());
			this->full_s_search = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->where_to_search = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFD = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->SuspendLayout();
			// 
			// use_index
			// 
			this->use_index->AutoSize = true;
			this->use_index->Location = System::Drawing::Point(12, 24);
			this->use_index->Name = L"use_index";
			this->use_index->Size = System::Drawing::Size(198, 17);
			this->use_index->TabIndex = 0;
			this->use_index->Text = L"Использовать индекс при поиске";
			this->use_index->UseVisualStyleBackColor = true;
			// 
			// full_s_search
			// 
			this->full_s_search->AutoSize = true;
			this->full_s_search->Location = System::Drawing::Point(12, 47);
			this->full_s_search->Name = L"full_s_search";
			this->full_s_search->Size = System::Drawing::Size(143, 17);
			this->full_s_search->TabIndex = 0;
			this->full_s_search->Text = L"Поиск строки целиком";
			this->full_s_search->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Поиск в..";
			// 
			// where_to_search
			// 
			this->where_to_search->Location = System::Drawing::Point(15, 88);
			this->where_to_search->Name = L"where_to_search";
			this->where_to_search->Size = System::Drawing::Size(122, 20);
			this->where_to_search->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(143, 88);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 20);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Обзор...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &settings_form::view);
			// 
			// settings_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(271, 132);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->where_to_search);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->full_s_search);
			this->Controls->Add(this->use_index);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"settings_form";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Settings";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &settings_form::closing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private:
	int toi(bool c)
	{
		if(c) return 1; return 0;
	}
	void closing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	{
		String^ s;
		char c[3];
		c[0] = toi(use_index->Checked) + '0';
		c[1] = toi(full_s_search->Checked) + '0';
		c[2] = 0;
		s = gcnew String(c);
		if(!Directory::Exists(where_to_search->Text))
			where_to_search->Text = L"";
		File::WriteAllText("data\\settings", String::Concat(s,where_to_search->Text));
	}
	void view(System::Object^  sender, System::EventArgs^  e) 
	{
		if(openFD->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			where_to_search->Text = openFD->SelectedPath;
	}
};
}
