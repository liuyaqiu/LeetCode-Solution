/*
  Valid Triangle Number

  Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

  Example 1:
  Input: [2,2,3,4]
  Output: 3
  Explanation:
  Valid combinations are:
  2,3,4 (using the first 2)
  2,3,4 (using the second 2)
  2,2,3
  Note:
  The length of the given array won't exceed 1000.
  The integers in the given array are in the range of [0, 1000].

 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int res = 0;
    for(auto iter_a = nums.begin(); iter_a != nums.end(); iter_a++) {
        for(auto iter_b = iter_a + 1; iter_b != nums.end(); iter_b++) {
            auto low = upper_bound(iter_b + 1, nums.end(), *iter_b - *iter_a);
            auto high = lower_bound(iter_b + 1, nums.end(), *iter_b + *iter_a);
            int tmp = high - low;
            if(tmp > 0)
                res += tmp;
        }
    }
    return res;
}
