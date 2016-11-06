#include <iostream>
#include <string>
#include <vector>

using namespace std;

long int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<long int>> paths = vector<vector<long int>>(m, vector<long int>(n, 0));
    for(int i = 0; i < m; ++i) {
    	if(obstacleGrid[i][0] == 0)
        	paths[i][0] = 1;
        else
        	break;
    }
    for(int j = 0; j < n; ++j) {
    	if(obstacleGrid[0][j] == 0)
        	paths[0][j] = 1;
        else
        	break;
    }
    for(int i = 1; i < m; ++i) {
        for(int j = 1; j < n; ++j) {
            if(obstacleGrid[i][j] == 0)
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
        }
    }
    return paths[m - 1][n - 1];
}
