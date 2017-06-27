#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Longest Palindrome
 *
 * Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
 *
 * This is case sensitive, for example "Aa" is not considered a palindrome here.
 *
 * Note:
 * Assume the length of given string will not exceed 1,010.
 *
 * Example:
 *
 * Input:
 * "abccccdd"
 *
 * Output:
 * 7
 *
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 *
 *
 */

int getPos(char c) {
    int pos = c - 'a';
    if(pos >= 0 && pos < 26)
        return pos;
    else
        return (c - 'A') + 26;
}

int longestPalindrome(string s) {
    vector<int> cnt(52, 0);
    for(int i = 0; i < s.length(); i++)
        cnt[getPos(s[i])] += 1;
    int res = 0;
    int odd = 0;
    for(int i = 0; i < cnt.size(); i++) {
        if(cnt[i] % 2 == 0)
            res += cnt[i];
        else {
            res += cnt[i] - 1;
            odd += 1;
        }
    }
    if(odd == 0)
        return res;
    else
        return res + 1;
}

int main() {
    string s;
    cin >> s;
    int res = longestPalindrome(s);
    cout << res << endl;
    return 0;
}
