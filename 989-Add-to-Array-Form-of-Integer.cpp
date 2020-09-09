class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        if (K == 0) {
            return A;
        }
        vector<int> K_digit;
        while (K > 0) {
            K_digit.push_back(K % 10);
            K /= 10;
        }
        reverse(K_digit.begin(), K_digit.end());
        if (A.size() < K_digit.size()) {
            swap(A, K_digit);
        }
        vector<int> res;
        int prev = 0;
        for (int i = 0; i < A.size(); i++) {
            int cur = A[A.size() - 1 - i] + prev;
            if (i < K_digit.size()) {
                cur += K_digit[K_digit.size() - 1 - i];
            }
            res.push_back(cur % 10);
            prev = cur / 10;
        }
        if (prev != 0) {
            res.push_back(prev);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};