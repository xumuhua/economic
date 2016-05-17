#include "StdAfx.h"
#include "corporation.h"


corporation::corporation(void)
{
	this->memeber_attr = 0;
}


corporation::~corporation(void)
{
}

double corporation::get_new_market_share() {
	this->market_share = this->market_share*(1-this->loss_prop)+this->memeber_attr;
	return this->market_share;
}

double corporation::deal_profit(){
	this->gross_profit = this->market_share*(this->sale_price-this->buy_price);
	return this->gross_profit;
}