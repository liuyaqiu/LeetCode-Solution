/*
  Partition to K Equal Sum Subsets
  Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

  Example 1:
  Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
  Output: True
  Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
  Note:

  1 <= k <= len(nums) <= 16.
  0 < nums[i] < 10000.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

bool partition(vector<int>& nums, int target) {
    if(nums.empty())
        return true;
    int sum = 0;
    vector<int> pos;
    while(true) {

        bool judge = false;
        if(sum < target) {
            if(pos.empty()) {
                sum += nums[0];
                pos.push_back(0);
            }
            else {
                if(pos.back() + 1 < nums.size()) {
                    sum += nums[pos.back() + 1];
                    pos.push_back(pos.back() + 1);
                }
                else
                    judge = true;
            }
        }

        if(sum == target) {
            set<int> position;
            vector<int> tmp;
            for(auto p: pos)
                position.insert(p);
            for(int i = 0; i < nums.size(); i++) {
                if(position.find(i) == position.end())
                    tmp.push_back(nums[i]);
            }
            if(partition(tmp, target))
                return true;
            else
                judge = true;
        }

        if(judge || sum > target) {
            sum -= nums[pos.back()];
            pos.pop_back();
            if(pos.empty())
                return false;
            sum -= nums[pos.back()];
            int cur = pos.back();
            while(cur < nums.size()) {
                if(nums[cur] > nums[pos.back()])
                    break;
                else
                    cur += 1;
            }
            if(cur >= nums.size())
                return false;
            sum += nums[cur];
            pos.back() = cur;
        }
    }
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sums = 0;
    for(auto num: nums)
        sums += num;
    if(sums % k != 0)
        return false;
    int target = sums / k;
    for(auto num: nums) {
        if(num > target)
            return false;
    }
    sort(nums.begin(), nums.end());
    return partition(nums, target);
}
