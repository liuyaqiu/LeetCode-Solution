/*
  Longest Word in Dictionary

  Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

  If there is no answer, return the empty string.
  Example 1:
  Input: 
  words = ["w","wo","wor","worl", "world"]
  Output: "world"
  Explanation: 
  The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
  Example 2:
  Input: 
  words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
  Output: "apple"
  Explanation: 
  Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
  Note:

  All the strings in the input will only contain lowercase letters.
  The length of words will be in the range [1, 1000].
  The length of words[i] will be in the range [1, 30].

 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

string longestWord(vector<string>& words) {
    unordered_set<string> dict;
    for(auto word: words)
        dict.insert(word);
    vector<string> res;
    for(auto word: words) {
        bool judge = true;
        for(int i = 1; i < word.length(); i++) {
            string prefix = word.substr(0, i);
            if(dict.find(prefix) == dict.end()) {
                judge = false;
                break;
            }
        }
        if(judge) {
            if(res.empty())
                res.push_back(word);
            else {
                if(word.length() > res.back().length()) {
                    res.clear();
                    res.push_back(word);
                }
                else if(word.length() == res.back().length())
                    res.push_back(word);
            }
        }
    }
    sort(res.begin(), res.end());
    if(res.empty())
        return "";
    else
        return res.front();
}
