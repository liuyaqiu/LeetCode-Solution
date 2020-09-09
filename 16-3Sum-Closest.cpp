/*
 * 3Sum Closest
 *
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

void  getCurRes(vector<int>& nums, int pos, int target, int& cloest) {
    int start = 0;
    int end = nums.size() - 1;
    while(start < pos && pos < end) {
        int tmp = nums[start] + nums[pos] + nums[end];
        if(tmp - target == 0) {
            cloest = tmp;
            break;
        }
        else if(tmp - target < 0) {
            int s_val = nums[start];
            while(start < end && nums[start] == s_val)
                start += 1;
            if(abs(tmp - target) < abs(cloest - target))
                cloest = tmp;
        }
        else {
            int e_val = nums[end];
            while(start < end && nums[end] == e_val)
                end -= 1;
            if(abs(tmp - target) < abs(cloest - target))
                cloest = tmp;
        }
    }
}

int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int cloest = nums[0] + nums[1] + nums[2];
    for(int i = 0; i < nums.size(); i += 1) {
        getCurRes(nums, i, target, cloest);
    }
    return cloest;
} 

int main() {
    int array[] = {-1, 2, 1, -4};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    int target = 1;
    int res = threeSumClosest(nums, target);
    cout << res << endl;
    return 0;
}

