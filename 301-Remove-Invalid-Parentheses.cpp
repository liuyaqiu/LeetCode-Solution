#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

/*
 * Remove Invalid Parentheses
 *
 * Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
 *
 * Note: The input string may contain letters other than the parentheses ( and ).
 *
 * Examples:
 * "()())()" -> ["()()()", "(())()"]
 * "(a)())()" -> ["(a)()()", "(a())()"]
 * ")(" -> [""]
 * ")"
 *
 *
 */

void print(vector<string>& res) {
    for(auto s: res)
        cout << s << " ";
    cout << endl;
}

void recursion(string str, int i, string cur, int cnt, unordered_set<string>& res) {
    if(cnt == 0) {
        if(i >= str.length()) {
            if(res.empty())
                res.insert(cur);
            else {
                int m = cur.length(), n = res.begin()->length();
                if(m > n) {
                    res.clear();
                    res.insert(cur);
                }
                else if(m == n)
                    res.insert(cur);
            }
            return;
        }
        char c = str[i];
        if(c == ')')
            recursion(str, i + 1, cur, cnt, res);
        else if(c == '(') {
            recursion(str, i + 1, cur, cnt, res);
            cnt++;
            recursion(str, i + 1, cur + c, cnt, res);
        }
        else
            recursion(str, i + 1, cur + c, cnt, res);
    }
    else {
        if(i >= str.length())
            return;
        char c = str[i];
        if(c == ')') {
            recursion(str, i + 1, cur, cnt, res);
            cnt--;
            recursion(str, i + 1, cur + c, cnt, res);
        }
        else if(c == '(') {
            recursion(str, i + 1, cur, cnt, res);
            cnt++;
            recursion(str, i + 1, cur + c, cnt, res);
        }
        else
            recursion(str, i + 1, cur + c, cnt, res);
    }
}

vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> res;
    res.insert("");
    recursion(s, 0, "", 0, res);
    vector<string> result;
    for(auto s: res)
        result.push_back(s);
    return result;
}

int main() {
    string s;
    cin >> s;
    cout << s << endl;
    vector<string> res = removeInvalidParentheses(s);
    print(res);
    return 0;
}
