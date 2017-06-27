#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL)
        return q == NULL;
    if(q == NULL)
        return p == NULL;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
