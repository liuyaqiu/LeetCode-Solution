#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dichotomy(vector<int>& nums, int target, int left, int right) {
    if(nums[left] > target)
        return left;
    if(nums[right] < target)
        return right + 1;
    int medium = (left + right) / 2;
    if(nums[medium] < target)
        return dichotomy(nums, target, medium + 1, right);
    else
        return dichotomy(nums, target, left, medium - 1);
}

int searchInsert(vector<int>& nums, int target) {
    return dichotomy(nums, target, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {1, 3};
    int target = 2;
    cout << searchInsert(nums, target) << endl;
    return 0;
}
