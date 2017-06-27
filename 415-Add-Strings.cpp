#include <iostream>
#include <vector>

using namespace std;

/*
 * Add Strings
 *
 * Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
 *
 * Note:
 *
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
 *
 *
 */

string addString(string num1, string num2) {
    int carry = 0;
    if(num1.length() < num2.length())
        swap(num1, num2);
    int i = 0;
    while(i < num2.size()) {
        int a = num1[num1.length() - 1 - i] - '0';
        int b = num2[num2.length() - 1 - i] - '0';
        char c = (a + b + carry) % 10 + '0';
        num1[num1.length() - 1 - i] = c;
        carry = (a + b + carry) / 10;
        i++;
    }
    while(carry != 0 && i < num1.size()) {
        int a = num1[num1.length() - 1 - i] - '0';
        char c = (a + carry) % 10 + '0';
        num1[num1.length() - 1 - i] = c;
        carry = (a + carry) / 10;
        i++;
    }
    if(carry != 0)
        num1 = "1" + num1;
    return num1;
}
