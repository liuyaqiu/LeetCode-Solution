#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> mypair;

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    vector<vector<int>> res(m, vector<int>(n, 0));
    queue<mypair> cur;
    queue<mypair> next;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                cur.push({i, j});
                visit[i][j] = true;
            }
        }
    }
    int dis = 0;
    while(!cur.empty()) {
        mypair top = cur.front();
        int i = top.first, j = top.second;
        res[i][j] = dis;
        cur.pop();
        if(i - 1 >= 0 && !visit[i - 1][j]) {
            visit[i - 1][j] = true;
            next.push({i - 1, j});
        }
        if(i + 1 < m && !visit[i + 1][j]) {
            visit[i + 1][j] = true;
            next.push({i + 1, j});
        }
        if(j - 1 >= 0 && !visit[i][j - 1]) {
            visit[i][j - 1] = true;
            next.push({i, j - 1});
        }
        if(j + 1 < n && !visit[i][j + 1]) {
            visit[i][j + 1] = true;
            next.push({i, j + 1});
        }
        if(cur.empty()) {
            cur = next;
            next = queue<mypair>();
            dis += 1;
        }
    }
    return res;
}

void print(vector<vector<int>>& matrix) {
    for(auto row: matrix) {
        for(auto item: row)
            cout << item << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    int val;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> val;
            matrix[i][j] = val;
        }
    }
    vector<vector<int>> res = updateMatrix(matrix);
    print(res);
    return 0;
}
