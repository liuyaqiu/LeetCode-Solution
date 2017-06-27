#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode* root, int psum, int target, bool& has) {
    if(has)
        return;
    if(root->left != NULL)
        preOrder(root->left, psum + root->val, target, has);
    if(root->right != NULL)
        preOrder(root->right, psum + root->val, target, has);
    if(root->left == NULL && root->right == NULL) {
        if(psum + root->val == target)
            has = true;
    }
}

int main() {
    vector<TreeNode*> tree;
    int n;
    cout << "Number of node: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Input node[" << i << "]: ";
        int k;
        cin >> k;
        TreeNode* cur = new TreeNode(k);
        tree.push_back(cur);
    }
    tree[0]->left = tree[1];
    tree[0]->right = tree[2];
    tree[1]->left = tree[3];
    tree[3]->left = tree[6];
    tree[3]->right = tree[7];
    tree[2]->left = tree[4];
    tree[2]->right = tree[5];
    tree[5]->right = tree[8];
    int target;
    cout << "Input target: ";
    cin >> target;
    bool has = false;
    preOrder(tree[0], 0, target, has);
    if(has)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
