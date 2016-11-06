#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* curTree(TreeNode* root, TreeNode* cur, int val) {
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    TreeNode* newLeft;
    if(left != NULL)
         newLeft = curTree(left, cur, val);
    else
        newLeft = NULL;
    TreeNode* newRight;
    if(right != NULL)
        newRight = curTree(right, cur, val);
    else
        newRight = NULL;
    if(root == cur) {
        TreeNode* last = new TreeNode(val);
        last->left = newRight;
        newRight = last;
    }
    TreeNode* newRoot = new TreeNode(root->val);
    newRoot->left = newLeft;
    newRoot->right = newRight;
    return newRoot;
}

void rightLeaf(TreeNode* root, TreeNode* cur, vector<TreeNode*>& res, int val) {
    TreeNode* right = cur->right;
    if(right != NULL) {
        rightLeaf(root, right, res, val);
    }
    TreeNode* tmp = curTree(root, cur, val);
    res.push_back(tmp);
}

void getTrees(TreeNode* root, vector<TreeNode*>& res, int n) {
    TreeNode* first = curTree(root, NULL, n);
    TreeNode* node = new TreeNode(n);
    node->left = first;
    res.push_back(node);
    rightLeaf(root, root, res, n);
}

void print(TreeNode* root) {
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    if(left != NULL)
        print(left);
    cout << root->val << " ";
    if(right != NULL)
        print(right);
}

vector<TreeNode*> generateTrees(int n) {
	vector<TreeNode*> pre;
	if(n == 0)
		return pre;
    int k = 1;
    TreeNode* tmp = new TreeNode(k);
    k += 1;
    pre.push_back(tmp);
    while(k <= n) {
        vector<TreeNode*> cur;
        for(auto iter = pre.begin(); iter != pre.end(); ++iter) {
            getTrees(*iter, cur, k);
        }
        pre = cur;
        k += 1;
    }
    cout << "res: " << endl;
    for(auto iter = pre.begin(); iter != pre.end(); ++iter) {
        print(*iter);
        cout << endl;
    }
    cout << "size: " << pre.size() << endl;
    return pre;
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode*> res = generateTrees(n);
    return 0;
}
