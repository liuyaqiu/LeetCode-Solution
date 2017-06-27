#include <iostream>
#include <vector>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for(int i = 0; i < n; i++) {
        if(!dp[i])
            continue;
        for(auto iter = wordDict.begin(); iter != wordDict.end(); iter++) {
            int len = iter->length();
            int end = i + len;
            if(end > s.length())
                continue;
            if(dp[end])
                continue;
            if(s.substr(i, len) == *iter)
                dp[end] = true;
        }
    }
    return dp[n];
}

int main() {
    string s;
    cin >> s;
    string val;
    vector<string> dict;
    while(cin >> val) {
        dict.push_back(val);
    }
    bool res = wordBreak(s, dict);
    if(res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
