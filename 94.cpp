#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root, vector<int>& res) {
    if(root == NULL)
        return;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    if(left != NULL)
        inorder(left, res);
    res.push_back(root->val);
    if(right != NULL)
        inorder(right, res);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
}

