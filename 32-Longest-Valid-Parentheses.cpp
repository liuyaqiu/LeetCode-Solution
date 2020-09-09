/*
 * Longest Valid Parentheses
 *
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
	if(s.empty())
		return 0;
	stack<char> stk;
    stack<int> pos;
    for(int i = 0; i < s.length(); i += 1) {
        if(stk.empty()) {
            stk.push(s[i]);
            pos.push(i);
        }
        else {
            if(s[i] == ')' && stk.top() == '(') {
                stk.pop();
                pos.pop();
            }
            else {
                stk.push(s[i]);
                pos.push(i);
            }
        }
    }
    int max;
    if(!pos.empty())
		max = s.length() - pos.top();
	else
		max = s.length() - 1;
    while(!pos.empty()) {
        int cur = pos.top();
        pos.pop();
        int pre;
        if(pos.empty())
            pre = -1;
        else
            pre = pos.top();
        if(max < cur - pre)
            max = cur - pre;
    }
    return max;
}

int main() {
    string s = "(()";
    int res = longestValidParentheses(s);
    cout << res << endl;
    return 0;
}
