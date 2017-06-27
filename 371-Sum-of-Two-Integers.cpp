#include <iostream>
#include <vector>

using namespace std;

/*
 * Sum of Two Integers
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 *
 * Example:
 * Given a = 1 and b = 2, return 3.
 *
 *
 */

int getSum(int a, int b) {
    while(b != 0) {
        int tmp_a = a ^ b;
        int tmp_b = (a & b) << 1;
        a = tmp_a;
        b = tmp_b;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    int res = getSum(a, b);
    cout << res << endl;
    return 0;
}
