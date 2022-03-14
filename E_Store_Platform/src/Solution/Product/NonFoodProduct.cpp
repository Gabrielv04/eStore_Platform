#include "NonFoodProduct.h"

NonFoodProduct::NonFoodProduct()
{

}

NonFoodProduct::NonFoodProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int quantity) : Product(category, id, name, quantity)
{
	this->yearsOfWarranty=yearsOfWarranty;
	this->price=price;
	this->producer=producer;

}

NonFoodProduct::NonFoodProduct(const NonFoodProduct &pn) : Product(pn)
{
	this->yearsOfWarranty=pn.yearsOfWarranty;
	this->price=pn.price;
	this->producer=pn.producer;
	
}

void NonFoodProduct::setYearsOfWarranty(int garantieAni)
{
	
	this->yearsOfWarranty=garantieAni;
}

void NonFoodProduct::setPrice(float price)
{
	
	this->price=price;
}

void NonFoodProduct::setProducer(const string &producer)
{
	
	this->producer=producer;
}

int NonFoodProduct::getYearsOfWarranty()
{
	
	return yearsOfWarranty;
}

float NonFoodProduct::getPrice()
{
	
	return price;
}

string &NonFoodProduct::getProducer()
{
	
	return producer;
}

bool NonFoodProduct::operator==(const NonFoodProduct &obj) const
{
	return(this->category==obj.category && this->id==obj.id && this->name==obj.name && this->quantity==obj.quantity && this->price==obj.price && this->producer==obj.producer && this->yearsOfWarranty==obj.yearsOfWarranty);
      
}

const NonFoodProduct &NonFoodProduct::operator=(const NonFoodProduct &a)
{
	this->id=a.id;
	this->category=a.category;
	this->quantity=a.quantity;
	this->name=a.name;
	this->producer=a.producer;
	this->price=a.price;
	this->yearsOfWarranty=a.yearsOfWarranty;
	return *this;
	
}

string NonFoodProduct::getProductType()
{
  string aux;
  aux="nealimentar";
  return aux;


}

json NonFoodProduct::toJSON()
{
	return json(*this);
}

void NonFoodProduct::display()
{
	cout << "Product Nealimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl
		 << endl;
}
