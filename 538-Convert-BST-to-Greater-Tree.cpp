#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void traversal(TreeNode* root, int& sum) {
    if(root->right != NULL)
        traversal(root->right, sum);
    sum += root->val;
    root->val = sum;
    if(root->left != NULL)
        traversal(root->left, sum);
}

TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    traversal(root, sum);
    return root;
}
