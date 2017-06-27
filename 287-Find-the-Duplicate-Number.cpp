#include <iostream>
#include <vector>

using namespace std;

/*
 * Find the Duplicate Number
 *
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
 *
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated more than once.
 *
 *
 */

int findDuplicate(vector<int>& nums) {
    int low = 1, high = nums.size() - 1;
    while(low < high) {
        int mid = (low + high) / 2;
        int cnt = 0;
        for(auto iter = nums.begin(); iter != nums.end(); iter++) {
            if(*iter <= mid)
                cnt++;
        }
        if(cnt > mid)
            high = mid;
        else
            low = mid + 1;
    }
    return high;
}

int findDuplicate2(vector<int>& nums) {
    int slow = 0, fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);
    int find = 0;
    while(find != slow) {
        slow = nums[slow];
        find = nums[find];
    }
    return find;
}
