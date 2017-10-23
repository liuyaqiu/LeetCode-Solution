/*
  Average of Levels in Binary Tree

  Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode* root, int depth, vector<double>& sums, vector<int>& cnt) {
    if(root == NULL)
        return;
    if(sums.size() < depth) {
        sums.push_back(root->val);
        cnt.push_back(1);
    }
    else {
        sums[depth - 1] += root->val;
        cnt[depth - 1] += 1;
    }
    preOrder(root->left, depth + 1, sums, cnt);
    preOrder(root->right, depth + 1, sums, cnt);
}

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> sums;
    vector<int> cnt;
    preOrder(root, 1, sums, cnt);
    if(sums.empty())
        return sums;
    for(int i = 0; i < sums.size(); i++)
        sums[i] /= cnt[i];
    return sums;
}
