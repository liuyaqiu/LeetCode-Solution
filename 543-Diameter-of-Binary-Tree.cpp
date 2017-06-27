#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int depth(TreeNode* root, int& res) {
    if(root == NULL)
        return -1;
    int lval = depth(root->left, res);
    int rval = depth(root->right, res);
    int tmp = lval + rval + 2;
    if(tmp > res)
        res = tmp;
    return 1 + max(lval, rval);
}

int diameterOfBinaryTree(TreeNode* root) {
    int res = 0;
    depth(root, res);
    return res;
}
