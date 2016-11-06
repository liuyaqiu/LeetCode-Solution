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

