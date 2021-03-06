#pragma once


namespace prog_cu {

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
	private: System::Windows::Forms::RichTextBox^  rtb;
	protected:
	private: System::Windows::Forms::Button^  button;
	protected:
	private: System::Windows::Forms::PictureBox^  pic;


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
			this->rtb = (gcnew System::Windows::Forms::RichTextBox());
			this->button = (gcnew System::Windows::Forms::Button());
			this->pic = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->BeginInit();
			this->SuspendLayout();
			// 
			// rtb
			// 
			this->rtb->DetectUrls = false;
			this->rtb->Location = System::Drawing::Point(606, 12);
			this->rtb->Name = L"rtb";
			this->rtb->Size = System::Drawing::Size(136, 379);
			this->rtb->TabIndex = 0;
			this->rtb->Text = L"0\n1\n2\n3";
			// 
			// button
			// 
			this->button->Location = System::Drawing::Point(606, 397);
			this->button->Name = L"button";
			this->button->Size = System::Drawing::Size(136, 23);
			this->button->TabIndex = 1;
			this->button->Text = L"Построить";
			this->button->UseVisualStyleBackColor = true;
			this->button->Click += gcnew System::EventHandler(this, &Form1::button_Click);
			// 
			// pic
			// 
			this->pic->BackColor = System::Drawing::Color::White;
			this->pic->Location = System::Drawing::Point(12, 12);
			this->pic->Name = L"pic";
			this->pic->Size = System::Drawing::Size(578, 409);
			this->pic->TabIndex = 2;
			this->pic->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(754, 433);
			this->Controls->Add(this->pic);
			this->Controls->Add(this->button);
			this->Controls->Add(this->rtb);
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"Лаб1 ЦУМ";
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
public:
	Graphics^ g;
	static int h = 20;
	Bitmap^canvas;
	static int sig = 4;

private: 
	void Form1_Resize(System::Object^  sender, System::EventArgs^  e) 
	{
		pic->Width = this->Width -770 + 566 + 12;
		pic->Height = this->Height - 471 + 409;
		button->Location = Point(pic->Width + (770-606-136), this->Height - 471+397);
		rtb->Location = Point(pic->Width + (770-606-136), 12);
		rtb->Height = this->Height - 471 + 379;
	}
	private: System::Void button_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if(canvas)
			delete canvas;
		int two[32];
		two[0] = 1;
		for(int i = 1; i < 30; i++)
		{
			two[i] = 2*two[i-1];
		}
		canvas = gcnew Bitmap(two[sig]*h + h, (rtb->Lines->Length)*(3*h) + h/2);
		//int **fu = new int*[rtb->Lines->Length];
		int fu[20][20];
		/*for(int i = 1; i < rtb->Lines->Length; i++)
			fu[i] = new int[two[sig]];*/
		//Convert::ToInt32( rtb->Lines[0]);	//signals
		//rtb->Lines->Length - 1;		//lines
		g = g->FromImage(canvas);
		for(int i = 0; i < two[sig]; i++)
		{
			for(int j = 0; j < sig; j++)
				fu[j][i] = (i & two[sig-j-1])/two[sig-j-1];
		}
		array<Point> ^p = gcnew array<Point>(two[sig+1]);
		for(int i = 0; i < sig; i++)
		{
			for(int j = 0, s = 0; j <two[sig+1]; j+=2, s++)
			{
				p[j] = Point(h + s*h, h/2 + h + (h/2 + h)*i - fu[i][j/2]*h);
				p[j+1] = Point(h + (s+1)*h, h/2 + h + (h/2 + h)*i - fu[i][j/2]*h);
			}
			g->DrawLines(Pens::Black, p);
		}
		for(int i = sig; i < rtb->Lines->Length; i++)
		{
			if(rtb->Lines[i]->Length == 0)
				continue;
			switch (rtb->Lines[i][0])
			{
			case '-':
				{
					for(int j = 0, s = 0; j <two[sig+1]; j+=2, s++)
					{
						if(rtb->Lines[i][1] <= '9' && rtb->Lines[i][1] >= '0')
							fu[i][j/2] = !fu[rtb->Lines[i][1] - '0'][j/2];
						else
							fu[i][j/2] = !fu[rtb->Lines[i][1] - 'a' + 10][j/2];
						p[j] = Point(h + s*h, h/2 + h + (h/2 + h)*i - (fu[i][j/2])*h);
						p[j+1] = Point(h + (s+1)*h, h/2 + h + (h/2 + h)*i - (fu[i][j/2])*h);
					}
					g->DrawLines(Pens::Black, p);
					break;
				}
			case '+':
				{
					for(int j = 0, s = 0; j <two[sig+1]; j+=2, s++)
					{
						bool temp = false;
						for(int k = 1; k <rtb->Lines[i]->Length; k++)
						{
							if(rtb->Lines[i][k] <= '9' && rtb->Lines[i][k] >= '0')
								temp = temp || fu[rtb->Lines[i][k] - '0'][j/2];
							else
								temp = temp || fu[rtb->Lines[i][k] - 'a' + 10][j/2];
						}
						fu[i][j/2] = temp;
						p[j] = Point(h + s*h, h/2 + h + (h/2 + h)*i - (fu[i][j/2])*h);
						p[j+1] = Point(h + (s+1)*h, h/2 + h + (h/2 + h)*i - (fu[i][j/2])*h);
					}
					g->DrawLines(Pens::Black, p);
					break;
				}
			case '&':
				{
					for(int j = 0, s = 0; j <two[sig+1]; j+=2, s++)
					{
						bool temp = true;
						for(int k = 1; k <rtb->Lines[i]->Length; k++)
						{
							if(rtb->Lines[i][k] <= '9' && rtb->Lines[i][k] >= '0')
								temp = temp && fu[rtb->Lines[i][k] - '0'][j/2];
							else
								temp = temp && fu[rtb->Lines[i][k] - 'a' + 10][j/2];
						}
						fu[i][j/2] = temp;
						p[j] = Point(h + s*h, h/2 + h + (h/2 + h)*i - (fu[i][j/2])*h);
						p[j+1] = Point(h + (s+1)*h, h/2 + h + (h/2 + h)*i - (fu[i][j/2])*h);
					}
					g->DrawLines(Pens::Black, p);
					break;
				}
			case '|':
				{
					for(int j = 0, s = 0; j <two[sig+1]; j+=2, s++)
					{
						bool temp = true;
						for(int k = 1; k <rtb->Lines[i]->Length; k++)
						{
							if(rtb->Lines[i][k] <= '9' && rtb->Lines[i][k] >= '0')
								temp = temp && fu[rtb->Lines[i][k] - '0'][j/2];
							else
								temp = temp && fu[rtb->Lines[i][k] - 'a' + 10][j/2];
						}
						fu[i][j/2] = !temp;
						p[j] = Point(h + s*h, h/2 + h + (h/2 + h)*i - (fu[i][j/2])*h);
						p[j+1] = Point(h + (s+1)*h, h/2 + h + (h/2 + h)*i - (fu[i][j/2])*h);
					}
					g->DrawLines(Pens::Black, p);
					break;
				}
			case '#':
				{
					for(int j = 0, s = 0; j <two[sig+1]; j+=2, s++)
					{
						bool temp = false;
						for(int k = 1; k <rtb->Lines[i]->Length; k++)
						{
							if(rtb->Lines[i][k] <= '9' && rtb->Lines[i][k] >= '0')
								temp = temp || fu[rtb->Lines[i][k] - '0'][j/2];
							else
								temp = temp || fu[rtb->Lines[i][k] - 'a' + 10][j/2];
						}
						fu[i][j/2] = !temp;
						p[j] = Point(h + s*h, h/2 + h + (h/2 + h)*i - (fu[i][j/2])*h);
						p[j+1] = Point(h + (s+1)*h, h/2 + h + (h/2 + h)*i - (fu[i][j/2])*h);
					}
					g->DrawLines(Pens::Black, p);
					break;
					break;
				}
			}
		}
		pic->Image = canvas;

	}
};
}

