/*
  Maximum Width of Binary Tree

  Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

  The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode* root, vector<int>& mini, vector<int>& maxi, int level, int pos) {
    if(root == NULL)
        return;
    if(mini.size() <= level) {
        mini.push_back(pos);
        maxi.push_back(pos);
    }
    else {
        mini[level] = min(mini[level], pos);
        maxi[level] = max(maxi[level], pos);
    }
    preOrder(root->left, mini, maxi, level + 1, 2 * pos);
    preOrder(root->right, mini, maxi, level + 1, 2 * pos + 1);
}

int widthOfBinaryTree(TreeNode* root) {
    vector<int> mini, maxi;
    preOrder(root, mini, maxi, 0, 0);
    int res = 0;
    for(int i = 0; i < mini.size(); i++)
        res = max(res, maxi[i] - mini[i] + 1);
    return res;
}
