#include <iostream>
#include <vector>

using namespace std;

/*
Single Element in a Sorted Array

Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
Note: Your solution should run in O(log n) time and O(1) space.

*/

int binarySearch(vector<int>& nums, int start, int end) {
    if(nums.size() == 1)
        return 0;
    if(start >= end)
        return -1;
    int med = (start + end) / 2;
    if(med == 0 && nums[med] != nums[med + 1])
        return med;
    if(med == nums.size() - 1 && nums[med] != nums[med - 1])
        return med;
    if(nums[med] != nums[med - 1] && nums[med] != nums[med + 1])
        return med;
    else {
        if(nums[med] == nums[med - 1]) {
            if((nums.size() - (med + 1)) % 2 == 0)
                return binarySearch(nums, start, med - 1);
            else
                return binarySearch(nums, med + 1, end);
        }
        else {
            if((nums.size() - (med + 1)) % 2 == 0)
                return binarySearch(nums, med + 2, end);
            else
                return binarySearch(nums, start, med);
        }
    }
}
int singleNonDuplicate(vector<int>& nums) {
    int pos = binarySearch(nums, 0, nums.size());
    return nums[pos];
}

int main() {
    vector<int> nums;
    int val;
    while(cin >> val) {
        nums.push_back(val);
    }
    int res = singleNonDuplicate(nums);
    cout << res << endl;
    return 0;
}
