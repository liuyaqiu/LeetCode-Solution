class Solution {
public:
    vector<int> diStringMatch(string S) {
        int N = S.length();
        int lo = 0, hi = N;
        vector<int> res(N + 1, 0);
        for (int i = 0; i < N; i++) {
            if (S[i] == 'I') {
                res[i] = lo++;
            } else {
                res[i] = hi--;
            }
        }
        res[N] = lo;
        return res;
    }
};