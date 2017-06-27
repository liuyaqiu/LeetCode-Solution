#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

void inOrder(TreeNode* root, ListNode* &head) {
    if(root->left != NULL)
        inOrder(root->left, head);
    root->val = head->val;
    head = head->next;
    if(root->right!= NULL)
        inOrder(root->right, head);
}

TreeNode* sortedListToBST(ListNode* head) {
    if(head == NULL)
        return NULL;
    int n = 0;
    ListNode* cur = head;
    while(cur != NULL) {
        cur = cur->next;
        n += 1;
    }
    cout << n << endl;
    TreeNode* root = filledTree(n);
    inOrder(root, head);
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
    ListNode* head = new ListNode(0);
    int val;
    ListNode* list = head;
    while(cin >> val) {
        ListNode* cur = new ListNode(val);
        head->next = cur;
        head = head->next;
    }
    TreeNode* root = sortedListToBST(list->next);
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
}
