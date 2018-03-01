/*
  Basic Calculator IV

  Given an expression such as expression = "e + 8 - a + 5" and an evaluation map such as {"e": 1} (given in terms of evalvars = ["e"] and evalints = [1]), return a list of tokens representing the simplified expression, such as ["-1*a","14"]

  An expression alternates chunks and symbols, with a space separating each chunk and symbol.
  A chunk is either an expression in parentheses, a variable, or a non-negative integer.
  A variable is a string of lowercase letters (not including digits.) Note that variables can be multiple letters, and note that variables never have a leading coefficient or unary operator like "2x" or "-x".
  Expressions are evaluated in the usual order: brackets first, then multiplication, then addition and subtraction. For example, expression = "1 + 2 * 3" has an answer of ["7"].

  The format of the output is as follows:

  For each term of free variables with non-zero coefficient, we write the free variables within a term in sorted order lexicographically. For example, we would never write a term like "b*a*c", only "a*b*c".
  Terms have degree equal to the number of free variables being multiplied, counting multiplicity. (For example, "a*a*b*c" has degree 4.) We write the largest degree terms of our answer first, breaking ties by lexicographic order ignoring the leading coefficient of the term.
  The leading coefficient of the term is placed directly to the left with an asterisk separating it from the variables (if they exist.)  A leading coefficient of 1 is still printed.
  An example of a well formatted answer is ["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"] 
  Terms (including constant terms) with coefficient 0 are not included.  For example, an expression of "0" has an output of [].
  Examples:

  Input: expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
  Output: ["-1*a","14"]

  Input: expression = "e - 8 + temperature - pressure",
  evalvars = ["e", "temperature"], evalints = [1, 12]
  Output: ["-1*pressure","5"]

  Input: expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
  Output: ["1*e*e","-64"]

  Input: expression = "7 - 7", evalvars = [], evalints = []
  Output: []

  Input: expression = "a * b * c + b * a * c * 4", evalvars = [], evalints = []
  Output: ["5*a*b*c"]

  Input: expression = "((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c - a))",
  evalvars = [], evalints = []
  Output: ["-1*a*a*b*b","2*a*a*b*c","-1*a*a*c*c","1*a*b*b*b","-1*a*b*b*c","-1*a*b*c*c","1*a*c*c*c","-1*b*b*b*c","2*b*b*c*c","-1*b*c*c*c","2*a*a*b","-2*a*a*c","-2*a*b*b","2*a*c*c","1*b*b*b","-1*b*b*c","1*b*c*c","-1*c*c*c","-1*a*a","1*a*b","1*a*c","-1*b*c"]
  Note:

  expression will have length in range [1, 250].
  evalvars, evalints will have equal lengths in range [0, 100].

 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>

using namespace std;

int count(string s) {
    int cnt = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '*')
            cnt += 1;
    }
    return cnt;
}

struct comp {
    bool operator() (const string& lhs, const string& rhs) const {
        int cnt1 = count(lhs), cnt2 = count(rhs);
        if(cnt1 != cnt2)
            return cnt1 > cnt2;
        else
            return lhs < rhs;
    }
};

string sortVar(string expr) {
    vector<string> vars;
    int pos = 0;
    while(pos < expr.length()) {
        int start = pos;
        pos = expr.find("*", pos);
        if(pos == -1)
            pos = expr.length();
        vars.push_back(expr.substr(start, pos - start));
        pos += 1;
    }
    sort(vars.begin(), vars.end());
    string res = "";
    for(auto item: vars)
        res = res + item + "*";
    return res.substr(0, res.length() - 1);
}

void eval(stack<unordered_map<string, int>>& res, string op) {
    auto top = res.top();
    res.pop();
    auto cur = res.top();
    res.pop();
    unordered_map<string, int> tmp;
    if(op == "*") {
        for(auto item1: top) {
            for(auto item2: cur) {
                if(item1.first != "0val") {
                    if(item2.first != "0val") {
                        string var = item1.first + "*" + item2.first;
                        var = sortVar(var);
                        int coef = item1.second * item2.second;
                        if(tmp.find(var) == tmp.end())
                            tmp[var] = coef;
                        else
                            tmp[var] += coef;
                        if(tmp[var] == 0)
                            tmp.erase(var);
                    }
                    else {
                        string var = item1.first;
                        int coef = item1.second * item2.second;
                        if(tmp.find(var) == tmp.end())
                            tmp[var] = coef;
                        else
                            tmp[var] += coef;
                        if(tmp[var] == 0)
                            tmp.erase(var);
                    }
                }
                else {
                    if(item2.first != "0val") {
                        string var = item2.first;
                        int coef = item1.second * item2.second;
                        if(tmp.find(var) == tmp.end())
                            tmp[var] = coef;
                        else
                            tmp[var] += coef;
                        if(tmp[var] == 0)
                            tmp.erase(var);
                    }
                    else {
                        string var = "0val";
                        int coef = item1.second * item2.second;
                        if(tmp.find(var) == tmp.end())
                            tmp[var] = coef;
                        else
                            tmp[var] += coef;
                        if(tmp[var] == 0)
                            tmp.erase(var);
                    }
                }
            }
        }
    }
    else if(op == "+") {
        for(auto item: cur)
            tmp[item.first] = item.second;
        for(auto item: top) {
            if(tmp.find(item.first) == tmp.end())
                tmp[item.first] = item.second;
            else
                tmp[item.first] += item.second;
            if(tmp[item.first] == 0)
                tmp.erase(item.first);
        }
    }
    else if(op == "-") {
        for(auto item: cur) {
            tmp[item.first] = item.second;
        }
        for(auto item: top) {
            if(tmp.find(item.first) == tmp.end())
                tmp[item.first] = -item.second;
            else
                tmp[item.first] -= item.second;
            if(tmp[item.first] == 0)
                tmp.erase(item.first);
        }
    }
    res.push(tmp);
}

string replace(string expression, unordered_map<string, int>& refer) {
    string res = "";
    int pos = 0;
    while(pos < expression.length()) {
        int start = pos;
        char c = expression[pos];
        if(c == ' ' || c == '(' || c == ')' || c == '+' || c == '-' || c == '*') {
            res = res + c;
            pos += 1;
        }
        else {
            int pos1 = expression.find(" ", pos);
            int pos2 = expression.find(")", pos);
            if(pos1 == -1)
                pos1 = expression.length();
            if(pos2 == -1)
                pos2 = expression.length();
            pos = min(pos1, pos2);
            string cur = expression.substr(start, pos - start);
            if(refer.find(cur) != refer.end())
                res = res + to_string(refer[cur]);
            else
                res = res + cur;
        }
    }
    return res;
}

vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
    unordered_map<string, int> refer;
    for(int i = 0; i < evalvars.size(); i++) {
        refer[evalvars[i]] = evalints[i];
    }
    expression = replace(expression, refer);
    stack<unordered_map<string, int>> res;
    stack<string> ops;
    int pos = 0;
    while(pos < expression.length()) {
        int start = pos;
        if(expression[pos] == '(') {
            ops.push("(");
            pos += 1;
        }
        else if(expression[pos] == ' ') {
            pos += 1;
        }
        else if(expression[pos] == ')') {
            //先计算完括号内的值
            while(!ops.empty() && ops.top() != "(") {
                string op = ops.top();
                ops.pop();
                eval(res, op);
            }
            if(!ops.empty())
                ops.pop();
            //归并括号外的乘法
            if(!ops.empty() && ops.top() == "*") {
                string op = ops.top();
                ops.pop();
                eval(res, op);
            }
            pos += 1;
        }
        else if(expression[pos] == '+' && pos < expression.length() - 1 && expression[pos + 1] == ' ') {
            //当前加法入栈，则计算已有的加法和减法。这保证了不会出现连续的加法和减法，从而防止出现a - b + c 变成a - (b + c)，计算(a - b) + c
            if(!ops.empty() && ops.top() != "(") {
                string op = ops.top();
                ops.pop();
                eval(res, op);
            }
            ops.push("+");
            pos += 2;
        }
        else if(expression[pos] == '-' && pos < expression.length() - 1 && expression[pos + 1] == ' ') {
            //当前减法入栈，则先计算已有的加法和减法，保证计算顺序
            if(!ops.empty() && ops.top() != "(") {
                string op = ops.top();
                ops.pop();
                eval(res, op);
            }
            ops.push("-");
            pos += 2;
        }
        else if(expression[pos] == '*' && pos < expression.length() - 1 && expression[pos + 1] == ' ') {
            //乘法算符前也是乘法算符，则直接计算前面的乘法算符
            if(!ops.empty() && ops.top() == "*") {
                string op = ops.top();
                ops.pop();
                eval(res, op);
            }
            ops.push("*");
            pos += 2;
        }
        else {
            int pos1 = expression.find(" ", pos);
            int pos2 = expression.find(")", pos);
            if(pos1 == -1)
                pos1 = expression.length();
            if(pos2 == -1)
                pos2 = expression.length();
            pos = min(pos1, pos2);
            string cur = expression.substr(start, pos - start);
            unordered_map<string, int> temp;
            if(cur[0] == '-' || cur[0] - '0' >= 0 && cur[0] - '0' < 10)
                temp["0val"] = stoi(cur);
            else
                temp[cur] = 1;
            res.push(temp);
            //当前进入的数的前一个操作符如果是乘法，则执行乘法运算。
            if(!ops.empty() && ops.top() == "*") {
                string op = ops.top();
                ops.pop();
                eval(res, op);
            }
        }
    }
    while(!ops.empty()) {
        string op = ops.top();
        ops.pop();
        eval(res, op);
    }
    map<string, int, comp> ans;
    for(auto item: res.top()) {
        ans[item.first] = item.second;
    }
    vector<string> result;
    for(auto item: ans) {
        if(item.first != "0val")
            result.push_back(to_string(item.second) + "*" + item.first);
    }
    if(ans.find("0val") != ans.end() && ans["0val"] != 0)
        result.push_back(to_string(ans["0val"]));
    return result;
}
