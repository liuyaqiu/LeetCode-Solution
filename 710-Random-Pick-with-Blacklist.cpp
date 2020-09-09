class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        N_ = N;
        for (int val : blacklist) {
            blacklist_.insert(val);
        }
        if (blacklist_.size() * 100 >= N) {
            for (int i = 0; i < N; i++) {
                if (blacklist_.find(i) == blacklist_.end()) {
                    candidates_.push_back(i);
                }
            }
            dis_can_ = std::uniform_int_distribution<int>(0, candidates_.size() - 1);
        } else {
            dis_full_ = std::uniform_int_distribution<int>(0, N - 1);
        }
    }

    int pick() {
        if (!candidates_.empty()) {
            int index = dis_can_(gen_);
            return candidates_[index];
        } else {
            int val = dis_full_(gen_);
            while (blacklist_.find(val) != blacklist_.end()) {
                val = dis_full_(gen_);
            }
            return val;
        }
    }

private:
    vector<int> candidates_;
    unordered_set<int> blacklist_;
    int N_;
    std::default_random_engine gen_;
    std::uniform_int_distribution<int> dis_can_;
    std::uniform_int_distribution<int> dis_full_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */