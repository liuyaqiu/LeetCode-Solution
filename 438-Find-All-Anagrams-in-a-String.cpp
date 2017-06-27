#include <iostream>
#include <vector>

using namespace std;

/*
 * Find All Anagrams in a String
 *
 * Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 *
 * Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 *
 * The order of output does not matter.
 *
 * Example 1:
 *
 * Input:
 * s: "cbaebabacd" p: "abc"
 *
 * Output:
 * [0, 6]
 *
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * Example 2:
 *
 * Input:
 * s: "abab" p: "ab"
 *
 * Output:
 * [0, 1, 2]
 *
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 */

bool isAnagrams(string a, vector<int>& cnt) {
    vector<int> tmp(26, 0);
    for(int i = 0; i < a.length(); i++)
        tmp[a[i] - 'a'] += 1;
    for(int i = 0; i < 26; i++) {
        if(tmp[i] != cnt[i])
            return false;
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    vector<int> cnt(26, 0);
    int k = p.length();
    for(int i = 0; i < k; i++)
        cnt[p[i] - 'a'] += 1;
    int n = s.length();
    for(int i = 0; i < n - k; i++) {
        if(isAnagrams(s.substr(i, k), cnt))
            res.push_back(i);
    }
    return res;
}
