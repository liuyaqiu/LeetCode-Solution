class Solution {
public:
    int binaryGap(int N) {
        int prev_index = -1;
        int res = 0;
        int index = 0;
        while (N != 0) {
            if (N & 1 != 0) {
                if (prev_index >= 0) {
                    res = max(res, index - prev_index);
                }
                prev_index = index;
            }
            N = N >> 1;
            index++;
        }
        return res;
    }
};