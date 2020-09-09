class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int even_index = 0;
        int odd_index = A.size() - 1;
        int index = 0;
        while (index <= odd_index) {
            if (A[index] % 2 == 0) {
                swap(A[index], A[even_index++]);
                if (index < even_index) {
                    index++;
                }
            } else {
                swap(A[index], A[odd_index--]);
            }
        }
        return A;
    }
};