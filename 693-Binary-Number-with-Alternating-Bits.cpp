/*
  Binary Number with Alternating Bits

  Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

  Example 1:
  Input: 5
  Output: True
  Explanation:
  The binary representation of 5 is: 101
  Example 2:
  Input: 7
  Output: False
  Explanation:
  The binary representation of 7 is: 111.
  Example 3:
  Input: 11
  Output: False
  Explanation:
  The binary representation of 11 is: 1011.
  Example 4:
  Input: 10
  Output: True
  Explanation:
  The binary representation of 10 is: 1010.

 */

#include <iostream>
#include <vector>

using namespace std;

bool hasAlternatingBits(int n) {
    int pre = -1;
    while(n != 0) {
        int cur = n % 2;
        n /= 2;
        if(cur == pre)
            return false;
        else
            pre = cur;
    }
    return true;
}
