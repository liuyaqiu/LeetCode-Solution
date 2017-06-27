#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>&nums, int r, int c) {
    int m = nums.size();
    int n = nums[0].size();
    if(m * n != r * c)
        return nums;
    vector<vector<int>> res(r, vector<int>(c, 0));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int index = (i + 1) * (j + 1) - 1;
            res[i][j] = nums[index / n][index % n];
        }
    }
    return res;
}
