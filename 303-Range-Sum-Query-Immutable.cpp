#include <iostream>
#include <vector>

using namespace std;

/*
 * Range Sum Query - Immutable
 *
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 *
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 *
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 *
 *
 */

class NumArray {
private:
    vector<int> res;

public:
    NumArray(vector<int> nums) {
        res = vector<int>(nums.size(), 0);
        int tmp = 0;
        for(int i = 0; i < nums.size(); i++) {
            tmp += nums[i];
            res[i] = tmp;
        }
    }

    int sumRange(int i, int j) {
        if(i < 0 || i >= res.size() || j < 0 || j >= res.size())
            return 0;
        if(i == 0)
            return res[j];
        else
            return res[j] - res[i - 1];
    }
};

