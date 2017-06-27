#include <iostream>
#include <vector>

using namespace std;

/*
 * Range Sum Query - Mutable
 *
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 *
 * The update(i, val) function modifies nums by updating the element at index i to val.
 * Example:
 * Given nums = [1, 3, 5]
 *
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * Note:
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is distributed evenly.
 *
 *
 */

struct Node {
    int val;
    int start;
    int end;
    Node* left;
    Node* right;
    Node(int x, int s, int e): val(x), start(s), end(e), left(NULL), right(NULL) {}
};

class NumArray {
private:
    Node* root;

    Node* create(vector<int>& nums, int start, int end) {
        if(nums.empty())
            return NULL;
        if(start == end)
            return new Node(nums[start], start, end);
        int mid = (start + end) / 2;
        Node* left = create(nums, start, mid);
        Node* right = create(nums, mid + 1, end);
        Node* cur = new Node(left->val + right->val, start, end);
        cur->left = left;
        cur->right = right;
        return cur;
    }

    void updateTree(Node* root, int i, int val, int old_val) {
        if(root == NULL)
            return;
        root->val += val - old_val;
        int mid = (root->start + root->end) / 2;
        if(i <= mid)
            updateTree(root->left, i, val, old_val);
        else
            updateTree(root->right, i, val, old_val);
    }

    int sum(int i, int j, Node* root) {
        int start = root->start;
        int end = root->end;
        int mid = (start + end) / 2;
        if(start == i && end == j)
            return root->val;
        if(mid >= i) {
            if(mid >= j)
                return sum(i, j, root->left);
            else
                return sum(i, mid, root->left) + sum(mid + 1, j, root->right);
        }
        else
            return sum(i, j, root->right);
    }

public:
	NumArray(vector<int> nums) {
        root = create(nums, 0, nums.size() - 1);
    }

    int sumRange(int i, int j) {
    	if(root == NULL)
    		return 0;
        return sum(i, j, root);
    }

    void update(int i, int val) {
        int old_val = sumRange(i, i);
        updateTree(root, i, val, old_val); 
    }
};

