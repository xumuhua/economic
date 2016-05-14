#include "StdAfx.h"
#include "enviroment.h"


enviroment::enviroment(void)
{
}


enviroment::~enviroment(void)
{
}

void enviroment::initial() {
	this->base_value = 1000;
	this->base_market_size = 1000;
	this->base_market_prop_A_B = 1;
	this->base_market_prop_B_C = 1;
	this->total_value = this->base_value;
	this->market_size = this->base_market_size;
	this->market_size_A_B = this->base_market_prop_A_B*this->base_market_size;
	this->market_size_B_C = this->base_market_prop_B_C*this->base_market_size;
	this->inflation = this->total_value/this->base_value;
	this->market_a = new market();
	this->market_b = new market();
	this->market_c = new market();
	this->market_d = new market();
	this->market_a->base_value = 10;
	this->market_b->base_value = 20;
	this->market_c->base_value = 30;
	this->market_d->base_value = 40;
	this->market_a->inflation = inflation;
	this->market_b->inflation = inflation;
	this->market_c->inflation = inflation;
	this->market_d->inflation = inflation;
	this->market_a->value = this->market_a->base_value;
	this->market_b->value = this->market_b->base_value;
	this->market_c->value = this->market_c->base_value;
	this->market_d->value = this->market_d->base_value;
	this->market_a->demand = this->market_size;
	this->market_a->supply = this->market_size;
	this->market_b->demand = this->market_size_A_B;
	this->market_b->supply = this->market_size_A_B;
	this->market_c->demand = this->market_size_B_C;
	this->market_c->supply = this->market_size_B_C;
	this->market_d->demand = this->market_size;
	this->market_d->supply = this->market_size;
}