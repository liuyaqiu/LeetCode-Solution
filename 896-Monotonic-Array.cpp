class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() <= 1) {
            return true;
        }
        bool increasing = false;
        bool decreasing = false;
        for (int i = 0; i < A.size() - 1; i++) {
            if (A[i] < A[i + 1]) {
                increasing = true;
            }
            if (A[i] > A[i + 1]) {
                decreasing = true;
            }
        }
        return (increasing && decreasing) ? false : true;
    }
};