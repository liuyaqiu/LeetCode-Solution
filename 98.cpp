#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void inOrder(TreeNode* root, TreeNode* &pre, bool& judge) {
    if(root == NULL)
        return;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    if(left != NULL)
        inOrder(left, pre, judge);
    if(pre != NULL) {
        if(root->val <= pre->val) {
            judge = false;
            return;
        }
    }
    pre = root;
    if(right != NULL)
        inOrder(right, pre, judge);
}

bool isValidBST(TreeNode* root) {
    TreeNode* pre = NULL;
    bool judge = true;
    inOrder(root, pre, judge);
    return judge;
}

