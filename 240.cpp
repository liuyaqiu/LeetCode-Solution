#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<vector<int>>& matrix, int target, int xp, int yp, int xq, int yq) {
    int m = matrix.size(), n = matrix[0].size();
    cout << xp << " " << yp << ", " << xq << " " << yq << endl;
    if(xp < 0 || xp >= m || xq < 0 || xq >= m || yp < 0 || yp >= n || yq < 0 || yq >= n)
        return false;
    if(xp > xq || yp > yq)
        return false;
    if(matrix[xp][yp] > target || matrix[xq][yq] < target)
        return false;
    if(xp == xq) {
        int mid = (yp + yq) / 2;
        int tmp = matrix[xp][mid];
        if(tmp == target)
            return true;
        else if(tmp < target)
            return binarySearch(matrix, target, xp, mid + 1, xq, yq);
        else
            return binarySearch(matrix, target, xp, yp, xq, mid - 1);
    }
    if(yp == yq) {
        int mid = (xp + xq) / 2;
        int tmp = matrix[mid][yp];
        if(tmp == target)
            return true;
        else if(tmp < target)
            return binarySearch(matrix, target, mid + 1, yp, xq, yq);
        else
            return binarySearch(matrix, target, xp, yp, mid - 1, yq);
    }
    int xp1 = xp, yp1 = yp, xq1 = (xp + xq) / 2, yq1 = (yp + yq) / 2;
    int xp2 = xp1, yp2 = yq1 + 1, xq2 = xq1, yq2 = yq;
    int xp3 = xq1 + 1, yp3 = yp1, xq3 = xq, yq3 = yq1;
    int xp4 = xp3, yp4 = yp2, xq4 = xq, yq4 = yq;
    return binarySearch(matrix, target, xp1, yp1, xq1, yq1) || binarySearch(matrix, target, xp2, yp2, xq2, yq2) || binarySearch(matrix, target, xp3, yp3, xq3, yq3) || binarySearch(matrix, target, xp3, yp3, xq3, yq3) || binarySearch(matrix, target, xp4, yp4, xq4, yq4);
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if(matrix.empty())
		return false;
    int m = matrix.size(), n = matrix[0].size();
    return binarySearch(matrix, target, 0, 0, m - 1, n - 1);
}

void print(vector<vector<int>>& matrix) {
    for(auto iter1 = matrix.begin(); iter1 != matrix.end(); iter1++) {
        for(auto iter2 = iter1->begin(); iter2 != iter1->end(); iter2++)
            cout << *iter2 << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix;
    for(int i = 0; i < m; i++) {
        vector<int> col;
        int val;
        for(int j = 0; j < n; j++) {
            cin >> val;
            col.push_back(val);
        }
        matrix.push_back(col);
    }
    print(matrix);
    int target;
    cin >> target;
    bool res = binarySearch(matrix, target, 0, 0, m - 1, n - 1);
    cout << res << endl;
    return 0;
}

/*
3 5 9 9 9 11
5 8 13 13 16 17
10 10 14 14 16 19
15 18 20 24 26 26
20 24 29 32 37 41
*/