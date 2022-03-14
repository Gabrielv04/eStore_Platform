#include "ReturnedProduct.h"

ReturnedProduct::ReturnedProduct()
{
}

ReturnedProduct::ReturnedProduct(const string &categorie, int id, const string &producator, const string &nume, float pret, int garantieAni, const string &motiv, int cantitate)
	: NonFoodProduct(categorie, id, producator, nume, pret, garantieAni, cantitate)
{
	this->reason=motiv;
	
}

ReturnedProduct::ReturnedProduct(const ReturnedProduct &prodRet) : NonFoodProduct(prodRet)
{

	this->reason=prodRet.reason;
}


const ReturnedProduct &ReturnedProduct::operator=(const ReturnedProduct &a)
{
	this->category=a.category;
	this->id=a.id;
	this->producer=a.producer;
	this->name=a.name;
	this->price=a.price;
	this->yearsOfWarranty=a.yearsOfWarranty;
	this->reason=a.reason;
	this->quantity=a.quantity;
	return *this;


}

string &ReturnedProduct::getReason()
{
	return reason;

}

void ReturnedProduct::setReason(string &reason)
{
	this->reason=reason;
}

string ReturnedProduct::getProductType()
{
	string aux;
	aux="returnat";
	return aux;

}

json ReturnedProduct::toJSON()
{
	return json(*this);
}

void ReturnedProduct::display()
{
	cout << "Product Returnat" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Motiv : " << this->reason << endl
		 << endl;
}
