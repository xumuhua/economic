#pragma once
#include "market.h"

class enviroment
{
public:
	enviroment(void);
	~enviroment(void);
	double total_value;
	double base_value;
	double market_size;
	double base_market_size;
	market * market_a;
	market * market_b;
	market * market_c;
	market * market_d;
	double base_market_prop_A_B;
	double base_market_prop_B_C;
	double market_size_A_B;
	double market_size_B_C;
	double inflation;
	void initial();
	void get_market_size();
};

