/*
  Two Sum IV - Input is a BST

  Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool findNode(TreeNode* root, int val) {
    if(root == NULL)
        return false;
    if(root->val == val)
        return true;
    else if(root->val < val)
        return findNode(root->right, val);
    else
        return findNode(root->left, val);
}

bool preOrder(TreeNode* root, TreeNode* cur, int target) {
    if(cur == NULL)
        return false;
    bool tmp = false;
    if(target > 2 * cur->val)
        tmp = findNode(root, target - cur->val);
    return tmp || preOrder(root, cur->left, target) || preOrder(root, cur->right, target);
}

bool findTarget(TreeNode* root, int k) {
    return preOrder(root, root, k);
}
