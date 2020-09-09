/*
 * Regular Expression Matching
 *
 * Implement regular expression matching with support for '.' and '*'.
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 *
 */

#include <iostream>
#include <string>

bool isMatch(char* s, char* p) {
    if(*p == '\0')
        return *s == '\0';
    if(*(p + 1) != '*')
        return (*p == *s || *p == '.' && *s != '\0') && isMatch(s + 1, p + 1);
    else {
        while(*s != '\0' && (*p == '.' || *s == *p)) {
            if(isMatch(s, p + 2))
                return true;
            s += 1;
        }
        return isMatch(s, p + 2);
    }
}
