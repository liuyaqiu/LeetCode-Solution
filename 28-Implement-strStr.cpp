/*
 * Implement strStr
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 * Example 1:
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * Example 2:
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int strStr(string haystak, string needle) {
    if(haystak.empty()) {
        if(needle.empty())
            return 0;
        else
            return -1;
    }
    int i = 0;
    int pos = haystak.length() - needle.length();
    while(i < pos) {
        if(haystak.substr(i, needle.length()) == needle)
            return i;
        i += 1;
    }
    return -1;
}
