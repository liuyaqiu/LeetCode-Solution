#include <iostream>
#include <map>
#include <string>

using namespace std;

/*
 * House Robber III
 *
 * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
 *
 * Determine the maximum amount of money the thief can rob tonight without alerting the police.
 *
 * Example 1:
 *      3
 *     / \
 *    2   3
 *     \   \
 *      3   1
 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * Example 2:
 *      3
 *     / \
 *    4   5
 *   / \   \
 *  1   3   1
 * Maximum amount of money the thief can rob = 4 + 5 = 9.
 *
 *
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        std::map<TreeNode*, int> noNode;
        int rob(TreeNode* root) {
        	if(root == NULL)
        		return 0;
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            noNode[root] = 0;
            int noLeft = 0;
            int resLeft = 0;
            if(left != NULL) {
                resLeft = rob(left);
                noLeft = noNode[left];
            }
            int noRight = 0;
            int resRight = 0;
            if(right != NULL) {
                resRight = rob(right);
                noRight = noNode[right];
            }
            root->val += noLeft + noRight;
            noNode[root] = resLeft + resRight;
            return root->val > noNode[root] ? root->val : noNode[root];
        }
};

