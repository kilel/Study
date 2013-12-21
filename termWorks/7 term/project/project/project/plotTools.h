#pragma once
#include <iostream>
#include <vector>
#define MSC 10

using namespace std;
using namespace System;
using namespace System::Drawing;
namespace plottools{
	typedef array<PointF> Line;
	typedef array<float> Radius;
	typedef array<Line^> LineArray;
	typedef array<int> LimArray;


	ref class plotTools{
	private:
		PointF centre, scale;
		Graphics^ g;
	
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
		LimArray^ limLine, ^limCurve, 
			^cacheLine, ^cacheCurve;
		Bitmap^ canvas;
		plotTools(int w, int h, int cx, int cy);
		~plotTools(void);
		void draw();
		Bitmap^ getCanvas();
		void setCanvas(int w, int h);
		void setCentre(int x, int y);
		void addLine(Line^ a, Pen^ p, int lim);
		void addCurve(Line^ a, Pen^ bm, int lim);
		void drawOverCurve(Line^ a, Pen^ bm, int start, int end);
		void addPoint(PointF p, float r, Brush^ b);
		void setScale(PointF s);
		void clearData();
		void clearCache(){
			for(int i = 0; i < cacheCurve->Length; i++){
				cacheCurve[i]=0;
			} 
			for(int i = 0; i < cacheLine->Length; i++){
				cacheLine[i]=0;
			}
		}
	
	};
};