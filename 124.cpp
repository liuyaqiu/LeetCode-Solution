#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void postOrder(TreeNode* root, int& path, int& res) {
        int lpath = 0;
        int rpath = 0;
        if(root->left != NULL) {
            postOrder(root->left, lpath, res);
        }
        if(root->right != NULL) {
            postOrder(root->right, rpath, res);
        }
        if(lpath < 0)
            lpath = 0;
        if(rpath < 0)
            rpath = 0;
        path = max(lpath, rpath) + root->val;
        if(lpath + rpath + root->val > res)
            res = lpath + rpath + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int path = 0;
        int res = root->val;
        postOrder(root, path, res);
        return res;
    }
};
