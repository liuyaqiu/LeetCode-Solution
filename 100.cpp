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

void inOrder(TreeNode* p, TreeNode* q, bool& judge) {
    if(p == NULL) {
        judge = q == NULL;
        return;
    }
    if(q == NULL) {
        judge = p == NULL;
        return;
    }
    inOrder(p->left, q->left, judge);
    if(!judge)
        return;
    judge = (p->val == q->val);
    if(!judge)
        return;
    inOrder(p->right, q->right, judge);
    if(!judge)
        return;
}

void preOrder(TreeNode* p, TreeNode* q, bool& judge) {
    if(p == NULL) {
        judge = q == NULL;
        return;
    }
    if(q == NULL) {
        judge = p == NULL;
        return;
    }
    judge = (p->val == q->val);
    if(!judge)
        return;
    inOrder(p->left, q->left, judge);
    if(!judge)
        return;
    inOrder(p->right, q->right, judge);
    if(!judge)
        return;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    bool judge = true;
    preOrder(p, q, judge);
    if(!judge)
        return false;
    inOrder(p, q, judge);
    return judge;
}

