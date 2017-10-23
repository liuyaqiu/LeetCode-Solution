/*
  Valid Parenthesis String

  Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

  Any left parenthesis '(' must have a corresponding right parenthesis ')'.
  Any right parenthesis ')' must have a corresponding left parenthesis '('.
  Left parenthesis '(' must go before the corresponding right parenthesis ')'.
  '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
  An empty string is also valid.

 */

#include <iostream>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

bool checkValidString(string s) {
    list<char> cnt;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(')
            cnt.push_back('(');
        else if(s[i] == ')') {
            if(cnt.empty())
                return false;
            auto iter = cnt.rbegin();
            while(iter != cnt.rend() && *iter != '(')
                iter++;
            if(iter == cnt.rend())
                cnt.erase(cnt.begin());
            else {
                advance(iter, 1);
                cnt.erase(iter.base());
            }
        }
        else
            cnt.push_back('*');
    }
    int star = 0;
    auto iter = cnt.rbegin();
    while(iter != cnt.rend()) {
        if(*iter == '*')
            star++;
        else {
            star--;
            if(star < 0)
                return false;
        }
        iter++;
    }
    return true;
}
