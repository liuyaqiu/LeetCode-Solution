/*
  Image Smoother

  Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

  Example 1:
  Input:
  [[1,1,1],
  [1,0,1],
  [1,1,1]]
  Output:
  [[0, 0, 0],
  [0, 0, 0],
  [0, 0, 0]]
  Explanation:
  For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
  For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
  For the point (1,1): floor(8/9) = floor(0.88888889) = 0
  Note:
  The value in the given matrix is in the range of [0, 255].
  The length and width of the given matrix are in the range of [1, 150].
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int surrounding(vector<vector<int>>& M, int i, int j) {
    int res = 0;
    int m = M.size();
    int n = M[0].size();
    int cnt = 0;
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            if(i + dx >= 0 && i + dx < m && j + dy >= 0 && j + dy < n) {
                res += M[i + dx][j + dy];
                cnt += 1;
            }
        }
    }
    return floor(res * 1.0 / cnt);
}

vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    int m = M.size();
    int n = M[0].size();
    vector<vector<int>> res(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            res[i][j] = surrounding(M, i, j);
    }
    return res;
}
