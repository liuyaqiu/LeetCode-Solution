#include <iostream>
#include <map>
#include <string>

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

