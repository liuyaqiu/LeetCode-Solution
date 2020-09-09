/*
 * Valid Parentheses
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int isPa(char a) {
    string pa = "()[]{}";
    for(int i = 0; i < pa.length(); i += 1) {
        if(a == pa[i])
            return i % 2;
    }
    return -1;
}

bool match(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'); 
}

bool isValid(string s) {
    vector<char> pa;
    for(int i = 0; i < s.length(); i += 1) {
        switch(isPa(s[i])) {
            case 0:
                pa.push_back(s[i]);
                break;
            case 1:
                if(!pa.empty() && match(pa.back(), s[i]))
                    pa.pop_back();
                else
                    return false;
            default:
            	break;
        }
    }
    return pa.empty();
}

int main() {
    string s1 = "(a + [c / d] * {x - y})";
    string s2 = "(a{b)";
    cout << s2;
    if(isValid(s2))
        cout << " is valid" << endl;
    else 
        cout << " is not valid" << endl;
    return 0;
}
