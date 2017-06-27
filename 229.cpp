#include <iostream>
#include <vector>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    int major1 = 0, major2 = 0;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == major1) {
            cnt1++;
        }
        else if(nums[i] == major2) {
            cnt2++;
        }
        else if(cnt1 == 0) {
            cnt1 = 1;
            major1 = nums[i];
        }
        else if(cnt2 == 0) {
            cnt2 = 1;
            major2 = nums[i];
        }
        else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == major1)
            cnt1++;
        else if(nums[i] == major2)
            cnt2++;
    }
    if(cnt1 > nums.size() / 3)
        res.push_back(major1);
    if(cnt2 > nums.size() / 3)
        res.push_back(major2);
    return res;
}

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val) {
        nums.push_back(val);
    }
    vector<int> res = majorityElement(nums);
    print(nums);
    print(res);
    return 0;
}
