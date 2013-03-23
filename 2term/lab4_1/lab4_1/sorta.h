#pragma once
#include "arra.h"

 class sorta  : public Arra
{
public:
	int *a, r;
public:
	sorta(int n);
	virtual void summ(int *a, int na, int *b, int nb) override{;}
	virtual void foreach(int i) override{;}
};
