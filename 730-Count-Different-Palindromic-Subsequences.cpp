/*
  Count Different Palindromic Subsequences

  Given a string S, find the number of different non-empty palindromic subsequences in S, and return that number modulo 10^9 + 7.

  A subsequence of a string S is obtained by deleting 0 or more characters from S.

  A sequence is palindromic if it is equal to the sequence reversed.

  Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there is some i for which A_i != B_i.

  Example 1:
  Input: 
  S = 'bccb'
  Output: 6
  Explanation: 
  The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
  Note that 'bcb' is counted only once, even though it occurs twice.
  Example 2:
  Input: 
  S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
  Output: 104860361
  Explanation: 
  There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.
  Note:

  The length of S will be in the range [1, 1000].
  Each character S[i] will be in the set {'a', 'b', 'c', 'd'}.

 */

#define mod 1000000007

class Solution {
public:
    vector<vector<int>> prev, next, dp;

    int solve(int i, int j) {
        if(i > j)
            return 0;
        if(dp[i][j] > 0)
            return dp[i][j];
        int res = 0;
        /*
        solve 为[i, j]范围内非空解的个数，可以分为以下四种情况
        aa, a, a[solve(i + 1, j - 1)]a
        bb, b, b[solve(i + 1, j - 1)]b
        cc, c, c[solve(i + 1, j - 1)]c
        dd, d, d[solve(i + 1, j - 1)]d
        */
        for(int k = 0; k < 4; k++) {
            int ii = next[i][k];
            int jj = prev[j][k];
            if(ii < 0)
                continue;
            if(ii < jj)
                res = (res + 1) % mod;
            if(ii <= j)
                res = (res + solve(ii + 1, jj - 1) + 1) % mod;
        }
        dp[i][j] = res;
        return res;
    }

    int countPalindromicSubsequences(string S) {
        int n = S.length();
        prev = vector<vector<int>>(n, vector<int>(4, -1));
        next = vector<vector<int>>(n, vector<int>(4, -1));
        dp = vector<vector<int>>(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 4; j++) {
                if(S[i] - 'a' == j)
                    prev[i][j] = i;
                else {
                    if(i > 0)
                        prev[i][j] = prev[i - 1][j];
                }
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < 4; j++) {
                if(S[i] - 'a' == j)
                    next[i][j] = i;
                else {
                    if(i < n - 1)
                        next[i][j] = next[i + 1][j];
                }
            }
        }

        return solve(0, n - 1);
    }
};
