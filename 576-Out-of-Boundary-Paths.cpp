/*
  Out of Boundary Paths

  There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

 */

#include <iostream>
#include <vector>

#define mod 1000000007
using namespace std;

vector<vector<vector<long long>>> solve(int m, int n, int N) {
    vector<vector<vector<long long>>> result(m, vector<vector<long long>>(n, vector<long long>(N + 1, 0)));
    for(int i = 0; i < m; i++) {
        result[i][0][1] += 1;
        result[i][n - 1][1] += 1;
    }
    for(int j = 0; j < n; j++) {
        result[0][j][1] += 1;
        result[m - 1][j][1] += 1;
    }
    for(int k = 2; k <= N; k++) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i - 1 >= 0)
                    result[i][j][k] = (result[i][j][k] + result[i - 1][j][k - 1]) % mod;
                if(i + 1 < m)
                    result[i][j][k] = (result[i][j][k] + result[i + 1][j][k - 1]) % mod;
                if(j - 1 >= 0)
                    result[i][j][k] = (result[i][j][k] + result[i][j - 1][k - 1]) % mod;
                if(j + 1 < n)
                    result[i][j][k] = (result[i][j][k] + result[i][j + 1][k - 1]) % mod;
            }
        }
    }
    return result;
}

int findPaths(int m, int n, int N, int i , int j) {
    vector<vector<vector<long long>>> result = solve(m, n, N);
    long long res = 0;
    for(int k = 1; k <= N; k++) {
        res = (res + result[i][j][k]) % mod;
    }
    return res;
}

int main() {
    int m, n, N, i, j;
    cin >> m >> n >> N >> i >> j;
    int res = findPaths(m, n, N, i, j);
    cout << res << endl;
    return 0;
}
