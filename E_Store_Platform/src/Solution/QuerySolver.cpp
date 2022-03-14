#include "QuerySolver.h"
#include"utility"

using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver()
{
  server = Server::GetInstance();
}

/* NU MODIFICATI */
QuerySolver::~QuerySolver()
{
  if (server != nullptr)
  {
    server = nullptr;
  }
}

list<Product*> QuerySolver::Query_3a(){
 
  list<Product *>pr;
  list<Product *>aux;
  pr=server->getProductsList();
for(auto itr=pr.begin();itr!=pr.end();++itr)
{
    if((*itr)->getProductType()=="redus"&&(*itr)->getCategory()=="espressor")
        aux.push_back(*itr);
}
return aux;


}

list<User*> QuerySolver::Query_3b(){

  list<User *>us;
  list<User *>aux;
  us=server->getUsersList();
  for(auto itr=us.begin();itr!=us.end();++itr)
  {
      if((*itr)->getTransportCost()>0 && (*itr)->getTransportCost()<=11.5)
        aux.push_back(*itr);
  }
  return aux;
}

list<Product*> QuerySolver::Query_3c(){
 
  list<ResealedProduct *> rp;
  list<Product *> p;
  list<ResealedProduct *>aux01;
  list<Product *>aux02;
  p=server->getProductsList();
  for(auto itr=p.begin();itr!=p.end();++itr){
        ResealedProduct*x=dynamic_cast<ResealedProduct*>(*itr);
        if(x!=nullptr)
  rp.push_back(x);
  else
   continue;
  }
  for(auto itr=rp.begin();itr!=rp.end();++itr)
  {
      if((*itr)->getReason()=="lipsa_accesorii")
        aux01.push_back(*itr);
  }
  aux01.sort(Utility::compareResealed);
  for(auto itr=aux01.begin();itr!=aux01.end();++itr)
    aux02.push_back(*itr);

  return aux02;


}

list<Product*> QuerySolver::Query_3d(){
 
  list<Product *>p;
  list<FoodProduct *>al;
  list<Product*>ans;
  p=server->getProductsList();
  for(auto itr=p.begin();itr!=p.end();++itr)
    {
        FoodProduct *x=dynamic_cast<FoodProduct*>(*itr);
        if(x!=nullptr)
            al.push_back(x);
        else
            continue;
  }
  al.sort(Utility::compareFood);
  
  for(auto itr=al.begin();itr!=al.end();++itr)
    {
        ans.push_back(*itr);
                           }


    return ans;


}

list<User*> QuerySolver::Query_3e(){
 
  list<User *> us;
  list<User *> aux1;
  list<User *>aux02;
  
  Address aux01;
  Address aux20;
  us=server->getUsersList();
  
  //partea 2
  map<string,int> aux2;
  for(auto itr=us.begin();itr!=us.end();++itr){
        aux01=(*itr)->getBillingData();
    if(aux2.find(aux01.getCounty())==aux2.end())
    {
       
       aux2.insert(pair<string,int>(aux01.getCounty(),1));
    }
    else{
        aux2[aux01.getCounty()]++;
    }

  }
string answer;
answer=Utility::findCounty(aux2);

for(auto itr=us.begin();itr!=us.end();++itr){
    aux01=(*itr)->getBillingData();
    if(aux01.getCounty()==answer)
        aux1.push_back(*itr);

}
for(auto itr=aux1.begin();itr!=aux1.end();++itr)
  {   aux01=(*itr)->getBillingData();
      aux20=(*itr)->getDeliveryData();
      if(aux01.getBlock()=="-" && aux01.getApartment()==0 && aux20.getBlock()=="-" && aux20.getApartment()==0)
      {
          aux02.push_back(*itr);
      }
      
  }
aux02.sort(Utility::compareUser);
return aux02;
   }

list<User*> QuerySolver::Query_3f()
{
    list<PremiumUser *> pu;
    list<User *> us;
    list<Product* >p;
    
    us=server->getUsersList();
    for(auto itr=us.begin();itr!=us.end();++itr)
   {
       PremiumUser*x=dynamic_cast<PremiumUser*>(*itr);
    if (x!=nullptr)
            pu.push_back(x);
        else
            continue;
      }
      list<int>redcp;
      map<int,int>aux;
      map<int,int>::iterator  it;
       for(auto itr=pu.begin();itr!=pu.end();++itr)
        {
            aux=(*itr)->getDiscounts();
            for(it=aux.begin();it!=aux.end();++it)
       {
           redcp.push_back((*it).first);
       }
        }
       p=server->getProductsList();
       list<int>ti;
       for(auto itr=p.begin();itr!=p.end();++itr)
       {
           if((*itr)->getCategory()=="telefon" || (*itr)->getCategory()=="imprimanta")
            ti.push_back((*itr)->getId());

       }
       list<int>redti;
       for(auto itr=redcp.begin();itr!=redcp.end();++itr)
        for(auto itrr=ti.begin();itrr!=ti.end();++itrr)
       {
           if((*itr)==(*itrr))
            {
                redti.push_back(*itrr);
            }
       }
       list<User *> answer;
       map<int,int>aux1;
       for(auto itr=pu.begin();itr!=pu.end();++itr)
        {
            aux1=(*itr)->getDiscounts();
            for(auto itrr=redti.begin();itrr!=redti.end();++itrr)
       for(auto mp=aux1.begin();mp!=aux1.end();++mp)
       {
           if((*itrr)==(*mp).first)
           {
               answer.push_back(*itr);
                goto mark;
             
           }
   }


      mark:;
    

        }


return answer;
          
}
