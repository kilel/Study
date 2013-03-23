#pragma once
using namespace System;
static ref class ParsingTools
{
public:
	static int getBracketEnd(String^ code, int start);
	static String^ delSpaces(String^code);
	static String^ evalf(double a);
	static String^ delBrackets(String^ code);
	static String^ arrayToString(array<double>^ a);
};

