#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void eval(int cur_val, vector<int>& cnt, vector<int>& res) {
    if(cnt.empty()) {
        res.push_back(cur_val);
        cnt.push_back(1);
        res.push_back(cur_val);
    }
    else {
        if(cur_val == res.back()) {
            cnt.back() += 1;
            if(cnt.back() > cnt.front()) {
                int tmp = cnt.back();
                cnt = {tmp};
                res = {cur_val};
            }
        }
        else {
            cnt.push_back(1);
            res.push_back(cur_val);
        }
    }
}

void inOrder(TreeNode* root, vector<int>& cnt, vector<int>& res) {
    if(root == NULL)
        return;
    inOrder(root->left, cnt, res);
    eval(root->val, cnt, res);
    inOrder(root->right, cnt, res);
}

vector<int> findMode(TreeNode* root) {
    vector<int> res;
    vector<int> cnt;
    inOrder(root, cnt, res);
    if(!res.empty()) {
        if(cnt.back() > cnt.front()) {
            res = {res.back()};
            cnt = {cnt.back()};
        }
        else if(cnt.back() < cnt.front()) {
            cnt.pop_back();
            res.pop_back();
        }
    }
    return res;
}
