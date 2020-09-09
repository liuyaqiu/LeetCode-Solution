class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        int left_index = 0;
        int right_index = 0;
        while (left_index < A.size() && A[left_index] < 0) {
            left_index++;
        }
        right_index = left_index;
        left_index--;
        while (right_index < A.size() && A[right_index] == 0) {
            res.push_back(0);
            right_index++;
        }
        while (left_index >= 0 && right_index < A.size()) {
            int left_sqr = A[left_index] * A[left_index];
            int right_sqr = A[right_index] * A[right_index];
            if (left_sqr < right_sqr) {
                res.push_back(left_sqr);
                left_index--;
            } else {
                res.push_back(right_sqr);
                right_index++;
            }
        }
        while (left_index >= 0) {
            res.push_back(A[left_index] * A[left_index]);
            left_index--;
        }
        while (right_index < A.size()) {
            res.push_back(A[right_index] * A[right_index]);
            right_index++;
        }
        return res;
    }
};