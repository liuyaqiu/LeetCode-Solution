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

int countNodes(TreeNode* root) {
	if(root == NULL)
		return 0;
    int lh = 0;
    TreeNode* left = root->left;
    while(left != NULL) {
        left = left->left;
        lh++;
    }
    int rh = 0;
    TreeNode* right = root->right;
    while(right != NULL) {
        right = right->right;
        rh++;
    }
    if(lh == rh)
        return pow(2, lh + 1) - 1;
    else
        return countNodes(root->left) + countNodes(root->right) + 1;
}

