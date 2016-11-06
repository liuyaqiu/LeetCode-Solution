#include <iostream>
#include <string>
#include <vector>

using namespace std;

string nextStr(string s) {
    int i = 0;
    int cnt = 1;
    string res;
    while(i < s.length() - 1) {
        if(s[i] == s[i + 1]) {
            cnt += 1;
        }
        else {
            res.push_back('0' + cnt);
            res.push_back(s[i]);
            cnt = 1;
        }
        i += 1;
    }
    res.push_back('0' + cnt);
    res.push_back(s[s.length() - 1]);
    return res;
}

int main() {
    int n;
    cin >> n;
    string s = "1";
    cout << s << endl;
    while(n > 0) {
        s = nextStr(s);
        cout << s << endl;
        n -= 1;
    }
    return 0;
}
