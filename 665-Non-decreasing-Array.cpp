/*
  Non-decreasing Array

  Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

  We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

  Example 1:
  Input: [4,2,3]
  Output: True
  Explanation: You could modify the first 
  4
  to 
  1
  to get a non-decreasing array.
  Example 2:
  Input: [4,2,1]
  Output: False
  Explanation: You can't get a non-decreasing array by modify at most one element.
  Note: The n belongs to [1, 10,000].


 */

#include <iostream>
#include <vector>

using namespace std;

bool checkPossibility(vector<int>& nums) {
    bool dec = false;
    int pos = 1;
    while(pos < nums.size() - 1) {
        if(nums[pos] < nums[pos - 1]) {
            if(pos > 1) {
                if(!(nums[pos - 1] <= nums[pos + 1] || nums[pos] >= nums[pos - 2]))
                    return false;
            }
            dec = true;
            break;
        }
        else
            pos++;
    }
    if(dec) {
        while(pos < nums.size() - 1) {
            if(nums[pos] <= nums[pos + 1])
                pos++;
            else
                return false;
        }
    }
    return true;
}
