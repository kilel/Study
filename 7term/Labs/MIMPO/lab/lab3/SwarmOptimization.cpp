#include "SwarmOptimization.h"
#include "ParsingTools.h"

void copyArg(Arg ^b, Arg ^a){
	for(int i = 0; i < a->Length; i++)
		b[i] = a[i];
}

void SwarmOptimization::run(Object^ o){
	
	int numArgs = 2;
	Arg ^best = gcnew Arg(numArgs);
	int capacitySwarm = 5;
	array<Arg^>^ vel = gcnew array<Arg^>(capacitySwarm), 
		^currArg = gcnew array<Arg^>(capacitySwarm), 
		^bestArg = gcnew array<Arg^>(capacitySwarm);
	Random^ r = gcnew Random();
	log = "Начинаю решать задачу 1\nСгенерировал вектор начального положения и начальной скорости:\n";
	for(int i = 0 ; i < capacitySwarm; i ++){
		currArg[i] = gcnew Arg(numArgs);
		bestArg[i] = gcnew Arg(numArgs);
		vel[i] = gcnew Arg(numArgs);
		
		for(int j = 0; j < numArgs; j++){
			bestArg[i][j] = currArg[i][j] = r->NextDouble()*20 - 10;
			vel[i][j] = r->NextDouble()*2 - 1;
		}
		log += "\t" + ParsingTools::arrayToString(currArg[i]) + " Положение ["+i+"]\n";
		log += "\t" + ParsingTools::arrayToString(vel[i]) + " Скорость ["+i+"] частицы\n";
		if(i == 0) copyArg( best, currArg[i]);
		if(f(currArg[i]) < f(currArg[i]))
			copyArg( best, currArg[i]);
	}
	
	
	for(int stepCount = 0; stepCount < N; stepCount++){
		log += "Вычисляю положения частиц в следующий момент времени:\n";
		for(int i = 0 ; i < capacitySwarm; i ++){
			bool isOk=true;
			for(int j = 0; j < numArgs; j++){
				currArg[i][j] = currArg[i][j] + vel[i][j];
				if(Math::Abs(currArg[i][j]) > 10){
					currArg[i][j] = r->NextDouble()*20 - 10;
					vel[i][j] = r->NextDouble()*2 - 1;
				}
			}
			log += "x'["+i+"] = \t" + ParsingTools::arrayToString(currArg[i]) + " Значение ("+f(currArg[i])+")\n";
			if(f(currArg[i]) < f(bestArg[i])){
				copyArg( bestArg[i], currArg[i]);
			}
			if(f(currArg[i]) < f(best)){
				copyArg( best, currArg[i]);
			}
		}
		log += "Вычисляю скорости частиц в следующий момент времени:\n";
		for(int i = 0 ; i < capacitySwarm; i ++){
			bool isOk=true;
			for(int j = 0; j < numArgs; j++){
				vel[i][j] = vel[i][j] + c1*r->NextDouble()*(bestArg[i][j] - currArg[i][j]) + c2*r->NextDouble()*(best[j] - currArg[i][j]);
			}
			log += "v'["+i+"] = \t" + ParsingTools::arrayToString(vel[i]) + "\n";
		}
	}
	log += "\nВ итоге лучшая точка:\n";
	log += "\t" + ParsingTools::arrayToString(best) + " \nЗначение ("+f(best)+")\n";
	isCplt=true;
}
