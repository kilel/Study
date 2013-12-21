#include "MPToolsCore.h"

namespace MPTools{
	using namespace System::Diagnostics;
	ref class FSetWeightedPenatly{
	private:
		FSet^ problem;
		double k;
		WeightVector^ w;
	public:
		FSetWeightedPenatly(FSet^ problem, WeightVector^ w, double consBarier){
			this->problem = problem;
			k = consBarier;
			this->w = w;
		}
		double getValue(Line^ arg){
			double s = 0, t = 0;
			int n = problem->getNumCons();
			for(int i = 0; i < n; i++){
				t = problem->getCons(i, arg);
				s += t + Math::Abs(t);			
			}
			s = s*k + problem->getWeighted(w, arg);
			return s;
		}
		int getNumArgs(){return problem->getNumArgs();};
		double getArgMinValue(int i){ return problem->getArgMinValue(i);}
		double getArgMaxValue(int i){ return problem->getArgMaxValue(i);}
	};

	ref class AlienorArg{
	private:
		int numArgs;
		FSetWeightedPenatly^ problem;
	public:
		AlienorArg(FSetWeightedPenatly^ problem){
			this->numArgs = problem->getNumArgs();
			this->problem = problem;
		}
		Line^ getArg(double x){
			Line^ res = gcnew Line(numArgs);
			double a=0,b=0, phi = 2., psy = 0.5, cPhi = DELTA_PHI, cPsy = DELTA_PSI;
			//Задали медленно растущие phi и psy
			for(int i = 0; i < numArgs; i++){
				a = problem->getArgMinValue(i);
				b = problem->getArgMaxValue(i);
				res[i] = 0.5*(a + b + (a - b)*Math::Cos(phi*x + psy));
				phi += cPhi;
				psy += cPsy;
			}
			return res;
		}
	};

	ref class OPO{
	private:
		double x0, y0;
		FSetWeightedPenatly^ problem;
		AlienorArg^ alienor;
	public:
		OPO(FSetWeightedPenatly^ problem, AlienorArg^ alienor, double start){
			this->problem = problem;
			this->alienor = alienor;
			setStart(start);
		}
		double getValue(double x){
			//double y = problem->getValue(alienor->getArg(x)) - y0;
			//return ( 0.5*(y + Math::Abs(y)) );
			return problem->getValue(alienor->getArg(x));
		}
		void setStart(double x){
			x0 = x;
			y0 = problem->getValue(alienor->getArg(x0));
		}
		double getRoots(double accuracy){
			double best = 1000000000., res = 0;
			double y = 0;
			/*int count = 0;
			for(double x = 0; x < 2*3.1415926; x+= 0.01){
				y = getValue(x);
				if(Math::Abs(y) < 1e-10){
					count++;
					best = x;
				}
			}
			if(count == 1)
				return best;
			else 
				return -1;*/
			for(double x = 0; x < 30*3.1415926; x+= EPS){
				y = getValue(x);
				if(y < best){
					best = y;
					res = x;
				}
			}
			return res;
		}
	};

	ref class MPsolverAlienor : public MPsolver{
	public:
		MPsolverAlienor(FSet ^problem, double accuracy, WeightVector^ w) : MPsolver(problem, accuracy, w){
		}
		virtual void solve(Object^ o) override {
			Stopwatch^ time = gcnew Stopwatch();
			time->Start();
			points = gcnew array<PointF>(w->getCountWeight());
			int pCount = 0;
			FSetWeightedPenatly^ wProblem = gcnew FSetWeightedPenatly(problem, w, K);
			AlienorArg^ alienor = gcnew AlienorArg(wProblem);
			OPO^ opo = gcnew OPO(wProblem, alienor, 0);
			log += "\n\n\tМетод Alienor\n\n";
			while(true){
				
				double res = -1;
				res = opo->getRoots(accuracy);
				Line^ out = problem->getCrit(alienor->getArg(res));
				log += "Весовой вектор:\t" + w + "\n";
				log += "Точка: \t\t" + lineToString( out ) + "\n";
				log += "Критерий:\t" +lineToString( problem->getCrit(out) ) + "\n";
				points[pCount++] = PointF(out[0], out[1]);
				if(w->hasNext()){
					w->getNext();
					log += "\n";
				}
				else break;
			}
			time->Stop();
			log += "Время выполнения:\t" + time->ElapsedMilliseconds + " мс ";
			isDn = true;
		}
	}; 
	
	ref class MPsolverGrid : public MPsolver{
	public:
		MPsolverGrid(FSet ^problem, double accuracy, WeightVector^ w) : MPsolver(problem, accuracy, w){
		}
		virtual void solve(Object^ o) override {
			Stopwatch^ time = gcnew Stopwatch();
			time->Start();
			points = gcnew array<PointF>(w->getCountWeight());
			int pCount = 0;
			GridPiontSet^ pnt = gcnew GridPiontSet(problem);
			Line^ res, ^best;
			int numCons = problem->getNumCons();
			log += "\n\n\tМетод Сеток\n\n";
			while(true){
				pnt->clear();
				best = (Line^) pnt->point->Clone();
				while(pnt->hasNext()){
					res = pnt->next();
					bool b = true;
					for(int i = 0; i < numCons; ++i){
						if(problem->getCons(i, res) > 0){
							b = false;
							break;
						}
					}
					if(!b)
						continue;
					//else
					if(problem->getWeighted(w, res) < problem->getWeighted(w, best)){
						best = (Line^)res->Clone();
					}
				}
				log += "Весовой вектор:\t" + w + "\n";
				log += "Точка: \t\t" + lineToString( best ) + "\n";
				log += "Критерий:\t" +lineToString( problem->getCrit(best) ) + "\n";
				
				points[pCount++] =  PointF(problem->getCrit(0, best), problem->getCrit(1, best));
				if(w->hasNext()){
					w->getNext();
					log +=  "\n";
				}
				else break;
			}
			time->Stop();
			log += "Время выполнения:\t" + time->ElapsedMilliseconds + " мс ";
			isDn = true;
		}
	}; 

	ref class MPsolverMK : public MPsolver{
	private:
		Random^ r;
		Line^ getRandArg(){
			Line^ a = gcnew Line(problem->getNumArgs());
			for(int i = 0; i < problem->getNumArgs(); ++i)
				a[i] = r->NextDouble()*(problem->getArgMaxValue(i) - problem->getArgMinValue(i) ) + problem->getArgMinValue(i) ;
			return a;
		}
	public:
		MPsolverMK(FSet ^problem, double accuracy, WeightVector^ w) : MPsolver(problem, accuracy, w){
			r = gcnew Random();
		}
		virtual void solve(Object^ o) override {
			Stopwatch^ time = gcnew Stopwatch();
			time->Start();
			points = gcnew array<PointF>(w->getCountWeight());
			int pCount = 0;
			int co;
			Line^ res, ^best = getRandArg();
			log += "\n\n\tМетод Монте-Карло\n\n";
			int numCons = problem->getNumCons();
			while(true){
				co = 0;
				best = getRandArg();
				while(co++ < K){
					res = getRandArg();
					bool b = true;
					for(int i = 0; i < numCons; ++i){
						if(problem->getCons(i, res) > 0){
							b = false;
							break;
						}
					}
					if(!b)
						continue;
					//else
					if(problem->getWeighted(w, res) < problem->getWeighted(w, best)){
						best = (Line^)res->Clone();
					}
				}
				log += "Весовой вектор:\t" + w + "\n";
				log += "Точка: \t\t" + lineToString( best ) + "\n";
				log += "Критерий:\t" +lineToString( problem->getCrit(best) ) + "\n";

				points[pCount++] =  PointF(problem->getCrit(0, best), problem->getCrit(1, best));
				if(w->hasNext()){
					w->getNext();
					log +=  "\n";
				}
				else break;
			}
			time->Stop();
			log += "Время выполнения:\t" + time->ElapsedMilliseconds + " мс ";
			isDn = true;
		}
	}; 
}


