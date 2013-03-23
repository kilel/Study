#include "ParsingTools.h"


int ParsingTools::getBracketEnd(String^ code, int start){
	int k = 0, delta = 1;
	char here = code[start], alt = '(';
	if(here == '('){
		alt = ')';
		delta = 1;
	}
	else{
		alt = '(';
		delta = -1;
	}
	for(int i = start+delta; i >= 0 && i < code->Length ; i+= delta){
		if( k == 0 && code[i] == alt){
			return i;
		}
		else if(code[i] == alt)
			k--;
		else if(code[i] == here)
			k++;
	}
	
	return -1;
}
String^ ParsingTools::delSpaces(String^code){
	int l = code->Length;
	for(int i = 0; i < l; i++){
		if(code[i] == ' '|| code[i] == '\t' || code[i] == '\r' || code[i] == '\n'){
			if(i != l-1)
					code = code->Substring(0,i)+code->Substring(i+1);
			else
				code = code->Substring(0,i);
			l--;
			i--;
			continue;
		}
	}
	return code;
}
String^ ParsingTools::evalf(double a){
	/*int integer = (int) a;
	a = a-integer;
	a = ((int)(a*10000))/10000.;
	return (  a+integer    );*/
	String^ s = "";
	if(a < 0)
		s+= "-";
	a = Math::Abs(a);
	
	int integer = (int) a;
	if(integer < 0) integer = 0;
	a = a-integer;
	int j = (a*10000000.);
	if(j < 0) j=0;
	s +=integer+".";
	for(int i = 1000000; i > 1; i/=10)
		if(j < i)
			s+= "0";
	s += j;
	return (s);
}
String^ ParsingTools::delBrackets(String^ code){
	while(code[0] == '(' && code[code->Length-1] == ')'){
		int end = getBracketEnd(code, 0);
		if(end == code->Length-1){
			code = code->Substring(1, end-1);
		}
		else
			break;
	}
	return code;	
}
String^ pointEvalf(double a){
	String^ s = "";
	if(a < 0)
		s = "-";
	a = Math::Abs(a);
	int integer = (int) a;
	a = a-integer;
	s = s+integer + ".";
	int  j = ((int)(a*10000));
	if(j < 1000)
		s+="0";
	if(j < 100)
		s += "0";
	if(j < 10)
		s+="0";
	s+= j;
	return (  s );
}
String^  ParsingTools::arrayToString(array<double>^ a){
	String^ s = "[";
	for(int i = 0; i < a->Length; i++){
		if(i < a->Length - 1)
			s+= " "+pointEvalf(a[i])+"; ";
		else
			s+= pointEvalf(a[i])+"]";
	}
	return s;
}