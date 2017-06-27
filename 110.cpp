#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool postOrder(TreeNode* root, int& depth) {
    if(root == NULL) {
        depth = 0;
        return true;
    }
    int ldepth = 0;
    int rdepth = 0;
    if(!postOrder(root->left, ldepth, balance) || !postOrder(root->right, rdepth, balance) || abs(ldepth - rdepth) > 1)
    	return false;
    else
        depth = max(ldepth, rdepth) + 1;
    return true;
}

bool isBalanced(TreeNode* root) {
    bool balance = true;
    int depth = 0;
    return postOrder(root, depth);
}


