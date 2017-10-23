/*
  Maximum Binary Tree

  Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

  The root is the maximum number in the array.
  The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
  The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
  Construct the maximum tree by the given array and output the root node of this tree.

 */

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define inf numeric_limits<int>::min()

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* construct(vector<int>& nums, int left, int right) {
    if(left > right)
        return NULL;
    int pos = left;
    for(int i = left; i <= right; i++) {
        if(nums[i] > nums[pos])
            pos = i;
    }
    TreeNode* cur = new TreeNode(nums[pos]);
    cur->left = construct(nums, left, pos - 1);
    cur->right = construct(nums, pos + 1, right);
    return cur;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return construct(nums, 0, nums.size() - 1);
}
