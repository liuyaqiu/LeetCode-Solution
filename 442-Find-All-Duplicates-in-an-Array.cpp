#include <iostream>
#include <vector>

using namespace std;

/*
 * Find All Duplicates in an Array
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *
 * Find all the elements that appear twice in this array.
 *
 * Could you do it without extra space and in O(n) runtime?
 *
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [2,3]
 *
 *
 */

vector<int> findDuplicates(vector<int>& nums) {
    int pos = 0;
    int n = nums.size();
    while(pos < n) {
        while(nums[pos] != pos + 1) {
            int next = nums[pos] - 1;
            if(nums[pos] == nums[next])
                break;
            else
                swap(nums[pos], nums[next]);
        }
        pos++;
    }
    vector<int> res;
    for(int i = 0; i < n; i++) {
        if(nums[i] != i + 1)
            res.push_back(nums[i]);
    }
    return res;
}
