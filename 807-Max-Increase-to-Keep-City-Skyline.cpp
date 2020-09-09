class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.empty() || grid.front().empty()) {
            return 0;
        }
        vector<int> row_max(grid.size(), -1);
        vector<int> col_max(grid.front().size(), -1);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                row_max[i] = max(row_max[i], grid[i][j]);
                col_max[j] = max(col_max[j], grid[i][j]);
            }
        }
        int res = ;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                res += min(row_max[i], col_max[j]) - grid[i][j];
            }
       }
        return res;
    }
};