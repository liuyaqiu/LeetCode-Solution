#include <iostream>
#include <vector>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(auto s: strs) {
        int zero = 0;
        int one = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0')
                zero += 1;
            else
                one += 1;
        }
        for(int i = m; i >= zero; i--) {
            for(int j = n; j >= one; j--) {
                dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
            }
        }
    }
    return dp[m][n];
}
