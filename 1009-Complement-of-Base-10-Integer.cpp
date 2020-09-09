class Solution {
public:
    int bitwiseComplement(int N) {
        if (N < 2) {
            return 1 - N;
        }
        int n = floor(log2(N));
        return pow(2,n + 1) - 1 - N;
    }
};