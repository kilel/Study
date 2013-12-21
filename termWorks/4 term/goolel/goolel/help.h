#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace goolel {

	/// <summary>
	/// ������ ��� help
	///
	/// ��������! ��� ��������� ����� ����� ������ ���������� ����� ��������
	///          �������� ����� ����� �������� ("Resource File Name") ��� �������� ���������� ������������ �������,
	///          ���������� �� ����� ������� � ����������� .resx, �� ������� ������� ������ �����. � ��������� ������,
	///          ������������ �� ������ ��������� �������� � ���������������
	///          ���������, ��������������� ������ �����.
	/// </summary>
	public ref class help : public System::Windows::Forms::Form
	{
	public:
		help(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~help()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  help_box;
	protected: 

	protected: 

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->help_box = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// help_box
			// 
			this->help_box->Dock = System::Windows::Forms::DockStyle::Fill;
			this->help_box->Location = System::Drawing::Point(0, 0);
			this->help_box->Name = L"help_box";
			this->help_box->ReadOnly = true;
			this->help_box->Size = System::Drawing::Size(620, 402);
			this->help_box->TabIndex = 0;
			this->help_box->Text = L"";
			// 
			// help
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(620, 402);
			this->Controls->Add(this->help_box);
			this->Name = L"help";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Goolel Help";
			this->Load += gcnew System::EventHandler(this, &help::load_do);
			this->ResumeLayout(false);

		}
#pragma endregion
private: 
	void load_do(System::Object^  sender, System::EventArgs^  e) 
	{
		help_box->Text = L"����������� �� ����������� ���������� Goolel.\
			\n�����:\
			\n1)������ ������ � ���������\
			\n2)���������� �������\
			\n3)�����\
			\n4)���������������\
			\n\
			\n���� 1. ������ ������ � ���������.\
			\n\t���� ��� ������ ������� � ��� �� ������������ ���� ��������, ������������� ������� ����� \"����\\������� ��� ��������� �����\", � ����� ����� � ���� ��������. ������ �������� ��������� �������� ������ ����� �������� � ������ ������ ��������� � ������. ����������� ������ ��������� ��� ������������� ������������� ����� �������� ��� ������� ��� ������.\
			\n\t� ���� �������� ���� 2 ��������� � ���� ������ ����� ������.\
			\n-��� ��������� ������ \"������������ ������ ��� ������\", ����� ����� �������������� � �������������� �������, �����, ���.\
			\n-��� ��������� ������ \"����� ������ �������\", ��������� ������ ����� ��������� ��� ������ ������, ����� �� ����� ��������� � �������� �� ����� ��� ������.\
			\n-� ������ ����� ������� �������, � ������� ����� ������������� �����. �������� ������ ��� ������, ���� ������� ������ ����� �� ����� ����������.\
			\n\
			\n���� 2. ���������� �������.\
			\n\t� ������ ���� \"������\" �� ������ ���������, �������� ��� ������� ������.\
			\n\
			\n���� 3. �����\
			\n\t������� ��������� ������ � ������ ������ � ������� ������ \"�����\". � ������ ����������� ����������� ��������� �����. ������ ������ �� ������ �� ����������� � ����������� ����������� ���� �� ������ ������� ��������� ���� ��� �������, ��� ����������.\
			\n\
			\n���� 4.���������������\
			\n\
			\n1)�� ��������� ����� � �������� \"data\", ������� ��������� � �������� ������������ �����\
			\n2)���� �� ��-��� ������� ���������, �� ������ �� ��������, ����������� � ������ ��������� ��� ����������� ���������� ��������� ���������\
			\n3)��������� ����� ������ ���� ��������� � ��������� Unicode\
			\n4)���� � ������ ������ ����";	
	}
};
}
