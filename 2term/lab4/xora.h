#pragma once
#include "Array.h"

public ref class xora : Array
{
	
public:
	int *a, r;
	xora(int n);
	~xora(void);
	virtual void summ(int *f, int fn) override;
	virtual double foreach(int i) override;
};
