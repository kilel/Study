#pragma once
#include "Array.h"

public ref class sorta  : public Array
{
	
public:
	int *a, r;
	sorta(int n);
	~sorta(void);
	virtual void summ(int *f, int fn) override;
	virtual double foreach(int i) override;
};
