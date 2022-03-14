#include "utility.h"
//#pragma once

// namespace std;
bool Utility::compareResealed(ResealedProduct *R1,ResealedProduct *R2){

//throw("undefined");
if(R1->getPrice()<R2->getPrice()){return true;}
if(R1->getPrice()>R2->getPrice()){return false;}


return false;
}

bool Utility::compareFood(FoodProduct *A1,FoodProduct *A2){

float aux1=A1->getLeiPerKg();


float aux2=A2->getLeiPerKg();

if(A1->getName() < A2->getName()){return true;}
if(A1->getName() > A2->getName()){return false;}

if(A1->getCountryOfOrigin() < A2->getCountryOfOrigin()){return true;}
if(A1->getCountryOfOrigin() > A2->getCountryOfOrigin()){return false;}

if(aux1<aux2){return true;}
if(aux1>aux2){return false;}


return false;}

string Utility::findCounty(map<string,int> M)
{

int  maxim=0;
string ans;
map<string,int>::iterator  it;
for(it=M.begin();it!=M.end();++it){
    if((*it).second>maxim){
        //it.second=maxim;
        maxim=(*it).second;
        ans=(*it).first;
    }


}
return ans;




}
bool Utility::compareUser(User *U1,User *U2){

//throw("undefined");
if(U1->getUserID()<U2->getUserID()){return true;}
if(U1->getUserID()>U2->getUserID()){return false;}


return false;
}
