/*
 * Largest Sum of Averages
 *
 * We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?
 *
 * Note that our partition must use every number in A, and that scores are not necessarily integers.
 *
 * Example:
 * Input: 
 * A = [9,1,2,3,9]
 * K = 3
 * Output: 20
 * Explanation: 
 * The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
 * We could have also partitioned A into [9, 1], [2], [3, 9], for example.
 * That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 *  
 *
 *  Note:
 *
 *  1 <= A.length <= 100.
 *  1 <= A[i] <= 10000.
 *  1 <= K <= A.length.
 *  Answers within 10^-6 of the correct answer will be accepted as correct.
 *
 */

#include <vector>

using namespace std;


double largestSumOfAverages(vector<int>& A, int K) {
    int n = A.size();
    vector<int> sums(n + 1, 0);
    for(int i = 0; i < n; i++)
        sums[i + 1] = sums[i] + A[i];
    vector<double> dp(n, 0);
    for(int i = 0; i < n; i++)
        dp[i] = 1.0 * sums[i + 1] / (i + 1);
    for(int x = 0; x < K - 1; x++) {
        vector<double> tmp(n, 0);
        for(int y = x; y < n; y++) {
            for(int z = x; z < y; z++) {
                tmp[y] = max(tmp[y], dp[z] + 1.0 * (sums[y + 1] - sums[z + 1]) / (y - z));
            }
        }
        dp = tmp;
    }
    return dp.back();
}
