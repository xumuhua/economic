#include "StdAfx.h"
#include "market.h"


market::market(void)
{
}


market::~market(void)
{
}

double market::get_new_value() {
	double target_value = 1;
	if(this->supply!=0) {
		target_value = this->demand/this->supply;
	} else {
		target_value = 1000;
	}
	target_value = target_value*this->base_value*this->inflation;
	double diff_value = target_value - this->value;
	this->value = this->value+diff_value*0.2;
	cout << value << endl;
	return this->value;
}
