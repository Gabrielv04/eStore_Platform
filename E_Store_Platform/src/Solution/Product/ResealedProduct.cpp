#include "ResealedProduct.h"

using namespace std;

ResealedProduct::ResealedProduct()
{
}

ResealedProduct::ResealedProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int discountPercentage, const string &reason, int wearPercentage, int quantity)
	: NonFoodProduct(category, id, producer, name, price, yearsOfWarranty, quantity),
		DiscountedProduct(category, id, producer, name, price, yearsOfWarranty, discountPercentage, quantity),
		ReturnedProduct(category, id, producer, name, price, yearsOfWarranty, reason, quantity)
{
	this->wearPercentage=wearPercentage;
	

}

ResealedProduct::ResealedProduct(const ResealedProduct &pr) : NonFoodProduct(pr), DiscountedProduct(pr), ReturnedProduct(pr)
{
     this->wearPercentage=pr.wearPercentage;
    
     }

void ResealedProduct::setWearPercentage(int wearPercentage)
{
	this->wearPercentage=wearPercentage;
}

float ResealedProduct::getWearPercentage()
{
	return wearPercentage;
}

const ResealedProduct &ResealedProduct::operator=(const ResealedProduct &a)
{
	this->category=a.category;
	this->id=a.id;
	this->quantity=a.quantity;
	this->price=a.price;
	this->discountPercentage=a.discountPercentage;
    this->reason=a.reason;
    this->yearsOfWarranty=a.yearsOfWarranty;
    this->wearPercentage=a.wearPercentage;
    this->name=a.name;
    this->producer=a.producer;

    return *this;

}

string ResealedProduct::getProductType()
{
	string aux;
	aux="resigilat";
	return aux;
}

json ResealedProduct::toJSON()
{
	return json(*this);
}

void ResealedProduct::display()
{
	cout << "Product Resigilat" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Procent Reducere: " << this->discountPercentage << endl;
	cout << "Procent Uzura: " << this->wearPercentage << endl;
	cout << "Motiv retur: " << this->reason << endl
         << endl;
}
