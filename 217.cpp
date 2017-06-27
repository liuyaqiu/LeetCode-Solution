#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool containDuplicate(vector<int>& nums) {
    set<int> refer;
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        if(refer.find(*iter) != refer.end())
            return true;
        else
            refer.insert(*iter);
    }
    return false;
}
