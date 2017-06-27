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

int find(vector<int>& vec, int val, int start, int end) {
    for(int i = start; i < end; i++) {
        if(vec[i] == val)
            return i - start;
    }
    return -1;
}

TreeNode* postOrder(vector<int>& postorder, int post_start, int post_end, vector<int>& inorder, int in_start, int in_end) {
    //cout << "post_start: " << post_start << ", " << "post_end: " << post_end << endl;
    if(post_end <= post_start)
        return NULL;
    int val = postorder[post_end - 1];
    TreeNode* cur = new TreeNode(val);
    int index = find(inorder, val, in_start, in_end);
    int left_post_start = post_start;
    int left_post_end = post_start + index;
    int left_in_start = in_start;
    int left_in_end = in_start + index;
    TreeNode* left = postOrder(postorder, left_post_start, left_post_end, inorder, left_in_start, left_in_end);
    int right_post_start = post_start + index;
    int right_post_end = post_end - 1;
    int right_in_start = in_start + 1 + index;
    int right_in_end = in_end;
    TreeNode* right = postOrder(postorder, right_post_start, right_post_end, inorder, right_in_start, right_in_end);
    cur->left = left;
    cur->right = right;
    return cur;
}

TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
    return postOrder(postorder, 0, postorder.size(), inorder, 0, inorder.size());
}

int main() {
	vector<int> postorder;
	vector<int> inorder;
	cout << "Input nodes number: ";
	int n;
	cin >> n;
	cout << "Input postorder: " << endl;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		postorder.push_back(val);
	}
	cout << "Input inorder: " << endl;
		for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		inorder.push_back(val);
	}
	TreeNode* root = buildTree(postorder, inorder);
	cout << "Output preorder: ";
	preOrder(root);
	cout << endl;
	cout << "Output inorder: ";
	inOrder(root);
	cout << endl;
	return 0;
}
