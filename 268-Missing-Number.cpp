#include <iostream>
#include <vector>

using namespace std;

/*
 * Missing Number
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 *
 * For example,
 * Given nums = [0, 1, 3] return 2.
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 *
 *
 */

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    for(int i = 0; i < n; i++) {
        res ^= i;
        res ^= nums[i];
    }
    res ^= n;
    return res;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val) {
        nums.push_back(val);
    }
    int res = missingNumber(nums);
    cout << res << endl;
    return 0;
}
