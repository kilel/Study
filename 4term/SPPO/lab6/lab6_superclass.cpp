#include "StdAfx.h"
#include "lab6_superclass.h"

lab6_superclass::lab6_superclass(EventWaitHandle^ ev):eva(ev)
{
	input = gcnew array<int>(0);
	copy = gcnew array<int>(0);
	accum = gcnew array<int>(0);
	file = File::OpenRead("input");
	mya = gcnew Mutex();
	sema = gcnew Semaphore(1,1);
	out = "";
	in = "";
	evb = gcnew EventWaitHandle(false,EventResetMode::AutoReset);
}
lab6_superclass::~lab6_superclass()
{
	file->Close();
	delete input;
	delete copy;
	delete accum;
	delete mya;
	delete sema;
	stop = 0;
}
void lab6_superclass::print_data()
{
	int n;
	while(1)
	{
		mya->WaitOne();
		n = accum->Length;
		mya->ReleaseMutex();

		out = L"result:\n";
		in = L"input:\n";
		for(int i = 0; i < n; i++)
		{
			out = out->Concat(out,accum[i], " ");
			in = in->Concat(in,input[i], " ");
			if(i != n-1)
			{
				in = in->Concat(in,",");
				out = in->Concat(out, ",");
			}
		}
		eva->Set();
		if(n == file->Length && n == input->Length &&  stop == 1)
		{
			stop = 6;
			eva->Set();
			break;
		}
	}
}

void lab6_superclass::read_data()
{
	array<Byte>^c = gcnew array<Byte>(1);
	UTF8Encoding^ temp = gcnew UTF8Encoding( true );

	while(file->Read(c,0,1) > 0)
	{
		sema->WaitOne();
		input->Resize(input, input->Length+1);
		copy->Resize(copy, input->Length);
		input[input->Length - 1] = c[0];
		sema->Release();

		input->Copy(input, copy, input->Length);
	}
}
void lab6_superclass::process_data()
{
	int n;
	while(1)
	{
		sema->WaitOne();
		n = input->Length;

		mya->WaitOne();
		ac_len = accum->Length;
		mya->ReleaseMutex();

		sema->Release();

		
		accum->Resize(accum, n);
		for(int i = ac_len; i < n; i++)
		{
			accum[i] = 0;
			for(int j = 0; j <= i; j++)
				accum[i] += input[j];
		}
		if(accum->Length == file->Length && input->Length == file->Length)
		{
			stop = 1;
			break;
		}
		
		

	}
}