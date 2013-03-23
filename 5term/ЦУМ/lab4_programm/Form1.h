#pragma once


namespace mult {

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
			X = gcnew array<int>(33);
			Y = gcnew array<int>(32);
			Z = gcnew array<int>(64);
			SMa = gcnew array<int>(64);
			SMb = gcnew array<int>(64);
			SMs = gcnew array<int>(64);
			y = gcnew array<int>(12);
			x = gcnew array<int>(7);
			p = gcnew array<int>(4);
			CT = gcnew array<int>(5);
			a = gcnew array<int>(8);
			R = gcnew array<int>(4);
			S = gcnew array<int>(4);
			Q = gcnew array<int>(4);
			CRP = 0;
			CR = 0;
			for(int i = 0; i < 32; i++)
			{
				X[i] = 0;
				Y[i] = 0;
			}
			nullify();
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

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label30;

	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::PictureBox^  pic;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label45;
	private: System::Windows::Forms::Label^  label44;
	private: System::Windows::Forms::Label^  label43;
	private: System::Windows::Forms::Label^  label42;
	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::Label^  label40;
	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::Label^  label56;
private: System::Windows::Forms::Label^  label55;
private: System::Windows::Forms::Label^  label54;
private: System::Windows::Forms::Label^  label53;
private: System::Windows::Forms::Label^  label52;
private: System::Windows::Forms::Label^  label51;
private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::Label^  label49;
private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::Label^  label59;
private: System::Windows::Forms::Label^  label58;
private: System::Windows::Forms::Label^  label57;
private: System::Windows::Forms::Label^  label65;
private: System::Windows::Forms::Label^  label64;
private: System::Windows::Forms::Label^  label63;
private: System::Windows::Forms::Label^  label62;
private: System::Windows::Forms::Label^  label61;
private: System::Windows::Forms::Label^  label60;
private: System::Windows::Forms::Label^  label66;
private: System::Windows::Forms::Label^  label67;
private: System::Windows::Forms::Label^  label68;
private: System::Windows::Forms::Label^  label72;
private: System::Windows::Forms::Label^  label71;
private: System::Windows::Forms::Label^  label70;
private: System::Windows::Forms::Label^  label69;
private: System::Windows::Forms::Label^  label73;
private: System::Windows::Forms::Label^  label81;
private: System::Windows::Forms::Label^  label80;
private: System::Windows::Forms::Label^  label79;
private: System::Windows::Forms::Label^  label78;
private: System::Windows::Forms::Label^  label77;
private: System::Windows::Forms::Label^  label76;
private: System::Windows::Forms::Label^  label75;
private: System::Windows::Forms::Label^  label74;
private: System::Windows::Forms::Label^  label84;
private: System::Windows::Forms::Label^  label83;
private: System::Windows::Forms::Label^  label82;
private: System::Windows::Forms::Label^  label87;
private: System::Windows::Forms::Label^  label86;
private: System::Windows::Forms::Label^  label90;
private: System::Windows::Forms::Label^  label89;
private: System::Windows::Forms::Label^  label88;
private: System::Windows::Forms::Label^  label85;
	private: System::ComponentModel::IContainer^  components;
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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label72 = (gcnew System::Windows::Forms::Label());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->label73 = (gcnew System::Windows::Forms::Label());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->pic = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->label81 = (gcnew System::Windows::Forms::Label());
			this->label80 = (gcnew System::Windows::Forms::Label());
			this->label79 = (gcnew System::Windows::Forms::Label());
			this->label78 = (gcnew System::Windows::Forms::Label());
			this->label77 = (gcnew System::Windows::Forms::Label());
			this->label76 = (gcnew System::Windows::Forms::Label());
			this->label75 = (gcnew System::Windows::Forms::Label());
			this->label84 = (gcnew System::Windows::Forms::Label());
			this->label83 = (gcnew System::Windows::Forms::Label());
			this->label87 = (gcnew System::Windows::Forms::Label());
			this->label86 = (gcnew System::Windows::Forms::Label());
			this->label90 = (gcnew System::Windows::Forms::Label());
			this->label89 = (gcnew System::Windows::Forms::Label());
			this->label88 = (gcnew System::Windows::Forms::Label());
			this->label85 = (gcnew System::Windows::Forms::Label());
			this->label82 = (gcnew System::Windows::Forms::Label());
			this->label74 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->BeginInit();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"RG1";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox1->Controls->Add(this->label17);
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->label16);
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->label29);
			this->groupBox1->Controls->Add(this->label27);
			this->groupBox1->Controls->Add(this->label26);
			this->groupBox1->Controls->Add(this->label20);
			this->groupBox1->Controls->Add(this->label25);
			this->groupBox1->Controls->Add(this->label19);
			this->groupBox1->Controls->Add(this->label24);
			this->groupBox1->Controls->Add(this->label18);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->label23);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label22);
			this->groupBox1->Controls->Add(this->label28);
			this->groupBox1->Controls->Add(this->label30);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->label21);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(716, 96);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(440, 203);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Данные";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(334, 176);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(20, 13);
			this->label17->TabIndex = 1;
			this->label17->Text = L"X6";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(131, 176);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(20, 13);
			this->label14->TabIndex = 1;
			this->label14->Text = L"X3";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(273, 176);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(20, 13);
			this->label16->TabIndex = 1;
			this->label16->Text = L"X5";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(62, 176);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(20, 13);
			this->label13->TabIndex = 1;
			this->label13->Text = L"X2";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(203, 176);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(20, 13);
			this->label15->TabIndex = 1;
			this->label15->Text = L"X4";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(227, 155);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(24, 13);
			this->label29->TabIndex = 1;
			this->label29->Text = L"y11";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(178, 155);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(24, 13);
			this->label27->TabIndex = 1;
			this->label27->Text = L"y10";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(135, 155);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(18, 13);
			this->label26->TabIndex = 1;
			this->label26->Text = L"y9";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(91, 142);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(18, 13);
			this->label20->TabIndex = 1;
			this->label20->Text = L"y3";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(90, 155);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(18, 13);
			this->label25->TabIndex = 1;
			this->label25->Text = L"y8";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(41, 142);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(18, 13);
			this->label19->TabIndex = 1;
			this->label19->Text = L"y2";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(41, 155);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(18, 13);
			this->label24->TabIndex = 1;
			this->label24->Text = L"y7";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(2, 142);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(18, 13);
			this->label18->TabIndex = 1;
			this->label18->Text = L"y1";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(2, 176);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(20, 13);
			this->label12->TabIndex = 1;
			this->label12->Text = L"X1";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(2, 155);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(18, 13);
			this->label23->TabIndex = 1;
			this->label23->Text = L"y6";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(2, 107);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(61, 13);
			this->label11->TabIndex = 1;
			this->label11->Text = L"Состояние";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(178, 142);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(18, 13);
			this->label22->TabIndex = 1;
			this->label22->Text = L"y5";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(227, 107);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(22, 13);
			this->label28->TabIndex = 1;
			this->label28->Text = L"CR";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(90, 120);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(19, 13);
			this->label30->TabIndex = 1;
			this->label30->Text = L"p3";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(135, 107);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(29, 13);
			this->label10->TabIndex = 1;
			this->label10->Text = L"CRP";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(135, 142);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(18, 13);
			this->label21->TabIndex = 1;
			this->label21->Text = L"y4";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(42, 120);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(19, 13);
			this->label9->TabIndex = 1;
			this->label9->Text = L"p2";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(1, 120);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(19, 13);
			this->label8->TabIndex = 1;
			this->label8->Text = L"p1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(2, 94);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(28, 13);
			this->label7->TabIndex = 1;
			this->label7->Text = L"SMs";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(2, 55);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(21, 13);
			this->label4->TabIndex = 1;
			this->label4->Text = L"CT";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(2, 81);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(29, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"SMb";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1, 42);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"RG3";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(2, 68);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"SMa";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"RG2";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(720, 300);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(226, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Автомат";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Control;
			this->textBox1->Location = System::Drawing::Point(781, 43);
			this->textBox1->MaxLength = 31;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(137, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"0";
			this->textBox1->Leave += gcnew System::EventHandler(this, &Form1::textBox2_Leave);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox2->Location = System::Drawing::Point(781, 66);
			this->textBox2->MaxLength = 31;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(137, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"0";
			this->textBox2->Leave += gcnew System::EventHandler(this, &Form1::textBox2_Leave);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(1053, 300);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(103, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"ОА";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(713, 50);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(49, 13);
			this->label32->TabIndex = 4;
			this->label32->Text = L"Число X";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(713, 69);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(49, 13);
			this->label33->TabIndex = 4;
			this->label33->Text = L"Число Y";
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(721, 329);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(225, 30);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Остановить автоматический режим";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(948, 329);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(208, 30);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Остановить всё";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(1069, 365);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(87, 23);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Подать X";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(1069, 394);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(87, 23);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Подать Y";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(1069, 423);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(87, 23);
			this->button7->TabIndex = 10;
			this->button7->Text = L"Считать Z";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(948, 300);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(106, 23);
			this->button8->TabIndex = 4;
			this->button8->Text = L"УА";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(1093, 452);
			this->trackBar1->Maximum = 1000;
			this->trackBar1->Minimum = 10;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar1->Size = System::Drawing::Size(45, 238);
			this->trackBar1->TabIndex = 11;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar1->Value = 500;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(924, 46);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(68, 13);
			this->label34->TabIndex = 4;
			this->label34->Text = L"Ответ точно";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(924, 69);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(101, 13);
			this->label35->TabIndex = 4;
			this->label35->Text = L"Ответ по решению";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1168, 726);
			this->tabControl1->TabIndex = 12;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label72);
			this->tabPage2->Controls->Add(this->label71);
			this->tabPage2->Controls->Add(this->label70);
			this->tabPage2->Controls->Add(this->label73);
			this->tabPage2->Controls->Add(this->label69);
			this->tabPage2->Controls->Add(this->label68);
			this->tabPage2->Controls->Add(this->label45);
			this->tabPage2->Controls->Add(this->label44);
			this->tabPage2->Controls->Add(this->label43);
			this->tabPage2->Controls->Add(this->label42);
			this->tabPage2->Controls->Add(this->label41);
			this->tabPage2->Controls->Add(this->label40);
			this->tabPage2->Controls->Add(this->label39);
			this->tabPage2->Controls->Add(this->label38);
			this->tabPage2->Controls->Add(this->label37);
			this->tabPage2->Controls->Add(this->label36);
			this->tabPage2->Controls->Add(this->label59);
			this->tabPage2->Controls->Add(this->label58);
			this->tabPage2->Controls->Add(this->label57);
			this->tabPage2->Controls->Add(this->label66);
			this->tabPage2->Controls->Add(this->label67);
			this->tabPage2->Controls->Add(this->label31);
			this->tabPage2->Controls->Add(this->pic);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1160, 700);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"ОА";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label72
			// 
			this->label72->AutoSize = true;
			this->label72->Location = System::Drawing::Point(428, 401);
			this->label72->Name = L"label72";
			this->label72->Size = System::Drawing::Size(18, 13);
			this->label72->TabIndex = 6;
			this->label72->Text = L"y1";
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->Location = System::Drawing::Point(484, 406);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(18, 13);
			this->label71->TabIndex = 6;
			this->label71->Text = L"y1";
			// 
			// label70
			// 
			this->label70->AutoSize = true;
			this->label70->Location = System::Drawing::Point(532, 340);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(18, 13);
			this->label70->TabIndex = 6;
			this->label70->Text = L"y1";
			// 
			// label73
			// 
			this->label73->AutoSize = true;
			this->label73->Location = System::Drawing::Point(24, 324);
			this->label73->Name = L"label73";
			this->label73->Size = System::Drawing::Size(18, 13);
			this->label73->TabIndex = 6;
			this->label73->Text = L"y1";
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->Location = System::Drawing::Point(310, 297);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(18, 13);
			this->label69->TabIndex = 6;
			this->label69->Text = L"y1";
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->Location = System::Drawing::Point(310, 518);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(18, 13);
			this->label68->TabIndex = 6;
			this->label68->Text = L"y1";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(174, 316);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(18, 13);
			this->label45->TabIndex = 5;
			this->label45->Text = L"y1";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(174, 283);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(18, 13);
			this->label44->TabIndex = 5;
			this->label44->Text = L"y1";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(621, 600);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(18, 13);
			this->label43->TabIndex = 5;
			this->label43->Text = L"y1";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(667, 509);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(18, 13);
			this->label42->TabIndex = 5;
			this->label42->Text = L"y1";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(667, 481);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(18, 13);
			this->label41->TabIndex = 5;
			this->label41->Text = L"y1";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(667, 451);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(18, 13);
			this->label40->TabIndex = 5;
			this->label40->Text = L"y1";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(390, 316);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(18, 13);
			this->label39->TabIndex = 5;
			this->label39->Text = L"y1";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(610, 229);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(18, 13);
			this->label38->TabIndex = 5;
			this->label38->Text = L"y1";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(631, 116);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(18, 13);
			this->label37->TabIndex = 5;
			this->label37->Text = L"y1";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(350, 129);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(18, 13);
			this->label36->TabIndex = 5;
			this->label36->Text = L"y1";
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->Location = System::Drawing::Point(57, 490);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(18, 13);
			this->label59->TabIndex = 5;
			this->label59->Text = L"y1";
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Location = System::Drawing::Point(234, 194);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(18, 13);
			this->label58->TabIndex = 5;
			this->label58->Text = L"y1";
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Location = System::Drawing::Point(219, 194);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(18, 13);
			this->label57->TabIndex = 5;
			this->label57->Text = L"y1";
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->Location = System::Drawing::Point(428, 127);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(18, 13);
			this->label66->TabIndex = 5;
			this->label66->Text = L"y1";
			// 
			// label67
			// 
			this->label67->AutoSize = true;
			this->label67->Location = System::Drawing::Point(125, 125);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(18, 13);
			this->label67->TabIndex = 5;
			this->label67->Text = L"y1";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(350, 103);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(18, 13);
			this->label31->TabIndex = 5;
			this->label31->Text = L"y1";
			// 
			// pic
			// 
			this->pic->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pic->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pic.Image")));
			this->pic->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pic.InitialImage")));
			this->pic->Location = System::Drawing::Point(3, 3);
			this->pic->Name = L"pic";
			this->pic->Size = System::Drawing::Size(1154, 694);
			this->pic->TabIndex = 0;
			this->pic->TabStop = false;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label56);
			this->tabPage1->Controls->Add(this->label55);
			this->tabPage1->Controls->Add(this->label54);
			this->tabPage1->Controls->Add(this->label53);
			this->tabPage1->Controls->Add(this->label52);
			this->tabPage1->Controls->Add(this->label51);
			this->tabPage1->Controls->Add(this->label50);
			this->tabPage1->Controls->Add(this->label49);
			this->tabPage1->Controls->Add(this->label48);
			this->tabPage1->Controls->Add(this->label47);
			this->tabPage1->Controls->Add(this->label65);
			this->tabPage1->Controls->Add(this->label64);
			this->tabPage1->Controls->Add(this->label63);
			this->tabPage1->Controls->Add(this->label62);
			this->tabPage1->Controls->Add(this->label61);
			this->tabPage1->Controls->Add(this->label60);
			this->tabPage1->Controls->Add(this->label81);
			this->tabPage1->Controls->Add(this->label80);
			this->tabPage1->Controls->Add(this->label79);
			this->tabPage1->Controls->Add(this->label78);
			this->tabPage1->Controls->Add(this->label77);
			this->tabPage1->Controls->Add(this->label76);
			this->tabPage1->Controls->Add(this->label75);
			this->tabPage1->Controls->Add(this->label84);
			this->tabPage1->Controls->Add(this->label83);
			this->tabPage1->Controls->Add(this->label87);
			this->tabPage1->Controls->Add(this->label86);
			this->tabPage1->Controls->Add(this->label90);
			this->tabPage1->Controls->Add(this->label89);
			this->tabPage1->Controls->Add(this->label88);
			this->tabPage1->Controls->Add(this->label85);
			this->tabPage1->Controls->Add(this->label82);
			this->tabPage1->Controls->Add(this->label74);
			this->tabPage1->Controls->Add(this->label46);
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1160, 700);
			this->tabPage1->TabIndex = 2;
			this->tabPage1->Text = L"УА";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Location = System::Drawing::Point(740, 598);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(18, 13);
			this->label56->TabIndex = 6;
			this->label56->Text = L"y1";
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Location = System::Drawing::Point(740, 576);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(18, 13);
			this->label55->TabIndex = 6;
			this->label55->Text = L"y1";
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Location = System::Drawing::Point(725, 554);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(18, 13);
			this->label54->TabIndex = 6;
			this->label54->Text = L"y1";
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Location = System::Drawing::Point(725, 536);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(18, 13);
			this->label53->TabIndex = 6;
			this->label53->Text = L"y1";
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(725, 517);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(18, 13);
			this->label52->TabIndex = 6;
			this->label52->Text = L"y1";
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(725, 497);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(18, 13);
			this->label51->TabIndex = 6;
			this->label51->Text = L"y1";
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(725, 477);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(18, 13);
			this->label50->TabIndex = 6;
			this->label50->Text = L"y1";
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(725, 456);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(18, 13);
			this->label49->TabIndex = 6;
			this->label49->Text = L"y1";
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(725, 438);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(18, 13);
			this->label48->TabIndex = 6;
			this->label48->Text = L"y1";
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(725, 417);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(18, 13);
			this->label47->TabIndex = 6;
			this->label47->Text = L"y1";
			// 
			// label65
			// 
			this->label65->AutoSize = true;
			this->label65->Location = System::Drawing::Point(22, 311);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(18, 13);
			this->label65->TabIndex = 6;
			this->label65->Text = L"y1";
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->Location = System::Drawing::Point(22, 278);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(18, 13);
			this->label64->TabIndex = 6;
			this->label64->Text = L"y1";
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Location = System::Drawing::Point(22, 247);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(18, 13);
			this->label63->TabIndex = 6;
			this->label63->Text = L"y1";
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(22, 215);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(18, 13);
			this->label62->TabIndex = 6;
			this->label62->Text = L"y1";
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(22, 181);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(18, 13);
			this->label61->TabIndex = 6;
			this->label61->Text = L"y1";
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Location = System::Drawing::Point(22, 142);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(18, 13);
			this->label60->TabIndex = 6;
			this->label60->Text = L"y1";
			// 
			// label81
			// 
			this->label81->AutoSize = true;
			this->label81->Location = System::Drawing::Point(651, 290);
			this->label81->Name = L"label81";
			this->label81->Size = System::Drawing::Size(13, 13);
			this->label81->TabIndex = 6;
			this->label81->Text = L"0";
			// 
			// label80
			// 
			this->label80->AutoSize = true;
			this->label80->Location = System::Drawing::Point(651, 257);
			this->label80->Name = L"label80";
			this->label80->Size = System::Drawing::Size(13, 13);
			this->label80->TabIndex = 6;
			this->label80->Text = L"0";
			// 
			// label79
			// 
			this->label79->AutoSize = true;
			this->label79->Location = System::Drawing::Point(651, 235);
			this->label79->Name = L"label79";
			this->label79->Size = System::Drawing::Size(13, 13);
			this->label79->TabIndex = 6;
			this->label79->Text = L"0";
			// 
			// label78
			// 
			this->label78->AutoSize = true;
			this->label78->Location = System::Drawing::Point(651, 200);
			this->label78->Name = L"label78";
			this->label78->Size = System::Drawing::Size(18, 13);
			this->label78->TabIndex = 6;
			this->label78->Text = L"y1";
			// 
			// label77
			// 
			this->label77->AutoSize = true;
			this->label77->Location = System::Drawing::Point(651, 158);
			this->label77->Name = L"label77";
			this->label77->Size = System::Drawing::Size(18, 13);
			this->label77->TabIndex = 6;
			this->label77->Text = L"y1";
			// 
			// label76
			// 
			this->label76->AutoSize = true;
			this->label76->Location = System::Drawing::Point(651, 129);
			this->label76->Name = L"label76";
			this->label76->Size = System::Drawing::Size(18, 13);
			this->label76->TabIndex = 6;
			this->label76->Text = L"y1";
			// 
			// label75
			// 
			this->label75->AutoSize = true;
			this->label75->Location = System::Drawing::Point(651, 103);
			this->label75->Name = L"label75";
			this->label75->Size = System::Drawing::Size(18, 13);
			this->label75->TabIndex = 6;
			this->label75->Text = L"y1";
			// 
			// label84
			// 
			this->label84->AutoSize = true;
			this->label84->Location = System::Drawing::Point(512, 235);
			this->label84->Name = L"label84";
			this->label84->Size = System::Drawing::Size(18, 13);
			this->label84->TabIndex = 6;
			this->label84->Text = L"y1";
			// 
			// label83
			// 
			this->label83->AutoSize = true;
			this->label83->Location = System::Drawing::Point(512, 142);
			this->label83->Name = L"label83";
			this->label83->Size = System::Drawing::Size(18, 13);
			this->label83->TabIndex = 6;
			this->label83->Text = L"y1";
			// 
			// label87
			// 
			this->label87->AutoSize = true;
			this->label87->Location = System::Drawing::Point(437, 218);
			this->label87->Name = L"label87";
			this->label87->Size = System::Drawing::Size(18, 13);
			this->label87->TabIndex = 6;
			this->label87->Text = L"y1";
			// 
			// label86
			// 
			this->label86->AutoSize = true;
			this->label86->Location = System::Drawing::Point(437, 125);
			this->label86->Name = L"label86";
			this->label86->Size = System::Drawing::Size(18, 13);
			this->label86->TabIndex = 6;
			this->label86->Text = L"y1";
			// 
			// label90
			// 
			this->label90->AutoSize = true;
			this->label90->Location = System::Drawing::Point(437, 250);
			this->label90->Name = L"label90";
			this->label90->Size = System::Drawing::Size(18, 13);
			this->label90->TabIndex = 6;
			this->label90->Text = L"y1";
			// 
			// label89
			// 
			this->label89->AutoSize = true;
			this->label89->Location = System::Drawing::Point(437, 155);
			this->label89->Name = L"label89";
			this->label89->Size = System::Drawing::Size(18, 13);
			this->label89->TabIndex = 6;
			this->label89->Text = L"y1";
			// 
			// label88
			// 
			this->label88->AutoSize = true;
			this->label88->Location = System::Drawing::Point(437, 60);
			this->label88->Name = L"label88";
			this->label88->Size = System::Drawing::Size(18, 13);
			this->label88->TabIndex = 6;
			this->label88->Text = L"y1";
			// 
			// label85
			// 
			this->label85->AutoSize = true;
			this->label85->Location = System::Drawing::Point(437, 28);
			this->label85->Name = L"label85";
			this->label85->Size = System::Drawing::Size(18, 13);
			this->label85->TabIndex = 6;
			this->label85->Text = L"y1";
			// 
			// label82
			// 
			this->label82->AutoSize = true;
			this->label82->Location = System::Drawing::Point(512, 51);
			this->label82->Name = L"label82";
			this->label82->Size = System::Drawing::Size(18, 13);
			this->label82->TabIndex = 6;
			this->label82->Text = L"y1";
			// 
			// label74
			// 
			this->label74->AutoSize = true;
			this->label74->Location = System::Drawing::Point(651, 74);
			this->label74->Name = L"label74";
			this->label74->Size = System::Drawing::Size(18, 13);
			this->label74->TabIndex = 6;
			this->label74->Text = L"y1";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(725, 395);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(18, 13);
			this->label46->TabIndex = 6;
			this->label46->Text = L"y1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1154, 694);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->pictureBox2);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1160, 700);
			this->tabPage3->TabIndex = 3;
			this->tabPage3->Text = L"ГСА";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.InitialImage")));
			this->pictureBox2->Location = System::Drawing::Point(3, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(1154, 694);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1168, 726);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->label35);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"pff-form";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
	array<int>^X, ^Y, ^Z, ^p, ^y, ^x, ^SMa, ^SMb, ^SMs, ^CT, ^a, ^R, ^S, ^Q;
	int CRP, CR, state, CR_to, r ;
	bool first;
	void nullify()
	{
		first = true;
		X[32] = 0;
		r = 0;
		for(int i = 0; i < 64; i++)
		{
			if(i < 32)
			{
				X[i] = 0;
				Y[i] = 0;
			}
			Z[i] = 0;
			SMa[i]  = 0;
			SMb[i] = 0;
			SMs[i] = 0;
		}
		for(int i = 0; i < 12; i++)
			y[i] = 0;
		x[3] = x[4] = x[5] = 0;
		for(int i = 0; i < 4; i++)
		{
			p[i] = 0;
			R[i] = 1;
			S[i] = 0;
		}
		for(int i = 0; i < 5; i++)
			CT[i] = 0;
		for(int i = 0; i < 8; i++)
			a[i] = 0;
		a[0] = 1;
		state = 0;
	}
	void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		output();
	}
	
	void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		int c = e->KeyChar;
		if(c=='-' && textBox1->Focused && textBox1->Text->Length == 0)
			return;
		if(c=='-' && textBox2->Focused && textBox2->Text->Length == 0)
			return;
		if((c < (int)'0' || c > (int) '9') && !(c==8))
			e->KeyChar = 0; 
	}
	void translate(array<int>^X, int n)
	{
		if(n >= 0)
		{
			X[0] = 0;
			for(int i = 31; i >0; i--)
			{
				X[i] = n%2;
				n/=2;
			}
		}
		else
		{
			X[0] = 1;
			n = -n;
			bool k = true;
			for(int i = 31; i >0; i--)
			{
				if(k)
					if(n%2 == 0)
					{
						X[i] = 0;
						n = n/2;
						continue;
					}
					else
					{
						k = false;
						X[i] = 1;
						n = n/2;
						continue;
					}
				
				
				X[i] = (n+1)%2;
				n/=2;
			}
		}
	}
	void write(array<int>^X, Label^ s, String^p, int n)
	{
		s->Text = p+X[0] +",";
		for(int i = 1; i < n; i++)
			s->Text += X[i];

	}
	int sum(array<int>^X,array<int>^Y,array<int>^Z, int n, int p)
	{
		if(p)
			plus_one(X,32);
		p = 0;
		for(int i = n-1; i >= 0; i--)
		{
			Z[i] = X[i] + Y[i] + p;
			p = 0;
			if( Z[i] > 1)
			{
				p = 1;
				Z[i] = Z[i]%2;
			}
		
		}
		return p;
	}
	void textBox2_Leave(System::Object^  sender, System::EventArgs^  e) 
	{
		if(textBox1->Text->Length == 0 || (textBox1->Text->Length == 1 && textBox1->Text[0] == '-')) 
			textBox1->Text = "0";
		if(textBox2->Text->Length == 0 || (textBox2->Text->Length == 1 && textBox2->Text[0] == '-')) 
			textBox2->Text = "0";
		textBox1->Text = ""+Convert::ToInt32(textBox1->Text);
		textBox2->Text = ""+Convert::ToInt32(textBox2->Text);
		output();
	}
	void null_y()
	{
		for(int i = 0; i < 12; i++)
			y[i] = 0;
	}
	void output()
	{
		write(X, label1,"RG1:", 32);
		write(X, label67,"", 32);
		write(Y, label2, "RG2:", 32);
		write(Y, label66,"", 32);
		write(Z, label3, "RG3:", 64);
		write(Z, label68,"", 64);
		write(SMa, label5, "SMa:", 64);
		write(SMb, label6, "SMb:", 64);
		write(SMs, label7, "SMs:", 64);
		write(SMa, label69, "", 64);
		write(SMb, label70, "", 64);
		write(SMs, label71, "", 64);
		write(CT, label4, "CT:", 5);
		write(CT, label73, "", 5);
		label8->Text = "p1:  "  + p[1];
		label9->Text = "p2:  "  + p[2];
		label30->Text = "p3:  "  + p[3];
		//
		label57->Text = ""  + p[1];
		label58->Text = ""  + p[2];
		label59->Text = ""  + p[3];
		//
		label82->Text = ""  + Q[1];
		label83->Text = ""  + Q[2];
		label84->Text = ""  + Q[3];
		//
		label85->Text = ""  + R[1];
		label86->Text = ""  + R[2];
		label87->Text = ""  + R[3];
		//
		label88->Text = ""  + S[1];
		label89->Text = ""  + S[2];
		label90->Text = ""  + S[3];
		//
		label18->Text = "y1:  "  + y[1];
		label19->Text = "y2:  "  + y[2];
		label20->Text = "y3:  "  + y[3];
		label21->Text = "y4:  "  + y[4];
		label22->Text = "y5:  "  + y[5];
		label23->Text = "y6:  "  + y[6];
		label24->Text = "y7:  "  + y[7];
		label25->Text = "y8:  "  + y[8];
		label26->Text = "y9:  "  + y[9];
		label27->Text = "y10:  "  + y[10];
		label29->Text = "y11:  "  + y[11];
		//
		label31->Text = ""  + y[1];
		label36->Text = ""  + y[2];
		label37->Text = ""  + y[3];
		label38->Text = ""  + y[4];
		label39->Text = ""  + y[5];
		label40->Text = ""  + y[6];
		label41->Text = ""  + y[7];
		label42->Text = ""  + y[8];
		label43->Text = ""  + y[9];
		label44->Text = ""  + y[10];
		label45->Text = ""  + y[11];
		//
		label46->Text = ""  + y[1];
		label47->Text = ""  + y[2];
		label48->Text = ""  + y[3];
		label49->Text = ""  + y[4];
		label50->Text = ""  + y[5];
		label51->Text = ""  + y[6];
		label52->Text = ""  + y[7];
		label53->Text = ""  + y[8];
		label54->Text = ""  + y[9];
		label55->Text = ""  + y[10];
		label56->Text = ""  + y[11];
		//
		label74->Text = ""  + a[0];
		label75->Text = ""  + a[1];
		label76->Text = ""  + a[2];
		label77->Text = ""  + a[3];
		label78->Text = ""  + a[4];
		label79->Text = ""  + a[5];
		label80->Text = ""  + a[6];
		label81->Text = ""  + a[7];
		//
		label12->Text = "x1:  "  + x[1];
		label13->Text = "x2:  "  + x[2];
		label14->Text = "x3:  "  + x[3];
		label15->Text = "x4:  "  + x[4];
		label16->Text = "x5:  "  + x[5];
		label17->Text = "x6:  "  + x[6];
		//
		label60->Text = ""  + x[1];
		label61->Text = ""  + x[2];
		label62->Text = ""  + x[3];
		label63->Text = ""  + x[4];
		label64->Text = ""  + x[5];
		label65->Text = ""  + x[6];
		//
		label10->Text = "CRP:  "  + CRP;
		label28->Text = "CR:  "  + CR;
		label72->Text = ""  + CR;
		//
		label11->Text = "Состояние: a[" + state + "]";
	}
	void plus_one(array<int>^X, int n)
	{
		int p = 1;
		for(int i = n-1; i >= 0; i--)
		{
			if(X[i] != 0)
			{
				X[i] = 0;
			}
			else
			{
				X[i] = 1;
				return;
			}
		}
	}
	bool get_p3()
	{
		int o=0;
		for(int i = 0; i < CT->Length; i++)
			o+=CT[i];			
		if(o == 5)
			return true;
		return false;
	}
	void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{//auto
		textBox1->Enabled = false;
		textBox2->Enabled = false;
		button1->Enabled = false;
		button2->Enabled = false;
		button8->Enabled = false;
		button3->Enabled = true;
		button4->Enabled = true;
		timer1->Start();
	}
	void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{//step
		textBox1->Enabled = false;
		textBox2->Enabled = false;
		button1->Enabled = true;
		button2->Enabled = true;
		button3->Enabled = false;
		button4->Enabled = true;
		button8->Enabled = true;
		button2->Enabled = false;
		to_do();
		

	}
	void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{//stop auto
		button1->Enabled = true;
		button3->Enabled = false;
		button4->Enabled = true;
		button8->Enabled = true;
		button2->Enabled = false;
		try{timer1->Stop();}
		catch(...){;};
	}
	void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{//full stop
		textBox1->Enabled = true;
		textBox2->Enabled = true;
		button1->Enabled = true;
		button3->Enabled = false;
		button4->Enabled = false;
		button8->Enabled = true;
		button2->Enabled = false;
		try{timer1->Stop();}
		catch(...){;};
		if(y[9] != 1)
			label35->Text = "Остановлено";
		else
		{
			String^s = "";
			long long m = 0, l = 1;
			if(Z[0] == 1)
			{
				s = "-";
				for(int i = 0; i < 63; i++)
					Z[i] = Z[i]^1;
				plus_one(Z,64);
				plus_one(Z,64);
			}
			for(int i = 0; i < 63; i++)
			{
				m += l*Z[63-i];
				l*=2;
			}
			label35->Text = "Ответ по решению: "+s+m;
			label34->Text = "Ответ точно:            " + Convert::ToInt64(textBox2->Text)*Convert::ToInt64(textBox1->Text);
		}
		nullify();
		x[1] = 1;
		x[2] = 1;
		x[6] = 1;
		button5->Enabled = true;
		button6->Enabled = true;
		//button7->Enabled = true;
	}

	void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		one_step();
		if(y[9])
		{
			button4_Click(sender,e);
			return;
		}
		to_do();
		
	}
	void button5_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if(button5->Text[0] == L'П')
		{
			x[1] = 1;
			button5->Text = "Снять X";
		}
		else
		{
			x[1] = 0;
			button5->Text = "Подать X";
		}
		output();
	}
	void button6_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if(button6->Text[0] == L'П')
		{
			x[2] = 1;
			button6->Text = "Снять Y";
		}
		else
		{
			x[2] = 0;
			button6->Text = "Подать Y";
		}
		output();
	}
	void button7_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if(button7->Text[0] == L'С')
		{
			x[6] = 1;
			button7->Text = "Не читать Z";
		}
		else
		{
			x[6] = 0;
			button7->Text = "Считать Z";
		}
		output();
	}
	void button8_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		textBox1->Enabled = false;
		textBox2->Enabled = false;
		button1->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = true;
		button8->Enabled = false;
		button2->Enabled = true;
		one_step();
		if(y[9])
		{
			button4_Click(sender,e);
			return;
		}
	}
	void to_do()
	{
		for(int i = 0; i < 64; i++)
		{
			SMa[i] = 0;
			SMb[i] = Z[i];
			SMs[i] = 0;
		}
		if(y[1])
			translate(X, Convert::ToInt32(textBox1->Text));
		if(y[2])
		{
			for(int i = 32; i > 0; i--)
				X[i] = X[i-1];
			X[0] = X[1];
		}
		if(y[3])
			translate(Y, Convert::ToInt32(textBox2->Text));
		if(y[4])
			for(int i = 0; i < 32; i++)
				SMa[i] = Y[i]^1;
		else if(x[3])
			for(int i = 0; i < 32; i++)
				SMa[i] = Y[i];
		CRP = y[5];
		if(y[6])
			for(int i = 0; i < 64; i++)
				Z[i] = 0;
		CR = sum(SMa,SMb,SMs,64,y[5]);
		if(y[7])
		{
			CR_to = CR;
			for(int i = 0; i < 64; i++)
				Z[i] = SMs[i];
		}
		if(y[8])
		{
			for(int i = 63; i > 0; i--)
				Z[i] = Z[i-1];
			//Z[0] = CR_to;
		}
		if(y[9])
		{
			;
		}
		if(y[10])
			for(int i = 0; i < 5; i++)
				CT[i] = 0;
		if(y[11])
		{
			plus_one(CT,5);
		}
		output();
		p[1] = X[31];
		p[2] = X[32];
		p[3] = get_p3();
		x[3] = p[1]^p[2];
		x[4] = p[2];
		x[5] = p[3];
	}
	void one_step()
	{
		
		if(first)
		{
			button5->Enabled = false;
			button6->Enabled = false;
			//button7->Enabled = false;
			r = 1;
			first = false;
		}
		y[1] = x[1]&a[0];
		y[2] = a[3];
		y[3] = x[2]&a[1];
		y[4] = x[3]&(!x[4])&a[2];
		y[5] = y[4];
		y[6] = y[3];
		y[7] = a[2];
		y[8] = y[2];
		y[9] = x[6]&a[5];
		y[10] = y[3];
		y[11] = y[2];
		//
		R[1] = y[9]|r;
		R[2] = y[9]|r;
		R[3] = y[7]|r;
		S[1] = x[5]&a[3];
		S[2] = y[3];
		S[3] = ((!x[5])&a[3])|y[1];
		if(r)
		{
			S[1] = 0;
			S[2] = 0;
			S[3] = 0;
		}
		for(int i = 1; i < 4; i++)
			if(R[i])
				Q[i] = 0;
			else if(S[i] == 1)
				Q[i] = 1;
		for(int i = 0; i < 8; i++)
			a[i] = 0;
		switch(Q[3] + 2*Q[2] + 4*Q[1])
		{
			case 0: a[0] = 1; break;
			case 1: a[1] = 1; break;
			case 2: a[3] = 1; break;
			case 3: a[2] = 1; break;
			case 4: a[4] = 1; break;
			case 5: a[6] = 1; break;
			case 6: a[5] = 1; break;
			case 7: a[7] = 1; break;
		}
		state = Q[3] + 2*Q[2] + 4*Q[1];
		if(a[0] == 1)
			y[1] = 0;
		output();
		if(r)
			r = 0;
		if(x[1]&y[1])
			x[1] = 0;
		if(x[2]&y[3])
			x[2] = 0;
		/*if(x[6]&y[9])
			x[6] = 0;*/
	}
	
	void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) 
	{
		timer1->Interval = trackBar1->Value;
	}
};
}

