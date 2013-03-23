#pragma once

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace lab1 {

	/// <summary>
	/// Сводка для Search
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Search : public System::Windows::Forms::Form
	{
	public:
		Search(String^ way)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			label1->Text = String::Concat("Ищем в ",way);
			source = way;
			backgroundWorker1->RunWorkerAsync();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Search()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  с1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  с2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  с3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label3;

	protected: 




	protected: 

	protected: 

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->с1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->с2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->с3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->с1, this->с2, 
				this->с3});
			this->dataGridView1->Location = System::Drawing::Point(1, 1);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(443, 257);
			this->dataGridView1->TabIndex = 0;
			// 
			// с1
			// 
			this->с1->HeaderText = L"Имя";
			this->с1->Name = L"с1";
			this->с1->ReadOnly = true;
			this->с1->Width = 200;
			// 
			// с2
			// 
			this->с2->HeaderText = L"Размер";
			this->с2->Name = L"с2";
			this->с2->ReadOnly = true;
			// 
			// с3
			// 
			this->с3->HeaderText = L"атрибуты";
			this->с3->Name = L"с3";
			this->с3->ReadOnly = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 265);
			this->label1->MaximumSize = System::Drawing::Size(328, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 278);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(360, 301);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Найти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Search::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(16, 317);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(328, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Search::key_press);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(16, 294);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(173, 17);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"Искать внутри подкаталогов";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Search::when_start);
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->WorkerReportsProgress = true;
			this->backgroundWorker2->WorkerSupportsCancellation = true;
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Search::search_do);
			this->backgroundWorker2->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Search::complete);
			this->backgroundWorker2->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Search::backgroundWorker2_ProgressChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(336, 264);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(99, 17);
			this->radioButton1->TabIndex = 6;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Искать файлы";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(336, 279);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(111, 17);
			this->radioButton2->TabIndex = 6;
			this->radioButton2->Text = L"Искать каталоги";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(16, 343);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(328, 10);
			this->progressBar1->TabIndex = 7;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(360, 330);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Стоп";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Search::stop_click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(450, 151);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 107);
			this->button3->TabIndex = 8;
			this->button3->Text = L"prev 50";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Search::button3_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(450, 45);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 100);
			this->button4->TabIndex = 8;
			this->button4->Text = L"next 50";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Search::button4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(451, 26);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 9;
			// 
			// Search
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(529, 358);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Search";
			this->Text = L"Search";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	int dirs, files, total, count, count1,index, STOP;
	String^ source, ^tete, ^search_value;
	cli::array<String^,1> ^ src, ^fi, ^search_results;
private: 
	int find_last_slash(String^ s) //находит индекс последнего символа \ в строке
	{
		for(int i = s->Length -2; i > 0; i--)
			if('\\' == s[i])
				return i;
	}
	void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		STOP = 0;
		dataGridView1->Rows->Clear();
		if(!(radioButton1->Checked||radioButton2->Checked))
			return;
		search_value = textBox1->Text;
		try
		{
			backgroundWorker2->RunWorkerAsync();
		}
		catch(...)
		{
			backgroundWorker2->CancelAsync();
			backgroundWorker2->RunWorkerAsync();
		}
		button1->Enabled = false;
	}
	void key_press(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		wchar_t k = e->KeyChar;
		if('<' == k || '>' == k || '|' == k || '\\' == k || '/' == k || '*' == k || '?' == k || '\"' == k || ':' == k)
			e->KeyChar = 0;
		if(e->KeyChar == 13)
			button1_Click(sender, gcnew EventArgs());
	}
	void when_start(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) 
	{
		dirs = 0;
		files = 0;
		total = 1;
		count = 0;
		count1 = 0;
		getNumberOfFil_dirs(source, Directory::GetDirectories(source), Directory::GetFiles(source));
	}
	void getNumberOfFil_dirs(String^ source, cli::array<String^>^ src, cli::array<String^>^ filelist)
	{
		String^ s, ^temp;
		cli::array<String^>^ dir_dest, ^file_dest;
		for(int i = 0; i < src->Length; ++i)		//получаем иерархию директорий
		{
			temp = src[i]->Substring(find_last_slash(src[i])+1);
			try
			{
				dir_dest = Directory::GetDirectories(s->Concat(source, temp, "\\"));
				file_dest = Directory::GetFiles(s->Concat(source, temp, "\\"));
			}
			catch(...)	//нет доступа
			{
				continue;
			}
			getNumberOfFil_dirs(s->Concat(source, temp, "\\"), dir_dest, file_dest);
		}
		dirs += src->Length;
		files += filelist->Length;
		if(!radioButton1->Checked)
			total = dirs;
		if(!radioButton2->Checked)
			total = files;
	}
	void search_do(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) 
	{
		count = count1 = 0;
		//total = 0;
		/*if(!radioButton1->Checked)
			total+= dirs;
		if(!radioButton2->Checked)
			total += files;*/
		
		search_results = gcnew array<String^,1>(total);
		search_process(source, Directory::GetDirectories(source), Directory::GetFiles(source));
	}
	void search_process(String^ source, cli::array<String^>^ src, cli::array<String^>^ filelist)
	{
		if(STOP)
			backgroundWorker2->CancelAsync();
		String^ s, ^temp;
		cli::array<String^>^ dir_dest, ^file_dest;
		for(int i = 0; i < src->Length; ++i)		//получаем иерархию директорий
		{
			temp = src[i]->Substring(find_last_slash(src[i])+1);
			if(radioButton2->Checked)
			{
				++count1;
				
				if((temp->ToLower())->Contains(search_value->ToLower()) || (search_value->ToLower())->Contains(temp->ToLower()))
				{
					try
					{
						search_results[count] = s->Concat(source, temp);
					}
					catch(...)
					{;}
					++count;
				}
				int nutts = (int)((double)100*count1/total);
				if(nutts < 99)
					backgroundWorker2->ReportProgress(nutts);
				else
					backgroundWorker2->ReportProgress(95);
			}
			try
			{
				dir_dest = Directory::GetDirectories(s->Concat(source, temp, "\\"));
				file_dest = Directory::GetFiles(s->Concat(source, temp, "\\"));
			}
			catch(...)	//нет доступа
			{
				continue;
			}
			if(checkBox1->Checked && STOP == 0)
				search_process(s->Concat(source, temp, "\\"), dir_dest, file_dest);
		}
		if(STOP == 0)
		for(int i = 0; i < filelist->Length; ++i)		//поиск файлов
		{
			try
			{
				temp = filelist[i]->Substring(find_last_slash(filelist[i])+1);
				if(radioButton1->Checked)
				{
					++count1;
					
					if((temp->ToLower())->Contains(search_value->ToLower()) || (search_value->ToLower())->Contains(temp->ToLower()))
					{
						
						try
						{
							search_results[count] = s->Concat(source, temp);
						}
						catch(...)
						{;}
						++count;
					}
					if((int)((double)100*count1/total) < 99)
						backgroundWorker2->ReportProgress((int)((double)100*count1/total));
					else
						backgroundWorker2->ReportProgress(95);
				}
				s = s->Concat(source, temp);		//полное имя исходного файла
			}
			catch(...)
			{
				;
			}
		}
	}
	void backgroundWorker2_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) 
	{
		progressBar1->Value = e->ProgressPercentage;
		label2->Text = String::Concat("Найдено: ",Convert::ToString(count));
	}
	void complete(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) 
	{
		if(count > 50)
			button4->Enabled = true;
		index = 0;
		if(count < 50)
			label3->Text = String::Concat("0-", Convert::ToString( count));
		else
			label3->Text = String::Concat("0-49");
		label2->Text = String::Concat("Найдено: ",Convert::ToString(count));
		showGrid();
		button1->Enabled = true;
	}
	void stop_click(System::Object^  sender, System::EventArgs^  e) 
	{
		STOP = 1;
		button1->Enabled = true;
		backgroundWorker1->CancelAsync();
		backgroundWorker2->CancelAsync();
	}
	void showGrid()
	{
		int a = index, b;
		array<String^,1>^ ar = gcnew array<String^,1>(3);
		if(count > a+50)
			b = a+50;
		else 
			b = count;
		label3->Text = String::Concat(Convert::ToString(a),"-",Convert::ToString(b-1));
		for(int i = a; i < b; i++)
		{
			ar[0] = search_results[i];
			try
			{
				FileAttributes^ pp = File::GetAttributes(ar[0]);
				ar[2] = pp->ToString();
				FileStream^ k = File::OpenRead(ar[0]); 
				ar[1] = Convert::ToString( k->Length);
				k->Close();
				
			}
			catch(...)
			{;}
			dataGridView1->Rows->Add(ar);
		}
	}
	void button4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		dataGridView1->Rows->Clear();
		index += 50;
		if(index+50 >= count)
			button4->Enabled = false;
		if(index >= 50)
			button3->Enabled = true;
		showGrid();
	}
	System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		dataGridView1->Rows->Clear();
		index -=50;
		if(index == 0)
			button3->Enabled = false;
		if(index+50 < count)
			button4->Enabled = true;
		showGrid();
	}
};
}
