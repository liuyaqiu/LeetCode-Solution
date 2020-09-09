/*
 * Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
 *
 * Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(TreeNode* cur, TreeNode* parent, int val, bool isleft) {
    if(cur != NULL) {
        if(val < cur->val)
            insert(cur->left, cur, val, true);
        else
            insert(cur->right, cur, val, false);
    }
    else {
        TreeNode* node = new TreeNode(val);
        if(parent == NULL)
            return;
        if(isleft)
            parent->left = node;
        else
            parent->right = node;
    }
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    insert(root, NULL, val, true);
    return root;
}
