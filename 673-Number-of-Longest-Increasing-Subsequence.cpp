/*
  Number of Longest Increasing Subsequence

  Given an unsorted array of integers, find the number of longest increasing subsequence.

  Example 1:
  Input: [1,3,5,4,7]
  Output: 2
  Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
  Example 2:
  Input: [2,2,2,2,2]
  Output: 5
  Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
  Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.

 */

#include <iostream>
#include <vector>

using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    vector<int> res(nums.size(), 1);
    vector<int> cnt(nums.size(), 1);
    for(int i = 1; i < nums.size(); i++) {
        int maxi = 1;
        int count = 1;
        for(int j = i - 1; j >= 0; j--) {
            if(nums[i] > nums[j]) {
                if(maxi < res[j] + 1) {
                    maxi = res[j] + 1;
                    count = cnt[j];
                }
                else if(maxi == res[j] + 1)
                    count += cnt[j];
            }
        }
        res[i] = maxi;
        cnt[i] = count;
    }
    int tmp = 0;
    for(auto item: res)
        tmp = max(tmp, item);
    int result = 0;
    for(int i = 0; i < res.size(); i++) {
        if(res[i] == tmp)
            result += cnt[i];
    }
    return result;
}
