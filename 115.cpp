#include <iostream>
#include <vector>

using namespace std;

int numDistinct(string s, string t) {
    int ns = s.length();
    int nt = t.length();
    vector<vector<int>> dp(ns + 1, vector<int>(nt + 1));
    for(int i = 0; i <= ns; i++) {
        for(int j = 0; j <= nt; j++) {
            if(i == 0) {
                if(j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            else {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];     //取s中的第i - 1个字符，继续匹配剩余的字符，或者不取第i - 1个字符，匹配当前字符串
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    return dp[ns][nt];
}

int main() {
    string s, t;
    cin >> s >> t;
    int res = numDistinct(s, t);
    cout << res << endl;
    return 0;
}
