#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int distributeCandies(vector<int>& candies) {
    set<int> cnt;
    for(auto item: candies)
    	cnt.insert(item);
    return min(candies.size() / 2, cnt.size());
}
