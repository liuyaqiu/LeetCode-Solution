#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void print(vector<vector<string>>& dp) {
    for(auto iter1 = dp.begin(); iter1 != dp.end(); iter1++) {
        cout << iter1 - dp.begin() << endl;
        for(auto iter2 = iter1->begin(); iter2 != iter1->end(); iter2++)
            cout << *iter2 << " ";
        cout << endl;
    }
    cout << endl;
}

void dfs(int end, vector<vector<string>>& dp, vector<string>& result, string cur) {
    if(end == 0) {
    	result.push_back(cur.substr(0, cur.length() - 1));
        return;
    }
    else {
        for(auto iter = dp[end].begin(); iter != dp[end].end(); iter++) {
            string comb = *iter + " " + cur;
            dfs(end - iter->length(), dp, result, comb);
        }
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    vector<vector<string>> dp(n + 1, vector<string>());
    dp[0].push_back("");
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    for(int i = 0; i < n; i++) {
        if(!dp[i].empty()) {
            for(int j = i + 1; j <= n; j++) {
                string sub = s.substr(i, j - i);
                if(dict.find(sub) != dict.end()) {
                    dp[j].push_back(sub);
                }
            }
        }
    }
    vector<string> result;
    vector<string> tmp;
    dfs(n, dp, result, "");
    return result;
}

int main() {
    string s;
    cin >> s;
    string val;
    vector<string> dict;
    while(cin >> val) {
        dict.push_back(val);
    }
    vector<string> res = wordBreak(s, dict);
    for(auto iter = res.begin(); iter != res.end(); iter++)
        cout << *iter << endl;
    cout << endl;
    return 0;
}

//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa a aa aaa aaaa aaaaa aaaaaa aaaaaaa aaaaaaaa aaaaaaaaa aaaaaaaaaa
