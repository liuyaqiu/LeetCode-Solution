#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool containsNearByDuplicate(vector<int>& nums, int k) {
    map<int, int> refer;
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        int pos = iter - nums.begin();
        if(refer.find(*iter) != refer.end()) {
            if(pos - refer[*iter] <= k)
                return true;
            else
                refer[*iter] = pos;
        }
        else
            refer[*iter] = pos;
    }
    return false;
}
