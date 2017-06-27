#include <iostream>
#include <vector>
#include <string>

using namespace std;

string complexNumberMultiply(string a, string b) {
    int pos_a = a.find_first_of('+');
    int m = stoi(a.substr(0, pos_a));
    int p = stoi(a.substr(pos_a + 1, a.length() - 1 - (pos_a + 1)));
    int pos_b = a.find_first_of('+');
    int n = stoi(b.substr(0, pos_b));
    int q = stoi(b.substr(pos_b + 1, b.length() - 1 - (pos_b + 1)));
    int x = m * n - p * q;
    int y = p * n + q * m;
    return to_string(x) + "+" + to_string(y) + "i";
}
