/*
 * Remove Duplicates from Sorted Array
 *
 * Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 *
 * Example:
 *
 * Given nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int dup = 0;
    int len = nums.size();
    for(int i = 1; i < len; i += 1) {
    	int pos = i - dup;
    	if(nums[pos] == nums[pos - 1]) {
    	    nums.erase(nums.begin() + pos);
    		dup += 1;
    	}
    }
    return nums.size();
}
