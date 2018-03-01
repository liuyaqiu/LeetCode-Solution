/*
  Cherry Pickup

  In a N x N grid representing a field of cherries, each cell is one of three possible integers.

  0 means the cell is empty, so you can pass through;
  1 means the cell contains a cherry, that you can pick up and pass through;
  -1 means the cell contains a thorn that blocks your way.
  Your task is to collect maximum number of cherries possible by following the rules below:

  Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
  After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
  When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
  If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.
  Example 1:
  Input: grid =
  [[0, 1, -1],
  [1, 0, -1],
  [1, 1,  1]]
  Output: 5
  Explanation: 
  The player started at (0, 0) and went down, down, right right to reach (2, 2).
  4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
  Then, the player went left, up, up, left to return home, picking up one more cherry.
  The total number of cherries picked up is 5, and this is the maximum possible.
  Note:

  grid is an N by N 2D array, with 1 <= N <= 50.
  Each grid[i][j] is an integer in the set {-1, 0, 1}.
  It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.

 */

#include <iostream>
#include <vector>
#include <numeric_limits>

using namespace std;

#define inf numeric_limits<int>::min()

int cherryPickup(vector<vector<int>>& grid) {
    int N = grid.size();
    vector<vector<int>> dp(N, vector<int>(N, inf));
    dp[0][0] = grid[0][0];
    for(int t = 1; t <= 2 * N - 2; t++) {
        vector<vector<int>> dp2(N, vector<int>(N, inf));
        for(int i = max(0, t - (N - 1)); i <= min(N - 1, t); i++) {
            for(int j = max(0, t - (N - 1)); j <= min(N - 1, t); j++) {
                if(grid[i][t - i] == -1 || grid[j][t - j] == -1)
                    continue;
                int val = grid[i][t - i];
                if(i != j)
                    val += grid[j][t - j]; //i,j不等，表示当前p1,p2所在位置不同，各可以pick一个cherry
                for(int pi = i - 1; pi <= i; pi++) {
                    for(int pj = j - 1; pj <= j; pj++) {
                        if(pi >= 0 && pj >= 0)
                            dp2[i][j] = max(dp2[i][j], dp[pi][pj] + val); // (i - 1, j) --> (i, j): p1向右，p2向下, (i, j - 1) --> (i, j): p1向下，p2向右
                    }
                }
            }
        }
        dp = dp2;
    }
    return max(0, dp[N - 1][N - 1]);
}
