#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

bool isDigit(char c) {
    return c - '0' >= 0 && c - '0' < 10;
}

int calculate(string s) {
    stack<int> num;
    stack<char> op;
    int tmp;
    int pos = 0;
    int cur = 0;
    while(pos < s.length()) {
        while(s[pos] == ' ')
            pos++;
        if(pos >= s.length())
        	break;
        if(!isDigit(s[pos])) {
            op.push(s[pos]);
            pos++;
        }
        else {
            cur = pos;
            while(pos < s.length() && isDigit(s[pos]))
                pos++;
            stringstream ss;
            ss << s.substr(cur, pos - cur);
            ss >> tmp;
            if(op.empty())
            	num.push(tmp);
            else {
	            char c = op.top();
	            if(c == '*') {
	                num.top() *= tmp;
	                op.pop();
	            }
                else if(c == '/') {
                    num.top() /= tmp;
                    op.pop();
                }
	            else
	                num.push(tmp);
            }
        }
    }
    int res = 0;
    while(!op.empty()) {
        char c = op.top();
        int top = num.top();
        num.pop();
        if(c == '+')
            res += top;
        else if(c == '-')
            res -= top;
        op.pop();
    }
    res += num.top();
    return res;
}

int main() {
    string s = "1 - 1 + 1   ";
    int res = calculate(s);
    cout << res << endl;
    return 0;
}
