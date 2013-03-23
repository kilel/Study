#pragma once
using namespace System;
using namespace System::IO;
using namespace System::Threading;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;


ref class lab6_superclass
{
private:
	Mutex^ mya;
	Semaphore^ sema;
	EventWaitHandle^ eva;
	EventWaitHandle^ evb;
	int ac_len;
	FileStream^ file;
	
public:
	int stop;
	array<int> ^input, ^copy, ^accum;
	String ^ in, ^out;
	lab6_superclass(EventWaitHandle^ ev);
	~lab6_superclass();
	void print_data();
	void read_data();
	void process_data();
};
