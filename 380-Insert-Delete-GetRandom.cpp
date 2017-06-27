#include <iostream>
#include <random>
#include <vector>
#include <unordered_set>
#include <iterator>

using namespace std;

/*
 * Insert Delete GetRandom O(1)
 *
 * Design a data structure that supports all following operations in average O(1) time.
 *
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 *
 *
 */

class RandomizedSet {
private:
    unordered_set<int> myset;
    default_random_engine generator;
    uniform_int_distribution<int> distribution;

public:
    RandomizedSet(): generator(0) {}

    bool insert(int val) {
        if(myset.find(val) != myset.end())
            return false;
        myset.insert(val);
        return true;
    }

    bool remove(int val) {
        if(myset.find(val) == myset.end())
            return false;
        myset.erase(val);
        return true;
    }

    int getRandom() {
        if(myset.empty())
            return -1;
        else
            return *next(myset.begin(), distribution(generator) % myset.size());
    }
};
