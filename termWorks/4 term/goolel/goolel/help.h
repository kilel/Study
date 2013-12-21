#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace goolel {

	/// <summary>
	/// Сводка для help
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class help : public System::Windows::Forms::Form
	{
	public:
		help(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
		help_box->Text = L"Руководство по пользованию программой Goolel.\
			\nэтапы:\
			\n1)Первый запуск и настройка\
			\n2)Построение индекса\
			\n3)Поиск\
			\n4)Предостережения\
			\n\
			\nЭтап 1. Первый запуск и настройка.\
			\n\tЕсли при первом запуске у вас не отобразилось окно настроек, рекомендуется выбрать пункт \"Меню\\Удалить все созданные файлы\", а затем зайти в меню настроек. Данные действия обеспечат создание нового файла настроек и удалят старые настройки и индекс. Большинстро ошибок позникают при использовании поврежденного файла настроек или индекса при поиске.\
			\n\tВ окне настроек есть 2 параметра и одна строка ввода текста.\
			\n-При выделении пункта \"Использовать индекс при поиске\", поиск будет осуществляться с использованием индекса, иначе, без.\
			\n-При выделении пункта \"Поиск строки целиком\", поисковый запрос будет воспринят как единая строка, иначе же будет обработан и разделен на слова при поиске.\
			\n-В строке ввода укажите каталог, в котором будет производиться поиск. Оставьте пустой эту строку, если желаете искать файлы по всему компьютеру.\
			\n\
			\nЭтап 2. Построение индекса.\
			\n\tВ пункте меню \"Индекс\" вы можете построить, обновить или удалить индекс.\
			\n\
			\nЭтап 3. Поиск\
			\n\tВведите поисковый запрос в строку поиска и нажмите кнопку \"Поиск\". В списке результатов отобразятся найденные файлы. Правым кликом по одному из результатов в появившемся контекстном меню вы можете открыть выбранный файл или каталог, его содержащий.\
			\n\
			\nЭтап 4.Предостережения\
			\n\
			\n1)Не изменяйте файлы в каталоге \"data\", который находится в каталоге запускаемого файла\
			\n2)Если вы всё-все сделали правильно, но ничего не работает, обращайтесь в службу поддержки или используйте нормальные поисковые программы\
			\n3)Текстовые файлы должны быть сохранены в кодировке Unicode\
			\n4)Пути к файлам должны быть";	
	}
};
}
