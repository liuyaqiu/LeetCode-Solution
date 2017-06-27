#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int res = 0;
    int n = nums.size();
    for(int i = n - 2; i >= 0; i -= 2)
        res += nums[i];
    return res;
}

int main() {
    vector<int> nums;
    int val;
    while(cin >> val)
        nums.push_back(val);
    int res = arrayPairSum(nums);
    cout << res << endl;
    return 0;
}
