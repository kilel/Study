#include "Automat.h"
using namespace System;
namespace Problems4{
	ref class PEnv{//environment
	private:
		Random^ r;
	public:
		PEnv(double p1, double p2){
			p  = gcnew array<double>(3);
			p[1] = p1;
			p[2] = p2;
			r = gcnew Random();
		}
		int getS(int f){
			if(r->NextDouble() < p[f])
				return 1;
			else return -1;
		}
		array<double> ^ p;
	};
	
	ref class Problem4{
		private:
			Random^ r;
			int vote(){
				int count = 0;
				for each(Automat^ a in automats)
					if(a->getF() == 1)
						count++;
				if(count > automats->Length/2)
					return 1;
				else return 2;
			}
		public:
			array<Automat^>^ automats;
			PEnv^ env;
			int numSteps, step;
			bool isDne;
			Problem4(double p1, double p2, AutomatType type, int numAutomats, int numStates, int numSteps){
				isDne = false;
				r = gcnew Random();
				this->env = gcnew PEnv(p1, p2);
				automats = gcnew array<Automat^>(numAutomats*2 + 1);
				for (int i = 0; i < automats->Length; i++)
					automats[i] = gcnew Automat(numStates, type, r->Next(numStates*2 - 1) + 1);
				this->numSteps = numSteps;
				step = 0;
				
			}
			
			void nextStep(){
				if(!hasNext())
					return;
				///one signal for all automats
				int s = env->getS(vote());
				for (int i = 0; i < automats->Length; i++)
					automats[i]->changeState(s, r->NextDouble());
				///
				step++;
				if(!hasNext())
					isDne = true;
			}
			bool hasNext(){
				if(step == numSteps)
					return false;
				else return true;
			}
			bool isDone(){ return isDne;	}
	};

	
	
	ref class OutputWriter{
	private:
		Problem4^ problem;
	public:
		OutputWriter(Problem4^ problem){
			this->problem = problem;
		}
		virtual String^ ToString() override {
			String^ out = "";
			double avgM = 0;
			//header
			out += "n\t\tM\t\tNf1\t\tNf2\n";
			for(int i = 0; i < problem->automats->Length; i++){
				double M = 0, nn[3], N;
				int n[3];
				N = problem->numSteps;
				n[1] = problem->automats[i]->count[1]; nn[1] = n[1]/N;
				n[2] = problem->automats[i]->count[2]; nn[2] = n[2]/N;
				M = problem->env->p[1]*nn[1] + problem->env->p[2]*nn[2];
				avgM += M;
				out += ""+ (i+1) + "\t\t" + M + "\t\t" + n[1] + "\t\t" + n[2] + "\n";
			}
			double p = 0;
			for(int i = 1; i < problem->env->p->Length; i++)
					p += problem->env->p[i];
			p = p/(problem->env->p->Length-1);
			avgM /= problem->automats->Length;
			out += "\navgM = "+avgM +"\nM = "+ p;
			return out;
		}
	};
};