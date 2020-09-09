bool is_vowel(char c) {
    if (c - 'a' < 0 || c - 'a' >= 26) {
        c = c - 'A' + 'a';
    }
    for (char v : {'a', 'e', 'i', 'o', 'u'}) {
        if (c == v) {
            return true;
        }
    }
    return false;
}

class Solution {
public:
    string toGoatLatin(string S) {
        string res = "";
        int pos = 0;
        int index = 0;
        while (pos < S.length()) {
            int next_pos = S.find(' ', pos);
            if (next_pos == -1) {
                next_pos = S.length();
            }
            string cur = S.substr(pos, next_pos - pos);
            pos = next_pos + 1;
            if (cur.empty()) {
                continue;
            }
            if (!is_vowel(cur[0])) {
                cur = cur.substr(1, cur.length() - 1) + cur[0];
            }
            cur += "ma";
            for (int i = 0; i < index + 1; i++) {
                cur += 'a';
            }
            res += cur;
            if (next_pos < S.length()) {
                res += " ";
            }
            index += 1;
        }
        return res;
    }
};