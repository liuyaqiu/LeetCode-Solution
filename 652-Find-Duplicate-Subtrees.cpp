/*
  Find Duplicate Subtrees

  Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

  Two trees are duplicate if they have the same structure with same node values.

 */

/*
  一个二叉树的前序序列和中序序列完全定义了该二叉树，比较两个二叉树是否相同，即比较对应的两个序列是否完全相同。
  因此此问题变成了一个编码问题，即采取适当的方式对二叉树进行编码以表示该二叉树，对任意节点，比较其编码即可得到树中是否存在等同的子树。
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL);
};

typedef pair<string, string> mypair;

struct comp {
    bool operator()(const mypair& x, const mypair& y) const {
        if(x.first != y.first)
            return x.first < y.first;
        else
            return x.second < y.second;
    }
};

string preOrder(TreeNode* root, map<TreeNode*, string>& preorder) {
    if(root == NULL)
        return "";
    string cur = to_string(root->val);
    string lstr = preOrder(root->left, preorder);
    string rstr = preOrder(root->right, preorder);
    preorder[root] = cur + "+" + lstr + "-" + rstr;
    return preorder[root];
}

string inOrder(TreeNode* root, map<TreeNode*, string>& inorder) {
    if(root == NULL)
        return "";
    string cur = to_string(root->val);
    string lstr = inOrder(root->left, inorder);
    string rstr = inOrder(root->right, inorder);
    inorder[root] = lstr + "+" + cur + "-" + rstr;
    return inorder[root];
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    map<TreeNode*, string> preorder;
    map<TreeNode*, string> inorder;
    preOrder(root, preorder);
    inOrder(root, inorder);
    map<mypair, int, comp> cnt;
    vector<TreeNode*> res;
    for(auto item: preorder) {
        string prestr = item.second;
        string instr = inorder[item.first];
        mypair p(prestr, instr);
        if(cnt.find(p) != cnt.end()) {
            if(cnt[p] == 1)
                res.push_back(item.first);
            cnt[p] += 1;
        }
        else
            cnt[p] = 1;
    }
    return res;
}
