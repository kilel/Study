#pragma once
#include "Function.h"
#include "CheckerForConstraints.h"
enum GlobalOptimumType{
	min, max
};

ref class GlobalOptimum
{
private: 
	Function ^f;
	String^ log;
	int numArgs;
	CheckerForConstraints^ cpm;
	bool isSmallDifference(array<double>^ a, array<double>^ b, double accuracy);
	bool isSmallDifference(array<double>^ a, double accuracy);
	array<double>^ getNextArg(array<double>^ arg, array<double>^ grad, double h);
public:
	GlobalOptimum(String^ code, GlobalOptimumType type, int numArgs, CheckerForConstraints^ cm);
	array<double>^ solve(array<double>^ start, double accuracy, int maxCountIter, double startH);
	String^ getLog();
};

