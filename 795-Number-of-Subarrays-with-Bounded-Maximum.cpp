class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        vector<int> sign(A.size(), 0);
        for (int i = 0; i < A.size(); i++) {
            if (A[i] < L) {
                sign[i] = -1;
            } else if (A[i] > R) {
                sign[i] = 1;
            } else {
                sign[i] = 0;
            }
        }
        vector<int> next_plus_index(A.size(), 0);
        int index = 0;
        while (index < A.size()) {
            int cur = index;
            while (index < A.size() && sign[index] != 1) {
                ++index;
            }
            for (int k = cur; k < index; k++) {
                next_plus_index[k] = index;
            }
            ++index;
        }
        index = 0;
        vector<int> next_zero_index(A.size(), 0);
        while (index < A.size()) {
            int cur = index;
            while (index < A.size() && sign[index] != 0) {
                ++index;
            }
            for (int k = cur; k < index; k++) {
                next_zero_index[k] = index;
            }
            ++index;
       }
        vector<int> count(A.size(), 0);
        for (int i = 0; i < A.size(); i++) {
            if (sign[i] == 0) {
                count[i] = next_plus_index[i] - i;
            }
        }
        for (int i = 0; i < A.size(); i++) {
            if (sign[i] == -1) {
                int next_zero = next_zero_index[i];
                int next_plus = next_plus_index[i];
                if (next_zero < next_plus) {
                    count[i] = count[next_zero];
                }
            }
        }
        int res = 0;
        for (int i = 0; i < count.size(); i++) {
            res += count[i];
        }
        return res;
    }
};