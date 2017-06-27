#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

/*
 * Decode StringDecode String
 *
 * Given an encoded string, return it's decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
 *
 * You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
 *
 * Examples:
 *
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 *
 *
 */

bool isNum(char c) {
    return c - '0' >= 0 && c - '0' <= 9;
}

vector<string> convert(string s) {
    vector<string> res;
    int pos = 0;
    int n = s.length();
    while(pos < n) {
        if(s[pos] == '[') {
            res.push_back("[");
            pos++;
        }
        else if(s[pos] == ']') {
            res.push_back("]");
            pos++;
        }
        else if(isNum(s[pos])) {
            int start = pos;
            while(isNum(s[pos]))
                pos++;
            string tmp = s.substr(start, pos - start);
            res.push_back(tmp);
        }
        else {
            int start = pos;
            while(s[pos] != '[' && s[pos] != ']' && !isNum(s[pos]))
                pos++;
            string tmp = s.substr(start, pos - start);
            res.push_back(tmp);
        }
    }
    return res;
}

string decodeString(string s) {
    vector<string> split = convert(s);
    int n = split.size();
    string res = "";
    int pos = 0;
    stack<string> opt;
    stack<string> strs;
    while(pos < n) {
        string cur = split[pos];
        if(isNum(cur[0])) {
            opt.push(cur);
        }
        else if(cur == "]") {
            string num = opt.top();
            int val;
            stringstream ss;
            ss << num;
            ss >> val;
            string tmp = "";
            string str = "";
            while(!strs.empty() && strs.top() != "[") {
                str = strs.top() + str;
                strs.pop();
            }
            strs.pop();
            for(int i = 0; i < val; i++)
                tmp += str;
            opt.pop();
            strs.push(tmp);
        }
        else if(cur == "[") {
        	strs.push(cur);
        }
        else {
            strs.push(cur);
        }
        pos++;
    }
    while(!strs.empty()) {
        res = strs.top() + res;
        strs.pop();
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    string res = decodeString(s);
    cout << res << endl;
    return 0;
}
