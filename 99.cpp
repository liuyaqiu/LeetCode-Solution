#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode* root, TreeNode* &pre, TreeNode* &node1, TreeNode* &node2) {
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    if(left != NULL)
        preOrder(root, pre, node1, node2);
    if(pre != NULL) {
        if(root->val <= pre->val) {
            if(node1 == NULL) {
                node1 = pre;
                node2 = root;
            }
            else {
                if(root->val < node2->val)
                    node2 = root;
            }
        }
    }
    pre = root;
    if(right != NULL)
        preOrder(root, pre, node1, node2);
}

void recoverTree(TreeNode* root) {
	if(root == NULL)
		return;
    TreeNode* pre = NULL;
    TreeNode* node1 = NULL;
    TreeNode* node2 = NULL;
    preOrder(root, pre, node1, node2);
    swap(node1->val, node2->val);
}
