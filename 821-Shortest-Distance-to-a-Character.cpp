class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> C_index;
        for (int i = 0 ;i < S.length(); i++) {
            if (S[i] == C) {
                C_index.push_back(i);
            }
        }
        int j = -1;
        int left_bound = -1;
        int right_bound = C_index[0];
        vector<int> res;
        for (int i = 0; i < S.length(); i++) {
            if (j + 1 < C_index.size() && i >= C_index[j + 1]) {
                j++;
                left_bound = C_index[j];
                if (j + 1 < C_index.size()) {
                    right_bound = C_index[j + 1];
                } else {
                    right_bound = -1;
                }
            }
            int count = numeric_limits<int>::max();
            if (left_bound >= 0) {
                count = min(count, i - left_bound);
            }
            if (right_bound >= 0) {
                count = min(count, right_bound - i);
            }
            res.push_back(count);
        }
        return res;
    }
};