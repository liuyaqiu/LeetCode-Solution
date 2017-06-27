#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void invert(TreeNode* root) {
    if(root == NULL)
        return;
    invert(root->left);
    invert(root->right);
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
}

TreeNode* invertTree(TreeNode* root) {
    invert(root);
    return root;
}
