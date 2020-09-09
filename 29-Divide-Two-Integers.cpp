/*
 * Divide Two Integers
 *
 * Divide two integers without using multiplication, division and mod operator.
 *
 * If it is overflow, return MAX_INT.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

long int MIN = -2147483648;
long int MAX = 2147483647;
int tmpRes(long int& dividend, long int divisor) {
    int res = 0;
    int base = 1;
    while(dividend >= divisor) {
        dividend -= divisor;
        res += base;
        base += base;
        divisor += divisor;
        if(divisor > MAX)
            break;
    }
    return res;
}

int divide(long int dividend, long int divisor) {
    long int res = 0;
    bool isPositive = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
    dividend = abs(dividend);
    divisor = abs(divisor);
    while(dividend >= divisor) {
        res += tmpRes(dividend, divisor);
    }
    if(!isPositive)
        res *= -1;
    if(res < MIN || res > MAX)
        return MAX;
    else
        return res;
}

int main() {
	int a, b;
	cin >> a >> b;
    int res = divide(a, b);
    cout << res << endl;
	return 0;
}
