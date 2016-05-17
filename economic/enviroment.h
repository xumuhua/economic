#pragma once
#include "market.h"
#include <vector>
#include "corporation.h"
#include <stdio.h>
#include "parameter.h"

using namespace std;

class environment
{
public:
	environment(void);
	~environment(void);
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
	double people;
	vector<corporation*> corporations_A;
	vector<corporation*> corporations_B;
	vector<corporation*> corporations_C;
	void initial();
	void getMarketSize();
	void getMarketValue();
	void getCorporationShare();
	void getCorporationProfit();
	void addNewCorporation(int i);

	void forwardAStep();
};

