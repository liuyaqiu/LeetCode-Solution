/*
  Sum of Square Numbers

  Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

  Example 1:
  Input: 5
  Output: True
  Explanation: 1 * 1 + 2 * 2 = 5
  Example 2:
  Input: 3
  Output: False

 */

#include <iostream>
#include <vector>
#include <cmath>

bool judgeSquareSum(int c) {
    int a_max = floor(sqrt(c));
    for(int a = 0; a <= a_max; a++) {
        int b = c - a * a;
        if(b == (int)pow(floor(sqrt(b)), 2))
            return true;
    }
    return false;
}
