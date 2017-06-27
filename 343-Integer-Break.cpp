#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
 * Integer Break
 *
 * Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
 *
 * For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
 *
 * Note: You may assume that n is not less than 2 and not larger than 58.
 *
 * Hint:
 *
 * There is a simple O(n) solution to this problem.
 * You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
 *
 *
 */

int integerBreak(int n) {
    vector<int> dp(n + 1, 0);
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < i + 1; j++) {
            if(i + j <= n) {
                dp[i + j] = max(max(dp[i], i) * max(dp[j], j), dp[i + j]);
            }
        }
    }
    return dp[n];
}

int integerBreak2(int n) {
    if(n == 2)
        return 1;
    if(n == 3)
        return 2;
    if(n == 4)
        return 4;
    if(n % 3 == 0) {
        int m = n / 3;
        return pow(3, m);
    }
    else if(n % 3 == 1) {
        int m = (n - 4) / 3;
        return pow(3, m) * 4;
    }
    else {
        int m = n / 3;
        return pow(3, m) * 2;
    }
}
