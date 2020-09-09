class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if (N == 1 && trust.empty()) {
            return 1;
        }
        unordered_map<int, int> trust_count;
        unordered_set<int> reverse_trust;
        for (const auto& the_trust : trust) {
            if (!trust_count.count(the_trust[1])) {
                trust_count[the_trust[1]] = 0;
            }
            trust_count[the_trust[1]] += 1;
            reverse_trust.insert(the_trust[0]);
        }
        for (const auto& num_and_count : trust_count) {
            if (num_and_count.second == N - 1 && !reverse_trust.count(num_and_count.first)) {
                return num_and_count.first;
            }
        }
        return -1;
    }
};