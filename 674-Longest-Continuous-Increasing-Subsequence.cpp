/*
  Longest Continuous Increasing Subsequence

  Given an unsorted array of integers, find the length of longest continuous increasing subsequence.

  Example 1:
  Input: [1,3,5,4,7]
  Output: 3
  Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
  Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
  Example 2:
  Input: [2,2,2,2,2]
  Output: 1
  Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
  Note: Length of the array will not exceed 10,000.

 */

#include <iostream>
#include <vector>

using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int pos = 0;
    int res = 1;
    while(pos < nums.size()) {
        int pre = pos;
        while(pos < nums.size() - 1 && nums[pos] < nums[pos + 1])
            pos++;
        pos++;
        res = max(res, pos - pre);
    }
    return res;
}
