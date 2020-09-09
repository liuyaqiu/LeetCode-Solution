class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> profit_and_diff;
        for (int i = 0; i < profit.size(); i++) {
            profit_and_diff.push_back({profit[i], difficulty[i]});
        }
        sort(profit_and_diff.begin(), profit_and_diff.end());
        map<int, int> diff_to_profit;
        for (int i = profit_and_diff.size() - 1; i >= 0; i--) {
            int diff = profit_and_diff[i].second;
            int prof = profit_and_diff[i].first;
            if (diff_to_profit.find(diff) == diff_to_profit.end()) {
                auto iter = diff_to_profit.upper_bound(diff);
                if (iter != diff_to_profit.begin()) {
                    iter--;
                    if (iter != diff_to_profit.end() && iter->second >= prof) {
                        continue;
                    }
                }
                diff_to_profit[diff] = prof;
            }
        }
        int res = 0;
        for (const int worker_diff : worker) {
            auto iter = diff_to_profit.upper_bound(worker_diff);
            if (iter == diff_to_profit.begin()) {
                continue;
            }
            if (iter != diff_to_profit.begin()) {
                iter--;
            }
            res += iter->second;
        }
        return res;
    }
};