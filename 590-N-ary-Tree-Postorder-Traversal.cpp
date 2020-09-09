/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> res;
        for (Node* child : root->children) {
            for (int val : postorder(child)) {
                res.push_back(val);
            }
        }
        res.push_back(root->val);
        return res;
    }
};