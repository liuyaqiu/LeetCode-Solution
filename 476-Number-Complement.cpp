#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findComplement(int num) {
    int cnt = ceil(log2(num));
    return (~num) & ((1 << cnt) - 1);
}

int main() {
    int num;
    cin >> num;
    int res = findComplement(num);
    cout << res << endl;
    return 0;
}
