#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(vector<int>& nums, int i, int sum, int S, int& res) {
    int n = nums.size();
    if(i >= n) {
        if(sum == S)
            res += 1;
        return;
    }
    dfs(nums, i + 1, sum + nums[i], S, res);
    dfs(nums, i + 1, sum - nums[i], S, res);
}

int findTargetSumWays2(vector<int>& nums, int S) {
    unordered_map<int, int> dp;
    dp[0] = 1;
    for(auto num: nums) {
        unordered_map<int, int> nx_dp;
        for(auto item: dp) {
            nx_dp[item.first + num] += item.second;
            nx_dp[item.first - num] += item.second;
        }
        dp = nx_dp;
    }
    return dp[S];
}

int findTargetSumWays(vector<int>& nums, int S) {
    int res = 0;
    dfs(nums, 0, 0, S, res);
    return res;
}

int main() {
    int val;
    vector<int> nums;
    int S;
    cin >> S;
    while(cin >> val) {
        nums.push_back(val);
    }
    int res = findTargetSumWays(nums, S);
    cout << res << endl;
    return 0;
}

