class Solution {
public:
    bool isLower(char c) {
        return c - 'a' >= 0 && c - 'a' < 26;
    }

    string customSortString(string S, string T) {
        vector<int> count(26, 0);
        int sum = 0;
        for (int i = 0; i < T.length(); i++) {
            if (isLower(T[i])) {
                count[T[i] - 'a'] += 1;
                sum += 1;
            }
        }
        string res;
        for (int i = 0; i < S.length(); i++) {
            for (int j = 0; j < count[S[i] - 'a']; j++) {
                res += S[i];
            }
            count[S[i] - 'a'] = 0;
        }
        for (int i = 0; i < T.length(); i++) {
            if (!isLower(T[i]) || count[T[i] - 'a'] > 0) {
                res += T[i];
            }
        }
        return res;
    }
};