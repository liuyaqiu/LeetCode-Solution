class Solution {
public:
    void splitSentence(string A, unordered_map<string, int>& words) {
        int index = 0;
        while (index < A.length()) {
            while (index < A.length() && A[index] == ' ') {
                index++;
            }
            if (index >= A.length()) {
                break;
            }
            int next_index = A.find_first_of(' ', index);
            if (next_index == -1) {
                next_index = A.length();
            }
            string word = A.substr(index, next_index - index);
            if (!words.count(word)) {
                words[word] = 0;
            }
            words[word] += 1;
            index = next_index + 1;
        }
    }

    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> words;
        splitSentence(A, words);
        splitSentence(B, words);
        vector<string> res;
        for (const auto& word_and_count : words) {
            if (word_and_count.second == 1) {
                res.push_back(word_and_count.first);
            }
        }
        return res;
    }
};