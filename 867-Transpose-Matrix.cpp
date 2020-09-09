class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> transposed(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                transposed[j][i] = A[i][j];
            }
        }
        return transposed;
    }
};