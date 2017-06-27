#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

/*
 * Kth Smallest Element in a Sorted Matrix
 *
 * Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
 *
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 *
 * Example:
 *
 * matrix = [
 *  [ 1,  5,  9],
 *  [10, 11, 13],
 *  [12, 13, 15]
 * ],
 * k = 8,
 *
 * return 13.
 *
 *
 */

typedef tuple<int, int, int> mytuple;

struct comp {
    bool operator() (const mytuple& lhs, const mytuple& rhs) {
        return get<0>(lhs) > get<0>(rhs);
    }
};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    if(matrix.empty())
        return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int res = 0;
    priority_queue<mytuple, vector<mytuple>, comp> que;
    que.push(mytuple(matrix[0][0], 0, 0));
    while(k > 0) {
        auto tmp = que.top();
        que.pop();
        res = get<0>(tmp);
        int i = get<1>(tmp), j = get<2>(tmp);
        if(j == 0 && i + 1 < m)
            que.push(mytuple(matrix[i + 1][j], i + 1, j));
        if(j + 1 < n)
            que.push(mytuple(matrix[i][j + 1], i, j + 1));
        k--;
    }
    return res;
}

int count(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int i = n - 1;
    int j = 0;
    int res = 0;
    while(i >= 0 && j < n) {
        if(matrix[i][j] <= target) {
            res += i + 1;
            j++;
        }
        else
            i--;
    }
    return res;
}

int kthSmallest2(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];
    while(low < high) {
        int mid = (low + high) / 2;
        int cnt = count(matrix, mid);
        if(cnt < k)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix;
    int val;
    for(int i = 0; i < m; i++) {
        vector<int> row;
        for(int j = 0; j < n; j++) {
            cin >> val;
            row.push_back(val);
        }
        matrix.push_back(row);
    }
    int k;
    cin >> k;
    int res = kthSmallest2(matrix, k);
    cout << res << endl;
    return 0;
}
