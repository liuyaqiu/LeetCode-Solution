#include <iostream>
#include <vector>

using namespace std;

/*
 * Pacific Atlantic Water Flow
 *
 * Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
 *
 * Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
 *
 * Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
 *
 * Note:
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 * Example:
 *
 * Given the following 5x5 matrix:
 *
 *  Pacific ~   ~   ~   ~   ~ 
 *       ~  1   2   2   3  (5) *
 *       ~  3   2   3  (4) (4) *
 *       ~  2   4  (5)  3   1  *
 *       ~ (6) (7)  1   4   5  *
 *       ~ (5)  1   1   2   4  *
 *          *   *   *   *   * Atlantic
 *
 * Return:
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
 *
 */

template <typename T> void printMatrix(vector<vector<T>>& matrix) {
    for(auto row: matrix) {
        for(auto item: row)
            cout << item << " ";
        cout << endl;
    }
    cout << endl;
}

typedef pair<int ,int> mypair;

void eval(vector<vector<int>>& matrix, vector<vector<bool>>& status, vector<vector<bool>>& visit, int i, int j) {
    if(!status[i][j] || visit[i][j])
        return;
    visit[i][j] = true;
    int m = matrix.size();
    int n = matrix[0].size();
    int val = matrix[i][j];
    if(i - 1 >= 0) {
        if(!status[i - 1][j] && matrix[i - 1][j] >= val) {
            status[i - 1][j] = true;
            eval(matrix, status, visit, i - 1, j);
        }
    }
    if(j - 1 >= 0) {
        if(!status[i][j - 1] && matrix[i][j - 1] >= val) {
            status[i][j - 1] = true;
            eval(matrix, status, visit, i, j - 1);
        }
    }
    if(i + 1 < m) {
        if(!status[i + 1][j] && matrix[i + 1][j] >= val) {
            status[i + 1][j] = true;
            eval(matrix, status, visit, i + 1, j);
        }
    }
    if(j + 1 < n) {
        if(!status[i][j + 1] && matrix[i][j + 1] >= val) {
            status[i][j + 1] = true;
            eval(matrix, status, visit, i, j + 1);
        }
    }
    visit[i][j] = false;
}

vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    for(int i = 0; i < m; i++) {
        pacific[i][0] = true;
        atlantic[i][n - 1] = true;
    }
    for(int j = 0; j < n; j++) {
        pacific[0][j] = true;
        atlantic[m - 1][j] = true;
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            eval(matrix, pacific, visit, i, j);
            eval(matrix, atlantic, visit, i, j);
        }
    }
    vector<mypair> res;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(pacific[i][j] && atlantic[i][j])
                res.push_back(mypair(i, j));
        }
    }
    return res;
}

int main() {
    vector<vector<int>> matrix;
    int m, n;
    cin >> m >> n;
    int val;
    for(int i = 0; i < m; i++) {
        vector<int> row;
        for(int j = 0; j < n; j++) {
            cin >> val;
            row.push_back(val);
        }
        matrix.push_back(row);
    }
    vector<mypair> res = pacificAtlantic(matrix);
    for(auto p: res) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
