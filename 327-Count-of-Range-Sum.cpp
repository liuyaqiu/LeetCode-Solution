#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

/*
 * Count of Range Sum
 *
 * Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
 * Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
 *
 * Note:
 * A naive algorithm of O(n2) is trivial. You MUST do better than that.
 *
 * Example:
 * Given nums = [-2, 5, -1], lower = -2, upper = 2,
 * Return 3.
 * The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
 *
 *
 */

vector<long long> buildPrefixSum(const vector<int>& nums) {
    vector<long long> prefixSum(nums.size() + 1, 0);
    for(int i = 1; i <= nums.size(); ++i) {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }
    return prefixSum;
}

int countRangeSum(vector<int>& nums, int lower, int upper) {
    if(nums.empty())
        return 0;
    const int n = nums.size();
    auto prefixSum = buildPrefixSum(nums);
    int count = 0;
    multiset<long long> ordered_sums;
    for(int i = n; i >= 1; --i) {
        ordered_sums.insert(prefixSum[i]);
        auto lb_iter = ordered_sums.lower_bound(lower + prefixSum[i - 1]);
        auto rb_iter = ordered_sums.upper_bound(upper + prefixSum[i - 1]);
        count += distance(lb_iter, rb_iter);
    }
    return count;
}
