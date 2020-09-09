char shift(char c, int x) {
    return 'a' + (c - 'a' + x) % 26;
}

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        vector<long long> prefix(S.length(), 0);
        for (int i = S.length() - 1; i>= 0; i--) {
            if (i + 1 < S.length()) {
                prefix[i] = prefix[i + 1];
            }
            if (i < shifts.size()) {
                prefix[i] = (shifts[i] + prefix[i]) % 26;
            }
        }
        string res;
        for (int i = 0; i < S.length(); i++) {
            res += shift(S[i], prefix[i]);
        }
        return res;
    }
};