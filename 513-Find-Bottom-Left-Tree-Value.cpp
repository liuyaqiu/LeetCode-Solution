#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void inOrder(TreeNode* root, int& res, int& res_depth, int cur_depth) {
    if(root->left != NULL)
        inOrder(root->left, res, res_depth, cur_depth + 1);
    if(root->right != NULL)
        inOrder(root->right, res, res_depth, cur_depth + 1);
    if(root->left == NULL) {
        if(cur_depth > res_depth) {
            res_depth = cur_depth;
            res = root->val;
        }
    }
}

int findBottomLeftValue(TreeNode* root) {
    int res = 0;
    int res_depth = 0;
    inOrder(root, res, res_depth, 1);
    return res;
}
