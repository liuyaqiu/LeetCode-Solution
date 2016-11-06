#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

vector<int> getSet(vector<int>& nums, vector<int>& pos) {
    vector<int> set;
    for(int i = 0; i < pos.size(); ++i) {
        for(int j = 0; j < pos[i]; ++j)
            set.push_back(nums[i]);
    }
    return set;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> unique;
    vector<int> cnt;
    sort(nums.begin(), nums.end());
    unique.push_back(nums.front());
    cnt.push_back(1);
    for(auto iter = nums.begin() + 1; iter != nums.end(); ++iter) {
        if(*iter == unique.back()) {
            cnt.back() += 1;
        }
        else {
            unique.push_back(*iter);
            cnt.push_back(1);
        }
    }
    print(unique);
    print(cnt);
    vector<int> pos;
    int len = cnt.size();
    vector<vector<int>> res;
    while(true) {
        if(pos.size() < len) {
            pos.push_back(0);
        }
        else {
            res.push_back(getSet(unique, pos));
            while(!pos.empty() && pos.back() == cnt[pos.size() - 1])
                pos.pop_back();
            if(!pos.empty())
                pos.back() += 1;
            else
                break;
        }
    }
    return res;
}

int main() {
    int n;
    cout << "Please input n: ";
    cin >> n;
    vector<int> nums;
    int val;
    for(int i = 0; i < n; ++i) {
        cin >> val;
        nums.push_back(val);
    }
    vector<vector<int>> res = subsetsWithDup(nums);
    for(auto iter = res.begin(); iter != res.end(); ++iter)
        print(*iter);
    return 0;
}
