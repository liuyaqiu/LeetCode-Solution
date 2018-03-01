/*
  Maximum Length of Repeated Subarray

  Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

  Example 1:
  Input:
  A: [1,2,3,2,1]
  B: [3,2,1,4,7]
  Output: 3
  Explanation: 
  The repeated subarray with maximum length is [3, 2, 1].
  Note:
  1 <= len(A), len(B) <= 1000
  0 <= A[i], B[i] < 100

 */

#include <iostream>
#include <vector>

using namespace std;

int findLength(vector<int>& A, vector<int>& B) {
    int n1 = A.size(), n2 = B.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    int res = 0;
    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            if(A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            res = max(res, dp[i][j]);
        }
    }
    return res;
}
