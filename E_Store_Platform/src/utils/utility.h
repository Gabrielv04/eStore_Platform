#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../Solution/Product/NonFoodProduct.h"
#include "../Solution/Product/FoodProduct.h"
#include "../Solution/Product/ResealedProduct.h"
#include "../Solution/Product/Product.h"
#include "../Solution/User/User.h"
using namespace std;

class Utility{

public:

    /*
      Metoda de mai jos va fi folosita de functia sort din STL pentru compararea a doua persoane.
    */
    static bool compareResealed(ResealedProduct*,ResealedProduct*);
    static bool compareFood(FoodProduct*,FoodProduct*);
    //static bool compareFoodPrice(FoodProduct*,FoodProduct*);
    //static bool compareFoodCountry(FoodProduct*,FoodProduct*);
    static string findCounty(map<string,int>);
    static bool compareUser(User*,User*);

};
