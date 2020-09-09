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
    void traverse(TreeNode* root, int L, int R, int& res) {
        if (root == nullptr) {
            return;
        }
        if (root->val >= L && root->val <= R) {
            res += root->val;
        }
        if (root->val >= L) {
            traverse(root->left, L, R, res);
        }
        if (root->val <= R) {
            traverse(root->right, L, R, res);
        }
    }

    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        traverse(root, L, R, res);
        return res;
    }
};