#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Longest Increasing Path in a Matrix
 *
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
 *
 * Example 1:
 *
 * nums = [
 *   [9,9,4],
 *   [6,6,8],
 *   [2,1,1]
 * ]
 * Return 4
 * The longest increasing path is [1, 2, 6, 9].
 *
 * Example 2:
 *
 * nums = [
 *   [3,4,5],
 *   [3,2,6],
 *   [2,2,1]
 * ]
 * Return 4
 * The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 *
 *
 */

typedef pair<int, int> coordinate;

template<typename T>

void printMatrix(const vector<vector<T>>& matrix) {
    for(auto array: matrix) {
        for(auto item: array)
            cout << item << " ";
        cout << endl;
    }
    cout << endl;
}

vector<coordinate> neighbours(vector<vector<int>>& matrix, vector<vector<bool>>& visit, coordinate pos) {
    int x = pos.first, y = pos.second;
    int m = matrix.size(), n = matrix[0].size();
    int cur = matrix[x][y];
    vector<coordinate> res;
    if(x - 1 >= 0 && matrix[x - 1][y] > cur && !visit[x - 1][y])
        res.push_back(coordinate(x - 1, y));
    if(y - 1 >= 0 && matrix[x][y - 1] > cur && !visit[x][y - 1])
        res.push_back(coordinate(x, y - 1));
    if(x + 1 < m && matrix[x + 1][y] > cur && !visit[x + 1][y])
        res.push_back(coordinate(x + 1, y));
    if(y + 1 < n && matrix[x][y + 1] > cur && !visit[x][y + 1])
        res.push_back(coordinate(x, y + 1));
    return res;
}

void visit(vector<vector<int>>& matrix, vector<vector<int>>& res, vector<vector<bool>>& visitted, coordinate cur) {
    if(res[cur.first][cur.second] > 0)
        return;
    int cnt = 0;
    visitted[cur.first][cur.second] = true;
    vector<coordinate> nbs = neighbours(matrix, visitted, cur);
    for(auto pos: nbs) {
        visit(matrix, res, visitted, pos);
        int tmp = res[pos.first][pos.second];
        cnt = max(cnt, tmp);
    }
    visitted[cur.first][cur.second] = false;
    res[cur.first][cur.second] = cnt + 1;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> res(m, vector<int>(n, 0));
    vector<vector<bool>> visitted(m, vector<bool>(n, false));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            visit(matrix, res, visitted, coordinate(i, j));
    }
    printMatrix(visitted);
    printMatrix(res);
    int maxi = 0;
    for(auto array: res) {
        for(auto num: array)
            maxi = max(maxi, num);
    }
    return maxi;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int val;
            cin >> val;
            matrix[i][j] = val;
        }
    }
    printMatrix(matrix);
    int res = longestIncreasingPath(matrix);
    cout << res << endl;
    return 0;
}

