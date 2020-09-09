class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int even_index = 0;
        int odd_index = 1;
        int index = 0;
        while (index < A.size()) {
            if (A[index] % 2 == 0) {
                if (index > even_index - 2) {
                    swap(A[index], A[even_index]);
                    even_index += 2;
                } else {
                    index++;
                }
            } else {
                if (index > odd_index - 2) {
                    swap(A[index], A[odd_index]);
                    odd_index += 2;
                } else {
                    index++;
                }
            }
        }
        return A;
    }
};