int convert(const vector<int>& digits) {
    int res = 0;
    for (int i = 0; i < digits.size(); i++) {
        if (digits[digits.size() - 1 - i] == 1) {
            res += 1 << i;
        }
    }
    return res;
}

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); i++) {
            int cur = convert(A[i]);
            if (cur < 1 << (A[0].size() - 1)) {
                for (int k = 0; k < A[i].size(); k++) {
                    A[i][k] = 1 - A[i][k];
                }
            }
        }
        for (int j = 0; j < A[0].size(); j++) {
            int cnt = 0;
            for (int i = 0; i < A.size(); i++) {
                cnt += A[i][j];
            }
            if (cnt <= A.size() / 2) {
                for (int i = 0; i < A.size(); i++) {
                    A[i][j] = 1 - A[i][j];
                }
            }
        }
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            res += convert(A[i]);
        }
        return res;
    }
};