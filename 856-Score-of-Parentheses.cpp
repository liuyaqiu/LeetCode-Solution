class Solution {
public:
    int scoreOfParentheses(string S) {
        vector<int> res;
        int left = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '(') {
                if (left >= res.size()) {
                    res.push_back(0);
                }
                left++;
            } else {
                left--;
                if (left + 1 >= res.size()) {
                    res[left] += 1;
                } else {
                    res[left] += 2 * res[left + 1];
                    res.pop_back();
                }
            }
        }
        return res[0];
    }

    int scoreOfParentheses(string S) {
        int left = 0;
        int res = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '(') {
                left++;
            } else {
                left--;
                if (i - 1 >= 0 && S[i - 1] == '(') {
                    res += 1 << left;
                }
            }
        }
        return res;
    }
};