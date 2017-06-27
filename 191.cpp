#include <iostream>
#include <vector>

using namespace std;

int hammingWeight(uint32_t n) {
    int res = 0;
    while(n > 0) {
        res += (n & 1);
        n >>= 1;
    }
    return res;
}

int main() {
    int val;
    int hw;
    while(cin >> val) {
        hw = hammingWeight(val);
        cout << hw << endl;
    }
    return 0;
}
