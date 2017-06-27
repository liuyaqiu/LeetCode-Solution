#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool judge(TreeNode* tree1, TreeNode* tree2) {
    if(tree1 == NULL)
        return tree2 == NULL;
    if(tree2 == NULL)
        return tree1 == NULL;
    bool res = tree1->val == tree2->val;
    if(res)
        res = judge(tree1->left, tree2->right);
    if(res)
        res = judge(tree1->right, tree2->left);
    return res;
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL)
        return true;
    return judge(root->left, root->right);
}
