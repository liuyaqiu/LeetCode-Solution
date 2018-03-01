/*
  Contain Virus

  A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

  The world is modeled as a 2-D array of cells, where 0 represents uninfected cells, and 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.

  Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region -- the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night. There will never be a tie.

  Can you save the day? If so, what is the number of walls required? If not, and the world becomes fully infected, return the number of walls used.

  Example 1:
  Input: grid = 
  [[0,1,0,0,0,0,0,1],
  [0,1,0,0,0,0,0,1],
  [0,0,0,0,0,0,0,1],
  [0,0,0,0,0,0,0,0]]
  Output: 10
  Explanation:
  There are 2 contaminated regions.
  On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:

  [[0,1,0,0,0,0,1,1],
  [0,1,0,0,0,0,1,1],
  [0,0,0,0,0,0,1,1],
  [0,0,0,0,0,0,0,1]]

  On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.
  Example 2:
  Input: grid = 
  [[1,1,1],
  [1,0,1],
  [1,1,1]]
  Output: 4
  Explanation: Even though there is only one cell saved, there are 4 walls built.
  Notice that walls are only built on the shared boundary of two different cells.
  Example 3:
  Input: grid = 
  [[1,1,1,0,0,0,0,0,0],
  [1,0,1,0,1,1,1,1,1],
  [1,1,1,0,0,0,0,0,0]]
  Output: 13
  Explanation: The region on the left only builds two new walls.
  Note:
  The number of rows and columns of grid will each be in the range [1, 50].
  Each grid[i][j] will be either 0 or 1.
  Throughout the described process, there is always a contiguous viral region that will infect strictly more uncontaminated squares in the next round.

 */

#include <iostream>
#include <vector>

using namespace std;

//计算从i,j开始的区域今晚可以感染多少个cell,并且计算围住该区域所需要的围墙数量
void dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visit, vector<vector<int>>& infected, vector<vector<int>>& all, int i, int j, int& infect, int& walls) {
    int m = grid.size(), n = grid[0].size();
    if(visit[i][j] || grid[i][j] != 1)
        return;
    visit[i][j] = true;
    if(i - 1 >= 0) {
        if(grid[i - 1][j] == 0) {
            infect += 1 ^ infected[i - 1][j];
            all[i - 1][j] += 1 ^ infected[i - 1][j];
            infected[i - 1][j] = 1;
            walls += 1;
        }
        dfs(grid, visit, infected, all, i - 1, j, infect, walls);
    }
    if(i + 1 < m) {
        if(grid[i + 1][j] == 0) {
            infect += 1 ^ infected[i + 1][j];
            all[i + 1][j] += 1 ^ infected[i + 1][j];
            infected[i + 1][j] = 1;
            walls += 1;
        }
        dfs(grid, visit, infected, all, i + 1, j, infect, walls);
    }
    if(j - 1 >= 0) {
        if(grid[i][j - 1] == 0) {
            infect += 1 ^ infected[i][j - 1];
            all[i][j - 1] += 1 ^ infected[i][j - 1];
            infected[i][j - 1] = 1;
            walls += 1;
        }
        dfs(grid, visit, infected, all, i, j - 1, infect, walls);
    }
    if(j + 1 < n) {
        if(grid[i][j + 1] == 0) {
            infect += 1 ^ infected[i][j + 1];
            all[i][j + 1] += 1 ^ infected[i][j + 1];
            infected[i][j + 1] = 1;
            walls += 1;
        }
        dfs(grid, visit, infected, all, i, j + 1, infect, walls);
    }
}

void dfs2(vector<vector<int>>& grid, vector<vector<bool>>& visit, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    if(visit[i][j] || grid[i][j] != 1)
        return;
    visit[i][j] = true;
    grid[i][j] = -1;
    if(i - 1 >= 0)
        dfs2(grid, visit, i - 1, j);
    if(i + 1 < m)
        dfs2(grid, visit, i + 1, j);
    if(j - 1 >= 0)
        dfs2(grid, visit, i, j - 1);
    if(j + 1 < n)
        dfs2(grid, visit, i, j + 1);
}

int solve(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int maxi = 0;
    int res = 0;
    int p = -1, q = -1;
    vector<vector<int>> choice(m, vector<int>(n, 0));
    vector<vector<int>> all(m, vector<int>(n, 0));
    vector<vector<bool>> visit1(m, vector<bool>(n, false));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            vector<vector<int>> infected(m, vector<int>(n, 0));
            int walls = 0;
            int infect = 0;
            dfs(grid, visit1, infected, all, i, j, infect, walls);
            if(infect > maxi) {
                maxi = infect;
                choice = infected;
                res = walls;
                p = i;
                q = j;
            }
        }
    }
    vector<vector<bool>> visit2(m, vector<bool>(n, false));
    if(p != -1 && q != -1)
        dfs2(grid, visit2, p, q);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            all[i][j] -= choice[i][j]; //排除已经被围住的区域
            if(all[i][j] > 0)
                grid[i][j] = 1; //i,j处仍然被感染，更新grid
        }
    }
    return res;
}

int containVirus(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int res = 0;
    int tmp = solve(grid);
    while(tmp > 0) {
        res += tmp;
        tmp = solve(grid);
    }
    return res;
}
