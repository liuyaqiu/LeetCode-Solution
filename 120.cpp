#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int>>& nums) {
    int n = nums.size();
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0)
                nums[i][j] += nums[i - 1][j];
            else if(j == i)
                nums[i][j] += nums[i - 1][j - 1];
            else
                nums[i][j] += min(nums[i - 1][j], nums[i - 1][j - 1]);
        }
    }
    int res = nums[n - 1][0];
    for(int i = 1; i < n; i++) {
        if(nums[n - 1][i] < res)
            res = nums[n - 1][i];
    }
    return res;
}
