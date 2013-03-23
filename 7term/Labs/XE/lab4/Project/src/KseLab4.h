#pragma once
#include "plotTools.h"
ref class KseLab3
{
private:
	double a1, a2, c1, c2, b12, b21, x10, x20;
	double endTime, accuracy;
	int addPerIter, currIter, endIter;
	int stopIterNum;
	void calcRK4(int calcIter);
	double f1(double t, double x1, double x2){
		return a1*x1 + b12*x1*x2 - c1*x1*x1;
	}
	double f2(double t, double x1, double x2){
		return a2*x2 + b21*x1*x2 - c2*x2*x2;
	}
public:
	Line ^x1, ^x2, ^N;
	KseLab3::KseLab3(double a1, double a2, double b12, double b21, double c1, double c2, double x10, double x20, double endTime, double accuracy);
	bool addStopIter(int value){ stopIterNum = stopIterNum + value > endIter ? endIter : stopIterNum + value; if(stopIterNum == endIter) return true; else return false;}
	int getCurrIter(){return currIter;}
	void run(Object^ o);
	bool isEndOfIter, isDone;
};

