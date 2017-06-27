#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Rotate Function
 *
 * Given an array of integers A and let n to be its length.
 *
 * Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:
 *
 * F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].
 *
 * Calculate the maximum value of F(0), F(1), ..., F(n-1).
 *
 * Note:
 * n is guaranteed to be less than 105.
 *
 * Example:
 *
 * A = [4, 3, 2, 6]
 *
 * F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
 * F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
 * F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
 * F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
 *
 * So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
 *
 *
 */

int maxRotateFunction(vector<int>& A) {
    int sums = 0;
    for(auto num: A)
        sums += num;
    int n = A.size();
    int sumk = 0;
    for(int i = 0; i < n; i++)
        sumk += i * A[i];
    int res = sumk;
    for(int i = 1; i < n; i++) {
        sumk += sums - n * A[n - i];
        res = max(res, sumk);
    }
    return res;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    int res = maxRotateFunction(nums);
    cout << res << endl;
    return 0;
}
