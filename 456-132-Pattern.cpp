#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool find132pattern(vector<int>& nums) {
    map<int, int> cnt;
    for(auto num: nums) {
        if(cnt.find(num) == cnt.end())
            cnt[num] = 1;
        else
            cnt[num] += 1;
    }
    int mini = nums[0];
    for(auto num: nums) {
        auto iter = cnt.find(num);
        if(iter->second > 1)
            iter->second -= 1;
        else
            cnt.erase(num);
        if(num <= mini) {
            mini = num;
        }
        else {
            auto iter = cnt.upper_bound(mini);
            if(iter != cnt.end() && iter->first < num)
                return true;
        }
    }
    return false;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    bool res = find132pattern(nums);
    cout << res << endl;
    return 0;
}
