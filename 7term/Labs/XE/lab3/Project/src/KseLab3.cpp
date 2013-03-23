#include "KseLab3.h"

KseLab3::KseLab3(double a1, double a2, double b, double f, double ro, double x0, double y0, double endTime, double accuracy){
	this->a1 = a1;
	this->a2 = a2;
	this->b = b;
	this->f = f;
	this->ro = ro;
	this->endTime = endTime;
	this->accuracy = accuracy;
	addPerIter = 1/10./accuracy < 1 ? 1 : 1/10./accuracy;
	endIter = endTime*10;
	x = gcnew Line(static_cast<int>(endTime*10));
	y = gcnew Line(static_cast<int>(endTime*10));
	x[0].Y = x0;
	x[0].X = 0;
	y[0].Y = y0;
	y[0].X = 0;
	currIter = 1;
	isEndOfIter = true;
	isDone = false;
}

void KseLab3::run(Object^ o){
	while(!isDone){
		if(stopIterNum == endIter) isDone = true;
		for(;currIter < stopIterNum; currIter++)
			calcRK4(addPerIter);
	}
}



void KseLab3::calcRK4(int calcIter){
	//
	double tempx, tempy;
	tempx = x[currIter-1].Y;
	tempy = y[currIter-1].Y;
	
	double k[5][5] = {0};
	double tempT, tempX, tempY;
	double currTime = (endTime/endIter)*(currIter-1);
	x[currIter].X = (endTime/endIter)*(currIter);
	y[currIter].X = (endTime/endIter)*(currIter);
	for(int i = 0; i < calcIter; i++){
		tempX = tempx;
		tempY = tempy;
		
		k[1][1] = accuracy*f1(currTime + i*accuracy, tempX, tempY);
		k[2][1] = accuracy*f2(currTime + i*accuracy, tempX, tempY);
		///2 step
		tempX = tempx + 0.5*k[1][1];
		tempY = tempy + 0.5*k[2][1];
		
		k[1][2] = accuracy*f1(currTime + (i+0.5)*accuracy, tempX, tempY);
		k[2][2] = accuracy*f2(currTime + (i+0.5)*accuracy, tempX, tempY);
		///
		tempX = tempx + 0.5*k[1][2];
		tempY = tempy + 0.5*k[2][2];
		
		k[1][3] = accuracy*f1(currTime + (i+0.5)*accuracy, tempX, tempY);
		k[2][3] = accuracy*f2(currTime + (i+0.5)*accuracy, tempX, tempY);
		///
		tempX = tempx + k[1][3];
		tempY = tempy + k[2][3];
		
		k[1][4] = accuracy*f1(currTime + (i+1)*accuracy, tempX, tempY);
		k[2][4] = accuracy*f2(currTime + (i+1)*accuracy, tempX, tempY);
		///
		x[currIter].Y = tempx = tempx + (k[1][1] + k[1][2] + k[1][3] + k[1][4])/6.;
		y[currIter].Y = tempy = tempy + (k[2][1] + k[2][2] + k[2][3] + k[2][4])/6.;	
	}
}





/*
(sun)(sun)(sun)(sun)(heidy)(heidy)(sun)(sun)(heidy)(heidy)(sun)(sun)(heidy)(sun)(heidy)(heidy)(heidy)(sun)(sun)
(sun)(sun)(heidy)(heidy)(heidy)(heidy)(sun)(heidy)(heidy)(heidy)(sun)(heidy)(heidy)(sun)(sun)(heidy)(heidy)(sun)
(heidy)(heidy)(sun)(sun)(heidy)(heidy)(sun)(heidy)(heidy)(heidy)(sun)(heidy)(heidy)(sun)(sun)(sun)(heidy)(sun)
(heidy)(heidy)(heidy)(sun)(sun)(heidy)(sun)(sun)(heidy)(sun)(sun)(heidy)(heidy)(sun)(heidy)(sun)(sun)(sun)
(sun)(sun)(sun)(sun)(sun)(heidy)(sun)(sun)(sun)(sun)(sun)(heidy)(heidy)(sun)(heidy)(heidy)(sun)(sun)
*/ // insert to skype & get fun ^_^