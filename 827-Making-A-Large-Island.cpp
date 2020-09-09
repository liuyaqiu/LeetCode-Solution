class Solution {
public:
    void DFS(const vector<vector<int>>& grid, int i, int j, int& island_size, vector<vector<bool>>& visited, vector<int>& boarder) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        if (grid[i][j] == 0) {
            if (island_size > 0) {
                boarder.push_back(i * n + j);
            }
            return;
        }
        if (visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        island_size += 1;
        DFS(grid, i - 1, j, island_size, visited, boarder);
        DFS(grid, i + 1, j, island_size, visited, boarder);
        DFS(grid, i, j - 1, island_size, visited, boarder);
        DFS(grid, i, j + 1, island_size, visited, boarder);
    }

    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> island_to_size;
        unordered_map<int, unordered_set<int>> boarder_to_islands;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int island_size = 0;
                vector<int> boarder;
                DFS(grid, i, j, island_size, visited, boarder);
                int index = i * n + j;
                if (island_size > 0) {
                    island_to_size[index] = island_size;
                }
                for (int boarder_index : boarder) {
                    if (!boarder_to_islands.count(boarder_index)) {
                        boarder_to_islands[boarder_index] = {};
                    }
                    boarder_to_islands[boarder_index].insert(index);
                }
            }
        }
        if (boarder_to_islands.empty()) {
            if (island_to_size.empty()) {
                return 1;
            }
            return m * n;
        }
        int res = 0;
        for (const auto& boarder_and_islands : boarder_to_islands) {
            int sum = 1;
            for (int island : boarder_and_islands.second) {
                sum += island_to_size[island];
            }
            res = max(res, sum);
        }
        return res;
    }
};