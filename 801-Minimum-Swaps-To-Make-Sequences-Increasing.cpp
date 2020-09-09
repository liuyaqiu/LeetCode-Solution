/*
 * Minimum Swaps To Make Sequences Increasing
 *
 * We have two integer sequences A and B of the same non-zero length.
 *
 * We are allowed to swap elements A[i] and B[i].  Note that both elements are in the same index position in their respective sequences.
 *
 * At the end of some number of swaps, A and B are both strictly increasing.  (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)
 *
 * Given A and B, return the minimum number of swaps to make both sequences strictly increasing.  It is guaranteed that the given input always makes it possible.
 *
 * Example:
 * Input: A = [1,3,5,4], B = [1,2,3,7]
 * Output: 1
 * Explanation: 
 * Swap A[3] and B[3].  Then the sequences are:
 * A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
 * which are both strictly increasing.
 * Note:
 *
 * A, B are arrays with the same length, and that length will be in the range [1, 1000].
 * A[i], B[i] are integer values in the range [0, 2000].
 *
 */

#include <vector>

using namespace std;

int minSwap(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> dp1(n, 0); // 交换第i个位置
    if(A[0] != B[0])
        dp1[0] = 1;
    vector<int> dp2(n, 0); // 不交换第i个位置
    for(int i = 1; i < n; i++) {
        if(A[i - 1] < A[i] && B[i - 1] < B[i]) {
            if(A[i] != B[i]) {
                dp1[i] = dp1[i - 1] + 1;
                if(B[i - 1] < A[i] && A[i - 1] < B[i])
                    dp1[i] = min(dp1[i], dp2[i - 1] + 1);
            }
            else
                dp1[i] = min(dp1[i - 1], dp2[i - 1]);
            dp2[i] = dp2[i - 1];
            if(B[i - 1] < A[i] && A[i - 1] < B[i]) //上一个位置可以交换
                dp2[i] = min(dp2[i], dp1[i - 1]);
        }
        else {
            dp1[i] = dp2[i - 1] + 1;
            dp2[i] = dp1[i - 1];
        }
    }
    return min(dp1[n - 1], dp2[n - 1]);
}
