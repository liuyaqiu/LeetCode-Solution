/*
  Longest Univalue Path

  Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

  Note: The length of path between two nodes is represented by the number of edges between them.

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

int longestUnivalue(TreeNode* root, int& res) {
    if(root == NULL)
        return 0;
    int lcur = 0;
    if(root->left != NULL) {
        int lres = longestUnivalue(root->left, res);
        if(root->left->val == root->val)
            lcur = lres + 1;
    }
    int rcur = 0;
    if(root->right != NULL) {
        int rres = longestUnivalue(root->right, res);
        if(root->right->val == root->val)
            rcur = rres + 1;
    }
    res = max(res, lcur + rcur);
    return max(lcur, rcur);
}

int longestUnivaluePath(TreeNode* root) {
    if(root == NULL)
        return 0;
    int res = 0;
    longestUnivalue(root, res);
    return res;
}
