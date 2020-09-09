/*
 * Pow(x, n)
 *
 * Implement pow(x, n).
 *
 *
 * Example 1:
 *
 * Input: 2.00000, 10
 * Output: 1024.00000
 * Example 2:
 *
 * Input: 2.10000, 3
 * Output: 9.26100
 *
 */

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

double myPow(double base, long int exp) {
    double res = 1;
    bool nega = exp < 0;
    if(nega)
    	exp = - exp;
    while(exp >= 2) {
        int val = exp % 2;
        exp = exp / 2;
        if(val == 1)
            res *= base;
        base = base * base;
    }
    if(exp == 1)
        res *= base;
    if(nega)
    	return 1 / res;
    else
    	return res;
}

int main() {
    double base;
    int exp;
    cout << "Please input the base and exp: ";
    cin >> base >> exp;
    double res = myPow(base, exp);
    cout << "The res is: " << res << endl;
    return 0;
}
