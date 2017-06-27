#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

/*
 * Binary Tree Paths
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 * For example, given the following binary tree:
 *
 *     1
 *    / \
 *   2   3
 *    \
 *     5
 * All root-to-leaf paths are:
 *
 * ["1->2->5", "1->3"]
 *
 *
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

string getPath(vector<int>& vec) {
    string res = "";
    if(vec.empty())
        return res;
    stringstream ss;
    ss << vec[0];
    ss >> res;
    for(auto iter = vec.begin() + 1; iter != vec.end(); iter++) {
        string tmp;
        stringstream str;
        str << *iter;
        str >> tmp;
        res = res + "->" + tmp;
    }
    return res;
}

void preOrder(TreeNode* root, vector<int>& path, vector<string>& res) {
    path.push_back(root->val);
    if(root->left != NULL)
        preOrder(root->left, path, res);
    if(root->right != NULL)
        preOrder(root->right, path, res);
    if(root->left == NULL && root->right == NULL)
        res.push_back(getPath(path));
    path.pop_back();
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<int> path;
    vector<string> res;
    if(root == NULL)
    	return res;
    preOrder(root, path, res);
    return res;
}
