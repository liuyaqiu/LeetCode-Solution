bool isChar(char c) {
    return (c - 'a' >= 0 && c - 'a' < 26) || (c - 'A' >= 0 && c - 'A' < 26);
}

class Solution {
public:
    string reverseOnlyLetters(string S) {
        string not_letter;
        for (int i = 0; i < S.length(); i++) {
            if (isChar(S[i])) {
                not_letter += S[i];
            }
        }
        int index = not_letter.length() - 1;
        for (int i = 0; i < S.length(); i++) {
            if (isChar(S[i])) {
                S[i] = not_letter[index--];
            }
        }
        return S;
    }
};