#include "plotTools.h"
namespace plottools{
	plotTools::plotTools(int w, int h, int cx, int cy)
	{
		setCanvas(w,h);
		scale =  PointF(1,1);
		centre =  PointF(cx,cy);
		line = gcnew LineArray(0);
		curve = gcnew LineArray(0);
		radius = gcnew Radius(0);
		points = gcnew Line(0);
		pensCurve = gcnew array<Pen^>(0);
		pensLine = gcnew array<Pen^>(0);
		brushesPoints = gcnew array<Brush^>(0);
		limLine = gcnew LimArray(0);
		limCurve = gcnew LimArray(0);
		cacheCurve = gcnew LimArray(0);
		cacheLine = gcnew LimArray(0);
	
	}
	void plotTools::setCanvas(int w, int h){
		if(canvas)
			delete canvas;
		if(g)
			delete g;
		canvas = gcnew Bitmap(w,h);
		g = g->FromImage(canvas);
	}
	plotTools::~plotTools(void)
	{
	}

	void plotTools::drawCoord(){
		PointF s = getPointFromReal( PointF(0,0));
		int bottom = canvas->Height - 20, left = 20, right = canvas->Width - 20, top = 20;
		Font ^f = gcnew Font("Microsoft Sans Serif",10.,GraphicsUnit::Pixel);
	
		Pen ^pBlack = Pens::Black;
		Brush ^bBlack = Brushes::Black;

		g->DrawLine(pBlack, left-5, bottom, right, bottom);
		g->DrawLine(pBlack, left, bottom+5, left, top);
		for(int i = 20; i < right; i+=40){
			g->DrawString(""+evalf(getRealFromPoint( PointF(i,bottom)).X, 2),	f, bBlack, i, bottom);
		}
		for(int i = 20; i < bottom; i+=40){
			g->DrawString(""+evalf(getRealFromPoint( PointF(left, i)).Y, 2),	f, bBlack, left, i);
		}

		g->DrawEllipse(pBlack, s.X-3, s.Y-3, 6.,6.);
	}

	double plotTools::evalf(double p, int n){
		int t = p*Math::Pow(10,n);
		p = t/Math::Pow(10,n);
		return p;
	}

	PointF plotTools::getPointFromReal(PointF real){
		return  PointF(centre.X + MSC*(real.X)*scale.X, centre.Y - MSC*(real.Y)*scale.Y);
	}
	PointF plotTools::getRealFromPoint(PointF point){
		return  PointF((double)(point.X - centre.X)/scale.X/MSC, -(-centre.Y + point.Y)/scale.Y/MSC);
	}
	void plotTools::setCentre(int x, int y){ centre.X += x; centre.Y += y;}
	void plotTools::draw(){
		g->Clear(Color::White);
		drawCoord();
		drawCurves();
		drawLines();
		drawPoints();
	}

	void plotTools::drawCurves(){
		array<PointF> ^temp = gcnew array<PointF>(0);
		for(int i = 0; i < curve->Length; i++){
			/*if(limCurve[i] > 1000){
				temp->Resize(temp,100);
				for(int j = 0; j < temp->Length; j++)
					temp[j] = getPointFromReal( curve[i][j*(limCurve[i]/100.)] );
			}
			else*/{
				temp->Resize(temp,limCurve[i]);
				for(int j = cacheCurve[i]; j < limCurve[i]; j++)
					temp[j] = getPointFromReal( curve[i][j] );
			}
			try{
				g->DrawCurve(pensCurve[i], temp);
			}
			catch(...){;}
		}
		delete temp;
	}
	void plotTools::drawOverCurve(Line^ a, Pen^ bm, int start, int end){
		array<PointF> ^temp = gcnew array<PointF>(0);
		temp->Resize(temp,end-start);
		for(int j = 0; j < end-start; j++)
			temp[j] = getPointFromReal( a[start+j] );
		
		try{
			g->DrawCurve(bm, temp);
		}
		catch(...){;}
	
		delete temp;
	}
	void plotTools::drawLines(){
		array<PointF> ^temp = gcnew array<PointF>(0);
		for(int i = 0; i < line->Length; i++){
			/*if(limLine[i] > 1000){
				temp->Resize(temp,100);
				for(int j = 0; j < temp->Length; j++)
					temp[j] = getPointFromReal( line[i][j*(limLine[i]/100.)] );
			}
			else*/{
				temp->Resize(temp,limLine[i]);
				for(int j = cacheLine[i]; j < limLine[i]; j++)
					temp[j] = getPointFromReal( line[i][j] );
			}
			try{
				g->DrawLines(pensLine[i], temp);
			}
			catch(...){;}
		}
		delete temp;
	}
	void plotTools::drawPoints(){
		for(int i = 0; i < points->Length; i++){
			g->FillEllipse(brushesPoints[i], RectangleF( getPointFromReal( points[i]).X - radius[i]*MSC*scale.X, getPointFromReal( points[i]).Y - radius[i]*MSC*scale.X, radius[i]*2*MSC*scale.X, radius[i]*2*MSC*scale.Y));
		}
	}
	void plotTools::clearData(){
		curve->Resize(curve,0);
		line->Resize(line,0);
		points->Resize(points,0);
		brushesPoints->Resize(brushesPoints,0);
		pensCurve->Resize(pensCurve,0);
		pensLine->Resize(pensLine, 0);
	}

	void plotTools::addToArray(LineArray ^a, Line ^b){
		a->Resize(a, a->Length+1);
		a[a->Length-1] = gcnew Line(b->Length);
		for(int i = 0; i < b->Length; i++)
			a[a->Length-1][i] = getPointFromReal( b[i] );
	}
	template<class T>
	void addToArray(array<T> ^a, T b){
		a->Resize(a, a->Length+1);
		a[a->Length-1] = b;
	}
	void plotTools::addCurve(Line ^a, System::Drawing::Pen ^p, int lim){
		curve->Resize(curve, curve->Length+1);
		curve[curve->Length-1] = gcnew Line(a->Length);
		for(int i = 0; i < a->Length; i++)
			curve[curve->Length-1][i] =  a[i] ;
		limCurve->Resize(limCurve, curve->Length);
		limCurve[curve->Length-1] = lim;
		cacheCurve->Resize(cacheCurve, curve->Length);
		cacheCurve[curve->Length-1] = 0;

		pensCurve->Resize(pensCurve, pensCurve->Length+1);
		pensCurve[pensCurve->Length-1] = p;
	}
	void plotTools::addLine(Line ^a, System::Drawing::Pen ^p, int lim){
		line->Resize(line, line->Length+1);
		line[line->Length-1] = gcnew Line(a->Length);
		for(int i = 0; i < a->Length; i++)
			line[line->Length-1][i] =  a[i] ;
		limLine->Resize(limLine, line->Length);
		limLine[line->Length-1] = lim;
		cacheLine->Resize(cacheLine, line->Length);
		cacheLine[line->Length-1] = 0;


		pensLine->Resize(pensLine, pensLine->Length+1);
		pensLine[pensLine->Length-1] = p;
	}
	void plotTools::addPoint(System::Drawing::PointF p, float r, System::Drawing::Brush ^b){
		/*addToArray(points, p);
		addToArray(radius,r);
		addToArray(brushesPoints,b);*/
		points->Resize(points, points->Length+1);
		points[points->Length-1] = p;

		radius->Resize(radius, radius->Length+1);
		radius[radius->Length-1] = r;

		brushesPoints->Resize(brushesPoints, brushesPoints->Length+1);
		brushesPoints[brushesPoints->Length-1] = b;
	}
	Bitmap^ plotTools::getCanvas(){ 
		return canvas; 
	}

	void plotTools::setScale(PointF s){
		scale = s;
	}

};