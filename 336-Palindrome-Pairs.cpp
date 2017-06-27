#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * Palindrome Pairs
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
 *
 * Example 1:
 * Given words = ["bat", "tab", "cat"]
 * Return [[0, 1], [1, 0]]
 * The palindromes are ["battab", "tabbat"]
 * Example 2:
 * Given words = ["abcd", "dcba", "lls", "s", "sssll"]
 * Return [[0, 1], [1, 0], [3, 2], [2, 4]]
 * The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
 *
 *
 */

bool isPalindrome(string word) {
    int low = 0, high = word.length() - 1;
    while(low < high) {
        if(word[low] != word[high])
            return false;
        low++;
        high--;
    }
    return true;
}

string reverse(string word) {
    string res = word;
    int low = 0, high = word.length() - 1;
    while(low < high)
        swap(res[low++], res[high--]);
    return res;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    unordered_map<string, int> refer;
    for(int i = 0; i < words.size(); i++)
        refer[words[i]] = i;
    vector<vector<int>> res;
    for(int i = 0; i < words.size(); i++) {
        string word = words[i];
        if(isPalindrome(word)) {
            if(word != "" && refer.find("") != refer.end()) {
                res.push_back({i, refer[""]});
                res.push_back({refer[""], i});
            }
        }
        string reversed = reverse(word);
        if(reversed != word && refer.find(reversed) != refer.end())
            res.push_back({i, refer[reversed]});
        for(int j = 1; j < word.length(); j++) {
            string left = word.substr(0, j);
            string right = word.substr(j, word.length() - j);
            if(isPalindrome(left)) {
                string reversedRight = reverse(right); 
                if(refer.find(reversedRight) != refer.end())
                    res.push_back({refer[reversedRight], i});
            }
            if(isPalindrome(right)) {
                string reversedLeft = reverse(left);
                if(refer.find(reversedLeft) != refer.end())
                    res.push_back({i, refer[reversedLeft]});
            }
        }
    }
    return res;
}
