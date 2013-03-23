#include "GlobalOptimum.h"

GlobalOptimum::GlobalOptimum(String^ code, GlobalOptimumType type, int numArgs, CheckerForConstraints^ cm){
	cpm = cm;
	this->numArgs = numArgs;
	if(type == GlobalOptimumType::max){
			f = gcnew Function("0-("+code+")");
		}
		else{
			f = gcnew Function(code);
		}
}
double norma(array<double>^ a, int numArgs){
	double dif = 0;
	for(int i = 0; i < numArgs; i++)
		dif += Math::Pow(a[i], 2.);
	return Math::Sqrt(dif);
}
array<double>^ nomalize(array<double>^ a, int numArgs){
	double dif = norma(a, numArgs);
	for(int i = 0; i< numArgs; i++){
		a[i] /= dif;
	}
	return a;
}
bool GlobalOptimum::isSmallDifference(array<double>^ a, array<double>^ b, double accuracy){
	double dif = 0;
	for(int i = 0; i < numArgs; i++)
		dif += Math::Pow(a[i]-b[i], 2.);
	if(Math::Sqrt(dif) < accuracy)
		return true;
	return false;
}
bool GlobalOptimum::isSmallDifference(array<double>^ a, double accuracy){
	array<double>^ b = gcnew array<double>(a->Length);
	for each (double a in b){
		a = 0;
	}
	return isSmallDifference(a,b,accuracy);
}
array<double>^ GlobalOptimum::getNextArg(array<double>^ arg, array<double>^ grad, double h){
	array<double>^ next = gcnew array<double>(arg->Length);
	for(int i = 0; i < arg->Length; i++){
		if(i < numArgs)
			next[i] = arg[i] - h*grad[i];
		else 
			next[i] = arg[i];
	}
	return next;	
}
array<double>^ GlobalOptimum::solve(array<double>^ start, double accuracy, int maxCountIter, double startH){
	array<double>^ result, ^currArg, ^nextArg, ^grad;
	currArg = dynamic_cast<array<double>^>(start->Clone());
	nextArg = dynamic_cast<array<double>^>(start->Clone());
	double h = startH;
	int countEq = 0;
		
	if(accuracy > 0.1)	{accuracy = 0.1; log += "Inadecvate accuracy. It was chanded to 0.1\n";}
	if(maxCountIter < 1) {maxCountIter = 1; log += "Inadecvate M. It was changed to 1\n";}
	for(int i = 0; ; i++){

		grad = f->getGrad(currArg, 0.0001);
		if( norma(grad, numArgs) > 1)
			grad = nomalize(grad, numArgs);
		if(isSmallDifference(grad, accuracy)){
			break;
		}
		if(i >= maxCountIter){
			break;//return start;
		}
		nextArg = getNextArg(currArg, grad, h);
		if(!cpm->isOKConsLt(nextArg)){
			h /= 2.;
			continue;
		}
		double df= f->getValue(nextArg) - f->getValue(currArg);
		if(df > 0){
			h /= 2.;
			continue;
		}
		if(Math::Abs(df) < accuracy && isSmallDifference(currArg, nextArg, accuracy) && ++countEq == 2){
			break;
		}
		else
			countEq = 0;
		for(int j = 0; j < numArgs; j++){
			currArg[j] = nextArg[j];
		}
	}
	result = nextArg;
	return result;
}
String^ GlobalOptimum::getLog(){
	return log;
}
