#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void leftToRight(vector<int>& height, vector<int>& res) {
    stack<int> pos;
    int cur = 0;
    while(cur < height.size()) {
        if(pos.empty() || height[cur] >= height[pos.top()])
            pos.push(cur);
        else {
            while(!pos.empty() && height[cur] < height[pos.top()]) {
                int tmp = pos.top();
                res[tmp] += (cur - tmp - 1) * height[tmp]; 
                pos.pop();
            }
            pos.push(cur);
        }
        cur += 1;
    }
    while(!pos.empty()) {
        int tmp = pos.top();
        res[tmp] += (cur - tmp - 1) * height[tmp];
        pos.pop();
    }
}

void rightToleft(vector<int>& height, vector<int>& res) {
    stack<int> pos;
    int cur = height.size() - 1;
    while(cur >= 0) {
        if(pos.empty() || height[cur] >= height[pos.top()])
            pos.push(cur);
        else {
            while(!pos.empty() && height[cur] < height[pos.top()]) {
                int tmp = pos.top();
                res[tmp] += (tmp - cur - 1) * height[tmp];
                pos.pop();
            }
            pos.push(cur);
        }
        cur -= 1;
    }
    while(!pos.empty()) {
        int tmp = pos.top();
        res[tmp] += (tmp - cur - 1) * height[tmp];
        pos.pop();
    }
}

int largestRectangleArea(vector<int>& heights) {
    vector<int> res(heights);
    leftToRight(heights, res);
    rightToleft(heights, res);
    int max = 0;
    for(auto iter = res.begin(); iter != res.end(); ++iter)
        if(*iter > max)
            max = *iter;
    return max;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty())
        return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> tmp(m, vector<int>(n, 0));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            tmp[i][j] = matrix[i][j] - '0';
        }
    }
    for(int i = 1; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(tmp[i][j] > 0)
                tmp[i][j] += tmp[i - 1][j];
        }
    }
    int res = 0;
    for(auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
        int temp = largestRectangleArea(*iter);
        if(temp > res)
            res = temp;
    }
    return res;
}

int main() {
    int m, n;
    cout << "Please input m, n: ";
    cin >> m >> n;
    vector<vector<char>> matrix;
    char c;
    for(int i = 0; i < m; ++i) {
        vector<char> row;
        for(int j = 0; j < n; ++j) {
            cin >> c;
            row.push_back(c);
        }
        matrix.push_back(row);
    }
    int res = maximalRectangle(matrix);
    cout << "The maximal rectangle's area is: " << res << endl;
    return 0;
}
