class Solution {
public:
    bool compare(const string& lhs, const string& rhs, const unordered_map<char, int>& char_to_order) {
        int i = 0;
        for (;i < min(lhs.size(), rhs.size()); i++) {
            if (lhs[i] != rhs[i]) {
                return char_to_order.at(lhs[i]) < char_to_order.at(rhs[i]);
            }
        }
        return i >= lhs.length();
    }

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> char_to_order;
        for (int i = 0; i < order.length(); i++) {
            char_to_order[order[i]] = i;
        }
        for (int i = 0; i + 1 < words.size(); i++) {
            if (!compare(words[i], words[i + 1], char_to_order)) {
                return false;
            }
        }
        return true;
    }
};