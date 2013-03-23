#pragma once
#include "plotTools.h"
ref class KseLab3
{
private:
	double a1, a2, b, f, ro;
	double endTime, accuracy;
	int addPerIter, currIter, endIter;
	int stopIterNum;
	void calcRK4(int calcIter);
	double f1(double t, double x, double y){
		return y;
	}
	double f2(double t, double x, double y){
		return (f*Math::Cos(ro*t) - b*y - a1*x - a2*x*x);
	}
public:
	Line ^x, ^y;
	KseLab3(double a1, double a2, double b, double f, double ro, double x0, double y0, double endTime, double accuracy);
	bool addStopIter(int value){ stopIterNum = stopIterNum + value > endIter ? endIter : stopIterNum + value; if(stopIterNum == endIter) return true; else return false;}
	int getCurrIter(){return currIter;}
	void run(Object^ o);
	bool isEndOfIter, isDone;
};

