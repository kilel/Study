#include "CombinedPenaltyMeth.h"
#include "ParsingTools.h"

bool CombinedPenaltyMeth::isOKConsLt(array<double>^ arg){
	for(int i = 0; i < consLt->Length; i++)
			if(consLt[i]->getValue(arg) > -1e-6)
				return false;
	return true;
}
array<double>^ CombinedPenaltyMeth::getRandArg(){
	array<double>^ rVect = gcnew array<double>(numArgs);
	Random^ rand = gcnew Random();
	if(consLt->Length == 0){
		for(int i = 0; i < numArgs; i++){
			rVect[i] = rand->NextDouble()*2. - 0;
		}
		return rVect;
	}
	while(true){
		for(int i = 0; i < numArgs; i++){
			rVect[i] = rand->NextDouble()*2. - 0;
		}
		if(isOKConsLt(rVect))
			return rVect;
	}
	return rVect;
}
String^ CombinedPenaltyMeth::getLog(){
	return log;
}
CombinedPenaltyMeth::CombinedPenaltyMeth(String^ func, int numArgs, array<String^>^ consEq, array<String^>^ consLt, double penStart, double penC){
	log = "Создаётся задача оптимизации. Решение комбинированнымметодом штрафных функций\n";
	log+= "Функция:\n\t" + func+ "\n";
	cm = gcnew CheckerForConstraints(consLt);
	isCompl = false;
	this->numArgs = numArgs;
	this->consLt = Function::getFunctionArray(consLt);
	String^ penArg = "x"+(numArgs+1), ^eq="0";
	if(consEq->Length > 0){
		log+= "Ограничения типа '=':\n";
		log += "\t"+consEq[0]+"\n";
		eq = consEq[0]+"";
		for(int i = 1; i < consEq->Length; i++){
			eq += "+" + consEq[i];
			log += "\t"+consEq[i]+"\n";
		}
		eq = "("+eq+")/(2*"+penArg+")*(1000000)";
	}
	String^ lt = "0";
	if(consLt->Length > 0){
		log+= "Ограничения типа '<=':\n";
		log += "\t"+consLt[0]+"\n";
		lt= "1/("+consLt[0]+")";
		for(int i = 1; i < consLt->Length; i++){
			lt  += "+" + "1/("+consLt[i]+")";
			log += "\t"+consLt[i]+"\n";
		}
		lt = "("+lt+")*("+penArg+")";
	}
	penCode = eq+ "-" +lt;
	penFunc = func+ "+" + eq + "-" + lt;
	log += "Штрафная функция:\n\t"+penCode+"\n";
	log += "Вспомогательная функция:\n\t"+penFunc+"\n";
	f = gcnew Function(func);
	this->penC = penC < 1 ? 2 : penC;
	this->penStart = penStart; 
}
array<double>^ CombinedPenaltyMeth::solve(double accuracy){
	GlobalOptimum^ globProbl = gcnew GlobalOptimum(penFunc, GlobalOptimumType::min, numArgs, cm);
	Function ^penF = gcnew Function(penCode);
	array<double>^ startArg = getRandArg();
	log += "Создана начальная точка, удовлетворяющая условиям неравенств:\n";
	log += "\t"+ ParsingTools::arrayToString(startArg)+"\n";
	array<double>^ currPenaltedArg = gcnew array<double>(numArgs+1), ^nextPenaltedArg;
	for(int i = 0; i < numArgs; i++){
		currPenaltedArg[i] = startArg[i];
	}
	currPenaltedArg[numArgs] = penStart;
	log+= "Создана начальная точка:\n";
	log += "\t"+ ParsingTools::arrayToString(currPenaltedArg)+"\n";
	double nextVal = 0;
	double h = 10;
	while(true){
		
		while(true){
			log+= "Следующая точка:\n";
			nextPenaltedArg = globProbl->solve(currPenaltedArg, accuracy, 1000, h);
			log += "\t"+ ParsingTools::arrayToString(nextPenaltedArg)+"\n";
			if(!isOKConsLt(nextPenaltedArg)){
				log+= "Не удовлетворяет условиям типа '<='. Уменьшается шаг H алгоритма безусловного поиска.\n";
				h/=2;
				currPenaltedArg[numArgs]/= penC;
			}
			else break;
		}
		nextVal = penF->getValue(nextPenaltedArg);
		log += "Штраф в ней:\n\t"+ParsingTools::evalf(nextVal)+"\n";
		value = f->getValue(nextPenaltedArg);
		log += "Функция в ней:\n\t"+ParsingTools::evalf(value)+"\n";
		if(Math::Abs(nextVal) < accuracy)
		//if(Math::Abs(nextPenaltedArg[numArgs]) < accuracy)
			break;
		currPenaltedArg = dynamic_cast<array<double>^>( nextPenaltedArg->Clone() );
		currPenaltedArg[numArgs] /= penC;
	}
	result = gcnew array<double>(numArgs);
	for(int i = 0; i < numArgs; i++){
		result[i] = nextPenaltedArg[i];
	}
	isCompl = true;
	return result;
}


void CombinedPenaltyMeth::sol(Object^ o){
	solve(0.1);
}
