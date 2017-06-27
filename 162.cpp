#include <iostream>
#include <vector>

using namespace std;

int judge(vector<int>& nums, int i) {
    int n = nums.size();
    if(n == 1)
    	return 0;
    if(i == 0) {
        if(nums[i] > nums[i + 1])
            return 0;
        else
            return 1;
    }
    else if(i == n - 1) {
        if(nums[i] > nums[i - 1])
            return 0;
        else
            return -1;
    }
    else {
        if(nums[i] > nums[i + 1]) {
            if(nums[i] > nums[i - 1])
                return 0;
            else
                return -1;
        }
        else
            return 1;
    }
}

int binarySearch(vector<int>& nums, int start, int end) {
    if(start > end)
        return -1;
    int mid = (start + end) / 2;
    if(judge(nums, mid) == 0)
        return mid;
    else if(judge(nums, mid) == 1)
        return binarySearch(nums, mid + 1, end);
    else
        return binarySearch(nums, start, mid - 1);
}

int findPeakElement(vector<int>& nums) {
    int start = 0, end = nums.size() - 1;
    return binarySearch(nums, start, end);
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val) {
        nums.push_back(val);
    }
    int res = findPeakElement(nums);
    cout << res << endl;
    return 0;
}
