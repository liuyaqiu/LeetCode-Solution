#include <iostream>
#include <vector>

using namespace std;

int magicalString(int n) {
    string str = "122";
    int pos = 2;
    while(str.length() < n) {
        char c = str[str.length() - 1];
        str += string(str[pos] - '0', (3 - (c - '0')) + '0');
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == '1')
            res += 1;
    }
    cout << str << endl;
    return res;
}

int main() {
    int n;
    cin >> n;
    int res = magicalString(n);
    cout << res << endl;
    return 0;
}
