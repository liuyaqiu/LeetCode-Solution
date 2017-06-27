#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int findGap(int n, int p, int q) {
    int gap = 0;
    while(p <= n) {
        gap += min(n + 1, q) - p;
        p *= 10;
        q *= 10;
    }
    return gap;
}

int findKthNumber(int n, int k) {
    int res = 1;
    k -= 1;
    while(k > 0) {
        int gap = findGap(n, res, res + 1);
        if(gap <= k) {
            res += 1;
            k -= gap;
        }
        else {
            res *= 10;
            k -= 1;
        }
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    int res = findKthNumber(n, k);
    cout << res << endl;
    return 0;
}
