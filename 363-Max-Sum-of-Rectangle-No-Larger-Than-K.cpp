#include <iostream>
#include <set>
#include <vector>
#include <limits>
#include <algorithm>
#include <iterator>

using namespace std;

/*
 * Max Sum of Rectangle No Larger Than K
 *
 * Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.
 *
 * Example:
 * Given matrix = [
 *   [1,  0, 1],
 *   [0, -2, 3]
 * ]
 * k = 2
 * The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).
 *
 * Note:
 * The rectangle inside the matrix must have an area > 0.
 * What if the number of rows is much larger than the number of columns?
 *
 *
 */

#define minf numeric_limits<int>::min()

int getLargestSumCloseToK(vector<int> arr, int k) {
    int sum = 0;
    set<int> cnt;
    int result = minf;
    cnt.insert(0);
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        auto ceil = cnt.lower_bound(sum - k);
        if(ceil != cnt.end())
            result = max(result, sum - *ceil);
        cnt.insert(sum);
    }
    return result;
}

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    if(matrix.empty())
        return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    int m = max(row, col);
    int n = min(row, col);
    bool rowLarger = row > col;
    int result = minf;
    for(int i = 0; i < n; i++) {
        vector<int> each(m, 0);
        for(int j = i; j>= 0; j--) {
            for(int k = 0; k < m; k++)
                each[k] += rowLarger ? matrix[k][j] : matrix[j][k];
            result = max(result, getLargestSumCloseToK(each, k));
        }
    }
    return result;
}
