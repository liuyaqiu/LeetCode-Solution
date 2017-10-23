/*
  Print Binary Tree

  Print a binary tree in an m*n 2D string array following these rules:

  The row number m should be equal to the height of the given binary tree.
  The column number n should always be an odd number.
  The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
  Each unused space should contain an empty string "".
  Print the subtrees following the same rules.

 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root) {
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

void tranversal(TreeNode* root, vector<vector<string>>& res, int level, int delta) {
    if(root == NULL)
        return;
    int h = res.size();
    int pos = pow(2, h - 1 - level) - 1 + delta;
    res[level][pos] = to_string(root->val);
    tranversal(root->left, res, level + 1, delta);
    tranversal(root->right, res, level + 1, pos + 1);
}

vector<vector<string>> printTree(TreeNode* root) {
    int m = height(root);
    int n = pow(2, m) - 1;
    vector<vector<string>> res(m, vector<string>(n, ""));
    tranversal(root, res, 0, 0);
    return res;
}
