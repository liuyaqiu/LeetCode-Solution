/*
  Degree of an Array

  Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

  Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

  Example 1:
  Input: [1, 2, 2, 3, 1]
  Output: 2
  Explanation:
  The input array has a degree of 2 because both elements 1 and 2 appear twice.
  Of the subarrays that have the same degree:
  [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
  The shortest length is 2. So return 2.
  Example 2:
  Input: [1,2,2,3,1,4,2]
  Output: 6
  Note:

  nums.length will be between 1 and 50,000.
  nums[i] will be an integer between 0 and 49,999.

 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> mypair;

struct comp {
    bool operator() (const mypair& lhs, const mypair& rhs) {
        if(lhs.first != rhs.first)
            return lhs.first > rhs.first;
        else
            return lhs.second < rhs.second;
    }
};

int findShortestSubArray(vector<int>& nums) {
    map<int, int> cnt; //统计各个元素出现的次数
    map<int, int> start; //统计各个元素的最先出现位置
    map<int, int> end; //统计各个元素的最后出现位置
    for(int i = 0; i < nums.size(); i++) {
        if(cnt.find(nums[i]) == cnt.end()) {
            cnt[nums[i]] = 1;
            start[nums[i]] = i;
        }
        else
            cnt[nums[i]]++;
        end[nums[i]] = i;
    }
    vector<mypair> res;
    for(auto item: cnt) {
        int i = item.first;
        res.push_back(mypair(cnt[i], end[i] - start[i] + 1));
    }
    sort(res.begin(), res.end(), comp());
    return res.front().second;
}
