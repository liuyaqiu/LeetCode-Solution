#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    TreeNode(): left(NULL), right(NULL) {}
};

void postOrder(TreeNode* root, int& path, int& res) {
    int lpath = 0;
    int rpath = 0;
    if(root->left != NULL) {
        postOrder(root->left, lpath, res);
    }
    if(root->right != NULL) {
        postOrder(root->right, rpath, res);
    }
    path = max(lpath, rpath) + 1;
    if(lpath + rpath > res)
        res = lpath + rpath;
}

int main() {
    vector<TreeNode*> tree;
    for(int i = 0; i < 100; i++) {
        TreeNode* cur = new TreeNode();
        tree.push_back(cur);
    }
    tree[1]->left = tree[0];
    tree[2]->left = tree[1];
    tree[2]->right = tree[3];
    tree[4]->left = tree[2];
    tree[4]->right = tree[6];
    //tree[6]->left = tree[5];
    tree[3]->left = tree[7];
    tree[7]->left = tree[8];
    tree[7]->right = tree[9];
    tree[9]->right = tree[10];
    int path = 0;
    int res = 0;
    cout << "Please input the node number: ";
    int k;
    cin >> k;
    postOrder(tree[k], path, res);
    cout << "The length is: " << path - 1 << endl;
    cout << "The longest path is: " << res << endl;
}

