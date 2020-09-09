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
    pair<TreeNode*, TreeNode*> leftAndRightNode(TreeNode* root) {
        if (root == nullptr) {
            return {nullptr, nullptr};
        }
        pair<TreeNode*, TreeNode*> left = leftAndRightNode(root->left);
        pair<TreeNode*, TreeNode*> right = leftAndRightNode(root->right);
        TreeNode* left_most = root;
        TreeNode* right_most= root;
        if (left.first != nullptr) {
            left_most = left.first;
            right_most = left.second;
        }
        if (right_most != root) {
            right_most->right = root;
            right_most->left = nullptr;
            right_most = root;
        }
        if (right.first != nullptr) {
            right_most->right = right.first;
            right_most->left = nullptr;
            right_most = right.second;
        }
        left_most->left = nullptr;
        right_most->left = nullptr;
        return {left_most, right_most};
    }

    TreeNode* increasingBST(TreeNode* root) {
        pair<TreeNode*, TreeNode*> left_most_and_right_most = leftAndRightNode(root);
        return left_most_and_right_most.first;
    }
};