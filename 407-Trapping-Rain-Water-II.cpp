#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

/*
 * Trapping Rain Water II
 *
 * Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.
 *
 * Note:
 * Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.
 *
 * Example:
 *
 * Given the following 3x6 height map:
 * [
 *   [1,4,3,1,3,2],
 *   [3,2,1,3,2,4],
 *   [2,3,3,2,3,1]
 * ]
 *
 * Return 4.
 *
 *
 */

#define inf numeric_limits<int>::max()

typedef pair<int, int> mypair;

void print(vector<vector<int>>& matrix) {
	for(auto row: matrix) {
		for(auto item: row)
			cout << item << " ";
		cout << endl;
	}
	cout << endl;
}

void eval(vector<vector<int>>& heightMap, vector<vector<int>>& peakMap, queue<mypair>& que, mypair cur, int i, int j) {
    int m = heightMap.size();
    int n = heightMap[0].size();
    int x = cur.first, y = cur.second;
    if(i < 0 || i >= m || j < 0 || j >= n)
        return;
    int val = peakMap[x][y];
    int limit = max(val, heightMap[i][j]);
    if(peakMap[i][j] > limit) {
        peakMap[i][j] = limit;
        que.push(mypair(i, j));
    }
}

int trapRainWater(vector<vector<int>>& heightMap) {
    if(heightMap.empty())
        return 0;
    int m = heightMap.size();
    int n = heightMap[0].size();
    vector<vector<int>> peakMap(m, vector<int>(n, inf));
    queue<mypair> que;
    for(int i = 0; i < m; i++) {
        peakMap[i][0] = heightMap[i][0];
        peakMap[i][n - 1] = heightMap[i][n - 1];
        que.push(mypair(i, 0));
        que.push(mypair(i, n - 1));
    }
    for(int j = 0; j < n; j++) {
        peakMap[0][j] = heightMap[0][j];
        peakMap[m - 1][j] = heightMap[m - 1][j];
        que.push(mypair(0, j));
        que.push(mypair(m - 1, j));
    }
    while(!que.empty()) {
        mypair top = que.front();
        int x = top.first, y = top.second;
        eval(heightMap, peakMap, que, top, x - 1, y);
        eval(heightMap, peakMap, que, top, x, y - 1);
        eval(heightMap, peakMap, que, top, x + 1, y);
        eval(heightMap, peakMap, que, top, x, y + 1);
        que.pop();
    }
    int res = 0;
    print(heightMap);
    print(peakMap);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            res += peakMap[i][j] - heightMap[i][j];
    }
    return res;
}

int main() {
	int val;
	int m, n;
	cin >> m >> n;
	vector<vector<int>> matrix(m, vector<int>(n, 0));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> val;
			matrix[i][j] = val;
		}
	}
	int res = trapRainWater(matrix);
	cout << res << endl;
	return 0;
}
