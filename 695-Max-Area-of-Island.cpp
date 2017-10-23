/*
  Max Area of Island

  Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

  Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

 */

#include <iostream>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int i, int j, int& res) {
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visit[i][j])
        return;
    visit[i][j] = true; // 不需要恢复visit,这样可以保证每个岛屿区域的点都只访问一次，保证总体的复杂度为O(m * n)
    if(grid[i][j] == 0)
        return;
    res += 1;
    bfs(grid, visit, i - 1, j, res);
    bfs(grid, visit, i + 1, j, res);
    bfs(grid, visit, i, j - 1, res);
    bfs(grid, visit, i, j + 1, res);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    int res = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int tmp = 0;
            bfs(grid, visit, i, j, tmp);
            res = max(res, tmp);
        }
    }
    return res;
}
