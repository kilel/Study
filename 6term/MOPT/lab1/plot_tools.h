#define pi 3.14159265358979323

using namespace System;
	
	using namespace System::Drawing;
	int Width, Height;
	Point c = Point(200,200);
	double mx=10, my=10;
	double m = 15;
	

	void set_centre(Point p)
	{
		c = p;
	}
	void set_scale(double px, double py, double pm)
	{
		mx = px;
		my = py;
		m = pm;
	}
	void mult_scale(double px, double py, double pm)
	{
		mx *= px;
		my *= py;
		m *= pm;
	}
	double evalf(double d)
	{
		return ((double)((int)(d*100))/100);
	}
	void draw_array(array<double>^ x, array<double>^ y, Graphics^ g)
	{//отрисовка массива точек
		double cx,cy;
		if(c.X > 20 && c.X < Width - 20)
			cx = c.X;
		else if(c.X >= Width - 21)
			cx = Width - 20;
		else 
			cx = 20;

		if(c.Y > 20 && c.Y < Height - 20)
			cy = c.Y;
		else if(c.Y >= Height - 21)
			cy = Height - 20;
		else 
			cy = 20;
		for(int i = 0; i < x->Length; i++)
			g->DrawEllipse(Pens::Blue, cx + x[i]*m*10/mx - 2, cy - y[i]*m*10/my - 2 , 4, 4);
		//pic->Image = canvas;
	}
	void draw_coord(Graphics^ g, int Width, int Height, Font^ f)
	{//отрисовка осей
		//m = 22;
		::Width = Width;
		::Height = Height;
		double x,y;
		if(c.X > 20 && c.X < Width - 20)
			x = c.X;
		else if(c.X >= Width - 21)
			x = Width - 20;
		else 
			x = 20;
		g->DrawLine(Pens::Black, x, Width - 40, x, 10); 
		g->DrawLine(Pens::Black, x + 5, 20, x, 10);
		g->DrawLine(Pens::Black, x - 5, 20, x, 10);
		//
		if(c.Y > 20 && c.Y < Height - 20)
			y = c.Y;
		else if(c.Y >= Height - 21)
			y = Height - 20;
		else 
			y = 20;
		g->DrawLine(Pens::Black, 10, y, Width - 20, y);
		g->DrawLine(Pens::Black, Width - 30, y + 5, Width - 20, (double)y);
		g->DrawLine(Pens::Black, Width - 30, y - 5, Width - 20, (double)y);
		for(int i = (-x/m)*2; i <= 2*(Width-x)/m; i++)
		{
			g->DrawString(""+evalf(2*i*mx/10),f, Brushes::Black, x + 2*i*m + 5, y + 7); 
			g->DrawLine(Pens::Black, (double)(x + i*m), y + 2,(double) x +i*m, (int)(y - 2));
			g->DrawLine(Pens::Black, x + 2*i*m, y + 4, x + 2*i*m, (int)y - 4);
			
		}
		for(int i = - y/m; i <= (Width-y)/m; i++)
		{
			if(i)
			g->DrawString(""+evalf(2*i*(-my/10.)),f, Brushes::Black, x +4 , y + 2*i*m + 5); 
			g->DrawLine(Pens::Black, x + 2, y + 2*i*m, (int)x - 2, y + 2*i*m);
		}
		//pic->Image = canvas;
	}
	void draw_polinom(array<double>^x,array<double>^p, int s, int f, Pen ^pen,Graphics^ g)
	{//отрисовка полинома
		double temp;
		int l = 2;
		array<Point>^res = gcnew array<Point>(l);
		for(int i = 0; i < l; i++)
			res[i].X = c.X + (x[s]+ i*(x[f]-x[s]))*m*10/mx;
		for(int i = 0; i < l; i++)
		{
			temp = 0;
			for(int  j = 0; j < p->Length; j++)
				temp = temp + Math::Pow(x[s]+ i*(x[f]-x[s]), j)*p[j];
			res[i].Y = c.Y - temp*m*10/my;
		}
		g->DrawLines(pen, res);
		//pic->Image = canvas;
	}

	void draw_func(array<double>^ x, array<double>^ y, Graphics^ g, Pen^ p)
	{
		double cx,cy;
		if(c.X > 20 && c.X < Width - 20)
			cx = c.X;
		else if(c.X >= Width - 21)
			cx = Width - 20;
		else 
			cx = 20;

		if(c.Y > 20 && c.Y < Height - 20)
			cy = c.Y;
		else if(c.Y >= Height - 21)
			cy = Height - 20;
		else 
			cy = 20;
		int n = y->Length;
		if(n > 100)
		for(int i = 0; i+n/20. < n; i+=n/20.)
			g->DrawLine(p, (int)(cx + (double)x[i]*m*10/mx), cy - y[i]*m*10/my, cx+ x[i+n/20.]*m*10/mx, cy - y[i+n/20.]*m*10/my);
		else
			for(int i = 0; i < n-1; i++)
				g->DrawLine(p, (int)(cx + (double)x[i]*m*10/mx), cy - y[i]*m*10/my, cx+ x[i+1]*m*10/mx, cy - y[i+1]*m*10/my);
	}