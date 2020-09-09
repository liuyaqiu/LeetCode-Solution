class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) {
            return false;
        }
        bool is_increasing = true;
        for (int i = 0; i + 1 < A.size(); i++) {
            if (A[i] > A[i + 1]) {
                if (i == 0) {
                    return false;
                }
                is_increasing = false;
            } else if (A[i] < A[i + 1]) {
                if (!is_increasing) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return !is_increasing;
    }
};