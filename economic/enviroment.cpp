#include "StdAfx.h"
#include "enviroment.h"


environment::environment(void)
{
}


environment::~environment(void)
{
}

void environment::initial() {
	this->base_value = BASE_VALUE;
	this->base_market_size = BASE_MARKET_SIZE;
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
	corporation * corp;
	corp = new corporation();
	corp->buy_price = this->market_a->value;
	corp->sale_price = this->market_b->value;
	corp->loss_prop = 0;
	corp->market_share = this->market_size_A_B;
	this->corporations_A.push_back(corp);
	corp = new corporation();
	corp->buy_price = this->market_b->value;
	corp->sale_price = this->market_c->value;
	corp->loss_prop = 0;
	corp->market_share = this->market_size_B_C;
	this->corporations_B.push_back(corp);
	corp = new corporation();
	corp->buy_price = this->market_c->value;
	corp->sale_price = this->market_d->value;
	corp->loss_prop = 0;
	corp->market_share = this->market_size;
	this->corporations_C.push_back(corp);
	this->people = 0;
}

void environment::getMarketSize() {
	double market_size = 0;
	for(int i=0;i<this->corporations_A.size();i++) {
		market_size += this->corporations_A[i]->market_share;
	}
	this->market_a->demand = market_size;
	this->market_b->supply = market_size;
	market_size = 0;
	for(int i=0;i<this->corporations_B.size();i++) {
		market_size += this->corporations_B[i]->market_share;
	}
	this->market_b->demand = market_size;
	this->market_c->supply = market_size;
	market_size = 0;
	for(int i=0;i<this->corporations_C.size();i++) {
		market_size += this->corporations_C[i]->market_share;
	}
	this->market_c->demand = market_size;
	this->market_d->supply = market_size;
	this->market_size = this->market_size + this->people;
	this->market_a->supply = this->market_size;
	this->market_d->demand = this->market_size;
}

void environment::getMarketValue() {
	this->total_value = this->base_value+this->people;
	this->inflation = this->total_value/this->base_value;
	this->market_a->inflation = this->inflation;
	this->market_b->inflation = this->inflation;
	this->market_c->inflation = this->inflation;
	this->market_d->inflation = this->inflation;
	this->market_a->get_new_value();
	this->market_b->get_new_value();
	this->market_c->get_new_value();
	this->market_d->get_new_value();
}

void environment::getCorporationShare(){
	for(int i=0;i<this->corporations_A.size();i++) {
		this->corporations_A[i]->get_new_market_share();
	}
	for(int i=0;i<this->corporations_B.size();i++) {
		this->corporations_B[i]->get_new_market_share();
	}
	for(int i=0;i<this->corporations_C.size();i++) {
		this->corporations_C[i]->get_new_market_share();
	}
}

void environment::getCorporationProfit() {
	for(int i=0;i<this->corporations_A.size();i++) {
		this->corporations_A[i]->buy_price = this->market_a->value;
		this->corporations_A[i]->sale_price = this->market_b->value;
		this->corporations_A[i]->deal_profit();
	}
	for(int i=0;i<this->corporations_B.size();i++) {
		this->corporations_B[i]->buy_price = this->market_b->value;
		this->corporations_B[i]->sale_price = this->market_c->value;
		this->corporations_B[i]->deal_profit();
	}
	for(int i=0;i<this->corporations_C.size();i++) {
		this->corporations_C[i]->buy_price = this->market_c->value;
		this->corporations_C[i]->sale_price = this->market_d->value;
		this->corporations_C[i]->deal_profit();
	}
}

void environment::forwardAStep() {
	this->getMarketSize();
	this->getMarketValue();
	this->getCorporationShare();
	this->getCorporationProfit();
}

void environment::addNewCorporation(int i) {
	corporation * corp;
	corp = new corporation();
	corp->market_share=0;
	corp->loss_prop = 0.05;
	corp->memeber_attr=100;
	switch(i) {
	case 0:
		corp->buy_price=this->market_a->value;
		corp->sale_price=this->market_b->value;
		this->corporations_A.push_back(corp);
		break;
	case 1:
		corp->buy_price=this->market_b->value;
		corp->sale_price=this->market_c->value;
		this->corporations_B.push_back(corp);
		break;
	case 2:
		corp->buy_price=this->market_c->value;
		corp->sale_price=this->market_d->value;
		this->corporations_C.push_back(corp);
		break;
	}
}