#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int rangeBitwiseAnd(int m, int n) {
	int k = ceil(log2(n - m + 1));
    m = m >> k;
    n = n >> k;
    return (m & n) << k;
}

int main() {
    int m, n;
    cin >> m >> n;
    int res = rangeBitwiseAnd(m, n);
    cout << res << endl;
    return 0;
}
