class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> selected;
        for (int i = 0; i < indexes.size(); i++) {
            bool is_select = true;
            for (int j = 0; j < sources[i].length(); j++) {
                if (S[indexes[i] + j] != sources[i][j]) {
                    is_select = false;
                    break;
                }
            }
            if (is_select) {
                selected.push_back({indexes[i], i});
            }
        }
        sort(selected.begin(), selected.end());
        int prev_index = 0;
        string res;
        for (int i = 0; i < selected.size(); i++) {
            int length = sources[selected[i].second].length();
            if (selected[i].first > prev_index) {
                res += S.substr(prev_index, selected[i].first - prev_index);
            }
            prev_index = selected[i].first + length;
            res += targets[selected[i].second];
        }
        if (prev_index < S.length()) {
            res += S.substr(prev_index, S.length() - prev_index);
        }
        return res;
    }
};