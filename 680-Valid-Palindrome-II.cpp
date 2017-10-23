/*
  Valid Palindrome II

  Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

  Example 1:
  Input: "aba"
  Output: True
  Example 2:
  Input: "abca"
  Output: True
  Explanation: You could delete the character 'c'.
  Note:
  The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool valid(const string& s, int start, int end, int del) {
    int left = start, right = end;
    while(left < right) {
        if(s[left] == s[right]) {
            left++;
            right--;
        }
        else {
            if(del <= 0)
                return false;
            else
                return valid(s, left + 1, right, del - 1) || valid(s, left, right - 1, del - 1);
        }
    }
    return true;
}

bool validPalindrome(string s) {
    return valid(s, 0, s.length() - 1, 1);
}
