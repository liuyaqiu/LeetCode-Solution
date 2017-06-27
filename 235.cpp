#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(p->val < root->val) {
        if(q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
    else if(p->val > root->val){
        if(q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
    else
        return root;
}
