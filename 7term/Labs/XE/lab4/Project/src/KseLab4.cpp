#include "KseLab4.h"

KseLab3::KseLab3(double a1, double a2, double b12, double b21, double c1, double c2, double x10, double x20, double endTime, double accuracy){
	this->a1 = a1;
	this->a2 = a2;
	this->c1 = c1;
	this->c2 = c2;
	this->b12 = b12;
	this->b21 = b21;
	this->x10 = x10;
	this->x20 = x20;
	this->endTime = endTime;
	this->accuracy = accuracy;
	addPerIter = 1/10./accuracy < 1 ? 1 : 1/10./accuracy;
	endIter = endTime*10;
	x1 = gcnew Line(static_cast<int>(endTime*10));
	x2 = gcnew Line(static_cast<int>(endTime*10));
	N = gcnew Line(static_cast<int>(endTime*10));
	x1[0].Y = x10;
	x1[0].X = 0;
	x2[0].Y = x20;
	x2[0].X = 0;
	N[0].X = x10;
	N[0].Y = x20;
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
	tempx = x1[currIter-1].Y;
	tempy = x2[currIter-1].Y;
	
	double k[5][5] = {0};
	double tempT, tempX, tempY;
	double currTime = (endTime/endIter)*(currIter-1);
	x1[currIter].X = (endTime/endIter)*(currIter);
	x2[currIter].X = (endTime/endIter)*(currIter);
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
		x1[currIter].Y = tempx = tempx + (k[1][1] + k[1][2] + k[1][3] + k[1][4])/6.;
		x2[currIter].Y = tempy = tempy + (k[2][1] + k[2][2] + k[2][3] + k[2][4])/6.;
		N[currIter].X = tempx;
		N[currIter].Y = tempy;
	}
}





/*
(sun)(sun)(sun)(sun)(heidy)(heidy)(sun)(sun)(heidy)(heidy)(sun)(sun)(heidy)(sun)(heidy)(heidy)(heidy)(sun)(sun)
(sun)(sun)(heidy)(heidy)(heidy)(heidy)(sun)(heidy)(heidy)(heidy)(sun)(heidy)(heidy)(sun)(sun)(heidy)(heidy)(sun)
(heidy)(heidy)(sun)(sun)(heidy)(heidy)(sun)(heidy)(heidy)(heidy)(sun)(heidy)(heidy)(sun)(sun)(sun)(heidy)(sun)
(heidy)(heidy)(heidy)(sun)(sun)(heidy)(sun)(sun)(heidy)(sun)(sun)(heidy)(heidy)(sun)(heidy)(sun)(sun)(sun)
(sun)(sun)(sun)(sun)(sun)(heidy)(sun)(sun)(sun)(sun)(sun)(heidy)(heidy)(sun)(heidy)(heidy)(sun)(sun)
*/ // insert to skype & get fun ^_^