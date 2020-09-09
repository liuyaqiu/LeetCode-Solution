class Solution {
public:
    string morseCode(string word) {
        vector<string> dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string res;
        for (int i = 0; i < word.length(); i++) {
            res += dict[word[i] - 'a'];
        }
        return res;
    }

    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> res;
        for (string word : words) {
            res.insert(morseCode(word));
        }
        return res.size();
    }
};