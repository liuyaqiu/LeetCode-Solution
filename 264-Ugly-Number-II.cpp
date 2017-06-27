#include <iostream>
#include <vector>

using namespace std;

/*
 * Ugly Number II
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 *
 * Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
 *
 * Hint:
 *
 * The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
 * An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
 * The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
 * Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
 *
 *
 */

int nthUglyNumber(int n) {
    if(n <= 0)
        return 0;
    vector<int> res;
    res.push_back(1);
    int i = 0;
    int j = 0;
    int k = 0;
    while(res.size() < n) {
        int m2 = res[i] * 2;
        int m3 = res[j] * 3;
        int m5 = res[k] * 5;
        int m = min(m2, min(m3, m5));
        res.push_back(m);
        if(m == m2)
            i++;
        else if(m == m3)
            j++;
        else
            k++;
    }
    return res[n - 1];
}

/*
    1   2   3   4   5   6   8   9   10   12    ...
    1*2 2*2 3*2 4*2 5*2 6*2 8*2 9*2 10*2 12*2  ...
    1*3 2*3 3*3 4*3 5*3 6*3 8*3 9*3 10*3 12*3  ...
    1*5 2*5 3*5 4*5 5*5 6*5 8*5 9*5 10*5 12*5  ...

    显然所有的ugly数的数组由1和下面3个数组共同构成。分别记录因子2,3,5用过的次数i, j, k，那么下一次将要产生的数必定是num[i] * 2, num[j] * 3, num[k] * 5中的最小者
*/
