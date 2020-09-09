class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int index = 0;
        int negative_sum = 0;
        while (K > 0 && index < A.size() && A[index] < 0) {
            negative_sum += -A[index++];
            K--;
        }
        int not_negative_index = index;
        int not_negative_sum = 0;
        while (index < A.size()) {
            not_negative_sum += A[index++];
        }
        if (K <= 0 || K % 2 == 0) {
            return negative_sum + not_negative_sum;
        }
        int min_num = numeric_limits<int>::max();
        if (not_negative_index < A.size()) {
            min_num = A[not_negative_index];
        }
        if (not_negative_index - 1 >= 0) {
            min_num = min(min_num, -A[not_negative_index - 1]);
        }
        return negative_sum + not_negative_sum - 2 * min_num;
    }
};