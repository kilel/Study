#pragma once
using namespace System;
typedef array<double> Arg;


ref class OptimizationProblem
{
public:
	private: 
	double f(double x, double y){
		Arg^ a = gcnew Arg(2);
		a[0] = x; a[1] = y;
		return f(a);
	}
	double f(Arg ^arg){ 
		double a[3][3] = {{0, 1, 0.4}, {0.7, 0.6, 0.4}, {.3, .3, .6}}, 
			b[3][3] = {{.8, .6, .9}, {0.1, 0, .6}, {.5, .2, .6}},
			c[3][3] = {{1, .3, .5}, {1, .4, 1}, {.9, .2, .8}},
			d[3][3] = {{.1, .6, 0}, {.6, .5, .6}, {.7, .3, .9}};
		double s1=0,s2=0, pi = 3.141592653589793238462643383275; 
		for(int i = 1; i <= 3; i++){
			for(int j = 1; j <= 3; j++){
				s1 += a[i][j]*Math::Sin(i*pi*arg[0])*Math::Sin(j*pi*arg[1]) + 
					b[i][j]*Math::Cos(i*pi*arg[0])*Math::Cos(j*pi*arg[1]);
				s1 += c[i][j]*Math::Sin(i*pi*arg[0])*Math::Sin(j*pi*arg[1]) + 
					d[i][j]*Math::Cos(i*pi*arg[0])*Math::Cos(j*pi*arg[1]);
			}
		}
		return Math::Sqrt(s1*s1 + s2*s2); 
	}
	double c1, c2;
	int N;
	String^ log;
	bool isCplt;
public: 
	OptimizationProblem(double c1, double c2, int nMax){
		this->c1 = c1; this->c2 = c2; this->N = nMax;log="";isCplt=false;
	}
	String^ getLog(){return log;}
	bool isComplete(){return isCplt;}
	void run(Object^ o);
};

