/*
  Longest Harmonious Subsequence

  We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

  Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

  Example 1:
  Input: [1,3,2,2,5,2,3,7]
  Output: 5
  Explanation: The longest harmonious subsequence is [3,2,2,2,3].
  Note: The length of the input array will not exceed 20,000.

 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int findLHS(vector<int>& nums) {
    map<int, int> cnt;
    for(auto num: nums) {
        if(cnt.find(num) != cnt.end())
            cnt[num] += 1;
        else
            cnt[num] = 1;
    }
    int res = 0;
    for(auto item: cnt) {
        if(cnt.find(item.first - 1) != cnt.end())
            res = max(res, item.second + cnt[item.first - 1]);
        if(cnt.find(item.first + 1) != cnt.end())
            res = max(res, item.second + cnt[item.first + 1]);
    }
    return res;
}
