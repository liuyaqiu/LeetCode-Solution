#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& nums, int start, int end) {
    int tmp_s = nums[start];
    while(start < end && nums[start + 1] == tmp_s)
        start++;
    int tmp_e = nums[end];
    while(end > start && nums[end - 1] == tmp_e)
        end--;
    if(start >= end)
        return nums[start];
    if(nums[start] < nums[end])
        return nums[start];
    if(end - start == 1)
    	return min(nums[start], nums[end]);
    int mid = (start + end) / 2;
    if(nums[mid] > nums[start])
        return binarySearch(nums, mid + 1, end);
    else
        return binarySearch(nums, start, mid);
}

int findMin(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    return binarySearch(nums, start, end);
}

int main() {
    vector<int> nums;
    int val;
    while(cin >> val) {
        nums.push_back(val);
    }
    int res = findMin(nums);
    cout << res << endl;
    return 0;
}
