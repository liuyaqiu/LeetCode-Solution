/*
  Reach a Number

  You are standing at position 0 on an infinite number line. There is a goal at position target.

  On each move, you can either go left or right. During the n-th move (starting from 1), you take n steps.

  Return the minimum number of steps required to reach the destination.

  Example 1:
  Input: target = 3
  Output: 2
  Explanation:
  On the first move we step from 0 to 1.
  On the second step we step from 1 to 3.
  Example 2:
  Input: target = 2
  Output: 3
  Explanation:
  On the first move we step from 0 to 1.
  On the second move we step  from 1 to -1.
  On the third move we step from -1 to 2.
  Note:
  target will be a non-zero integer in the range [-10^9, 10^9].

 */

#include <iostream>
#include <vector>

int sums(int x) {
    return x * (1 + x) / 2;
}

int reachNumber(int target) {
    long long t = abs(target);
    int res = (sqrt(1 + 8 * t) - 1) / 2;
    int sum_res = sums(res);
    if(sum_res < t) {
        res += 1;
        sum_res = sums(res);
    }
    if(t % 2 != sum_res % 2)
        res += 1 + res % 2;
    return res;
}
