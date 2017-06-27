#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode* root, string res) {
    if(root == NULL) {
    	res += "NULL";
        return;
    }
    res += to_string(root->val) + "-";
    preOrder(root->left, res);
    preOrder(root->right, res);
}

void inOrder(TreeNode* root, string res) {
    if(root == NULL) {
    	res += "NULL";
        return;
    }
    preOrder(root->left, res);
    res += to_string(root->val) + "-";
    preOrder(root->right, res);
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    string res1_s = "";
    string res2_s = "";
    preOrder(s, res1_s);
    inOrder(s, res2_s);
    string res1_t = "";
    string res2_t = "";
    preOrder(t, res1_t);
    inOrder(t, res2_t);
    return (int)res1_s.find(res1_t) != -1 && (int)res2_s.find(res2_t) != -1;
}
