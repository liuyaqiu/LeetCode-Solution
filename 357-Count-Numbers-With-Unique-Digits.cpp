#include <iostream>
#include <vector>

using namespace std;

/*
 * Count Numbers with Unique Digits
 *
 * Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
 *
 * Example:
 * Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
 *
 * Hint:
 *
 * Let f(k) = count of numbers with unique digits with length equals k.
 * f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].
 *
 *
 */

int countNumbersUniqueDigits(int n) {
	if(n == 0)
		return 1;
    if(n < 0 || n > 10)
        return 0;
    int res = 10;
    for(int i = 2; i <= n; i++) {
        int tmp = 9;
        for(int j = i; j > 1; j++)
            tmp *= (9 - j + 2);
        res += tmp;
    }
    return res;
}

