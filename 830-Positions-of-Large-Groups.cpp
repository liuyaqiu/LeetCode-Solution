class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int index = 0;
        while (index < S.length()) {
            int end_index = index;
            while (end_index < S.length() && S[end_index] == S[index]) {
                end_index++;
            }
            if (end_index - index >= 3) {
                res.push_back({index, end_index - 1});
            }
            index = end_index;
        }
        return res;
    }
};