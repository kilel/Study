#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <algorithm>
/**
	@var meth: 0 -- adaptive, 1 -- with ret, 3 --best shoot
**/
#define ALP 1.2
#define BTA 0.4
#define N 20
#define M 2
#define MINR -10.
#define MAXR 10.
#define sqr(r) (r)*(r)
#define EPS 1e-4
using namespace std;

typedef vector<double> vd;
typedef pair<double,int> di;
typedef vector<di> vdi;
vector<string> methS = vector<string> (3);

vd logx = vd(0), logy = vd(0);

int typeF;
double H = 10.;
int rVectCount = 0;

vd randV(int n){
	rVectCount++;
	vd v = vd(n);
	double t = 0;
	for(int i = 0; i < n; i++){
		v[i] = (double)std::rand()/(RAND_MAX+1)*(MAXR-MINR) + MINR;
		t += sqr(v[i]);
	}
	t = sqrt(t);
	cout << "сгенерирован новый случайный вектор <";
	for(int i = 0; i < n; i++){
		v[i] /= t;
		cout << " "<< v[i];
		if(i == n-1)
			cout << ">\n";
		else 
			cout << ",";
	}
	return v;
}

double fX(vd v, int typeF){
	double t;
	if(typeF == 0){
		t = 18*sqr(v[0]) + 18*v[0] - 12*v[0]*v[1] + 8*sqr(v[1]) + 12*v[1] - 8;
	}
	else if(typeF == 1){
		t = 7*sqr(v[0]-1)+ 6*sqr(v[1] - 2) + 8*sqr(v[2] - 5);
	}
	else{
		double y1,y2, a = sqrt(3.),b=2, d =0.5;
		y1 = (v[0]*sqrt(3.) - v[1])/2. + a*(b/(sqrt( b*b - a*a)  ));
		y2 = (v[0] + v[1]*sqrt(3.))*0.5;
		t = a*y1 + b*sqrt(sqr(y1) + d*(sqr(y2) + 1)) - (d*(sqrt( b*b - a*a)  ));
	}
	return t;
}

vd next(vd st, vd ran, int isAlpUsed){
	double a;
	if(isAlpUsed == 1)
		a = ALP;
	else 
		a = 1;
	cout << "для данной точки и случайного вектора сгенерирована следующая точка ";
	if(isAlpUsed == 1)
		cout << "(с расширяющим коэффициентом) ";
	for(int i = 0; i < st.size(); i++){
		st[i] = st[i] + a*H*ran[i];
	}
	cout << "со значением " << fX(st,typeF) << " <";
	for(int i = 0; i < st.size(); i++){
		cout << " "<< st[i];
		if(i == st.size()-1)
			cout << ">\n";
		else 
			cout << ",";
	}
	return st;
}

void randSearch(int typeF, int meth, vd st){
	cout << methS[meth] << "на функции "<< typeF << "\n\n";
	int n =	st.size();
	int curM = 0;
	vdi pts = vdi(0);
	vector<vd > args = vector<vd > (0), nexts = vector<vd > (0);
	vd nxt, nnxt, rnd;
	while(rVectCount < N){
		logx.push_back(st[0]);
		logy.push_back(st[1]);
		cout << "глобальная итерация " << rVectCount << " из " << N << "\n\n";
		cout << "текущая точка (значение "<< fX(st,typeF) << " ): <";
		for(int i = 0; i < n; i++){
			cout << " " << st[i];
			if(i == n-1)
				cout << ">\n";
			else 
				cout << ",";
		}
		if(meth < 2){//they are almost similar
			cout << "итерация из текущей вершины " << curM << " из " << M << "\n";
			if(curM == M){
				cout << "уменьшение радиуса поиска до ";
				H *= BTA;
				cout << H << "\n";
				curM = 0;
			}
			rnd = randV(n);
			nxt = next(st,rnd,0);
			if(fX(st, typeF) > fX(nxt, typeF)){	//good step
				cout << "Хороший шаг\n\n";
				if(abs( fX(st,typeF) - fX(nxt,typeF) )  < EPS){
					cout << "Изменение в значении функции мало. Прекращаю поиск\n";
					break;
				}
				if(meth == 0){
					nnxt = next(st,rnd,1);
					if(fX(st, typeF) > fX(nnxt, typeF)){
						st = nnxt;
						H *= ALP;
					}

				}
				else{
					st = nxt;
				}
			}
			else{
				cout << "Плохой шаг\n\n";
			}
			curM++;
		}
		else{//best shoot
			pts.clear();
			args.clear();
			nexts.clear();
			for(int i = 0; i < M; i++){
				args.push_back(randV(n));
				nexts.push_back(next(st,args[i],0));
				pts.push_back(di(fX( nexts[i], typeF), i));
			}
			sort(pts.begin(), pts.end());
			
			cout << "\n\nлучшая точка (значение "<< fX(nexts[pts[0].second],typeF) << " ): <";
			for(int i = 0; i < n; i++){
				cout << " " << nexts[pts[0].second][i];
				if(i == n-1)
					cout << ">\n";
				else 
					cout << ",";
			}
			
			if(abs( fX(st,typeF) - fX(nexts[pts[0].second],typeF) )  < EPS){
				cout << "Изменение в значении функции мало. Прекращаю поиск\n";
				break;
			}
			if(fX(st,typeF) > fX(nexts[pts[0].second], typeF))
				st = nexts[pts[0].second];
			else H *= BTA;
		}

		cout << "\n";
	}
	cout << "\n\nконечная точка (значение "<< fX(st,typeF) << " ): <";
		for(int i = 0; i < n; i++){
			cout << " " << st[i];
			if(i == n-1)
				cout << ">\n";
			else 
				cout << ",";
		}
}


int main(){
	srand(time(NULL));
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	vector<vd > x0 = vector<vd > (3);
	x0[0] = vd(2);
	x0[0][0] = -2;
	x0[0][1] = -3;
	x0[1] = vd(3);
	x0[1][0] = 2;
	x0[1][1] = 4;
	x0[1][2] = 0;
	x0[2] = vd(2);
	x0[2][0] = -178;
	x0[2][1] = 710;
	///
	methS[0] = "Метод адаптивного поиска\n";
	methS[1] = "Метод поиска с возвратом при неудачном шаге\n";
	methS[2] = "Метод наилучшей стрельбы\n";
	///
	int meth;
	cin >> typeF >> meth;
	randSearch(typeF, meth, x0[typeF]);

	cout << "\n\n<";
	for(int i = 0; i < logx.size(); i++){
		cout << "<" << logx[i] << "| " << logy[i] << ">, ";
	}
	cout << ">";
	return 0;
}
