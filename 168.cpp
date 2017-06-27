#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string convertToTitle(int n) {
    string res = "";
    while(n > 0) {
        int cur;
        if(n % 26 == 0)
            cur = 26;
        else
            cur = n % 26;
        char c = 'A' + (cur - 1);
        res = c + res;
        n -= cur;
        n /= 26;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    string res = convertToTitle(n);
    cout << res << endl;
    return 0;
}
