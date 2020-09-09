string convert(string S) {
    string res;
    int index = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '#') {
            if (index > 0) {
                index--;
            }
        } else {
            if (index >= res.length()) {
                res += S[i];
            } else {
                res[index] = S[i];
            }
            index++;
        }
    }
    return res.substr(0, index);
}

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return convert(S) == convert(T);
    }
};