bool check(int x, int m) {
    return x >= 0 && x < m;
}
int compare(const vector<vector<int>>& A, const vector<vector<int>>& B, int x, int y) {
    int m = A.size();
    int res = 0;
    int res1 = 0;
    for (int i = x; i < m; i++) {
        for (int j = y; j < m; j++) {
            if (A[i - x][j - y] == 1 && B[i][j] == 1) {
                res1++;
            }
        }
    }
    res = max(res, res1);
    int res2 = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (A[m - 1 + i - x][m - 1 + j - y] == 1 && B[i][j] == 1) {
                res2++;
            }
        }
    }
    res = max(res, res2);
    int res3 = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = y; j < m; j++) {
            if (A[m - 1 + i - x][j - y] == 1 && B[i][j] == 1) {
                res3++;
            }
        }
    }
    res = max(res, res3);
    int res4 = 0;
    for (int i = x; i < m; i++) {
        for (int j = 0; j <= y; j++) {
            if (A[i - x][m - 1 + j - y] == 1 && B[i][j] == 1) {
                res4++;
            }
        }
    }
    res = max(res, res4);
    return res;
}

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int res = 0;
        for (int i = 0; i < B.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                res = max(res, compare(A, B, i, j));
            }
        }
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                res = max(res, compare(B, A, i, j));
            }
        }
        return res;
    }
};