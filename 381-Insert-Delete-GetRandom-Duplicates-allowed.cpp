#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
#include <iterator>

using namespace std;

/*
 * Insert Delete GetRandom O(1) - Duplicates allowed
 *
 * Design a data structure that supports all following operations in average O(1) time.
 *
 * Note: Duplicate elements are allowed.
 * insert(val): Inserts an item val to the collection.
 * remove(val): Removes an item val from the collection if present.
 * getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
 *
 *
 */

class RandomizedCollection {
private:
    unordered_map<int, int> mymap;
    default_random_engine generator;
    discrete_distribution<int> distribution;
    bool change;
    
    int getPos() {
    	if(change) {
            vector<int> cnt;
            for(auto item: mymap)
                cnt.push_back(item.second);
            distribution = discrete_distribution<int>(cnt.begin(), cnt.end());
            change = false;
        }
        return distribution(generator);
    }

public:
    RandomizedCollection(): generator(0), change(false) {}

    bool insert(int val) {
        if(mymap.find(val) != mymap.end()) {
            mymap[val] += 1;
            return false;
        }
        mymap[val] = 1;
        change = true;
        return true;
    }

    bool remove(int val) {
        if(mymap.find(val) == mymap.end())
            return false;
        mymap[val] -= 1;
        if(mymap[val] == 0)
            mymap.erase(val);
        change = true;
        return true;
    }

    int getRandom() {
        if(mymap.empty())
            return -1;
        else
            return next(mymap.begin(), getPos())->first;
    }
};
