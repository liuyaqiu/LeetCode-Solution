class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int res = 0;
        for (int j = 0; j < A[0].length(); j++) {
            for (int i = 0; i + 1 < A.size(); i++) {
                if (A[i][j] > A[i + 1][j]) {
                    res += 1;
                    break;
                }
            }
        }
        return res;
    }
};