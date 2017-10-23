/*
  Solve the Equation

  Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

  If there is no solution for the equation, return "No solution".

  If there are infinite solutions for the equation, return "Infinite solutions".

  If there is exactly one solution for the equation, we ensure that the value of x is an integer.

  Example 1:
  Input: "x+5-3+x=6+x-2"
  Output: "x=2"
  Example 2:
  Input: "x=x"
  Output: "Infinite solutions"
  Example 3:
  Input: "2x=x"
  Output: "x=0"
  Example 4:
  Input: "2x+3x-6x=x+2"
  Output: "x=-1"
  Example 5:
  Input: "x=x+2"
  Output: "No solution"

 */

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;
typedef pair<int, int> mypair;

mypair resolve(string expr) {
    if(expr[0] != '-')
        expr = '+' + expr;
    mypair res(0, 0);
    int pos = 0;
    while(pos < expr.size()) {
        int prev = pos;
        pos = expr.find_first_of("+-", pos + 1);
        if(pos == -1)
            pos = expr.length();
        string tmp = expr.substr(prev + 1, pos - prev - 1);
        int k = 1;
        if(expr[prev] == '-')
            k = -1;
        if(tmp[tmp.size() - 1] == 'x') {
            if(tmp == "x")
                res.first += k;
            else
                res.first += k * stoi(tmp.substr(0, tmp.length() - 1));
        }
        else {
            res.second += k * stoi(tmp);
        }
    }
    return res;
}

string solveEquation(string equation) {
    int p = equation.find('=', 0);
    mypair left = resolve(equation.substr(0, p));
    mypair right = resolve(equation.substr(p + 1, equation.length() - 1));
    int a = left.first - right.first;
    int b = right.second - left.second;
    if(a == 0) {
        if(b == 0)
            return "Infinite solutions";
        else
            return "No solution";
    }
    else
        return "x=" + to_string(b / a);
}
