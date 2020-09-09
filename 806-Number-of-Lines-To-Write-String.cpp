class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lines = 0;
        int remained = 0;
        int i = 0;
        while (i < S.length()) {
            if (remained + widths[S[i] - 'a'] > 100) {
                lines++;
                remained = 0;
            } else {
                remained += widths[S[i] - 'a'];
                if (remained >= 100) {
                    lines++;
                    remained = 0;
                }
                i++;
            }
        }
        return {lines + 1, remained};
    }
};