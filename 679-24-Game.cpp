/*
  24 Game

  You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.

  Example 1:
  Input: [4, 1, 8, 7]
  Output: True
  Explanation: (8-4) * (7-1) = 24
  Example 2:
  Input: [1, 2, 1, 2]
  Output: False
  Note:
  The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
  Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
  You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.

 */

#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <set>
#include <stack>

using namespace std;

#define inf numeric_limits<int>::max()

//generate all the evaluation order, for example: 1, 2, 3 indicates that (((a1 op1 a2) op2 a3) op3)

template <typename T>
void permute(vector<vector<T>>& res, vector<T>& tmp, int l, int r) {
    if(l == r)
        res.push_back(tmp);
    else {
        for(int i = l; i <= r; i++) {
            swap(tmp[l], tmp[i]);
            permute(res, tmp, l + 1, r);
            swap(tmp[l], tmp[i]);
        }
    }
}

double compute(double a, double b, int op) {
    if(op == 0)
        return a + b;
    else if(op == 1)
        return a - b;
    else if(op == 2)
        return a * b;
    else if(op == 3) {
        if(b == 0)
            return inf;
        else
            return a * 1.0 / b;
    }
    else
        return inf;
}

double eval(vector<double> nums, vector<int>& ops, vector<int>& orders) {
    double res = inf;
    vector<bool> used(ops.size(), false);
    for(int i = 0; i < orders.size(); i++) {
        int pos = orders[i];
        double a = nums[pos - 1], b = nums[pos];
        res = compute(a, b, ops[pos - 1]);
        if(res == inf)
            return inf;
        used[pos - 1] = true;
        int start = pos - 1;
        while(start < used.size() && used[start]) {
            nums[start] = res;
            nums[start + 1] = res;
            start++;
        }
        int end = pos - 1;
        while(end >= 0 && used[end]) {
            nums[end] = res;
            nums[end + 1] = res;
            end--;
        }
    }
    return res;
}

void loops(vector<vector<int>>& res, vector<int>& tmp, int k) {
    if(k >= tmp.size()) {
        res.push_back(tmp);
        return;
    }
    for(int p = 0; p < 4; p++) {
        tmp[k] = p;
        loops(res, tmp, k + 1);
    }
}

template <typename T>
void print(vector<T>& nums) {
    for(auto item: nums)
        cout << item << " ";
    cout << endl;
}

bool judgePoint24(vector<int>& nums) {
    vector<int> od = {1, 2, 3};
    vector<vector<int>> orders;
    permute<int>(orders, od, 0, od.size() - 1);
    vector<vector<int>> ops;
    vector<int> opt = {0, 0, 0};
    loops(ops, opt, 0);
    vector<vector<double>> perms;
    vector<double> t;
    for(auto num: nums)
        t.push_back(num);
    permute<double>(perms, t, 0, t.size() - 1);
    // int cnt = 0;
    for(auto perm: perms) {
        for(auto op: ops) {
            for(auto order: orders) {
                double val = eval(perm, op, order);
                // print<double>(perm);
                // print<int>(op);
                // print<int>(order);
                // cout << cnt << ": " << val << endl;
                // cnt++;
                if(abs(val - 24.0) < 0.001)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    vector<int> nums;
    int val;
    while(cin >> val) {
        nums.push_back(val);
    }
    bool res = judgePoint24(nums);
    if(res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
