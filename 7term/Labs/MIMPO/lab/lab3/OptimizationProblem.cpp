#include "OptimizationProblem.h"
#include "ParsingTools.h"

void OptimizationProblem::run(Object^ o){
	log += "����� ������ ������ ������� �������� � ������������������ ���������� �����\n";
	log += "����� ������� ��������\n";
	double min = 1e10;
	double h = 2./N;
	double maxX=-1, maxY=-1;
	min = f(maxX, maxY);
	long long count = 0;
	for(double x = -1.; x < 1; x+=h){
		for ( double y = -1; y < 1; y+=h){
			if(f(x,y) < f(maxX, maxY)){
				maxX = x;
				maxY = y;
			}	
		}
		log += "������ �������� �� �������� ["+count+++"]:  \t"+ParsingTools::evalf(f(maxX, maxY))+"\n";
	}
	log += "������� ����� ��������: \n\t["+maxX+"; "+maxY+"]\n��������: \t"+ParsingTools::evalf(f(maxX, maxY));
	isCplt = true;
}
