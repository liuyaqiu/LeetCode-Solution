class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int fliped = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '0') {
                fliped += 1;
            }
        }
        int res = fliped;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '0') {
                fliped -= 1;
            } else {
                fliped += 1;
            }
            res = min(res, fliped);
        }
        return res;
    }
};