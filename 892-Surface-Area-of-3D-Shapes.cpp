class Solution {
public:
    void DFS(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int& res) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        res += 2;
        if (i - 1 < 0 ) {
            res += grid[i][j];
        } else {
            res += max(0, grid[i][j] - grid[i - 1][j]);
        }
        if (j + 1 >= n) {
            res += grid[i][j];
        } else {
            res += max(0, grid[i][j] - grid[i][j + 1]);
        }
        if (i + 1 >= m) {
            res += grid[i][j];
        } else {
            res += max(0, grid[i][j] - grid[i + 1][j]);
        }
        if (j - 1 < 0) {
            res += grid[i][j];
        } else {
            res += max(0, grid[i][j] - grid[i][j - 1]);
        }
        DFS(grid, visited, i - 1, j, res);
        DFS(grid, visited, i + 1, j, res);
        DFS(grid, visited, i, j - 1, res);
        DFS(grid, visited, i, j + 1, res);
    }
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                DFS(grid, visited, i, j, res);
            }
        }
        return res;
    }
};