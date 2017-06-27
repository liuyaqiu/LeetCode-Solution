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

void traversal(vector<vector<int>>& res, vector<int>& out, queue<TreeNode*>& cur, queue<TreeNode*>& next) {
    if(cur.empty()) {
        res.push_back(out);
        out.clear();
        if(next.empty())
            return;
        queue<TreeNode*> tmp = cur;
        cur = next;
        next = tmp;
    }
    else {
        TreeNode* root = cur.front();
        out.push_back(root->val);
        cur.pop();
        if(root->left != NULL)
            next.push(root->left);
        if(root->right != NULL)
            next.push(root->right);
    }
    traversal(res, out, cur, next);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<int> out;
    vector<vector<int>> res;
    if(root == NULL)
        return res;
    queue<TreeNode*> cur;
    cur.push(root);
    queue<TreeNode*> next;
    traversal(res, out, cur, next);
    return res;
}

int main() {
    int n;
    cout << "Input number of nodes: ";
    cin >> n;
    vector<TreeNode*> tree;
    for(int i = 0; i < n; i++) {
        int val;
        cout << "Input val of node[" << i << "]: ";
        cin >> val;
        TreeNode* cur = new TreeNode(val);
        tree.push_back(cur);
    }
    tree[0]->left = tree[1];
    tree[0]->right = tree[2];
    tree[2]->left = tree[3];
    tree[2]->right = tree[4];
    vector<vector<int>> res = levelOrder(tree[0]);
    cout << "Level order traversal sequence: " << endl;
    for(auto iter1 = res.begin(); iter1 != res.end(); iter1++) {
    	cout << "Depth " << iter1 - res.begin() + 1 << ": ";
        for(auto iter2 = iter1->begin(); iter2 != iter1->end(); iter2++) {
            cout << *iter2 << " ";
        }
        cout << endl;
    }
}
