class Solution {
public:
    bool isValid(const vector<int>& digits) {
        int hour = digits[0] * 10 + digits[1];
        int minute = digits[2] * 10 + digits[3];
        return hour >= 0 && hour < 24 && minute >= 0 && minute < 60;
    }

    bool compare(const vector<int>& lhs, const vector<int>& rhs) {
        if (lhs.size() != rhs.size()) {
            return lhs.size() < rhs.size();
        }
        for (int i = 0; i < lhs.size(); i++) {
            if (lhs[i] != rhs[i]) {
                return lhs[i] < rhs[i];
            }
        }
        return false;
    }

    string convert(const vector<int>& digits) {
        if (digits.empty()) {
            return "";
        }
        return to_string(digits[0]) + to_string(digits[1]) + ":" + to_string(digits[2]) + to_string(digits[3]);
    }

    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> res;
        do {
            if (!isValid(arr)) {
                continue;
            }
            if (res.empty() || compare(res, arr)) {
                res = arr;
            }
        } while (next_permutation(arr.begin(), arr.end()));
        return convert(res);
    }
};