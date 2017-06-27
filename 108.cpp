#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* filledTree(int n) {
    vector<TreeNode*> tree;
    for(int i = 0; i < n; i++) {
        TreeNode* cur = new TreeNode(i);
        tree.push_back(cur);
    }
    for(int i = 1; i <= n; i++) {
        if(2 * i <= n)
            tree[i - 1]->left = tree[2 * i - 1];
        if(2 * i + 1 <= n)
            tree[i - 1]->right = tree[2 * i];
    }
    return tree[0];
}

void inOrder(TreeNode* root, vector<int>& nums) {
    if(root->right != NULL)
        inOrder(root->right, nums);
    root->val = nums.back();
    nums.pop_back();
    if(root->left != NULL)
        inOrder(root->left, nums);
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.empty())
        return NULL;
    TreeNode* root = filledTree(nums.size());
    inOrder(root, nums);
    return root;
}

void preOrder(TreeNode* root) {
	if(root == NULL)
		return;
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(TreeNode* root) {
	if(root == NULL)
		return;
	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

int main() {
    vector<int> nums;
    int val;
    while(cin >> val) {
        nums.push_back(val);
    }
    TreeNode* root = sortedArrayToBST(nums);
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
}
