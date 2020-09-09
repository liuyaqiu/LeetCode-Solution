class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    res += 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                cur = max(cur, grid[i][j]);
            }
            res += cur;
        }
        for (int j = 0; j < n; j++) {
            int cur = 0;
            for (int i = 0; i < m; i++) {
                cur = max(cur, grid[i][j]);
            }
            res += cur;
        }
        return res;
    }
};