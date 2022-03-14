#include "DiscountedProduct.h"
using namespace std;

DiscountedProduct::DiscountedProduct() : NonFoodProduct()
{

}

DiscountedProduct::DiscountedProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int discountPercentage, int quantity)
	: NonFoodProduct(category, id, producer, name, price, yearsOfWarranty, quantity)
{
	this->discountPercentage=discountPercentage;
}

DiscountedProduct::DiscountedProduct(const DiscountedProduct &discountedProduct) : NonFoodProduct(discountedProduct)
{
	this->discountPercentage=discountedProduct.discountPercentage;
}

float DiscountedProduct::priceAfterDiscount() const
{

    float ans;
    ans=price*(100-discountPercentage);
	return ans;
}

float DiscountedProduct::getDiscountPercentage()
{

	return discountPercentage;
}

const DiscountedProduct &DiscountedProduct::operator=(const DiscountedProduct &a)
{
	
	this->name=a.name;
	this->category=a.category;
	this->discountPercentage=a.discountPercentage;
	this->id=a.id;
	this->quantity=a.quantity;
	this->yearsOfWarranty=a.yearsOfWarranty;
	this->price=a.price;
	this->producer=a.producer;
	return *this;
}

void DiscountedProduct::setDiscountPercentage(int discountPercentage)
{
	
	this->discountPercentage=discountPercentage;
}

string DiscountedProduct::getProductType()
{
       string aux;
       aux="redus";
       return aux;
}

json DiscountedProduct::toJSON()
{
	return json(*this);
}

void DiscountedProduct::display()
{
	cout << "Product Redus" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Procent reducere : " << this->discountPercentage << endl
		 << endl;
}
