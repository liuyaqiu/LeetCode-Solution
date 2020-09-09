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
    pair<int, TreeNode*> maxDepthAndMinSubtree(TreeNode* root, int depth) {
        if (root == nullptr) {
            return {-1, nullptr};
        }
        pair<int, TreeNode*> left = maxDepthAndMinSubtree(root->left, depth + 1);
        pair<int, TreeNode*> right = maxDepthAndMinSubtree(root->right, depth + 1);
        if (left.second == nullptr) {
            if (right.second != nullptr) {
                return right;
            } else {
                return {depth, root};
            }
        } else {
            if (right.second == nullptr) {
                return left;
            } else {
                if (left.first != right.first) {
                    return left.first > right.first ? left : right;
                } else {
                    return {left.first, root};
                }
            }
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<int, TreeNode*> res = maxDepthAndMinSubtree(root, 0);
        return res.second;
    }
};