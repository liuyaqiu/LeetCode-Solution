#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<pair<int, int>> neighbors(int m, int n, int x, int y) {
    vector<pair<int, int>> res;
    if(x - 1 >= 0)
        res.push_back(pair<int, int>(x - 1, y));
    if(y - 1 >= 0)
        res.push_back(pair<int, int>(x, y - 1));
    if(x + 1 < m)
        res.push_back(pair<int, int>(x + 1, y));
    if(y + 1 < n)
        res.push_back(pair<int, int>(x, y + 1));
    return res;
}

void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visit) {
    int m = grid.size();
    int n = grid[0].size();
    if(grid[x][y] == '0' || visit[x][y])
        return;
    else {
        visit[x][y] = true;
        vector<pair<int, int>> nb = neighbors(m, n, x, y);
        for(auto iter = nb.begin(); iter != nb.end(); iter++) {
            dfs(iter->first, iter->second, grid, visit);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
	if(grid.empty())
		return 0;
    int res = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1' && !visit[i][j]) {
                res += 1;
                dfs(i, j, grid, visit);
            }
        }
    }
    return res;
}

void print(vector<vector<char>>& grid) {
    for(auto iter1 = grid.begin(); iter1 != grid.end(); iter1++) {
        for(auto iter2 = iter1->begin(); iter2 != iter1->end(); iter2++)
            cout << *iter2 << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    int m;
    int n;
    cin >> m >> n;
    char c;
    vector<vector<char>> grid(m, vector<char>());
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> c;
            grid[i].push_back(c);
        }
    }
    print(grid);
    int res = numIslands(grid);
    cout << res << endl;
    return 0;
}
