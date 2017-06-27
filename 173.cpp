#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    private:
        stack<TreeNode*> visit;
        void insert(TreeNode* root) {
            if(root == NULL)
                return;
            visit.push(root);
            TreeNode* p = root->left;
            while(p != NULL) {
                visit.push(p);
                p = p->left;
            }
        }

    public:
        BSTIterator(TreeNode* root) {
            insert(root);
        }

        bool hasNext() {
            return !visit.empty();
        }

        int next() {
            if(visit.empty()) {
                return -1;
            }
            TreeNode* top = visit.top();
            visit.pop();
            insert(top->right);
            return top->val;
        }
};

