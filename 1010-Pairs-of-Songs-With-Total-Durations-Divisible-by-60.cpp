class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> time_to_count(60, 0);
        for (int t : time) {
            t = t % 60;
            time_to_count[t] += 1;
        }
        int res = 0;
        for (int t = 0; t <= 30; t++) {
            int cnt = time_to_count[t];
            if (cnt == 0) {
                continue;
            }
            if (t % 60 == 0 || t % 30 == 0) {
                res += cnt * (cnt - 1) / 2;
            } else {
                res += cnt * time_to_count[60 - t];
            }
        }
        return res;
    }
};