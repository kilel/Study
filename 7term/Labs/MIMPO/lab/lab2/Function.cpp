#include "Function.h"
#include "ParsingTools.h"

Function::Function(String^Code)
{
	code = ParsingTools::delSpaces(Code) ;
	if(highOp == nullptr){
		highOp = "^*/-+";
		allOp = "^*/+-()";
	}

}




array<Function ^>^ Function::getFunctionArray(array<String^>^ sArray){
	array<Function^>^ fArray = gcnew array<Function^>(sArray->Length);
	for(int i = 0; i < sArray->Length; i++){
		fArray[i] = gcnew Function(sArray[i]);
	}
	return fArray;
}
double Function::getValue(array<double> ^arg){
	return getVal(code, arg);
}
double Function::getDiffValue(array<double>^ arg, int diffVar, double accuracy){
	array<double>^ argNext = dynamic_cast<array<double>^>(arg->Clone());
	argNext[diffVar] += accuracy;
	double a = getValue(argNext), b = getValue(arg); 
	return( ( a - b)/accuracy );
}
array<double>^ Function::getGrad(array<double>^arg, double accuracy){
	array<double>^ grad = gcnew array<double>(arg->Length);
	for(int i = 0; i < arg->Length; i++)
		grad[i] = getDiffValue(arg, i, accuracy);
	return grad;
}


double Function::getVal(String^ code, array<double>^ arg){
	code = ParsingTools::delBrackets(code);	
	if(code[0] == '-')
		code = "0"+ code;
	double r = 0, l = 0;
	int finL = 0, finR = 0;
	int currPos = 0;
	char F;
	bool isF;
	String^ currOper;
	for each (char operation in highOp){
		do{
			currPos = code->IndexOf(operation);
			if(currPos < 0) 
				break;
			//right direction
			F = code[currPos+1];
			if(F == 's' || F == 'c' || F == 'l'){
				isF = true;
				currPos+= 3;
			}
			else isF = false;

			if(code[currPos+1] == '('){
				finR = ParsingTools::getBracketEnd(code, currPos+1);
				currOper = code->Substring(currPos+2, finR - currPos - 2);
				finR++;			//should point next oper or end
				r = getVal(currOper, arg);
				if(isF){
					switch(F){
					case 'c': r = Math::Cos(r);
						break;
					case 's': r = Math::Sin(r);
						break;
					case 'l': r = Math::Log(r);
						break;
					}
					currPos -= 3;
				}
			}
			else{
				currOper = "";
				int len = code->Length;
				for(int i = currPos+1; i < len; i++){
					if(allOp->IndexOf(code[i]) >= 0){
						finR = i;
						break;
					}
					if(i == len-1){
						finR = len;
						break;
					}
				}
				currOper = code->Substring(currPos+1, finR - currPos - 1);
				r = getVal(currOper, arg);
			}
			//// left direction
			if(code[currPos-1] == ')'){
				finL = ParsingTools::getBracketEnd(code, currPos-1);
				currOper = code->Substring(finL+1, currPos-1-finL-1);
				finL--;
				isF = false;
				F = 0;
				if(finL > 0){
					F = code[finL];
					if(F == 's' ||	F == 'n' ||	F == 'g' ){
						isF = true;
						finL -= 3;
					}
				}
				l = getVal(currOper, arg);
				if(isF){
					switch(F){
					case 's': l = Math::Cos(l);
						break;
					case 'n': l = Math::Sin(l);
						break;
					case 'g': l = Math::Log(l);
						break;
					}
				}
			}
			else{
				currOper = "";
				for(int i = currPos-1; i >= 0; i--){
					if(allOp->IndexOf(code[i]) >= 0){
						finL = i;
						break;
					}
					if(i == 0){
						finL = -1;
						break;
					}
				}
				currOper = code->Substring(finL+1, currPos-1-finL);
				l = getVal(currOper, arg);
			}
			//result
			//double res = 0;
			String^ res = "";
			switch(operation){
			case '^': res = ParsingTools::evalf(Math::Pow(l,r));				break;
			case '*': res = ParsingTools::evalf(l*r);				break;
			case '-': res = ParsingTools::evalf(l-r);				break;
			case '+': res = ParsingTools::evalf(l+r);				break;
			case '/': res = ParsingTools::evalf(l/r);				break;
			}
			if(finL == -1)
				currOper = "";
			else 
				currOper = code->Substring(0, finL+1);
			currOper+= "(";
			//if(res < 0)
				//currOper+="=";
			if(res[0] == '-')
				res = "="+res->Substring(1);
			//currOper += ""+Math::Abs(res)+")";
			currOper += res+")";
			if(finR != code->Length)
				currOper += code->Substring(finR);
			code = currOper;
		}while(currPos >= 0);
		
	} 
	code = ParsingTools::delBrackets(code);
		try{
			if(code->Length > 3){
				if(code->StartsWith("sin")){
					return Math::Sin(getVal(code->Substring(4,code->Length-5), arg));
				}
				else if(code->StartsWith("cos")){
					return Math::Cos(getVal(code->Substring(4,code->Length-5), arg));
				}
				else if(code->StartsWith("log")){
					return Math::Log(getVal(code->Substring(4,code->Length-5), arg));
				}
			}
			if(code[0] == 'x'){
				int t = int::Parse(code->Substring(1));
				return arg[t-1];
			}
			else if(code[0] == '='){
				double t = double::Parse(code->Substring(1));
				return -t;
			}
			else{
				double t = double::Parse(code);;
				return t;
			}
		}
		catch(Exception^ e){	}
	return 0;
}