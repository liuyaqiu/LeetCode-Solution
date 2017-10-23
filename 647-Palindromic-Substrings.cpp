/*
  Palindromic Substrings

  Given a string, your task is to count how many palindromic substrings in this string.

  The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

  Example 1:
  Input: "abc"
  Output: 3
  Explanation: Three palindromic strings: "a", "b", "c".
  Example 2:
  Input: "aaa"
  Output: 6
  Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
  Note:
  The input string length won't exceed 1000.

 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int countSubstrings(string s) {
    int res = 0;
    for(int i = 0; i < s.length(); i++) {
        res += 1;
        //for odd palindrome
        if(i > 0 && i < s.length() - 1 && s[i - 1] == s[i + 1]) {
            int start = i - 1;
            int end = i + 1;
            while(start >= 0 && end < s.length() && s[start] == s[end]) {
                res += 1;
                start--;
                end++;
            }
        }
        //for even palindrome
        if(i < s.length() - 1 && s[i] == s[i + 1]) {
            int start = i;
            int end = i + 1;
            while(start >= 0 && end < s.length() && s[start] == s[end]) {
                res += 1;
                start--;
                end++;
            }
        }
    }
    return res;
}
