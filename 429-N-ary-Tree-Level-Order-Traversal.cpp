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
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {
            return {};
        }
        std::queue<Node*> current_level;
        std::queue<Node*> next_level;
        current_level.push(root);
        vector<vector<int>> values;
        values.push_back({});
        while (!current_level.empty()) {
            Node* cur = current_level.front();
            values.back().push_back(cur->val);
            current_level.pop();
            for (Node* child : cur->children) {
                next_level.push(child);
            }
            if (current_level.empty()) {
                if (!next_level.empty()) {
                    current_level = next_level;
                    next_level = {};
                    values.push_back({});
                }
            }
        }
        return values;
    }
};