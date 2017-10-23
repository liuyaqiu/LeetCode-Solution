/*
  Maximum Product of Three Numbers

  Given an integer array, find three numbers whose product is maximum and output the maximum product.

  Example 1:
  Input: [1,2,3]
  Output: 6
  Example 2:
  Input: [1,2,3,4]
  Output: 24
  Note:
  The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
  Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
#define inf numeric_limits<int>::min()

int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if(nums.size() < 3)
        return -1;
    else if(nums.size() == 3)
        return nums[0] * nums[1] * nums[2];
    else {
        if(nums[0] < 0) {
            int neg = 0;
            while(neg < nums.size() && nums[neg] < 0)
                neg++;
            int res = inf;
            if(neg > 1)
                res = max(res, nums[0] * nums[1] * nums.back());
            res = max(res, nums[n - 3] * nums[n - 2] * nums[n - 1]);
            return res;
        }
        else
            return nums[n - 3] * nums[n - 2] * nums[n - 1];
    }
}
