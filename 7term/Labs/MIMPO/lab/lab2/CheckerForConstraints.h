#pragma once
#include "Function.h"
ref class CheckerForConstraints
{
private:
	array<Function^>^ consLt;
public:
	CheckerForConstraints(array<String^>^ as);
	bool isOKConsLt(array<double>^ arg);
};

