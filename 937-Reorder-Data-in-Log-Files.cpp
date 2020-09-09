bool isDigit(char c) {
    return c - '0' >= 0 && c - '0' < 10;
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter_logs;
        vector<string> digit_logs;
        for (const auto& log : logs) {
            int index = log.find_first_of(' ');
            if (!isDigit(log[index + 1])) {
                letter_logs.push_back(log);
            } else {
                digit_logs.push_back(log);
            }
        }
        sort(letter_logs.begin(), letter_logs.end(), [](const string& lhs, const string& rhs) {
            int lhs_index = lhs.find_first_of(' ');
            int rhs_index = rhs.find_first_of(' ');
            return lhs.substr(lhs_index, lhs.length() - lhs_index) <= rhs.substr(rhs_index, rhs.length() - rhs_index);
        });
        copy(digit_logs.begin(), digit_logs.end(), back_inserter(letter_logs));
        return letter_logs;
    }
};