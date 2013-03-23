#pragma once
#include "GlobalOptimum.h"

ref class CombinedPenaltyMeth
{
private: 
	int numArgs;
	Function^ f;
	CheckerForConstraints^ cm;
	array<Function^>^ consLt;
	String^ penFunc,  ^penCode;
	double penStart, penC;
	String ^log;
	bool isCompl;
	array<double>^ result;
	double value;
	array<double>^ getRandArg();
	
public:
	CombinedPenaltyMeth(String^ func, int numArgs, array<String^>^ consEq, array<String^>^ consLt,double penStart, double penC);
	String^ getLog();
	array<double>^ solve(double accuracy);
	void sol(Object^ o);
	array<double>^ getResult(){if(isCompl) return result; else return nullptr;};
	double getValue(){if(isCompl) return value; else return 0;}
	bool isComplete(){return isCompl;}
	bool isOKConsLt(array<double>^ arg);
	
};

