class Solution {
public:
    pair<string, vector<int>> squeeze(string S) {
        string res;
        vector<int> count;
        for (int i = 0; i < S.length(); i++) {
            if (res.empty() || S[i] != res.back()) {
                res += S[i];
                count.push_back(1);
            } else {
                count.back() += 1;
            }
        }
        return {res, count};
    }

    int expressiveWords(string S, vector<string>& words) {
        pair<string, vector<int>> char_and_count = squeeze(S);
        vector<string> word_chars;
        vector<vector<int>> word_count;
        for (const string& word : words) {
            auto cur = squeeze(word);
            word_chars.push_back(cur.first);
            word_count.push_back(cur.second);
        }
        int res = 0;
        for (int k = 0; k < word_chars.size(); k++) {
            string word = word_chars[k];
            if (char_and_count.first == word) {
                bool has_result = true;
                for (int i = 0; i < word.size(); i++) {
                    if (char_and_count.second[i] < word_count[k][i]) {
                        has_result = false;
                        break;
                    } else if (char_and_count.second[i] > word_count[k][i]) {
                        if (char_and_count.second[i] < 3) {
                            has_result = false;
                        }
                    }
                }
                if (has_result) {
                    ++res;
                }
            }
        }
        return res;
    }
};