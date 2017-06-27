#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void merge(int head, vector<vector<int>>& res) {
    if(res.empty())
        res.push_back({head});
    else {
        for(auto& arr: res)
            arr.push_back(head);
    }
}

vector<vector<int>> dfs(vector<int>& nums, int head, int start) {
    int n = nums.size();
    int pos = start + 1;
    vector<vector<int>> res;
    while(pos < n && nums[pos] < head)
        pos++;
    if(pos >= n) {
        return {{head}};
    }
    vector<vector<int>> tmp1 = dfs(nums, head, pos);    //不包含pos位置
    vector<vector<int>> tmp2 = dfs(nums, nums[pos], pos);
    merge(head, tmp2);
    for(auto row: tmp1)
        res.push_back(row);
    for(auto row: tmp2)
        res.push_back(row);
    return res;
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    for(int i = 0; i < n; i++) {
        vector<vector<int>> tmp = dfs(nums, nums[i], i);
        for(auto row: tmp) {
            if(row.size() > 1) {
                reverse(row.begin(), row.end());
                res.push_back(row);
            }
        }
    }
    set<vector<int>> dict(res.begin(), res.end());
    vector<vector<int>> ans(dict.begin(), dict.end());
    return ans;
}

void print(vector<vector<int>>& res) {
    for(auto row: res) {
        for(auto item: row)
            cout << item << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    vector<vector<int>> res = findSubsequences(nums);
    print(res);
    return 0;
}

