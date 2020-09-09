class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == A[(i + 1) % A.size()]) {
                return A[i];
            }
            if (A[i] == A[(i + 2) % A.size()]) {
                return A[i];
            }
        }
        return -1;
    }
};