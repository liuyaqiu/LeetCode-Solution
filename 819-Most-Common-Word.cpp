bool is_lower(char c) {
    return c - 'a' >= 0 && c - 'a' < 26;
}

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> word_counts;
        int pos = 0;
        while (pos < paragraph.size()) {
            int next_pos = paragraph.find_first_of("!?',;. ", pos);
            if (next_pos == -1) {
                next_pos = paragraph.size();
            }
            string word = paragraph.substr(pos, next_pos - pos);
            for (int i = 0; i < word.length(); i++) {
                if (!is_lower(word[i])) {
                    word[i] = word[i] - 'A' + 'a';
                }
            }
            if (!word.empty()) {
                if (word_counts.find(word) == word_counts.end()) {
                    word_counts[word] = 0;
                }
                word_counts[word] += 1;
            }
            pos = next_pos + 1;
        }
        unordered_set<string> banned_words;
        for (string banned_word : banned) {
            banned_words.insert(banned_word);
        }
        string res = "";
        int cnt = 0;
        for (const auto& word_and_count : word_counts) {
            string word = word_and_count.first;
            int count = word_and_count.second;
            if (banned_words.find(word) == banned_words.end() && word_and_count.second > cnt) {
                res = word;
                cnt = count;
            }
        }
        return res;
    }
};