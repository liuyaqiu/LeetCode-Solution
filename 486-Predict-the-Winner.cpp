#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> mypair;

mypair optSelect(vector<vector<mypair>>& dp, vector<int>& nums, int i, int j) {
    if(dp[i][j] != mypair(-1, -1))
        return dp[i][j];
    if(i >= j)
        return mypair(nums[i], 0);
    mypair nx_i = optSelect(dp, nums, i + 1, j);
    int score_iA = nums[i] + nx_i.second;
    int score_iB = nx_i.first;
    int delta_i = score_iA - score_iB;
    mypair nx_j = optSelect(dp, nums, i, j - 1);
    int score_jA = nums[j] + nx_j.second;
    int score_jB = nx_j.first;
    int delta_j = score_jA - score_jB;
    mypair res = delta_i >= delta_j ? mypair(score_iA, score_iB) : mypair(score_jA, score_jB);
    dp[i][j] = res;
    return res;
}

bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    //记忆化搜索
    vector<vector<mypair>> dp(n, vector<mypair>(n, mypair(-1, -1)));
    mypair res = optSelect(dp, nums, 0, n - 1);
    cout << res.first << " " << res.second << endl;
    return res.first >= res.second;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    int res = PredictTheWinner(nums);
    cout << res << endl;
    return 0;
}

