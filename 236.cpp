#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* ancestor(vector<TreeNode*>& path_p, vector<TreeNode*>& path_q) {
    int i = 0;
    while(i < path_p.size() && i < path_q.size()) {
        if(path_p[i] != path_q[i]) {
            if(i == 0)
                return NULL;
            else
                return path_p[i - 1];
        }
        i++;
    }
    if(i == path_p.size())
        return path_p.back();
    else
        return path_q.back();
}

void preOrder(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& path, vector<TreeNode*>& path_p, vector<TreeNode*>& path_q) {
    path.push_back(root);
    if(root == p)
        path_p = path;
    if(root == q)
        path_p = path;
    if(root->left != NULL)
        preOrder(root->left, p, q, path, path_p, path_q);
    if(root->right != NULL)
        preOrder(root->right, p, q, path, path_p, path_q);
    path.pop_back();
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> path, path_p, path_q;
    preOrder(root, p, q, path, path_p, path_q);
    return ancestor(path_p, path_q);
}
