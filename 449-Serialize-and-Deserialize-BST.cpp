#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* construct(vector<int>& data) {
    if(data.empty())
        return NULL;
    int val = data.front();
    auto iter = data.begin() + 1;
    while(iter != data.end() && *iter < val)
        iter++;
    vector<int> left(data.begin() + 1, iter);
    vector<int> right(iter, data.end());
    TreeNode* root = new TreeNode(val);
    TreeNode* lnode = construct(left);
    TreeNode* rnode = construct(right);
    root->left = lnode;
    root->right = rnode;
    return root;
}

void deconstruct(TreeNode* root, vector<int>& res) {
    if(root == NULL)
        return;
    res.push_back(root->val);
    deconstruct(root->left, res);
    deconstruct(root->right, res);
}

string vecToStr(vector<int>& data) {
    string res = "";
    for(auto item: data) {
        res = res + to_string(item) + " ";
    }
    return res;
}

vector<int> strToVec(string str) {
    int start = 0;
    int n= str.length();
    vector<int> res;
    while(start < n) {
        int end = str.find_first_of(' ', start);
        string cur = str.substr(start, end - start);
        res.push_back(stoi(cur));
        start = end + 1;
    }
    return res;
}

string serialize(TreeNode* root) {
    vector<int> data;
    deconstruct(root, data);
    string res = vecToStr(data);
    return res;
}

TreeNode* deserialize(string data) {
    vector<int> vec = strToVec(data);
    TreeNode* root = construct(vec);
    return root;
}

int main() {
    string s;
    s = "2 1 3 ";
    TreeNode* root = deserialize(s);
    cout << root->val << endl;
    return 0;
}
