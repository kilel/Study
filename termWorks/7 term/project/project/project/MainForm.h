#pragma once
#include "plotTools.h"
#include "MPToolsAlienor.h"
namespace project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MPTools;
	using namespace plottools;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			plotter = gcnew plotTools(pic->Width, pic->Height, pic->Width/2, pic->Height/2);
			downed = 0;
			update();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  propertiesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel;
	private: System::Windows::Forms::ToolStripMenuItem^  showLogToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  showSettingsToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  LogBox;
	private: System::Windows::Forms::RichTextBox^  Log;
	private: System::Windows::Forms::GroupBox^  CodeBox;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::GroupBox^  SettingsBox;
	private: System::Windows::Forms::Button^  buttonStart;
	private: System::Windows::Forms::PictureBox^  pic;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TrackBar^  SCALE;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  lallalala;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  DPSI;

	private: System::Windows::Forms::NumericUpDown^  DPHI;

	private: System::Windows::Forms::NumericUpDown^  K;
	private: System::Windows::Forms::NumericUpDown^  M;
	private: System::Windows::Forms::NumericUpDown^  EPS;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;


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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->propertiesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showLogToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->LogBox = (gcnew System::Windows::Forms::GroupBox());
			this->Log = (gcnew System::Windows::Forms::RichTextBox());
			this->CodeBox = (gcnew System::Windows::Forms::GroupBox());
			this->pic = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SettingsBox = (gcnew System::Windows::Forms::GroupBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lallalala = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->DPSI = (gcnew System::Windows::Forms::NumericUpDown());
			this->DPHI = (gcnew System::Windows::Forms::NumericUpDown());
			this->K = (gcnew System::Windows::Forms::NumericUpDown());
			this->M = (gcnew System::Windows::Forms::NumericUpDown());
			this->EPS = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SCALE = (gcnew System::Windows::Forms::TrackBar());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->LogBox->SuspendLayout();
			this->CodeBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->BeginInit();
			this->panel1->SuspendLayout();
			this->SettingsBox->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPSI))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPHI))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->K))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->M))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EPS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SCALE))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::Window;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->propertiesToolStripMenuItem, this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(648, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuBar";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->closeToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->closeToolStripMenuItem->Text = L"Close";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::closeToolStripMenuItem_Click);
			// 
			// propertiesToolStripMenuItem
			// 
			this->propertiesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->showLogToolStripMenuItem, 
				this->showSettingsToolStripMenuItem});
			this->propertiesToolStripMenuItem->Name = L"propertiesToolStripMenuItem";
			this->propertiesToolStripMenuItem->Size = System::Drawing::Size(72, 20);
			this->propertiesToolStripMenuItem->Text = L"Properties";
			// 
			// showLogToolStripMenuItem
			// 
			this->showLogToolStripMenuItem->Checked = true;
			this->showLogToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->showLogToolStripMenuItem->Name = L"showLogToolStripMenuItem";
			this->showLogToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->showLogToolStripMenuItem->Tag = L"1";
			this->showLogToolStripMenuItem->Text = L"Show log";
			this->showLogToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::Prop_click);
			// 
			// showSettingsToolStripMenuItem
			// 
			this->showSettingsToolStripMenuItem->Checked = true;
			this->showSettingsToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->showSettingsToolStripMenuItem->Name = L"showSettingsToolStripMenuItem";
			this->showSettingsToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->showSettingsToolStripMenuItem->Tag = L"2";
			this->showSettingsToolStripMenuItem->Text = L"Show settings";
			this->showSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::Prop_click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->helpToolStripMenuItem->Text = L"About";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::helpToolStripMenuItem_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel});
			this->statusStrip1->Location = System::Drawing::Point(0, 357);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(648, 22);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel
			// 
			this->toolStripStatusLabel->Name = L"toolStripStatusLabel";
			this->toolStripStatusLabel->Size = System::Drawing::Size(60, 17);
			this->toolStripStatusLabel->Text = L"Welcome!";
			this->toolStripStatusLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// LogBox
			// 
			this->LogBox->BackColor = System::Drawing::SystemColors::Window;
			this->LogBox->Controls->Add(this->Log);
			this->LogBox->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->LogBox->Location = System::Drawing::Point(0, 233);
			this->LogBox->Name = L"LogBox";
			this->LogBox->Size = System::Drawing::Size(433, 100);
			this->LogBox->TabIndex = 2;
			this->LogBox->TabStop = false;
			this->LogBox->Text = L"Log";
			// 
			// Log
			// 
			this->Log->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Log->Location = System::Drawing::Point(3, 16);
			this->Log->Name = L"Log";
			this->Log->ReadOnly = true;
			this->Log->Size = System::Drawing::Size(427, 81);
			this->Log->TabIndex = 0;
			this->Log->Text = L"";
			// 
			// CodeBox
			// 
			this->CodeBox->BackColor = System::Drawing::SystemColors::Window;
			this->CodeBox->Controls->Add(this->pic);
			this->CodeBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CodeBox->Location = System::Drawing::Point(0, 0);
			this->CodeBox->Name = L"CodeBox";
			this->CodeBox->Size = System::Drawing::Size(433, 233);
			this->CodeBox->TabIndex = 3;
			this->CodeBox->TabStop = false;
			this->CodeBox->Text = L"Output";
			// 
			// pic
			// 
			this->pic->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pic->Location = System::Drawing::Point(3, 16);
			this->pic->Name = L"pic";
			this->pic->Size = System::Drawing::Size(427, 214);
			this->pic->TabIndex = 0;
			this->pic->TabStop = false;
			this->pic->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pic_MouseDown);
			this->pic->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pic_MouseMove);
			this->pic->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pic_MouseUp);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->CodeBox);
			this->panel1->Controls->Add(this->LogBox);
			this->panel1->Controls->Add(this->SettingsBox);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(648, 333);
			this->panel1->TabIndex = 4;
			// 
			// SettingsBox
			// 
			this->SettingsBox->BackColor = System::Drawing::SystemColors::Window;
			this->SettingsBox->Controls->Add(this->panel3);
			this->SettingsBox->Controls->Add(this->panel2);
			this->SettingsBox->Controls->Add(this->label1);
			this->SettingsBox->Controls->Add(this->SCALE);
			this->SettingsBox->Controls->Add(this->buttonStart);
			this->SettingsBox->Dock = System::Windows::Forms::DockStyle::Right;
			this->SettingsBox->Location = System::Drawing::Point(433, 0);
			this->SettingsBox->Name = L"SettingsBox";
			this->SettingsBox->Size = System::Drawing::Size(215, 333);
			this->SettingsBox->TabIndex = 0;
			this->SettingsBox->TabStop = false;
			this->SettingsBox->Text = L"Settings";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->checkBox3);
			this->panel3->Controls->Add(this->checkBox2);
			this->panel3->Controls->Add(this->checkBox1);
			this->panel3->Controls->Add(this->radioButton3);
			this->panel3->Controls->Add(this->radioButton2);
			this->panel3->Controls->Add(this->radioButton1);
			this->panel3->Location = System::Drawing::Point(6, 200);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(200, 86);
			this->panel3->TabIndex = 4;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(97, 60);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(83, 17);
			this->checkBox3->TabIndex = 1;
			this->checkBox3->Text = L"Monte-Karlo";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(97, 37);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(83, 17);
			this->checkBox2->TabIndex = 1;
			this->checkBox2->Text = L"Grid method";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(97, 14);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(96, 17);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->Text = L"Method alienor";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(6, 59);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(72, 17);
			this->radioButton3->TabIndex = 0;
			this->radioButton3->Text = L"Problem 3";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(6, 36);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(72, 17);
			this->radioButton2->TabIndex = 0;
			this->radioButton2->Text = L"Problem 2";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(6, 13);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(72, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Problem 1";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->lallalala);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->DPSI);
			this->panel2->Controls->Add(this->DPHI);
			this->panel2->Controls->Add(this->K);
			this->panel2->Controls->Add(this->M);
			this->panel2->Controls->Add(this->EPS);
			this->panel2->Location = System::Drawing::Point(6, 67);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 127);
			this->panel2->TabIndex = 3;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 106);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"delta psi";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 83);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"delta phi";
			// 
			// lallalala
			// 
			this->lallalala->AutoSize = true;
			this->lallalala->Location = System::Drawing::Point(3, 57);
			this->lallalala->Name = L"lallalala";
			this->lallalala->Size = System::Drawing::Size(14, 13);
			this->lallalala->TabIndex = 1;
			this->lallalala->Text = L"K";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 31);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(16, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"M";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 5);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Accuracy";
			// 
			// DPSI
			// 
			this->DPSI->DecimalPlaces = 5;
			this->DPSI->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->DPSI->Location = System::Drawing::Point(77, 104);
			this->DPSI->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->DPSI->Name = L"DPSI";
			this->DPSI->Size = System::Drawing::Size(120, 20);
			this->DPSI->TabIndex = 0;
			this->DPSI->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {11, 0, 0, 65536});
			// 
			// DPHI
			// 
			this->DPHI->DecimalPlaces = 5;
			this->DPHI->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->DPHI->Location = System::Drawing::Point(77, 81);
			this->DPHI->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->DPHI->Name = L"DPHI";
			this->DPHI->Size = System::Drawing::Size(120, 20);
			this->DPHI->TabIndex = 0;
			this->DPHI->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			// 
			// K
			// 
			this->K->DecimalPlaces = 3;
			this->K->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->K->Location = System::Drawing::Point(77, 55);
			this->K->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000000, 0, 0, 0});
			this->K->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			this->K->Name = L"K";
			this->K->Size = System::Drawing::Size(120, 20);
			this->K->TabIndex = 0;
			this->K->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, 0});
			// 
			// M
			// 
			this->M->Location = System::Drawing::Point(77, 29);
			this->M->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, 0});
			this->M->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->M->Name = L"M";
			this->M->Size = System::Drawing::Size(120, 20);
			this->M->TabIndex = 0;
			this->M->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			// 
			// EPS
			// 
			this->EPS->DecimalPlaces = 5;
			this->EPS->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->EPS->Location = System::Drawing::Point(77, 3);
			this->EPS->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->EPS->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 327680});
			this->EPS->Name = L"EPS";
			this->EPS->Size = System::Drawing::Size(120, 20);
			this->EPS->TabIndex = 0;
			this->EPS->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Scale";
			// 
			// SCALE
			// 
			this->SCALE->Location = System::Drawing::Point(6, 36);
			this->SCALE->Maximum = 10000;
			this->SCALE->Minimum = 1;
			this->SCALE->Name = L"SCALE";
			this->SCALE->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->SCALE->Size = System::Drawing::Size(197, 45);
			this->SCALE->TabIndex = 1;
			this->SCALE->TabStop = false;
			this->SCALE->Value = 1000;
			this->SCALE->Scroll += gcnew System::EventHandler(this, &MainForm::trackBar1_Scroll);
			// 
			// buttonStart
			// 
			this->buttonStart->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonStart->Location = System::Drawing::Point(3, 292);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(209, 38);
			this->buttonStart->TabIndex = 0;
			this->buttonStart->Text = L"Run";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->Click += gcnew System::EventHandler(this, &MainForm::buttonStartClick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(648, 379);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->statusStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(487, 328);
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->Text = L"Alienor Method Solver";
			this->Resize += gcnew System::EventHandler(this, &MainForm::MainForm_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->LogBox->ResumeLayout(false);
			this->CodeBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->EndInit();
			this->panel1->ResumeLayout(false);
			this->SettingsBox->ResumeLayout(false);
			this->SettingsBox->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPSI))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DPHI))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->K))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->M))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EPS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SCALE))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public: 
	plotTools^ plotter;
	int downed;
	Point currPoint, updPoint;
private: 
	void update(){
		plotter->clearCache();
		plotter->draw();
		pic->Image = plotter->getCanvas();
	}
	void fillData(){
		MPTools::DELTA_PHI = Decimal::ToDouble(DPHI->Value);
		MPTools::DELTA_PSI = Decimal::ToDouble(DPSI->Value);
		MPTools::EPS = Decimal::ToDouble(EPS->Value);
		MPTools::M = Decimal::ToDouble(M->Value);
		MPTools::K = Decimal::ToDouble(K->Value);
	}
System::Void MainForm_Resize(System::Object^  sender, System::EventArgs^  e) {
	if( this->Height  > 300){ 
		LogBox->Height = this->Height/4 ;
	}
	plotter->setCanvas(pic->Width, pic->Height);
	update();
}
System::Void buttonStartClick(System::Object^  sender, System::EventArgs^  e) {
	fillData();
	plotter->clearData();
	int numArgs = 2;
	MPsolver^ mps;
	FSet^ problem;
	
	//добавить окошечко, которое просит подождать, пока считаю.
	if(radioButton1->Checked)
		problem = gcnew FSetZizler(numArgs);
	else if(radioButton2->Checked)
		problem = gcnew FSetBIHNKORN(numArgs);
	else{
		numArgs = 6;
		problem = gcnew FSetOsyczkaKundu(numArgs);
	}
	List<MPsolver^>^ al = gcnew List<MPsolver^>();
	List<Pen^>^ pen = gcnew List<Pen^>();
	pen->Add(Pens::Green);pen->Add(Pens::Red);pen->Add(Pens::Blue);
	if(checkBox1->Checked)
		al->Add(gcnew MPsolverAlienor(problem, MPTools::EPS, gcnew WeightVector(2, MPTools::M)));
	if(checkBox2->Checked)
		al->Add(gcnew MPsolverGrid(problem, MPTools::EPS, gcnew WeightVector(2, MPTools::M)));
	if(checkBox3->Checked)
		al->Add(gcnew MPsolverMK(problem, MPTools::EPS, gcnew WeightVector(2, MPTools::M)));
	this->Log->Text = "";
	for(int i = 0; i < al->Count; ++i){
		al[i]->solve(nullptr);
		plotter->addCurve(al[i]->points, pen[i], al[i]->points->Length);
		this->Log->Text += al[i]->getLog();
	}
	
	update();
	
}
System::Void Prop_click(System::Object^  sender, System::EventArgs^  e) {
	dynamic_cast<ToolStripMenuItem^>(sender) -> Checked ^= true;
	
	SettingsBox->Visible = showSettingsToolStripMenuItem->Checked;
	LogBox->Visible = showLogToolStripMenuItem->Checked;
	MainForm_Resize(sender, e);
}

System::Void pic_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	downed = 1;
	currPoint = e->Location;
}
System::Void pic_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	downed = 0;
}
System::Void pic_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	updPoint = e->Location;
	if(downed){
		plotter->setCentre(updPoint.X - currPoint.X ,  updPoint.Y - currPoint.Y);
		currPoint = updPoint;
		update();
	}

}
System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	plotter->setScale(PointF(SCALE->Value/1000., SCALE->Value/1000.));
	update();
}
private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				MessageBox::Show("Построитель решения ЗМНКО\nКислицын илья, 2012", "О программе");
			}
private: System::Void closeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				this->Close();
			}
};//end of namespace
}
