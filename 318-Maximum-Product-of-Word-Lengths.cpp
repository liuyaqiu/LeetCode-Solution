#include <iostream>
#include <vector>

using namespace std;

/*
 * Maximum Product of Word Lengths
 *
 * Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
 *
 * Example 1:
 * Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 * Return 16
 * The two words can be "abcw", "xtfn".
 *
 * Example 2:
 * Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 * Return 4
 * The two words can be "ab", "cd".
 *
 * Example 3:
 * Given ["a", "aa", "aaa", "aaaa"]
 * Return 0
 * No such pair of words.
 *
 *
 */

int myHash(string s) {
    vector<int> pos(26, 0);
    for(int i = 0; i < s.length(); i++) {
        int k = s[i] - 'a';
        pos[k] += 1;
    }
    int res = 0;
    for(int i = 0; i < 26; i++) {
        if(pos[i] > 0)
            res += 1 << i;
    }
    return res;
}

int maxProduct(vector<string>& words) {
    vector<int> hashes;
    for(auto word: words)
        hashes.push_back(myHash(word));
    int n = words.size();
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int judge = hashes[i] & hashes[j];
            if(judge == 0) {
                int tmp = words[i].length() * words[j].length();
                if(tmp > res)
                    res = tmp;
            }
        }
    }
    return res;
}

int main() {
    string word;
    vector<string> words;
    while(cin >> word) {
        words.push_back(word);
    }
    int res = maxProduct(words);
    cout << res << endl;
    return 0;
}
