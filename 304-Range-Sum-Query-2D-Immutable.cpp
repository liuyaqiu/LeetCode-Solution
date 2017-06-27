#include <iostream>
#include <vector>

using namespace std;

/*
 * Range Sum Query 2D - Immutable
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 *
 * Range Sum Query 2D
 * The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
 *
 * Example:
 * Given matrix = [
 *   [3, 0, 1, 4, 2],
 *   [5, 6, 3, 2, 1],
 *   [1, 2, 0, 1, 5],
 *   [4, 1, 0, 1, 7],
 *   [1, 0, 3, 0, 5]
 *   ]
 *
 *   sumRegion(2, 1, 4, 3) -> 8
 *   sumRegion(1, 1, 2, 2) -> 11
 *   sumRegion(1, 2, 2, 4) -> 12
 *   Note:
 *   You may assume that the matrix does not change.
 *   There are many calls to sumRegion function.
 *   You may assume that row1 ≤ row2 and col1 ≤ col2.
 *
 *
 */

class NumMatrix {
private:
    vector<vector<int>> res;

public:
    NumMatrix(vector<vector<int>> matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        res = vector<vector<int>>(m, vector<int>(n, 0));
        int sum = 0;
        for(int i = 0; i < m; i++) {
            sum += matrix[i][0];
            res[i][0] = sum;
        }
        sum = 0;
        for(int j = 0; j < n; j++) {
            sum += matrix[0][j];
            res[0][j] = sum;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                res[i][j] = res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 > 0) {
            if(col1 > 0)
                return res[row2][col2] - res[row1 - 1][col2] - res[row2][col1 - 1] + res[row1 - 1][col1 - 1]; 
            else
                return res[row2][col2] - res[row1 - 1][col2];
        }
        else {
            if(col1 > 0)
                return res[row2][col2] - res[row2][col1 - 1];
            else
                return res[row2][col2];
        }
    }
};

