#include <iostream>
#include <vector>

using namespace std;

/*
 * Sum of Left Leaves
 *
 * Find the sum of all left leaves in a given binary tree.
 *
 * Example:
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 *
 *
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int eval(TreeNode* root, bool isLeft) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL && isLeft)
        return root->val;
    else
        return eval(root->left, true) + eval(root->right, false);
}

int sumOfLeftLeaves(TreeNode* root) {
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return eval(root, true);
}
