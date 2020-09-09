#include <cmath>
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
    void MidOrder(TreeNode* root, int* prev, int* res) {
        if (root == nullptr) {
            return;
        }
        MidOrder(root->left, prev, res);
        if (*prev != numeric_limits<int>::max()) {
            *res = min(*res, abs(root->val - *prev));
        }
        *prev = root->val;
        MidOrder(root->right, prev, res);
    }

    int minDiffInBST(TreeNode* root) {
        int prev = numeric_limits<int>::max();
        int res = numeric_limits<int>::max();
        MidOrder(root, &prev, &res);
        return res;
    }
};