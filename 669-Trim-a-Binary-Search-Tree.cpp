/*
  Trim a Binary Search Tree

  Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

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

TreeNode* trimBST(TreeNode* root, int L, int R) {
    while(root != NULL) {
        if(root->val < L)
            root = root->right;
        else if(root->val > R)
            root = root->left;
        else
            break;
    }
    if(root == NULL)
        return NULL;
    TreeNode* ltree = root->left;
    TreeNode* rtree = root->right;
    TreeNode* lprev = root;
    TreeNode* rprev = root;
    while(ltree != NULL) {
        if(ltree->val >= L) {
            lprev = ltree;
            ltree = ltree->left;
        }
        else {
            lprev->left = ltree->right;
            ltree = ltree->right;
        }
    }
    while(rtree != NULL) {
        if(rtree->val <= R) {
            rprev = rtree;
            rtree = rtree->right;
        }
        else {
            rprev->right = rtree->left;
            rtree = rtree->left;
        }
    }
    return root;
}
