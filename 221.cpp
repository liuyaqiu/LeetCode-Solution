#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m ,vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = matrix[i][j] - '0';
        }
    }
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < m; j++) {
            if(dp[i][j] == 1) {
                dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(dp[i][j] > res)
                res = dp[i][j];
        }
    }
    return res * res;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> matrix;
    for(int i = 0; i < m; i++) {
        vector<char> array;
        char c;
        for(int j = 0; j < n; j++) {
            cin >> c;
            array.push_back(c);
        }
        matrix.push_back(array);
    }
    int res = maximalSquare(matrix);
    cout << res << endl;
    return 0;
}
