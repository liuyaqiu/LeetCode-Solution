#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> firstCol(vector<vector<int>>& matrix) {
    vector<int> res;
    for(auto iter = matrix.begin(); iter != matrix.end(); ++iter) {
        res.push_back(iter->front());
    }
    return res;
}

int findPos(vector<int>& col, int target) {
    int left = 0, right = col.size() - 1;
    int medium;
    while(left < right) {
        medium = (left + right) / 2;
        if(col[medium] == target)
            return medium;
        else if(col[medium] < target) {
            left = medium + 1;
        }
        else {
            right = medium - 1;
        }
    }
    if(col[left] <= target)
        return left;
    else
        return left - 1;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    vector<int> col = firstCol(matrix);
    int pos = findPos(col, target);
    if(pos < 0)
        return false;
    vector<int> row = matrix[pos];
    int res = findPos(row, target);
    return (res < row.size() && row[res] == target);
}
