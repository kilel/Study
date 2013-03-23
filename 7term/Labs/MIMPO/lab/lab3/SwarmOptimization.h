#pragma once
using namespace System;
typedef array<double> Arg;
ref class SwarmOptimization
{
	

private: 
	double f(Arg ^arg){ 
		double s1=0,s2=0; 
		for(int i = 1; i <= 5; i++){
			s1 += i*Math::Cos((i+1)*arg[0] + 1);
			s2 += i*Math::Cos((i+1)*arg[1] + 1);
		}
		return (s1*s2); 
	}
	double c1, c2;
	int N;
	String^ log;
	bool isCplt;
public: 
	SwarmOptimization(double c1, double c2, int nMax){
		this->c1 = c1; this->c2 = c2; this->N = nMax;log="";isCplt=false;
	}
	String^ getLog(){return log;}
	bool isComplete(){return isCplt;}
	void run(Object^ o);
}; 

