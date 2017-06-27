#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k , int t) {
    if(k < 1 || t < 0)
        return false;
    set<long> dict;
    for(int i = 0; i < nums.size(); i++) {
        long n = nums[i];
        auto low = dict.lower_bound(n - t);
        if(low != dict.end() && *low >= n - t && *low <= n + t)
            return true;
        dict.insert(n);
        if(i >= k)
            dict.erase(nums[i - k]); //总是维护距当前k距离以内的元素
    }
    return false;
}

int main() {
    int val;
    int k, t;
    cin >> k >> t;
    vector<int> nums;
    while(cin >> val) {
        nums.push_back(val);
    }
    bool res = containsNearbyAlmostDuplicate(nums, k, t);
    if(res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
