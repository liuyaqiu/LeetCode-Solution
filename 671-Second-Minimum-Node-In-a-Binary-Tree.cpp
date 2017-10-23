/*
  Second Minimum Node In a Binary Tree

  Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

  Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

  If no such second minimum value exists, output -1 instead.

 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int findSecondMinimumValue(TreeNode* root) {
    if(root == NULL)
        return -1;
    TreeNode* ltree = root->left;
    TreeNode* rtree = root->right;
    if(ltree == NULL)
        return -1;
    int res1 = findSecondMinimumValue(ltree);
    int res2 = findSecondMinimumValue(rtree);
    if(ltree->val > rtree->val) {
        if(res2 == -1)
            return ltree->val;
        else
            return min(ltree->val, res2);
    }
    else if(ltree->val < rtree->val) {
        if(res1 == -1)
            return rtree->val;
        else
            return min(rtree->val, res1);
    }
    else {
        if(res1 == -1)
            return res2;
        if(res2 == -1)
            return res1;
        return min(res1, res2);
    }
}
