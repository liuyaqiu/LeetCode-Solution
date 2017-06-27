#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define inf numeric_limits<int>::max()

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode* root, int& res, bool& has_pre, int& pre) {
    if(root->left != NULL)
        preOrder(root->left, res, has_pre, pre);
    if(has_pre) {
        int tmp = root->val - pre;
        res = min(tmp, res);
    }
    else
        has_pre = true;
    pre = root->val;
    if(root->right != NULL)
        preOrder(root->right, res, has_pre, pre);
}

int getMinimumDifference(TreeNode* root) {
    int res = inf;
    bool has_pre = false;
    int pre = inf;
    preOrder(root, res, has_pre, pre);
    return res;
}
