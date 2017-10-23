/*
  Student Attendance Record II

  Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.

  A student attendance record is a string that only contains the following three characters:

  'A' : Absent.
  'L' : Late.
  'P' : Present.
  A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

  Example 1:
  Input: n = 2
  Output: 8 
  Explanation:
  There are 8 records with length 2 will be regarded as rewardable:
  "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
  Only "AA" won't be regarded as rewardable owing to more than one absent times. 
  Note: The value of n won't exceed 100,000.

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define mod 1000000007

int checkRecord(int n) {
    if(n == 1)
        return 3;
    vector<vector<long long>> cnt(8, vector<long long>(2, 0));
    vector<vector<long long>> dp(8, vector<long long>(2, 0));
    for(int i = 0; i < 8; i++) {
        if(i < 3 || i == 5)
            cnt[i][1] = 1;
        else
            cnt[i][0] = 1;
    }
    for(int i = 3; i <= n; i++) {
        dp[0][1] = (cnt[2][1] + cnt[5][1]) % mod;
        dp[1][1] = (cnt[2][1] + cnt[5][1]) % mod;
        dp[2][1] = (cnt[3][0] + cnt[6][0]) % mod;
        dp[3][0] = cnt[6][0];
        dp[3][1] = (cnt[0][1] + cnt[6][1]) % mod;
        dp[4][0] = (cnt[3][0] + cnt[6][0]) % mod;
        dp[4][1] = (cnt[0][1] + cnt[3][1] + cnt[6][1]) % mod;
        dp[5][1] = (cnt[4][0] + cnt[7][0]) % mod;
        dp[6][0] = (cnt[4][0] + cnt[7][0]) % mod;
        dp[6][1] = (cnt[1][1] + cnt[4][1] + cnt[7][1]) % mod;
        dp[7][0] = (cnt[4][0] + cnt[7][0]) % mod;
        dp[7][1] = (cnt[1][1] + cnt[4][1] + cnt[7][1]) % mod;
        cnt = dp;
    }
    long long res = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 2; j++)
            res = (res + cnt[i][j]) % mod;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int res = checkRecord(n);
    cout << res << endl;
    return 0;
}
