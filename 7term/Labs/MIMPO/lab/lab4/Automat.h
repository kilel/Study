
namespace Problems4{
	enum AutomatType{
		robbins,
		krinsky,
		waisbord
	};

	ref class Automat{
	private:
		
		AutomatType type;
		int getNextStateRobbins(int signal){
			int nextState = 0;
			if(signal < 0){
				if(state == numStates/2)
					nextState = numStates;
				else if(state == numStates/2 + 1)
					nextState = 1;
				else if(getF() == 1)
					nextState = state + 1;
				else 
					nextState = state - 1;
			}
			else{
				if(getF() == 1)
					nextState = 1;
				else
					nextState = numStates;
			}
			return nextState;
		}
		int getNextStateKrinsky(int signal){
			int nextState = 0;
			if(signal < 0){
				if(getF() == 1)
					nextState = state + 1;
				else 
					nextState = state - 1;
			}
			else{
				if(getF() == 1)
					nextState = 1;
				else
					nextState = numStates;
			}
			return nextState;
		}
		int getNextStateWaisbord(int signal, double p){
			int nextState = 0;
			if(signal > 0){
				if(state == 1 || state == numStates)
					nextState = state;
				else if(getF() == 1)
					nextState = state - 1;
				else 
					nextState = state + 1;
			}
			else{
				if(getF() == 1){
					if(state != numStates/2)
						nextState = state + 1;
					else{
						if(p > 0.5)
							nextState = state + 1;
						else 
							nextState = state;
					}
				}
				else{
					if(state != numStates/2 + 1)
						nextState = state - 1;
					else{
						if(p > 0.5)
							nextState = state - 1;
						else 
							nextState = state;
					}
				}
			}
			return nextState;
		}
	public:
		Automat(int numStates, AutomatType type, int St){
			count = gcnew array<int>(3);
			count[1] = 0;
			count[2] = 0;
			this->numStates = numStates*2;
			state = St;
			this->type = type;
		}
		virtual void changeState(int signal, double p){
			int nextState=0;
			switch(type){
			case AutomatType::robbins: 
				nextState = getNextStateRobbins(signal);
				break;
			case AutomatType::krinsky:
				nextState = getNextStateKrinsky(signal);
				break;
			case AutomatType::waisbord:
				nextState = getNextStateWaisbord(signal, p);
				break;
			}
			state = nextState;
			count[getF()]++;
		};
		int getF(){
			return  (state < numStates/2) ? 1 : 2;
		}
		int state, numStates;
		array<int> ^count;
	};
};