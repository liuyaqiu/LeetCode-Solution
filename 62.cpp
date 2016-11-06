#include <iostream>
#include <string>
#include <vector>

using namespace std;

long int uniquePaths(int m, int n) {
    vector<vector<long int>> matrix(m, vector<long int>(n, 0));
    for(int i = 0; i < n; ++i) {
        matrix[0][i] = 1;
    }
    for(int j = 0; j < m; ++j) {
        matrix[j][0] = 1;
    }
    for(int i = 1; i < m; ++i) {
        for(int j = 1; j < n; ++j) {
            matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j];
        }
    }
    return matrix[m - 1][n - 1];
}

int main() {
    int m, n;
    cout << "Please input the m and n: ";
    cin >> m >> n;
    cout << "The unique paths is: " << uniquePaths(m, n) << endl;
    return 0;
}
