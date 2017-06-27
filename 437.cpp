#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

unordered_map<int, int> merge(unordered_map<int, int>& lpath, unordered_map<int, int>& rpath, int val, int target, int& count) {
    unordered_map<int, int> path;
    for(auto iter = lpath.begin(); iter != lpath.end(); iter++) {
        int key = iter->first;
        int v = iter->second;
        if(path.find(key + val) == path.end()) {
            path.insert(pair<int, int>(key + val, v));
        }
        else {
            path[key + val] += v;
        }
    }
    for(auto iter = rpath.begin(); iter != rpath.end(); iter++) {
        int key = iter->first;
        int v = iter->second;
        if(path.find(key + val) == path.end()) {
            path.insert(pair<int, int>(key + val, v));
        }
        else {
            path[key + val] += v;
        }
    }
    auto iter = path.find(val);
    if(iter == path.end()) {
        path.insert(pair<int, int>(val, 1));
    }
    else {
        path[val] += 1;
    }
    cout << val << endl;
    for(auto iter = path.begin(); iter != path.end(); iter++)
        cout << "(" << iter->first << "--" << iter->second << "), ";
    cout << endl;
    cout << endl;
    
    iter = path.find(target);
    if(iter != path.end())
        count += iter->second;
    return path;
}

void postOrder(TreeNode* root, unordered_map<int, int>& path, int target, int& count) {
    unordered_map<int, int> lpath;
    unordered_map<int, int> rpath;
    if(root->left != NULL) {
        postOrder(root->left, lpath, target, count);
    }
    if(root->right != NULL) {
        postOrder(root->right, rpath, target, count);
    }
    path = merge(lpath, rpath, root->val, target, count);
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
    unordered_map<int, int> path;
    int count = 0;
    postOrder(tree[0], path, target, count);
    cout << "There is " << count << " downwards pathsums." << endl;
    return 0;
}
