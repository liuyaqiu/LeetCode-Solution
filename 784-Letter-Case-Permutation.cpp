class Solution {
public:
    bool isLower(char x) {
        return x - 'a' >= 0 && x - 'a' < 26;
    }
    bool isUpper(char x) {
        return x - 'A' >= 0 && x - 'A' < 26;
    }
    char getLower(char x) {
        return isLower(x) ? x : x - 'A' + 'a';
    }
    char getUpper(char x) {
        return isUpper(x) ? x : x - 'a' + 'A';
    }

    void dfs(vector<vector<char>> candidates, int index, string cur, vector<string>& res) {
        if (index >= candidates.size()) {
            res.push_back(cur);
            return;
        }
        for (char x : candidates[index]) {
            dfs(candidates, index + 1, cur + x, res);
        }
    }

    vector<string> letterCasePermutation(string S) {
        vector<vector<char>> candidates;
        for (int i = 0; i < S.length(); i++) {
            if (isLower(S[i]) || isUpper(S[i])) {
                candidates.push_back({getLower(S[i]), getUpper(S[i])});
            } else {
                candidates.push_back({S[i]});
            }
        }
        vector<string> res;
        dfs(candidates, 0, "", res);
        return res;
    }
};