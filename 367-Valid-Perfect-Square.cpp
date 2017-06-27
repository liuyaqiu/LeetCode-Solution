#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * Valid Perfect Square
 *
 * Given a positive integer num, write a function which returns True if num is a perfect square else False.
 *
 * Note: Do not use any built-in library function such as sqrt.
 *
 * Example 1:
 *
 * Input: 16
 * Returns: True
 * Example 2:
 *
 * Input: 14
 * Returns: False
 *
 *
 */

bool isPerfectSquare(int num) {
    double delta = 0.0001;
    double x0 = num;
    double x1 = (x0 + num / x0) / 2.0;
    while(abs(x0 - x1) > delta) {
        cout << x0 << " " << x1 << endl;
        x0 = x1;
        x1 = (x0 + num / x0) / 2.0;
    }
    int t = floor(x0);
    return t * t == num;
}

int main() {
    int num;
    cin >> num;
    bool res = isPerfectSquare(num);
    cout << res << endl;
    return 0;
}
