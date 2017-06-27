#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

int evalRPN(vector<string> tokens) {
    stack<int> stk;
    for(auto iter = tokens.begin(); iter != tokens.end(); iter++) {
        if(*iter == "*") {
            int top = stk.top();
            stk.pop();
            stk.top() *= top;
        }
        else if(*iter == "/") {
            int top = stk.top();
            stk.pop();
            stk.top() /= top;
        }
        else if(*iter == "+") {
            int top = stk.top();
            stk.pop();
            stk.top() += top;
        }
        else if(*iter == "-") {
            int top = stk.top();
            stk.pop();
            stk.top() -= top;
        }
        else {
            istringstream iss(*iter);
            int val;
            iss >> val;
            stk.push(val);
        }
    }
    return stk.top();
}

int main() {
    string op;
    vector<string> tokens;
    while(cin >> op) {
        tokens.push_back(op);
    }
    int res = evalRPN(tokens);
    cout << res << endl;
    return 0;
}
