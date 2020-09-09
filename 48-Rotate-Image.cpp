/*
 * Rotate Image
 *
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Note:
 * You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int len = matrix.size();
    vector<vector<int>> res;
    for(int j = 0; j < len; j += 1) {
        vector<int> row;
        for(int i = 0; i < len; i += 1) {
            row.push_back(matrix[len - 1 - i][j]);
        }
        res.push_back(row);
    }
    matrix = res;
}

void print(vector<int> res) {
	for(auto iter = res.begin(); iter != res.end(); iter += 1) {
		cout << *iter << " ";
	}
	cout << endl;
}

int main() {
    int n;
    cout << "Please input the number: ";
    cin >> n;
    vector<vector<int>> matrix;
    int val;
    for(int i = 0; i < n; i += 1) {
        vector<int> line;
        for(int j = 0; j < n; j += 1) {
            cin >> val;
            line.push_back(val);
        }
        matrix.push_back(line);
    }
    for(auto iter = matrix.begin(); iter != matrix.end(); iter += 1)
        print(*iter);
    rotate(matrix);
    for(auto iter = matrix.begin(); iter != matrix.end(); iter += 1)
        print(*iter);
    return 0;
}
