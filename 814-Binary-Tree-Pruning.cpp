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
    int prune(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_prune = prune(root->left);
        int right_prune = prune(root->right);
        int res = (root->val == 1);
        if (left_prune == 0) {
            root->left = nullptr;
        } else {
            res += left_prune;
        }
        if (right_prune == 0) {
            root->right = nullptr;
        } else {
            res += right_prune;
        }
        return res;
    }

    TreeNode* pruneTree(TreeNode* root) {
        int res = prune(root);
        if (res == 0) {
            return nullptr;
        }
        return root;
    }
};