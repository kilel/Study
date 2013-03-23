#include "CheckerForConstraints.h"


CheckerForConstraints::CheckerForConstraints(array<String^>^ as){
	consLt = Function::getFunctionArray(as);
}


bool CheckerForConstraints::isOKConsLt(array<double>^ arg){
	for(int i = 0; i < consLt->Length; i++)
			if(consLt[i]->getValue(arg) > -1e-6)
				return false;
	return true;
}