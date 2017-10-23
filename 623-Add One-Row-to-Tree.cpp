/*
  Add One Row to Tree

  Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1.

  The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree nodes with value v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of the new left subtree root, its original right subtree should be the right subtree of the new right subtree root. If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v as the new root of the whole original tree, and the original tree is the new root's left subtree.

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

void add(TreeNode* parent, TreeNode* root, int v, int d, bool left) {
    if(d == 1) {
        TreeNode* node = new TreeNode(v);
        if(left) {
            node->left = root;
            if(parent != NULL)
                parent->left = node;
        }
        else {
            node->right = root;
            if(parent != NULL)
                parent->right = node;
        }
        return;
    }
    else {
        if(root != NULL) {
            add(root, root->left, v, d - 1, true);
            add(root, root->right, v, d - 1, false);
        }
    }
}

TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if(d == 1) {
        TreeNode* node = new TreeNode(v);
        node->left = root;
        return node;
    }
    else {
        add(NULL, root, v, d, true);
        return root;
    }
}
