class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int x_upper = x > 1 ? ceil(log2(bound) / log2(x)) : 0;
        int y_upper = y > 1 ? ceil(log2(bound) / log2(y)) : 0;
        unordered_set<int> res;
        for (int i = 0; i <= x_upper; i++) {
            for (int j = 0; j <= y_upper; j++) {
                int cur = pow(x, i) + pow(y, j);
                if (cur <= bound) {
                    res.insert(cur);
                } else {
                    break;
                }
            }
        }
        vector<int> nums;
        for (const int num : res) {
            nums.push_back(num);
        }
        return nums;
    }
};