class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) {
            return 0;
        }
        if (K > pow(2.0, N - 2)) {
            return 1 - kthGrammar(N, K - pow(2.0, N - 2));
        }
        return kthGrammar(N - 1, K);
    }
};