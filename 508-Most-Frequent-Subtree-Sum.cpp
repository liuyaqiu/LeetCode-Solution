#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int lastOrder(TreeNode* root, unordered_map<int, int>& res) {
    int sum = root->val;
    if(root->left != NULL)
        sum += lastOrder(root->left, res);
    if(root->right != NULL)
        sum += lastOrder(root->right, res);
    if(res.find(sum) == res.end())
        res[sum] = 1;
    else
        res[sum] += 1;
    return sum;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    if(root == NULL)
        return {};
    unordered_map<int, int> res;
    lastOrder(root, res);
    vector<int> ans;
    for(auto item: res) {
        if(ans.empty())
            ans.push_back(item.first);
        else {
            if(item.second > res[ans.back()]) {
                ans = {item.first};
            }
            else if(item.second == res[ans.back()])
                ans.push_back(item.first);
        }
    }
    return ans;
}
