class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) {
            return {};
        }
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][n - 1 - j] = 1 - A[i][j];
            }
        }
        return res;
    }
};