#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode* root) {
    queue<TreeLinkNode*> curlevel;
    queue<TreeLinkNode*> nextlevel;
    curlevel.push(root);
    while(!curlevel.empty()) {
        TreeLinkNode* cur = curlevel.front();
        curlevel.pop();
        if(!curlevel.empty()) {
            cur->next = curlevel.front();
        }
        if(cur->left != NULL)
            nextlevel.push(cur->left);
        if(cur->right != NULL)
            nextlevel.push(cur->right);
        if(curlevel.empty()) {
            curlevel = nextlevel;
            nextlevel = queue<TreeLinkNode*>();
        }
    }
}
