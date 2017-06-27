#include <iostream>
#include <vector>

using namespace std;

int robList(vector<int>& nums) {
	if(nums.empty())
		return 0;
    int n = nums.size();
    vector<int> local(n, 0);
    vector<int> global(n, 0);
    local[0] = nums[0];
    local[1] = nums[1];
    global[0] = nums[0];
    global[1] = max(nums[0], nums[1]);
    for(int i = 2; i < n; i++) {
        local[i] = max(local[i - 1], global[i - 2] + nums[i]);
        global[i] = max(local[i], global[i - 1]);
    }
    return global[n - 1];
}

int rob(vector<int>& nums) {
    if(nums.empty())
        return 0;
    else if(nums.size() == 1)
        return nums[0];
    else if(nums.size() == 2)
        return max(nums[0], nums[1]);
    else if(nums.size() == 3)
        return max(nums[0], max(nums[1], nums[2]));
    else if(nums.size() == 4) {
    	return max(nums[0] + nums[2], nums[1] + nums[3]);
    }
    else {
        vector<int> nums1(nums.begin() + 2, nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        return max(nums[0] + robList(nums1), robList(nums2));
    }
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val) {
        nums.push_back(val);
    }
    int res = rob(nums);
    cout << res << endl;
    return 0;
}
