#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefix(n, 0);
    unordered_map<int, int> mods; //first: mod值, second: 对应该mod值的前缀和的最小截至坐标
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        if(i >= 1 && (sum == k || (k != 0 && sum % k == 0)))
        	return true;
        int m = sum;
        if(k != 0)
            m = sum % k;
        if(mods.find(m) == mods.end())
            mods[m] = i;
        else  {
            if(i > mods[m] + 1)
                return true;
        }
    }
    return false;
}
