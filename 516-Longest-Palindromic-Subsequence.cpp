#include <iostream>
#include <vector>

using namespace std;

int longestPalindromeSubseq(string s) {
	if(s.empty())
		return 0;
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 1));
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == s[i + 1])
            dp[i][i + 1] = 2;
    }
    for(int delta = 2; delta < n; delta++) {
        for(int i = 0; i < n - delta; i++) {
            if(s[i] == s[i + delta])
                dp[i][i + delta] = dp[i + 1][i + delta - 1] + 2;
            else
                dp[i][i + delta] = max(dp[i][i + delta - 1], dp[i + 1][i + delta]);
        }
    }
    for(auto row: dp) {
        for(auto item: row)
            cout << item << " ";
        cout << endl;
    }
    cout << endl;
    return dp[0][n - 1];
}

int main() {
    string s;
    cin >> s;
    int res = longestPalindromeSubseq(s);
    cout << res << endl;
    return 0;
}
