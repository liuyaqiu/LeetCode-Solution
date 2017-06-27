#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findPairs(vector<int>& nums, int k) {
    if(k < 0)
        return 0;
    sort(nums.begin(), nums.end());
    int low = 0, high = 0;
    int n = nums.size();
    int res = 0;
    while(low < n && high < n) {
        if(high == low)
            high++;
        while(high < n && nums[high] < nums[low] + k)
            high++;
        if(nums[high] == nums[low] + k)
            res += 1;
        while(high < n && nums[high] == nums[low] + k)
            high++;
        while(low < n && nums[high] > nums[low] + k)
            low++;
    }
    return res;
}

int main() {
    int val;
    int k;
    cin >> k;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    int res = findPairs(nums, k);
    cout << res << endl;
    return 0;
}
