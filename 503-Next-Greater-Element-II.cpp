#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> mypair;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<mypair> cur;
    vector<int> res(nums);
    int pos = 0;
    while(pos < n) {
        if(cur.empty() || nums[pos] <= cur.top().second) {
            cur.push({pos, nums[pos]});
            pos++;
        }
        else {
            while(!cur.empty() && nums[pos] > cur.top().second) {
                res[cur.top().first] = nums[pos];
                cur.pop();
            }
        }
    }
    pos = 0;
    while(pos < n && !cur.empty()) {
        while(nums[pos] > cur.top().second) {
            res[cur.top().first] = nums[pos];
            cur.pop();
        }
        pos++;
    }
    while(!cur.empty()) {
        res[cur.top().first] = -1;
        cur.pop();
    }
    return res;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val) {
        nums.push_back(val);
    }
    vector<int> res = nextGreaterElements(nums);
    for(auto item: res)
        cout << item << " ";
    cout << endl;
    return 0;
}
