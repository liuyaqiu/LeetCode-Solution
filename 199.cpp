#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if(root == NULL)
    	return res;
    queue<TreeNode*> cur;
    queue<TreeNode*> next;
    cur.push(root);
    while(!cur.empty()) {
        TreeNode* top = cur.front();
        if(top->left != NULL)
            next.push(top->left);
        if(top->right != NULL)
            next.push(top->right);
        cur.pop();
        if(cur.empty()) {
            res.push_back(top->val);
            cur = next;
            next = queue<TreeNode*>();
        }
    }
    return res;
}

