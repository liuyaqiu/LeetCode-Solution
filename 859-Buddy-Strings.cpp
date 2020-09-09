class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        int index = -1;
        bool swaped = false;
        vector<int> cnt(26, 0);
        for (int i = 0; i < A.length(); i++) {
            cnt[A[i] - 'a'] += 1;
            if (A[i] != B[i]) {
                if (swaped) {
                    return false;
                }
                if (index == -1) {
                    index = i;
                } else {
                    if (A[i] == B[index] && A[index] == B[i]) {
                        swaped = true;
                    }
                }
            }
        }
        if (swaped) {
            return true;
        }
        if (A != B) {
            return false;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 1) {
                return true;
            }
        }
        return false;
    }
};