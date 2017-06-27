#include <iostream>
#include <vector>

using namespace std;

int eval(vector<vector<int>>& grid, int i, int j) {
    int m = grid.size();
    int n = grid.front().size();
    int res = 0;
    if(grid[i][j] == 0) {
        if(i - 1 >= 0 && grid[i - 1][j] == 1)
            res += 1;
        if(i + 1 < m && grid[i + 1][j] == 1)
            res += 1;
        if(j - 1 >= 0 && grid[i][j - 1] == 1)
            res += 1;
        if(j + 1 < n && grid[i][j + 1] == 1)
            res += 1;
    }
    else {
        if(i == 0)
            res += 1;
        if(i == m - 1)
            res += 1;
        if(j == 0)
            res += 1;
        if(j == n - 1)
            res += 1;
    }
    return res;
}

int islandPerimeter(vector<vector<int>>& grid) {
    if(grid.empty())
        return 0;
    int m = grid.size();
    int n = grid.front().size();
    int res = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            res += eval(grid, i, j);
    }
    return res;
}
