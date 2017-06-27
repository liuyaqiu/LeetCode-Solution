#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode* root, int depth, int& res) {
    if(root->left == NULL && root->right == NULL) {
        if(depth > res)
            res = depth;
    }
    if(root->left != NULL)
        preOrder(root->left, depth + 1, res);
    if(root->right != NULL)
        preOrder(root->right, depth + 1, res);
}

int maxDepth(TreeNode* root) {
    if(root == NULL)
        return 0;
    int res = 1;
    preOrder(root, 1, res);
    return res;
}
