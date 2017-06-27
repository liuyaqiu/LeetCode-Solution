#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int len = nums.size();
    vector<int> res;
    if(nums.empty())
    	return res;
    int pos = 0;
    int maxi = nums[0];
    int p = 0;
    while(p <= len - k) {
        for(int i = p; i < p + k; i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
                pos = i;
            }
        }
        int end = p + k;
        while(end < len && end < pos + k && nums[end] < maxi)
            end++;
        end -= k;
        for(int i = p; i <= end; i++)
            res.push_back(maxi);
        p = end + 1;
        maxi = nums[p];
    }
    return res;
}

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main() {
    int val;
    vector<int> nums;
    int k;
    cin >> k;
    while(cin >> val) {
        nums.push_back(val);
    }
    vector<int> res = maxSlidingWindow(nums, k);
    print(nums);
    print(res);
    return 0;
}
