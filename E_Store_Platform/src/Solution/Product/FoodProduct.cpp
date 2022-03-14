#include "FoodProduct.h"

FoodProduct::FoodProduct()
{
}

FoodProduct::FoodProduct(const string &categorie, int id, const string &nume, float leiPerKg, const string &taraOrigine, int cantitate) : Product(categorie, id, nume, cantitate)
{
	this->category=categorie;
	this->id=id;
	this->name=nume;
	this->leiPerKg=leiPerKg;
	this->countryOfOrigin=taraOrigine;
	this->quantity=cantitate;
}

FoodProduct::FoodProduct(const FoodProduct &pa) : Product(pa)
{
	this->leiPerKg=pa.leiPerKg;
	this->countryOfOrigin=pa.countryOfOrigin;

}

void FoodProduct::setLeiPerKg(float leiPerKg)
{
	this->leiPerKg=leiPerKg;

}

void FoodProduct::setCountryOfOrigin(const string &countryOfOrigin)
{
	this->countryOfOrigin=countryOfOrigin;

}

float FoodProduct::getLeiPerKg()
{
	return leiPerKg;
}

string &FoodProduct::getCountryOfOrigin()
{

	return countryOfOrigin;

}

const FoodProduct &FoodProduct::operator=(const FoodProduct &a)
{
	this->category=a.category;
	this->name=a.name;
	this->id=a.id;
	this->quantity=a.quantity;
	this->countryOfOrigin=a.countryOfOrigin;
	this->leiPerKg=a.leiPerKg;
	return *this;
}

string FoodProduct::getProductType()
{
	string aux;
	aux="alimentar";
	return aux;
}

json FoodProduct::toJSON()
{
	return json(*this);
}

void FoodProduct::display()
{
	cout << "Product alimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Categorie : " << this->category << endl;
	cout << "ID : " << this->id << endl;
	cout << "Cantitate (stoc): " << this->quantity << endl;
	cout << "Lei per KG : " << this->leiPerKg << endl;
	cout << "Tara de Origine : " << this->countryOfOrigin << endl
		 << endl;
}
