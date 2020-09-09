/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void tranverse(TreeNode* root, TreeNode* target, int level, int& depth) {
    if (root == target) {
        depth = level;
        return;
    }
    if (root == nullptr) {
        return;
    }
    tranverse(root->left, target, level + 1, depth);
    tranverse(root->right, target, level + 1, depth);
}

void collect(TreeNode* root, int target, int level, vector<int>& res) {
    if (root == nullptr || level > target) {
        return;
    }
    if (level == target) {
        res.push_back(root->val);
        return;
    }
    collect(root->left, target, level + 1, res);
    collect(root->right, target, level + 1, res);
}

void parent_nodes(TreeNode* root, TreeNode* target, vector<TreeNode*>& path, vector<TreeNode*>& res) {
    if (root == nullptr) {
        return;
    }
    path.push_back(root);
    if (root == target) {
        res = path;
        return;
    }
    parent_nodes(root->left, target, path, res);
    parent_nodes(root->right, target, path, res);
    path.pop_back();
}

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        int depth = 0;
        tranverse(root, target, 0, depth);
        vector<TreeNode*> path;
        vector<TreeNode*> pnodes;
        parent_nodes(root, target, path, pnodes);
        vector<int> res;
        for (int i = 0; i < depth; i++) {
            if (depth - i < K) {
                if (pnodes[i]->left == pnodes[i + 1]) {
                    collect(pnodes[i]->right, K - (depth - i) - 1, 0, res);
                } else {
                    collect(pnodes[i]->left, K - (depth - i) - 1, 0, res);
                }
            } else if (depth - i == K) {
                res.push_back(pnodes[i]->val);
            }
        }
        collect(target, K, 0, res);
        return res;
    }
};