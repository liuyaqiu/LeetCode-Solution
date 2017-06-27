#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
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
