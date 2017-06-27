#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

/*
 * Mini Parser
 *
 * Given a nested list of integers represented as a string, implement a parser to deserialize it.
 *
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 *
 * Note: You may assume that the string is well-formed:
 *
 * String is non-empty.
 * String does not contain white spaces.
 * String contains only digits 0-9, [, - ,, ].
 * Example 1:
 *
 * Given s = "324",
 *
 * You should return a NestedInteger object which contains a single integer 324.
 * Example 2:
 *
 * Given s = "[123,[456,[789]]]",
 *
 * Return a NestedInteger object containing a nested list with 2 elements:
 *
 * 1. An integer containing value 123.
 * 2. A nested list containing two elements:
 *     i.  An integer containing value 456.
 *     ii. A nested list with one element:
 *          a. An integer containing value 789.
 *
 *
 */

class NestedInteger {
    public:
        NestedInteger();

        NestedInteger(int value);

        bool isInteger() const;

        int getInteger() const;

        void setInteger(int value);

        void add(const NestedInteger& ni);

        const vector<NestedInteger>& getList() const;
};

bool isDigit(char c) {
    return c == '-' || (c - '0' >= 0 && c - '0' <= 9);
} 

class Solution {
public:
    NestedInteger deserialize(string s) {
    	NestedInteger res;
    	if(isDigit(s[0])) {
            int num;
    	    stringstream ss;
            ss << s;
            ss >> num;
            res.setInteger(num);
            return res;
    	}
        int n = s.length();
        int pos = 0;
        stack<NestedInteger> stk;
        while(pos < n) {
            if(s[pos] == '[') {
                NestedInteger cur;
                stk.push(cur);
                pos++;
            }
            else if(s[pos] == ','){
                pos++;
            }
            else if(isDigit(s[pos])) {
                int start = pos;
                while(pos < n && isDigit(s[pos]))
                    pos++;
                if(pos != start) {
                    string str = s.substr(start, pos - start);
                    int num;
                    stringstream ss;
                    ss << str;
                    ss >> num;
                    NestedInteger tmp(num);
                    stk.top().add(tmp);
                }
            }
            else {
                NestedInteger cur = stk.top();
                stk.pop();
                if(stk.empty()) {
                	res = cur;
                	break;
                }
                stk.top().add(cur);
                pos++;
            }
        }
        return res;
    }
};
