/*
  Maximum Sum of 3 Non-Overlapping Subarrays

  In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

  Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

  Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

  Example:
  Input: [1,2,1,2,6,7,5,1], 2
  Output: [0, 3, 5]
  Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
  We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
  Note:
  nums.length will be between 1 and 20000.
  nums[i] will be between 1 and 65535.
  k will be between 1 and floor(nums.length / 3).

 */

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print(vector<T>& nums) {
    for(auto item: nums)
        cout << item << " ";
    cout << endl;
}

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> left(n, -1);
    vector<int> lsums(n, -1);
    vector<int> right(n, -1);
    vector<int> rsums(n, -1);
    vector<int> sums(n, -1);
    int s = 0;
    for(int i = 0; i < k; i++)
        s += nums[i];
    sums[0] = s;
    for(int i = k; i < n; i++) {
        s += nums[i] - nums[i - k];
        sums[i - k + 1] = s;
    }
    int lsum = 0;
    for(int i = 0; i < k; i++)
        lsum += nums[i];
    int lindex = 0;
    left[k - 1] = lindex;
    lsums[k - 1] = lsum;
    int lmax = lsum;
    for(int i = k; i < n; i++) {
        lsum += nums[i] - nums[i - k];
        if(lsum > lmax) {
            lmax = lsum;
            lindex = i - k + 1;
        }
        left[i] = lindex;
        lsums[i] = lmax;
    }
    int rsum = 0;
    for(int i = n - 1; i >= n - k; i--)
        rsum += nums[i];
    int rindex = n - k;
    right[n - k] = rindex;
    rsums[n - k] = rsum;
    int rmax = rsum;
    for(int i = n - k - 1; i >= 0; i--) {
        rsum += nums[i] - nums[i + k];
        if(rsum >= rmax) {
            rmax = rsum;
            rindex = i;
        }
        right[i] = rindex;
        rsums[i] = rmax;
    }
    /*
    print<int>(sums);
    print<int>(lsums);
    print<int>(left);
    print<int>(rsums);
    print<int>(right);
    */
    int maxi = 0;
    int l = -1, m = -1, r = -1;
    for(int i = k; i <= n - 2 * k; i++) {
        int tmp = sums[i] + lsums[i - 1] + rsums[i + k];
        if(tmp > maxi) {
            maxi = tmp;
            l = left[i - 1];
            m = i;
            r = right[i + k];
        }
    }
    return {l, m, r};
}
