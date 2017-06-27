#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int treeSum(TreeNode* root, int& tilt) {
    if(root == NULL)
        return 0;
    int lsum = treeSum(root->left, tilt); 
    int rsum = treeSum(root->right, tilt);
    tilt += abs(lsum - rsum);
    return lsum + rsum;
}

int findTilt(TreeNode* root) {
    int tilt = 0;
    return treeSum(root, tilt);
}
