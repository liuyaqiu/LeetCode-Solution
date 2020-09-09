class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for (int i = A.size() - 1; i >= 2; i--) {
            int a = A[i];
            int b = A[i - 1];
            int c = A[i - 2];
            if (c > a - b) {
                return a + b + c;
            }
        }
        return 0;
    }
};