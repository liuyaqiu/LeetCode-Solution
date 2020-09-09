class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum_A = 0;
        for (int num : A) {
            sum_A += num;
        }
        int sum_B = 0;
        for (int num : B) {
            sum_B += num;
        }
        int delta = sum_A - sum_B;
        if (delta % 2 != 0) {
            return {};
        }
        unordered_set<int> A_nums;
        for (int num : A) {
            A_nums.insert(num);
        }
        for (int b : B) {
            int a = delta / 2 + b;
            if (A_nums.count(a)) {
                return {a, b};
            }
        }
        return {};
    }
};