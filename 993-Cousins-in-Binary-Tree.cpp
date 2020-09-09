/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, int x, int y, int depth, TreeNode* prev, int& x_depth, TreeNode*& x_parent, int& y_depth, TreeNode*& y_parent) {
        if (root == nullptr) {
            return;
        }
        if (root->val == x) {
            x_parent = prev;
            x_depth = depth;
        }
        if (root->val == y) {
            y_parent= prev;
            y_depth = depth;
        }
        traverse(root->left, x, y, depth + 1, root, x_depth, x_parent, y_depth, y_parent);
        traverse(root->right, x, y, depth + 1, root, x_depth, x_parent, y_depth, y_parent);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int x_depth = -1;
        int y_depth = -1;
        TreeNode* x_parent = nullptr;
        TreeNode* y_parent = nullptr;
        traverse(root, x, y, 0, nullptr, x_depth, x_parent, y_depth, y_parent);
        return (x_depth >= 0 && y_depth == x_depth && y_parent != x_parent);
    }
};