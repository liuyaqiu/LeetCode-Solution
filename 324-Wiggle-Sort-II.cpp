#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Wiggle Sort II
 *
 * Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
 *
 * Example:
 * (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
 * (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
 *
 * Note:
 * You may assume all input has valid answer.
 *
 * Follow Up:
 * Can you do it in O(n) time and/or in-place with O(1) extra space?
 *
 *
 */

int newIndex(int i, int n) {
    return (2 * i + 1) % (n | 1);
}

int findMedian(int start, int end, int k, vector<int>& nums) {
    if(start > end)
        return -1;
    int pivot = nums[end];
    int index = start;
    for(int i = start; i < end; i++) {
        if(nums[i] <= pivot) {
            swap(nums[i], nums[index]);
            index++;
        }
    }
    swap(nums[index], nums[end]);
    if(index == k)
        return nums[index];
    else if(index < k)
        return findMedian(index + 1, end, k, nums);
    else
        return findMedian(start, index - 1, k, nums);
}

void wiggleSort(vector<int>& nums) {
    if(nums.empty())
        return;
    int n = nums.size();
    int mid = findMedian(0, n - 1, n / 2, nums);
    cout << mid << endl;
    int i = 0, j = 0, k = n - 1;
    while(j <= k) {
        if(nums[newIndex(j, n)] < mid)
            swap(nums[newIndex(j, n)], nums[newIndex(k--, n)]);
        else if(nums[newIndex(j, n)] > mid)
            swap(nums[newIndex(i++, n)], nums[newIndex(j++, n)]);
        else
            j++;
    }
}

void print(vector<int>& nums) {
    for(auto n: nums)
        cout << n << " ";
    cout << endl;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    print(nums);
    wiggleSort(nums);
    print(nums);
    return 0;
}

