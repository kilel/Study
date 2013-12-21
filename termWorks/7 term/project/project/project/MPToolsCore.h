using namespace System;


namespace MPTools{
	///
	double DELTA_PSI = 1, DELTA_PHI = 0.5, EPS = 0.1, M = 10, K = 10000;
	///

	typedef array<double> Line;

	String^ lineToString(Line^ l){
		String^ out = "(";
		for(int i = 0; i < l->Length; i++){
				if(i)
					out += ",  ";
				out += l[i];
			}
			out += ")";
			return out;
	}

	ref class WeightVector{
	private:
		Line^ outBuff;
		array<int>^ w;
		int numCrit, maxWeight;
		bool cached;
		void genNext(){
			if(!hasNext()) // 1 1 8
				return;
			cached = false;
			for(int i = 0; i < numCrit; i++){
				//if(w[0] != 1){ // 8 1 1 -> 7 2 1
				if(w[0] != 0){
					w[0]--;
					w[1]++;
					break;
				}
				//if(w[i] == 1) continue; // 1 6 3 -> 5 1 4
				if(w[i] == 0) continue;
				w[i+1]++;
				w[0] = w[i]-1;
				for(int j = 1; j <= i; j++)
					w[j] = 0; //1
				break;
			}
		}
		void fillOutBuff(){
			cached = true;
			for(int i = 0; i < numCrit; i++){
				outBuff[i] = (double) w[i]/maxWeight;
			}
		}
	public:
		int getCountWeight(){
			if(numCrit == 2)
				return maxWeight+1;
			
			else return 0;
			long long t = maxWeight - 1;
			for(int i = 2; i < numCrit; i++){
				t *= maxWeight - i + 1;
				t /= i;
			}
			return t;
		}
		WeightVector(int numCrit, int maxWeight){
			cached = false;
			//this->count = 0;
			//this->maxCount =  getCountWeight(numCrit, maxWeight);
			this->maxWeight = maxWeight;
			this->numCrit = numCrit;
			w = gcnew array<int>(numCrit);
			outBuff = gcnew Line(numCrit);
			w[0] = maxWeight; //- numCrit + 1;
			for(int i = 1; i < numCrit; i++)
				w[i] = 0; //1;
		}
		bool hasNext(){
			//if(w[numCrit-1] == maxWeight - numCrit + 1) 
			if(w[numCrit-1] == maxWeight) 
				return false; 
			else return true;
		}
		Line^ getNext(){
			genNext();
			return getCurr();
		}
		Line^ getCurr(){
			if(!cached) 
				fillOutBuff();
			return outBuff;
		}
		virtual String^ ToString() override{
			if(!cached) 
				fillOutBuff();
			String^ out = "(";
			for(int i = 0; i < numCrit; i++){
				if(i)
					out += "; ";
				out += outBuff[i];
			}
			out += ")";
			return out;
		}
		double operator[] (int i){
			if(!cached)
				fillOutBuff();
			return outBuff[i];
		}
	};
	
	ref class FSet{
	protected:
		int numCrit, numCons, numArgs;
		Line^ argMinValue, ^argMaxValue;
	public:
		FSet(int numCrit, int numCons, int numArgs){
			this->numCrit = numCrit;
			this->numCons = numCons;
			this->numArgs = numArgs;
			argMinValue = gcnew Line(numArgs);
			argMaxValue = gcnew Line(numArgs);
		}
		virtual double getCrit(int i, Line^ arg){return 0;}
		virtual double getCons(int i, Line^ arg){return 0;}
		Line^ getCrit(Line^ arg){
			Line^ ret = gcnew Line(numCrit);
			for(int i = 0; i < numCrit; i++)
				ret[i] = getCrit(i, arg);
			return ret;
		}
		int getNumCrit(){return numCrit;};
		int getNumCons(){return numCons;};
		int getNumArgs(){return numArgs;};
		virtual double getArgMinValue(int i){
			if(i < numArgs)
				return argMinValue[i];
			else return 0;
		}
		virtual double getArgMaxValue(int i){ 
			if(i < numArgs)
				return argMaxValue[i];
			else return 0;
		}
		double getWeighted(WeightVector^ w, Line^ arg){
			double s = 0;
			for(int i = 0; i < numCrit; i++){
				s += getCrit(i, arg)*w[i];
			}
			return s;
		}
	};

	ref class MPsolver{
	protected: 
		FSet ^problem;
		double accuracy;
		WeightVector^ w;
		String^ log;
		bool isDn;
	public:
		array<PointF>^ points;
		MPsolver(FSet ^problem, double accuracy, WeightVector^ w){
			this->problem = problem;
			this->accuracy = accuracy;
			this->w = w;
			isDn=false;
			log = "";
		}
		virtual void solve(Object^ o){}
		bool isDone(){return isDn;}
		String^ getLog(){return log;}
	};

	ref class GridPiontSet{
	private:
		FSet^ problem;
		bool isEnd;
		void tryAdd(int i){
			if(i >= problem->getNumArgs()){
				isEnd = true;
				return;
			}
			point[i] += EPS;
			if(point[i] > problem->getArgMaxValue(i)){
				point[i] = problem->getArgMinValue(i);
				tryAdd(i+1);
			}
		}
	public: 
		Line^ point;
		GridPiontSet(FSet^ problem){
			this->problem = problem;
			point = gcnew Line(problem->getNumArgs());
			clear();
		}
		bool hasNext(){return !isEnd;}
		Line^ next(){
			if(isEnd)
				return point;
			tryAdd(0);
			return point;
		}
		void clear(){
			for(int i = 0; i < point->Length; ++i)
				point[i] = problem->getArgMinValue(i);
			isEnd = 0;
		}
	};

	ref class FSetZizler : public FSet{
	public:
		FSetZizler(int numArgs) : FSet(2,0,numArgs){
		}
		virtual double getCrit(int i, Line^ arg) override{
			switch (i){
			case 0: return arg[0];
			case 1: 
				double s = 0;
				for(int i = 1; i < arg->Length; i++)
					s += arg[i];
				s = s*9./(arg->Length - 1) + 1;
				return ( s*(1- Math::Sqrt(arg[0]/s) ) );
			}
		}
		virtual double getCons(int i, Line^ arg) override{
			return 0;
		}
		virtual double getArgMinValue(int i) override { return 0;}
		virtual double getArgMaxValue(int i) override { return 1;}
	};
	ref class FSetBIHNKORN : public FSet{
	public:
		FSetBIHNKORN(int numArgs) : FSet(2,2,numArgs){
			argMinValue = gcnew Line(this->numCons);
			argMinValue[0] = 0;
			argMinValue[1] = 0;
			argMaxValue = gcnew Line(this->numCons);
			argMaxValue[0] = 5;
			argMaxValue[1] = 3;

		}
		virtual double getCrit(int i, Line^ arg) override{
			switch (i){
			case 0: return 4*(arg[0]*arg[0] + arg[1]*arg[1]);
			case 1: return ((arg[0]-5)*(arg[0]-5) + (arg[1]-5)*(arg[1]-5));
			}
		}
		virtual double getCons(int i, Line^ arg) override{
			switch (i){
			case 0: return (arg[0]-5)*(arg[0]-5) + arg[1]*arg[1] - 25;
			case 1: 7.7 - (arg[0]-8)*(arg[0]-8) - (arg[1]+3)*(arg[1]+3);
			}
		}
		virtual double getArgMinValue(int i) override { return argMinValue[i];}
		virtual double getArgMaxValue(int i) override { return argMaxValue[i]; }
	};
		ref class FSetOsyczkaKundu : public FSet{
	public:
		FSetOsyczkaKundu(int numArgs) : FSet(2,6,numArgs){
			argMinValue = gcnew Line(this->numCons);
			argMinValue[0] = 0;
			argMinValue[1] = 0;
			argMinValue[2] = 1;
			argMinValue[3] = 0;
			argMinValue[4] = 1;
			argMinValue[5] = 0;
			argMaxValue = gcnew Line(this->numCons);
			argMaxValue[0] = 10;
			argMaxValue[1] = 10;
			argMaxValue[2] = 5;
			argMaxValue[3] = 6;
			argMaxValue[4] = 5;
			argMaxValue[5] = 10;
		}
		virtual double getCrit(int i, Line^ arg) override{
			switch (i){
			case 0: return (Math::Pow((arg[0]-2), 2) - Math::Pow((arg[1]-2), 2) - Math::Pow((arg[2]-1), 2) - Math::Pow((arg[3]-4), 2) - Math::Pow((arg[4]-1), 2) );
			case 1: return (Math::Pow((arg[0]), 2) +  Math::Pow((arg[1]), 2) + Math::Pow((arg[2]), 2) + Math::Pow((arg[3]), 2) + Math::Pow((arg[4]), 2) + Math::Pow((arg[5]), 2));
			}
		}
		virtual double getCons(int i, Line^ arg) override{
			switch (i){
			case 0: return 2 - arg[0] - arg[1];
			case 1: return arg[0] + arg[1] - 6;
			case 2: return arg[0] + arg[1] - 2;
			case 3: return arg[0] - 3*arg[1] - 2;
			case 4: return arg[3] + Math::Pow(arg[2]-3, 2) - 4;
			case 5: return 4 - arg[5] - Math::Pow(arg[4]-3, 2);
			}
		}
		virtual double getArgMinValue(int i) override { return argMinValue[i];}
		virtual double getArgMaxValue(int i) override { return argMaxValue[i]; }
	};
};


