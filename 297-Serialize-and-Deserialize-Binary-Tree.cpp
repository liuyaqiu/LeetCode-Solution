#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

/*
 * Serialize and Deserialize Binary Tree
 *
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
 *
 * For example, you may serialize the following tree
 *
 *     1
 *    / \
 *   2   3
 *      / \
 *     4   5
 * as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
 * Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 *
 *
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    vector<vector<TreeNode*>> levelOrder(TreeNode* root) {
        vector<vector<TreeNode*>> res;
        queue<TreeNode*> cur;
        queue<TreeNode*> next;
        cur.push(root);
        vector<TreeNode*> nodes;
        while(!cur.empty()) {
            TreeNode* top = cur.front();
            cur.pop();
            if(top != NULL) {
                next.push(top->left);
                next.push(top->right);
            }
            nodes.push_back(top);
            if(cur.empty()) {
                res.push_back(nodes);
                nodes.clear();
                cur = next;
                next = queue<TreeNode*>();
            }
        }
        return res;
    }

    string encode(vector<vector<TreeNode*>>& levels) {
        string res = "[";
        for(auto iter1 = levels.begin(); iter1 != levels.end() - 1; iter1++) {
            for(auto iter2 = iter1->begin(); iter2 != iter1->end(); iter2++) {
                if(*iter2 == NULL) {
                    res = res + "null,";
                }
                else {
                    string str;
                    stringstream ss;
                    ss << (*iter2)->val;
                    ss >> str;
                    res = res + str + ",";
                }
            }
        }
        res[res.length() - 1] = ']';
        return res;
    }

    queue<TreeNode*> decode(string str) {
        queue<TreeNode*> nodes;
        string s = str.substr(1, str.length() - 2);
        int pos = 0;
        int n = s.length();
        while(pos < n) {
            int start = pos;
            while(pos < n && s[pos] != ',')
                pos++;
            string cur = s.substr(start, pos - start);
            if(cur == "null")
                nodes.push(NULL);
            else {
                int val;
                stringstream ss;
                ss << cur;
                ss >> val;
                nodes.push(new TreeNode(val));
            }
            pos++;
        }
        return nodes;
    }

    TreeNode* construct(queue<TreeNode*>& nodes) {
        if(nodes.empty())
            return NULL;
        TreeNode* root = nodes.front();
        queue<TreeNode*> cur;
        cur.push(root);
        nodes.pop();
        while(!nodes.empty() && !cur.empty()) {
            TreeNode* top = cur.front();
            cur.pop();
            TreeNode* left = NULL;
            if(!nodes.empty()) {
                left = nodes.front();
                nodes.pop();
            }
            TreeNode* right = NULL;
            if(!nodes.empty()) {
                right = nodes.front();
                nodes.pop();
            }
            if(left != NULL) {
                top->left = left;
                cur.push(left);
            }
            if(right != NULL) {
                top->right = right;
                cur.push(right);
            }
        }
        return root;
    }

public:
    string serialize(TreeNode* root) {
        vector<vector<TreeNode*>> levels = levelOrder(root);
        return encode(levels);
    }

    TreeNode* deserialize(string data) {
        queue<TreeNode*> nodes = decode(data);
        return construct(nodes);
    }
};
