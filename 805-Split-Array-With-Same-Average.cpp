class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        sort(A.begin(), A.end(), greater<int>());
        map<int, int> dp;
        dp[0] = 0; // sum为first的和总共有多少个元素.
        int N = A.size();
        int sum = 0;
        for (int val : A) {
            sum += val;
        }
        for (int val : A) {
            for (auto iter = dp.rbegin(); iter != dp.rend(); iter++) {
                int k = iter->first + val;
                int v = iter->second + 1;
                dp[k] = v; // A是逆序的保证了dp[k]是递增的，先统计的是较大的数，后统计的较小的数字。
                if (v > 0 && N - v > 0 && k * (N - v) == (sum - k) * v) {
                    return true;
                }
            }
        }
        return false;
    }
};