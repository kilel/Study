#pragma once
#include <iostream>
#include <vector>
#define MSC 10

using namespace std;
using namespace System;
using namespace System::Drawing;

typedef array<PointF> Line;
typedef array<float> Radius;
typedef array<Line^> LineArray;
typedef array<int> LimPrintArray;


ref class plotTools{
private:
	PointF centre, scale;
	Graphics^ g;
	Bitmap^ canvas;
	array<Pen^> ^pensLine, ^pensCurve;
	array<Brush^> ^brushesPoints;
	void drawCoord();
	void drawLines();
	void drawCurves();
	void drawPoints();
	PointF getPointFromReal(PointF real);
	PointF getRealFromPoint(PointF point);
	double evalf(double p, int n);
	void addToArray(LineArray ^a, Line ^b);
	
public:
	Line ^points;
	Radius ^radius;
	LineArray ^line, ^curve;
	LimPrintArray^ limLime, ^limCurve;

	plotTools(int w, int h, int cx, int cy);
	~plotTools(void);
	void draw();
	Bitmap^ getCanvas();
	void setCanvas(int w, int h);
	void setCentre(int x, int y);
	void addLine(Line^ a, Pen^ p, int lim);
	void addCurve(Line^ a, Pen^ bm, int lim);
	void addPoint(PointF p, float r, Brush^ b);
	void setScale(PointF s);
	void clearData();
	
};
