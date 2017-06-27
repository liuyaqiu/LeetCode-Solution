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
        if(!isDigit(s[pos])) {
            if(s[pos] == ')') {
                op.pop();
                if(!op.empty()) {
                	char c = op.top();
                	if(c != '(') {
                		op.pop();
                		int cur = num.top();
	                	num.pop();
		                if(c == '+')
		                    num.top() += cur;
		                else if(c == '-')
		                    num.top() -= cur;
                	}
                }
            }
            else
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
	            if(c == '+') {
	                num.top() += tmp;
	                op.pop();
	            }
	            else if(c == '-') {
	                num.top() -= tmp;
	                op.pop();
	            }
	            else
	                num.push(tmp);
            }
        }
    }
    return num.top();
}

int main() {
    string s = "(((1) + 2 - (3 - 4)))";
    int res = calculate(s);
    cout << res << endl;
    return 0;
}
