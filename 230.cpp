#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void inOrder(TreeNode* root, int& k, int& res) {
    if(root->left != NULL)
        inOrder(root->left, k, res);
    k--;
    if(k == 0) {
        res = root->val;
        return;
    }
    if(root->right != NULL)
        inOrder(root->right, k, res);
}

int kthSmallest(TreeNode* root, int k) {
    int res = root->val;
    int kth = k;
    inOrder(root, kth, res);
    return res;
}
