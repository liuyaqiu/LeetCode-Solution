#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
	if(nums.empty())
		return 0;
    int start = 0, end = 0;
    int sum = 0;
    int res = 0;
    while(start < nums.size() && end < nums.size()) {
        while(end < nums.size() && sum < s) {
            sum += nums[end];
            end++;
        }
        while(sum >= s) {
        	if(res == 0 || end - start < res)
            	res = end - start;
            sum -= nums[start];
            start++;
        }
    }
    return res;
}

int main() {
    int val;
    vector<int> nums;
    int s;
    cin >> s;
    while(cin >> val) {
        nums.push_back(val);
    }
    int res = minSubArrayLen(s, nums);
    cout << res << endl;
    return 0;
}
