#include <iostream>
#include <vector>

using namespace std;

/*
 * Longest Increasing Subsequence
 *
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 *
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
 *
 * Your algorithm should run in O(n2) complexity.
 *
 * Follow up: Could you improve it to O(n log n) time complexity?
 *
 *
 */

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> cnt(n, 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j])
                cnt[i] = max(cnt[i], cnt[j] + 1);
        }
    }
    int res = 1;
    for(int i = 0; i < n; i++) {
        if(cnt[i] > res)
            res = cnt[i];
    }
    return res;
}

int lengthOfLIS2(vector<int>& nums) {
    if(nums.empty())
        return 0;
    vector<int> inc;
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        if(inc.empty() || *iter > inc.back())
            inc.push_back(*iter);
        else {
            int i = 0, j = inc.size() - 1;
            while(i < j) {
                int mid = (i + j) / 2;
                if(inc[mid] < *iter)
                    i = mid + 1;
                else
                    j = mid;
            }
            inc[j] = *iter;
        }
    }
    return inc.size();
}
