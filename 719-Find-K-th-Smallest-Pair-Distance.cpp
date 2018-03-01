/*
  Find K-th Smallest Pair Distance

  Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

  Example 1:
  Input:
  nums = [1,3,1]
  k = 1
  Output: 0 
  Explanation:
  Here are all the pairs:
  (1,3) -> 2
  (1,1) -> 0
  (3,1) -> 2
  Then the 1st smallest distance pair is (1,1), and its distance is 0.
  Note:
  2 <= len(nums) <= 10000.
  0 <= nums[i] < 1000000.
  1 <= k <= len(nums) * (len(nums) - 1) / 2.

 */

#include <iostream>
#include <vector>

using namespace std;

#define inf numeric_limits<int>::max()

int count(vector<int>& vec, int val) {
    int res = 0;
    int start = 0;
    int end = 0;
    while(start < vec.size()) {
        while(end < vec.size() && vec[end] - vec[start] <= val)
            end += 1;
        res += end - start - 1;
        start += 1;
    }
    return res;
}

int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int low = inf, high = nums.back() - nums.front();
    for(int i = 0; i < nums.size() - 1; i++)
        low = min(low, nums[i + 1] - nums[i]);
    while(low <= high) {
        int mid = (low + high) / 2;
        if(count(nums, mid) >= k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
