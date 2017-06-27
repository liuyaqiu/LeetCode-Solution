#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    int n = nums.size();
    int pos = 0;
    unordered_map<int, int> ans;
    stack<int> cur;
    while(pos < n) {
        if(cur.empty() || nums[pos] <= cur.top()) {
            cur.push(nums[pos]);
            pos++;
        }
        else {
            while(!cur.empty() && nums[pos] > cur.top()) {
                ans[nums[cur.top()]] = nums[pos];
                cur.pop();
            }
        }
    }
    while(!cur.empty()) {
        ans[cur.top()] = -1;
        cur.pop();
    }
    vector<int> res;
    for(auto item: findNums) {
        res.push_back(ans[item]);
    }
    return res;
}

