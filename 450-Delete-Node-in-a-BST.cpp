#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* search(TreeNode* root, TreeNode*& pre, int val) {
    if(root == NULL)
        return NULL;
    while(root != NULL && root->val != val) {
        pre = root;
        if(root->val < val)
            root = root->right;
        else
            root = root->left;
    }
    return root;
}

TreeNode* leftNode(TreeNode* root) {
    if(root == NULL)
        return NULL;
    while(root->left != NULL)
        root = root->left;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* pre = NULL;
    TreeNode* node = search(root, pre, key);
    if(node == NULL)
        return root;
    if(pre == NULL)
        root = root->right;
    if(node->right == NULL) {
        if(pre != NULL) {
            if(pre->left == node)
                pre->left = node->left;
            else
                pre->right = node->left;
        }
    }
    else {
        TreeNode* left = leftNode(node->right);
        if(pre != NULL) {
            left->left = node->left;
            if(pre->left == node)
                pre->left = node->right;
            else
                pre->right = node->right;
        }
    }
    delete(node);
    return root;
}

