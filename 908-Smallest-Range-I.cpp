class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        vector<pair<int, int>> intervals;
        for (int num : A) {
            intervals.push_back({num - K, num + K});
        }
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> selected_intervals;
        for (const auto& start_and_end : intervals) {
            if (selected_intervals.empty() || selected_intervals.back().second < start_and_end.first) {
                selected_intervals.push_back(start_and_end);
            } else {
                selected_intervals.back().first = start_and_end.first;
            }
        }
        if (selected_intervals.size() <= 1) {
            return 0;
        } else {
            return selected_intervals.back().first - selected_intervals.front().second;
        }
    }
};