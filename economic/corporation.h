#pragma once
class corporation
{
public:
	corporation(void);
	~corporation(void);
	double market_share;
	double sale_price;
	double buy_price;
	double gross_profit;
	double loss_prop;
	double memeber_attr;
	double get_new_market_share();
	double deal_profit();
};

