class Solution {
public:
    vector<string> get_string(string candidate) {
        if (candidate.empty()) {
            return {};
        }
        if (candidate == "0") {
            return {candidate};
        }
        if (candidate[0] == '0') {
            int index = 0;
            while (index < candidate.size() && candidate[index] == '0') {
                index += 1;
            }
            if (index == candidate.size()) {
                return {};
            } else {
                if (candidate.back() == '0') {
                    return {};
                } else {
                    return {"0." + candidate.substr(1, candidate.size() - 1)};
                }
            }
        }
        if (candidate.back() == '0') {
            return {candidate};
        }
        vector<string> res = {candidate};
        for (int i = 1; i < candidate.size(); i++) {
            res.push_back(candidate.substr(0, i) + "."  + candidate.substr(i, candidate.size() - i));
        }
        return res;
    }
    vector<string> ambiguousCoordinates(string S) {
        S = S.substr(1, S.size() - 2);
        vector<string> res;
        for (int i = 1; i < S.size(); i++) {
            vector<string> x_c = get_string(S.substr(0, i));
            vector<string> y_c = get_string(S.substr(i, S.size() - i));
            for (const string& x : x_c) {
                for (const string& y : y_c) {
                    res.push_back("(" + x + ", " + y + ")");
                }
            }
        }
        return res;
    }
};