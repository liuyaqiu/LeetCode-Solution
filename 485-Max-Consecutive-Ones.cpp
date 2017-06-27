#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int pos = 0;
    int res = 0;
    int n = nums.size();
    while(pos < n) {
        while(pos < n && nums[pos] == 0)
            pos++;
        int tmp = 0;
        while(pos < n && nums[pos] == 1) {
            pos++;
            tmp++;
        }
        res = max(tmp, res);
    }
    return res;
}
