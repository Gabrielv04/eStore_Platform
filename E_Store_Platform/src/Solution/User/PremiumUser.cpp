#include "PremiumUser.h"

using namespace std;

PremiumUser::PremiumUser()
{
	//throw("undefined");
}

PremiumUser::PremiumUser(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf,
						 const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl,
						 int id, const string &nume, const string &prenume, const string &email, int premiumSubscriptionCost, const map<int, int> &discounts)
	: User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
//:discounts(discounts),premiumSubscriptionCost(premiumSubscriptionCost)
{this->discounts=discounts;
this->premiumSubscriptionCost=premiumSubscriptionCost;
	//throw("undefined");
}

PremiumUser::PremiumUser(const PremiumUser &up) : User(up)
//:discounts(up.discounts),premiumSubscriptionCost(up.premiumSubscriptionCost)
{  discounts=up.discounts;
premiumSubscriptionCost=up.premiumSubscriptionCost;
	//throw("undefined");
}

const PremiumUser &PremiumUser::operator=(const PremiumUser &up)
{
	//throw("undefined");
	this->billingData=up.billingData;
	this->deliveryData=up.deliveryData;
	this->lastName=up.lastName;
	this->firstName=up.firstName;
	this->email=up.email;
	this->UserID=up.UserID;
	this->discounts=up.discounts;
	this->premiumSubscriptionCost=up.premiumSubscriptionCost;
	return *this;
}

void PremiumUser::displayUser()
{
	throw("undefined");
}

string PremiumUser::getUserType()
{
	//throw("undefined");
	string aux;
	aux="premium";
	return aux;

}

float PremiumUser::getTransportCost()
{
	//throw("undefined");
	return 0;
}

map<int, int> &PremiumUser::getDiscounts()
{
	//throw("undefined");
	return discounts;
}

void PremiumUser::setDiscounts(map<int, int> red)
{
	//throw("undefined");
	this->discounts=red;
}

void PremiumUser::setPremiumSubscriptionCost(int cap)
{
	//throw("undefined");
	this->premiumSubscriptionCost=cap;
}

int PremiumUser::getPremiumSubscriptionCost()
{
	//throw("undefined");
	return premiumSubscriptionCost;
}

json PremiumUser::toJSON()
{
	return json(*this);
}
