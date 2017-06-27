#include <iostream>
#include <vector>
#include <stack>

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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
	if(root == NULL)
		return res;
    stack<TreeNode*> stk;
    stk.push(root);
    bool track = true;
    while(!stk.empty()) {
        TreeNode* cur = stk.top();
        if(track && cur->left != NULL)
            stk.push(cur->left);
        else {
            res.push_back(cur->val);
            //cout << cur->val << " ";
            stk.pop();
            track = false;
            if(cur->right != NULL) {
                stk.push(cur->right);
                track = true;
            }
        }
    }
    return res;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
	if(root == NULL)
		return res;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()) {
        TreeNode* cur = stk.top();
        res.push_back(cur->val);
        //cout << cur->val << " ";
        stk.pop();
        if(cur->right != NULL)
        	stk.push(cur->right);
        if(cur->left != NULL)
        	stk.push(cur->left);
    }
    return res;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
	if(root == NULL)
		return res;
    stack<TreeNode*> stk;
    stk.push(root);
    stack<int> status; //定义节点访问状态，０表示未访问左子树，１表示未方位右子树，２表示已经访问右子树
    status.push(0);
    while(!stk.empty()) {
        TreeNode* cur = stk.top();
        if(status.top() == 0) {
            if(cur->left != NULL) {
                stk.push(cur->left);
                status.push(0);
            }
            else
                status.top() += 1;
        }
        else if(status.top() == 1) {
            if(cur->right != NULL) {
                stk.push(cur->right);
                status.push(0);
            }
            else
                status.top() += 1;
        }
        else {
            res.push_back(cur->val);
            //cout << cur->val << " ";
            stk.pop();
            status.pop();
            if(status.empty())
                break;
            else
                status.top() += 1;
        }
    }
    return res;
}

int find(vector<int>& vec, int val, int start, int end) {
    for(int i = start; i < end; i++) {
        if(vec[i] == val)
            return i - start;
    }
    return -1;
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
	postorderTraversal(root);
	cout << endl;
	return 0;
}
