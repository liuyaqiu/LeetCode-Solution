#include <iostream>
#include <vector>

using namespace std;

/*
 * Burst Balloons
 *
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
 *
 * Find the maximum coins you can collect by bursting the balloons wisely.
 *
 * Note: 
 * (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
 * (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 *
 * Example:
 *
 * Given [3, 1, 5, 8]
 *
 * Return 167
 *
 *     nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
 *        coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 *
 *
*/

void print(vector<vector<int>>& res) {
    for(auto& col: res) {
        for(auto& val: col)
            cout << val << " ";
        cout << endl;
    }
    cout << endl;
}

class Solution {
private:
    vector<vector<int>> dp;
    vector<int> values;

    int DP(int i, int j) {
        if(dp[i][j] > 0)
            return dp[i][j];
        for(int x = i; x <= j; x++)
            dp[i][j] = max(dp[i][j], DP(i, x - 1) + values[i - 1] * values[x] * values[j + 1] + DP(x + 1, j));
        return dp[i][j];
    }

public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        dp = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
        values.push_back(1);
        for(auto num: nums)
            values.push_back(num);
        values.push_back(1);
        return DP(1, n);
    }
};

