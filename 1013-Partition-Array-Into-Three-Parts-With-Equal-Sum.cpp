class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (int num : A) {
            sum += num;
        }
        if (sum % 3 != 0) {
            return false;
        }
        int target = sum / 3;
        int head_sum = 0;
        int head_index = -1;
        for (int i = 0; i < A.size(); i++) {
            head_sum += A[i];
            if (head_sum == target) {
                head_index = i;
                break;
            }
        }
        int tail_sum = 0;
        int tail_index = -1;
        for (int i = A.size() - 1; i >= 0; i--) {
            tail_sum += A[i];
            if (tail_sum == target) {
                tail_index = i;
                break;
            }
        }
        return head_index != -1 && tail_index != -1 && head_index + 1 < tail_index;
    }
};