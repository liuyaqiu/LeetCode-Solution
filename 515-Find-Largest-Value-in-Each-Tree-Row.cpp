#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<int> largestValues(TreeNode* root) {
    if(root == NULL)
        return {};
    queue<TreeNode*> cur;
    queue<TreeNode*> next;
    cur.push(root);
    int maxi = root->val;
    vector<int> res;
    while(!cur.empty()) {
        TreeNode* top = cur.front();
        maxi = max(maxi, top->val);
        if(top->left != NULL)
            next.push(top->left);
        if(top->right != NULL)
            next.push(top->right);
        cur.pop();
        if(cur.empty()) {
            res.push_back(maxi);
            cur = next;
            maxi = cur.front()->val;
            next = queue<TreeNode*>();
        }
    }
    return res;
}
