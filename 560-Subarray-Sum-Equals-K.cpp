#include <iostream>
#include <vector>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int sum = 0;
    vector<int> subsum = {0};
    for(auto num: nums) {
        sum += num;
        subsum.push_back(sum);
    }
    int res = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(subsum[j] - subsum[i] == k)
                res += 1;
        }
    }
    return res;
}

int main() {
    vector<int> nums;
    int val;
    while(cin >> val)
        nums.push_back(val);
    int k;
    cin >> k;
    int res = subarraySum(nums, k);
    cout << res << endl;
    return 0;
}
