#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void postOrder(TreeNode* root, int psum, int target, vector<int>& path, vector<vector<int>>& res) {
    path.push_back(root->val);
    if(root->left != NULL)
        postOrder(root->left, psum + root->val, target, path, res);
    if(root->right != NULL)
        postOrder(root->right, psum + root->val, target, path, res);
    if(root->left == NULL && root->right == NULL) {
        if(psum + root->val == target) {
            res.push_back(path);
        }
    }
    path.pop_back();
}

void print(vector<int> path) {
    for(auto iter = path.begin(); iter != path.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
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
    tree[5]->left = tree[8];
    tree[5]->right = tree[9];
    int target;
    cout << "Input target: ";
    cin >> target;
    vector<int> path;
    vector<vector<int>> res;
    postOrder(tree[0], 0, target, path, res);
    for(auto iter = res.begin(); iter != res.end(); iter++)
        print(*iter);
    return 0;
}
