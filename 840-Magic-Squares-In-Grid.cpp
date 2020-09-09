bool is_magic(const vector<vector<int>>& grid, int m, int n) {
    if (m + 2 >= grid.size() || n + 2 >= grid[0].size()) {
        return false;
    }
    vector<bool> nums(9, false);
    for (int i = m; i < m + 3; i++) {
        int row_sum = 0;
        for (int j = n; j < n + 3; j++) {
            if (grid[i][j] < 1 || grid[i][j] > 9) {
                return false;
            }
            if (nums[grid[i][j] - 1]) {
                return false;
            } else {
                nums[grid[i][j] - 1] = true;
            }
            row_sum += grid[i][j];
        }
        if (row_sum != 15) {
            return false;
        }
    }
    for (int j = n; j < n + 3; j++) {
        int col_sum = 0;
        for (int i = m; i < m + 3; i++) {
            col_sum += grid[i][j];
        }
        if (col_sum != 15) {
            return false;
        }
    }
    int dig_sum = 0;
    for (int i = 0; i < 3; i++) {
        dig_sum += grid[m + i][n + i];
    }
    if (dig_sum != 15) {
        return false;
    }
    int rev_dig_sum = 0;
    for (int i = 0; i < 3; i++) {
        rev_dig_sum += grid[m + i][n + 2 - i];
    }
    if (rev_dig_sum != 15) {
        return false;
    }
    return true;
}

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                res += is_magic(grid, i, j);
            }
        }
        return res;
    }
};