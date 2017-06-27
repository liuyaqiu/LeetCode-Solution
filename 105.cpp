#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int find(vector<int>& vec, int val, int start, int end) {
    for(int i = start; i < end; i++) {
        if(vec[i] == val)
            return i - start;
    }
    return -1;
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

TreeNode* postOrder(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end) {
	//cout << "pre_start: " << pre_start << ", " << "pre_end: " << pre_end << endl;
    if(pre_end <= pre_start)
        return NULL;
    int val = preorder[pre_start];
    TreeNode* cur = new TreeNode(val);
    int index = find(inorder, val, in_start, in_end);
    int left_pre_start = pre_start + 1;
    int left_pre_end = pre_start + 1 + index;
    int left_in_start = in_start;
    int left_in_end = in_start + index;
    TreeNode* left = postOrder(preorder, left_pre_start, left_pre_end, inorder, left_in_start, left_in_end);
    int right_pre_start = pre_start + 1 + index;
    int right_pre_end = pre_end;
    int right_in_start = in_start + 1 + index;
    int right_in_end = in_end;
    TreeNode* right = postOrder(preorder, right_pre_start, right_pre_end, inorder, right_in_start, right_in_end);
    cur->left = left;
    cur->right = right;
    return cur;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return postOrder(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}

int main() {
	vector<int> preorder;
	vector<int> inorder;
	cout << "Input nodes number: ";
	int n;
	cin >> n;
	cout << "Input preorder: " << endl;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		preorder.push_back(val);
	}
	cout << "Input inorder: " << endl;
		for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		inorder.push_back(val);
	}
	TreeNode* root = buildTree(preorder, inorder);
	cout << "Output preorder: ";
	preOrder(root);
	cout << endl;
	cout << "Output inorder: ";
	inOrder(root);
	cout << endl;
	return 0;
}
