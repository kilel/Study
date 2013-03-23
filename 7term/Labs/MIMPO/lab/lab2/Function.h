#pragma once
using namespace System;
using namespace System::Collections;
ref class Function
{
private:
	
	static String^highOp, ^allOp;
	String^ code;
	double getVal(String^ code, array<double>^ arg);
public:
	Function(String^ code);
	static array<Function ^> ^getFunctionArray(array<String^>^ fArray);
	double getValue(array<double> ^arg);
	double getDiffValue(array<double>^ arg, int diffVar, double accuracy);
	array<double>^ getGrad(array<double>^arg, double accuracy);	
};

