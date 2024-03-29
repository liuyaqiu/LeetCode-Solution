/*
  Shortest Unsorted Continuous Subarray

  Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

  You need to find the shortest such subarray and output its length.

  Example 1:
  Input: [2, 6, 4, 8, 10, 9, 15]
  Output: 5
  Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
  Note:
  Then length of the input array is in range [1, 10,000].
  The input array may contain duplicates, so ascending order here means <=.

 */

#include <iostream>
#include <vector>

using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    int len = nums.size();
    int i = 0;
    while(i < len - 1 && nums[i] <= nums[i + 1])
        i++;
    if(i >= len - 1)
        return 0;
    int j = len - 1;
    while(j > 0 && nums[j] >= nums[j - 1])
        j--;
    int mini = nums[i], maxi = nums[i];
    for(int k = i; k <= j; k++) {
        mini = min(mini, nums[k]);
        maxi = max(maxi, nums[k]);
    }
    while(i > 0 && nums[i - 1] > mini)
        i--;
    while(j < len - 1 && nums[j + 1] < maxi)
        j++;
    return j + 1 - i;
}
