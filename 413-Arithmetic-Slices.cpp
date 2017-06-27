#include <iostream>
#include <vector>

using namespace std;

/*
 * Arithmetic SlicesArithmetic Slices
 *
 * A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
 *
 * For example, these are arithmetic sequence:
 *
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * The following sequence is not arithmetic.
 *
 * 1, 1, 2, 5, 7
 *
 * A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
 *
 * A slice (P, Q) of array A is called arithmetic if the sequence:
 * A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
 *
 * The function should return the number of arithmetic slices in the array A.
 *
 *
 * Example:
 *
 * A = [1, 2, 3, 4]
 *
 * return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
 *
 *
 */

int f(int n) {
    return (n - 1) * (n - 2) / 2;
}

int numberOfArithmeticsSlices(vector<int>& A) {
    int res = 0;
    int start = 0;
    int n = A.size();
    while(start <= n - 3) {
        int pos = start + 1;
        int delta = A[pos] - A[start];
        int cnt = 2;
        pos++;
        while(pos < n && A[pos] - A[pos - 1] == delta) {
            pos++;
            cnt++;
        }
        start = pos - 1;
        res += f(cnt);
    }
    return res;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    int res = numberOfArithmeticsSlices(nums);
    cout << res << endl;
    return 0;
}
