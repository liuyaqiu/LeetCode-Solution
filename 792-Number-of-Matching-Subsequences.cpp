class Solution {
public:
    bool isSubsequence(string S, string word) {
        int s_index = 0;
        int w_index = 0;
        while (w_index < word.length()) {
            while (s_index < S.length() && S[s_index] != word[w_index]) {
                ++s_index;
            }
            if (s_index >= S.length()) {
                break;
            }
            ++s_index;
            ++w_index;
        }
        return w_index >= word.length();
    }

    int numMatchingSubseq(string S, vector<string>& words) {
        int res = 0;
        unordered_map<string, int> word_map;
        for (const string word : words) {
            if (!word_map.count(word)) {
                word_map[word] = 0;
            }
            word_map[word] += 1;
        }
        for (const auto& word_cnt : word_map) {
            if (isSubsequence(S, word_cnt.first)) {
                res += word_cnt.second;
            }
        }
        return res;
    }
};