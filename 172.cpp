#include <iostream>
#include <vector>

using namespace std;

int trailingZeroes(int n) {
    long base = 5;
    long res = 0;
    while(base <= n) {
        res += n / base;
        base *= 5;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int res = trailingZeroes(n);
    cout << res << endl;
    return 0;
}
