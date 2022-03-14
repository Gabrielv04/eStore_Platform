#include "LRUCache.h"
#include <algorithm>

using namespace std;

LRUCache::LRUCache(int capacity)
{
	this->capacity=capacity;
}

vector<int> LRUCache::processRequests(vector<int> requestsNo)
{
vector<int>::iterator aux;
for(auto itr=requestsNo.begin();itr!=requestsNo.end();++itr)
{
    if(lru.size()<capacity)
    {
        aux = find (lru.begin(), lru.end(), *itr);
        if(aux!=lru.end())
        {
            lru.erase(aux);
            lru.insert(lru.begin(), *itr);
        }
        else
        {
            lru.insert(lru.begin(), *itr);
        }

    }
    else if(lru.size()==capacity)
    {
        aux = find (lru.begin(), lru.end(), *itr);
        if(aux!=lru.end())
        {
            lru.erase(aux);
            lru.insert(lru.begin(), *itr);
        }
        else
        {

            lru.pop_back();
            lru.insert(lru.begin(), *itr);

        }

    }




}
   return lru;
   }

int LRUCache::getCapacity()
{
	return capacity;
}

int LRUCache::getSize()
{
	return size;
}

vector<int> LRUCache::getLRU()
{
	return lru;
}

int LRUCache::getLRUCapacity()
{
	return capacity;
}

void LRUCache::setCapacity(int capacity)
{
	this->capacity=capacity;
}

void LRUCache::setLRU(vector<int> aux)
{
	lru=aux;
}
