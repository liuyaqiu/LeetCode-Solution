#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int findMaximumXOR(vector<int>& nums) {
    int max = 0, mask = 0;
    for(int i = 31; i >= 0; i--) {
        mask |= (1 << i);
        unordered_set<int> dict;
        for(auto n: nums)
            dict.insert(n & mask);
        int target = max | (1 << i);
        for(auto item: dict) {
            if(dict.find(item ^ target) != dict.end())
                max = target;
        }
    }
    return max;
}
