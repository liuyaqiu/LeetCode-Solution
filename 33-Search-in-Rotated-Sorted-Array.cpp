/*
 * Search in Rotated Sorted Array
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dichotomy(vector<int>& ordered, int left, int right, int target) {
    if(left > right)
        return -1;
    int medium = (left + right) / 2;
    if(target == ordered[medium])
    	return medium;
    else if(target < ordered[medium])
        return dichotomy(ordered, left, medium - 1, target);
    else
        return dichotomy(ordered, medium + 1, right, target);
}

int nextSearch(vector<int>& nums, int left, int right, int target) {
    if(left > right)
        return -1;
    int medium = (left + right) / 2;
    int ordered_left, ordered_right, unorder_left, unorder_right;
    if(nums[left] <= nums[right])
    	return dichotomy(nums, left, right, target);
    else {
	    if(nums[left] < nums[medium]) {
	        ordered_left = left;
	        ordered_right = medium;
	        unorder_left = medium + 1;
	        unorder_right = right;
	    }
	    else {
	        ordered_left = medium + 1;
	        ordered_right = right;
	        unorder_left = left;
	        unorder_right = medium;
	    }
	}
    if(target >= nums[ordered_left] && target <= nums[ordered_right])
        return dichotomy(nums, ordered_left, ordered_right, target);
    else
        return nextSearch(nums, unorder_left, unorder_right, target);
}

int search(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	return nextSearch(nums, left, right, target);
}

int main() {
	vector<int> vec = {1};
	int target = 1;
	int pos = search(vec, target);
	cout << pos << endl;
	return 0;
}
