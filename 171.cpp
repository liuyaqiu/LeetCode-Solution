#include <iostream>
#include <vector>

using namespace std;

int titleToNumber(string s) {
    int base = 1;
    int n = s.length();
    int res = 0;
    for(int i = 0; i < n; i++) {
        char c = s[n - 1 - i];
        int tmp = (c - 'A' + 1) * base;
        base *= 26;
        res += tmp;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    int res = titleToNumber(s);
    cout << res << endl;
    return 0;
}
