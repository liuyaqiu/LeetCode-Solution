/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid, int row, int col, int size) {
        int top_left_ones = 0;
        int top_right_ones = 0;
        int bottom_left_ones = 0;
        int bottom_right_ones = 0;
        int half_size = size / 2;
        int subsqr_size = half_size * half_size;
        for (int i = row; i < row + size; i++) {
            for (int j = col; j < col + size; j++) {
                if (grid[i][j] == 1) {
                    if (i < row + half_size) {
                        if (j < col + half_size) {
                            top_left_ones += 1;
                        } else {
                            top_right_ones += 1;
                        }
                    } else {
                        if (j < col + half_size) {
                            bottom_left_ones += 1;
                        } else {
                            bottom_right_ones += 1;
                        }
                    }
                }
            }
        }
        int all_ones = top_left_ones + top_right_ones + bottom_left_ones + bottom_right_ones;
        Node* cur = new Node();
        if (all_ones == 0) {
            cur->val = false;
            cur->isLeaf = true;
            return cur;
        } else if(all_ones == size * size) {
            cur->val = true;
            cur->isLeaf = true;
            return cur;
        }
        Node* top_left = new Node();
        if (top_left_ones == 0) {
            top_left->val = false;
            top_left->isLeaf = true;
        } else if(top_left_ones == subsqr_size) {
            top_left->val = true;
            top_left->isLeaf = true;
        } else {
            top_left = construct(grid, row, col, half_size);
        }
        cur->topLeft = top_left;
        Node* top_right = new Node();
        if (top_right_ones == 0) {
            top_right->val = false;
            top_right->isLeaf = true;
        } else if (top_right_ones == subsqr_size) {
            top_right->val = true;
            top_right->isLeaf = true;
        } else {
            top_right = construct(grid, row, col + half_size, half_size);
        }
        cur->topRight = top_right;
        Node* bottom_left = new Node();
        if (bottom_left_ones == 0) {
            bottom_left->val = false;
            bottom_left->isLeaf = true;
        } else if(bottom_left_ones == subsqr_size) {
            bottom_left->val = true;
            bottom_left->isLeaf = true;
        } else {
            bottom_left = construct(grid, row + half_size, col, half_size);
        }
        cur->bottomLeft = bottom_left;
        Node* bottom_right = new Node();
        if (bottom_right_ones = 0) {
            bottom_right->val = false;
            bottom_right->isLeaf = true;
        } else if(bottom_right_ones == subsqr_size) {
            bottom_right->val = true;
            bottom_right->isLeaf = true;
        } else {
            bottom_right = construct(grid, row + half_size, col + half_size, half_size);
        }
        cur->bottomRight = bottom_right;
        return cur;
    }
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size());
    }
};