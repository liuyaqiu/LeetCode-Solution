#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <deque>

using namespace std;

void printSet(set<char>& myset) {
    for(auto iter = myset.begin(); iter != myset.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

void print(vector<vector<char>>& nums) {
    cout << "xxxxxxxxxxxxxxxxxxx" << endl;
    for(auto iter = nums.begin(); iter != nums.end(); ++iter) {
        for(auto iter2 = (*iter).begin(); iter2 != (*iter).end(); ++iter2)
            cout << *iter2 << " ";
        cout << endl;
    }
}

bool judge(vector<vector<char>>& nums, stack<int>& stkA, stack<int>& stkB, int val, vector<set<char>>& x, vector<set<char>>& y, vector<set<char>>& z) {
    int pos = stkA.top();
    int len = 9;
    char c = '0' + val;
    int i = pos % len; 
    int j = pos / len;
    int k = (j / 3) * 3 + i / 3;
    if(x[i].find(c) != x[i].end()) {
        return false;
    }
    if(y[j].find(c) != y[j].end()) {
        return false;
    }
    if(z[k].find(c) != z[k].end()) {
        return false;
    }
    char pre = nums[j][i];
    if(pre != '.') {
        x[i].erase(pre);
        y[j].erase(pre);
        z[k].erase(pre);
    }
    x[i].insert(c);
    y[j].insert(c);
    z[k].insert(c);
    stkB.push(pos);
    nums[j][i] = c;
    stkA.pop();
    return true;
}

void getAllSet(vector<vector<char>>& nums, vector<set<char>>& x, vector<set<char>>& y, vector<set<char>>& z, stack<int>& stk) {
    int len = 9;
    for(int j = 0; j < len; j += 1) {
        for(int i = 0; i < len; i += 1) {
            char c = nums[j][i];
            if(c - '0' >= 0 && c - '0' <= 9) {
                x[i].insert(c);
                y[j].insert(c);
                int k = (j / 3) * 3 + i / 3;
                z[k].insert(c);
            }
            else {
                int pos = j * len + i;
                stk.push(pos);
            }
        }
    }
}

void solveSudoku(vector<vector<char>>& nums) {
    int len = 9;
    vector<set<char>> x(len);
    vector<set<char>> y(len);
    vector<set<char>> z(len);
    stack<int> stkA;
    stack<int> stkB;
    getAllSet(nums, x, y, z, stkA);
    while(true) {
        if(stkA.empty())
            break;
        int cur_pos = stkA.top();
        int cur_val; 
        char c = nums[cur_pos / len][cur_pos % len];
        if(c == '.')
            cur_val = 1;
        else
            cur_val = c - '0' + 1;
        while(cur_val <= 9 && !judge(nums, stkA, stkB, cur_val, x, y, z))
            cur_val += 1;
        if(cur_val > 9) {
            if(c != '.') {
                int i = cur_pos % len;
                int j = cur_pos / len;
                int k = (j / 3) * 3 + i / 3;
                x[i].erase(c);
                y[j].erase(c);
                z[k].erase(c);
            }
            nums[cur_pos / len][cur_pos % len] = '.'; //当前点无法填充，将其还原为初试状态，然后调整上一个填充位置，并将其相关的set中的值置为空
            int pre_pos = stkB.top();   
            stkA.push(pre_pos);
            stkB.pop();
        }
    }
}

int main() {
    int len = 9;
    vector<vector<char>> nums(len);
    for(int i = 0; i < len; i += 1) {
        for(int j = 0; j < len; j += 1) {
            char val;
            cin >> val;
            nums[i].push_back(val);
        }
    }
    print(nums);
    solveSudoku(nums);
    print(nums);
}
