auto my_comp =
    [](const std::pair<int, int>& e1, const std::pair<int, int>& e2)
    { return e1.second > e2.second; };

using my_queue =  std::priority_queue<std::pair<int, int>,
                std::vector<std::pair<int, int>>,
                decltype(my_comp)>;

class Solution {
public:
    void addNeighbors(const vector<vector<int>>& grid, my_queue& que, vector<vector<bool>>& visit, int& res) {
        int n = grid.size();
        if (que.empty()) {
            return;
        }
        std::pair<int, int> top = que.top();
        que.pop();
        int m = top.first;
        int i = m / n;
        int j = m % n;
        res = max(res, top.second);
        if (i == n - 1 && j == n - 1) {
            return;
        }
        if (i - 1 >= 0 && !visit[i - 1][j]) {
            que.push(std::make_pair((i - 1) * n + j, grid[i - 1][j]));
            visit[i - 1][j] = true;
        }
        if (i + 1 < n && !visit[i + 1][j]) {
            visit[i + 1][j] = true;
            que.push(std::make_pair((i + 1) * n + j, grid[i + 1][j]));
        }
        if (j - 1 >= 0 && !visit[i][j - 1]) {
            visit[i][j - 1] = true;
            que.push(std::make_pair(i * n + j - 1, grid[i][j - 1]));
        }
        if (j + 1 < n && !visit[i][j + 1]) {
            visit[i][j + 1] = true;
            que.push(std::make_pair(i * n + j + 1, grid[i][j + 1]));
        }
        addNeighbors(grid, que, visit, res);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        my_queue que(my_comp);
        visit[0][0] = true;
        que.push(make_pair(0, grid[0][0]));
        int res = 0;
        addNeighbors(grid, que, visit, res);
        return res;
    }
};