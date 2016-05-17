#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

class market
{
public:
	market(void);
	~market(void);
	double base_value;
	double supply;
	double demand;
	double inflation;
	double value;
	double get_new_value();
};

