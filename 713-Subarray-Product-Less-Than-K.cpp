/*
  Subarray Product Less Than K

  Your are given an array of positive integers nums.

  Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

  Example 1:
  Input: nums = [10, 5, 2, 6], k = 100
  Output: 8
  Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
  Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
  Note:

  0 < nums.length <= 50000.
  0 < nums[i] < 1000.
  0 <= k < 10^6.

 */

#include <iostream>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    vector<int> ziped;
    vector<int> cnt;
    int p = 0;
    while(p < nums.size()) {
        if(nums[p] == 1) {
            ziped.push_back(nums[p]);
            int cur = 1;
            p += 1;
            while(p < nums.size() && nums[p] == 1) {
                cur += 1;
                p += 1;
            }
            cnt.push_back(cur);
        }
        else {
            ziped.push_back(nums[p]);
            cnt.push_back(1);
            p += 1;
        }
    }
    return solve(ziped, cnt, k);
}

int solve(vector<int>& nums, vector<int>& cnt, int k) {
    int res = 0;
    for(int start = 0; start < nums.size(); start++) {
        int prod = nums[start];
        if(prod >= k)
            continue;
        res += cnt[start] * (cnt[start] + 1) / 2;
        int end = start + 1;
        prod *= nums[end];
        int tmp = 0;
        while(end < nums.size() && prod < k) {
            tmp += cnt[end];
            end += 1;
            prod *= nums[end];
        }
        res += tmp * cnt[start];
    }
    return res;
}
