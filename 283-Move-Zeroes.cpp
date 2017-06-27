#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Move Zeroes
 *
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 *
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 *
 */

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

void moveZeroes(vector<int>& nums) {
    int pos1 = 0;
    int pos2 = 0;
    while(pos2 < nums.size() && nums[pos2] == 0)
        pos2++;
    while(pos1 < nums.size() && pos2 < nums.size()) {
        nums[pos1] = nums[pos2];
        pos1++;
        pos2++;
        while(pos2 < nums.size() && nums[pos2] == 0)
            pos2++;
    }
    while(pos1 < nums.size()) {
        nums[pos1] = 0;
        pos1++;
    }
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val) {
        nums.push_back(val);
    }
    print(nums);
    moveZeroes(nums);
    print(nums);
    return 0;
}
