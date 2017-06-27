#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

string convert(vector<long>& digit, long pos) {
    string res = "";
    for(long i = 0; i < digit.size(); i++) {
        stringstream ss;
        ss << digit[i];
        string cur;
        ss >> cur;
        if(i == 0)
            res = res + cur + ".";
        else if(i == pos + 1)
            res = res + "(" + cur;
        else
            res = res + cur;
    }
    if(pos >= 0)
        res += ")";
    return res;
}

string fractionToDecimal(long numerator, long denominator) {
    if(numerator % denominator == 0) {
        stringstream ss;
        string r;
        ss << numerator / denominator;
        ss >> r;
        return r;
    }
    bool minus = (numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0);
    numerator = abs(numerator);
    denominator = abs(denominator);
    vector<long> digit;
    map<long, long> pos;
    long cur = numerator / denominator;
    long next = (numerator % denominator) * 10;
    digit.push_back(cur);
    while(next != 0 && pos.find(next) == pos.end()) {
        pos[next] = digit.size() - 1;
        cur = next / denominator;
        next = (next % denominator) * 10;
        digit.push_back(cur);
    }
    long k = -1;
    if(next != 0)
        k = pos[next];
    string res = convert(digit, k);
    if(minus)
        return "-" + res;
    else
        return res;
}

int main() {
    long a, b;
    cin >> a >> b;
    string res = fractionToDecimal(a, b);
    cout << res << endl;
    return 0;
}
