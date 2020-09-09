bool is_upper(char c) {
    return c - 'A' >= 0 && c - 'A' < 26;
}

char to_lower(char c) {
    if (is_upper(c)) {
        c = c - 'A' + 'a';
    }
    return c;
}

bool is_digit(char c) {
    return c - '0' >= 0 && c - '0' < 10;
}

class Solution {
public:
    string maskPII(string S) {
        int pos = S.find_first_of('@');
        string res;
        if (pos != -1) {
            res += to_lower(S[0]);
            for (int i = 0; i < 5; i++) {
                res += '*';
            }
            res += to_lower(S[pos - 1]);
            for (int i = pos; i < S.length(); i++) {
                res += to_lower(S[i]);
            }
        } else {
            string cleaned;
            for (int i = 0; i < S.length(); i++) {
                if (is_digit(S[i])) {
                    cleaned += S[i];
                }
            }
            cout << cleaned << endl;
            if (cleaned.length() > 10) {
                res += '+';
                for (int i = 0; i < cleaned.length() - 10; i++) {
                    res += '*';
                }
                res += '-';
            }
            res += "***-***-" + cleaned.substr(cleaned.length() - 4, 4);
        }
        return res;
    }
};