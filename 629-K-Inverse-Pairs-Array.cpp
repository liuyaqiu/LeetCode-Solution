/*
  K Inverse Pairs Array

  Given two integers n and k, find how many different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs.

  We define an inverse pair as following: For ith and jth element in the array, if i < j and a[i] > a[j] then it's an inverse pair; Otherwise, it's not.

  Since the answer may be very large, the answer should be modulo 109 + 7.

  Example 1:
  Input: n = 3, k = 0
  Output: 1
  Explanation:
  Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pair.
  Example 2:
  Input: n = 3, k = 1
  Output: 2
  Explanation:
  The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.

  Note:
  The integer n is in the range [1, 1000] and k is in the range [0, 1000].
 */

#include <iostream>
#include <vector>

using namespace std;

#define mod 1000000007

int kInversePairs(int n, int k) {
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
    for(int i = 1; i <= n; i++)
        dp[i][0] = 1;
    vector<vector<long long>> prefix(n + 1, vector<long long>(k + 1, 0));
    for(int i = 1; i <= n; i++)
        prefix[i][0] = 1;
    for(int j = 1; j <= k; j++)
        prefix[1][j] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j >= i)
                dp[i][j] = (prefix[i - 1][j] - prefix[i - 1][j - i] + mod) % mod;
            else
                dp[i][j] = prefix[i - 1][j];
            prefix[i][j] = (prefix[i][j - 1] + dp[i][j]) % mod;
        }
    }
    return dp[n][k];
}
