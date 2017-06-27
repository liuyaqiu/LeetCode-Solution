#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

/*
 * Convert a Number to Hexadecimal
 *
 * Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.
 *
 * Note:
 *
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed integer.
 * You must not use any method provided by the library which converts/formats the number to hex directly.
 * Example 1:
 *
 * Input:
 * 26
 *
 * Output:
 * "1a"
 * Example 2:
 *
 * Input:
 * -1
 *
 *  Output:
 *  "ffffffff"
 *
 *
 */

#define inf 0xffffffff

long getCode(int n) {
    if(n >= 0)
        return n;
    else
        return inf - abs(n) + 1;
}

char getDigit(int n) {
    if(n < 10)
        return '0' + n;
    else
        return 'a' + (n - 10);
}

string toHex(int m) {
    string res = "";
    long n = getCode(m);
    if(n == 0)
    	return "0";
    while(n >= 16) {
        res = getDigit(n & 0x0f) + res; 
        n >>= 4;
    }
    if(n > 0)
        res = getDigit(n) + res;
    return res;
}

int main() {
    int n;
    cin >> n;
    string res = toHex(n);
    cout << res << endl;
    return 0;
}

