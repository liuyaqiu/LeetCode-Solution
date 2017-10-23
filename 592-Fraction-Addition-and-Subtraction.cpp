/*
  Fraction Addition and Subtraction

  Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.

  Example 1:
  Input:"-1/2+1/2"
  Output: "0/1"

  Example 2:
  Input:"-1/2+1/2+1/3"
  Output: "1/3"

  Example 3:
  Input:"1/3-1/2"
  Output: "-1/6"

  Example 4:
  Input:"5/3+1/3"
  Output: "2/1"

Note:
  The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
  Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
  The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
  The number of given fractions will be in the range [1,10].
  The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.

 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> mypair;

int gcd(int x, int y) {
    if(x < y)
        swap(x, y);
    if(y == 0)
        return x;
    int r = x % y;
    while(r != 0) {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

mypair add(mypair a, mypair b) {
    int p = a.first * b.second + a.second * b.first;
    int q = a.second * b.second;
    int r = gcd(p, q);
    p = p / r;
    q = q / r;
    if(q < 0) {
        p *= -1;
        q *= -1;
    }
    return mypair(p, q);
}

mypair extract(string& exp) {
    bool neg = false;
    int pos = 0;
    if(exp[pos] == '-') {
        neg = true;
        pos += 1;
    }
    else if(exp[pos] == '+')
        pos += 1;
    int end = exp.find('/', pos);
    int x = stoi(exp.substr(pos, end - pos));
    if(x == 0)
        return mypair(0, 1);
    if(neg)
        x *= -1;
    pos = end + 1;
    end = min(exp.find('+', pos), exp.find('-', pos));
    if(end == -1)
        end = exp.length();
    int y = stoi(exp.substr(pos, end - pos));
    exp = exp.substr(end, exp.length() - end);
    int r = gcd(x, y);
    return mypair(x / r, y / r);
}

string fractionAddition(string expression) {
    mypair sum(0, 1);
    while(!expression.empty()) {
        mypair frac = extract(expression);
        sum = add(sum, frac);
    }
    return to_string(sum.first) + "/" + to_string(sum.second);
}

int main() {
    string exp;
    cin >> exp;
    string res = fractionAddition(exp);
    cout << res << endl;
    return 0;
}
