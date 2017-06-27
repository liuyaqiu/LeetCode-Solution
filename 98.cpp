#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool inOrder(TreeNode* root, TreeNode* &pre) {
    if(root == NULL)
        return true;
    if(!inOrder(root->left, pre))
        return false;
    if(pre != NULL) {
        if(root->val <= pre->val)
            return false;
    }
    pre = root;
    if(!inOrder(root->right, pre))
        return false;
    return true;
}

bool isValidBST(TreeNode* root) {
    TreeNode* pre = NULL;
    return inOrder(root, pre);
}

