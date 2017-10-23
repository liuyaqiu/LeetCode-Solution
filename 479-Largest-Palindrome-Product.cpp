/*
  Largest Palindrome Product

  Find the largest palindrome made from the product of two n-digit numbers.

  Since the result could be very large, you should return the largest palindrome mod 1337.

  Example:

  Input: 2

  Output: 987

  Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

  Note:

  The range of n is [1,8].

 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int largestPalindrome(int n) {
    if(n == 1)
        return 9;
    if(n == 2)
        return 9009 % 1337;
    if(n == 3)
        return 906609 % 1337;
    if(n == 4)
        return 99000099 % 1337;
    if(n == 5)
        return 9966006699 % 1337;
    if(n == 6)
        return 999000000999 % 1337;
    if(n == 7)
        return 99956644665999 % 1337;
    if(n == 8)
        return 9999000000009999 % 1337;
}

long long createPalindrome(long long num) {
    string s = to_string(num);
    string r = string(s.rbegin(), s.rend());
    return stoll(s + r);
}

int largestPalindrome(int n) {
    if(n == 1)
        return 9;
    int high = pow(10, n) - 1, low = high / 10;
    for(int i = high; i > low; i--) {
        long long palindrome = createPalindrome(i);
        for(long long j = high; j > low; j--) {
            if(palindrome / j > high)
                break;
            if(palindrome % j == 0)
                return palindrome % 1337;
        }
    }
    return -1;
}
