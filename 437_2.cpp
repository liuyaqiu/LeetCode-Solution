#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int dfs(TreeNode* root, int target) {
    if(root == NULL)
        return 0;
    int res = 0;
    if(root->val == target)
        res += 1;
    res += dfs(root->left, target - root->val) + dfs(root->right, target - root->val);
    return res;
}

int pathSum(TreeNode* root, int sum) {
    if(root == NULL)
        return 0;
    return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
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
    tree[1]->right = tree[4];
    tree[3]->left = tree[6];
    tree[2]->right = tree[5];
    int target;
    cout << "Input target: ";
    cin >> target;
    int count = pathSum(tree[0], target);
    cout << "There is " << count << " downwards pathsums." << endl;
    return 0;
}
