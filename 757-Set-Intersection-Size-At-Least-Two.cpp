/*
  Set Intersection Size At Least Two

  An integer interval [a, b] (for integers a < b) is a set of all consecutive integers from a to b, including a and b.

  Find the minimum size of a set S such that for every integer interval A in intervals, the intersection of S with A has size at least 2.

  Example 1:
  Input: intervals = [[1, 3], [1, 4], [2, 5], [3, 5]]
  Output: 3
  Explanation:
  Consider the set S = {2, 3, 4}.  For each interval, there are at least 2 elements from S in the interval.
  Also, there isn't a smaller size set that fulfills the above condition.
  Thus, we output the size of this set, which is 3.
  Example 2:
  Input: intervals = [[1, 2], [2, 3], [2, 4], [4, 5]]
  Output: 5
  Explanation:
  An example of a minimum sized set is {1, 2, 3, 4, 5}.
  Note:

  intervals will have length in range [1, 3000].
  intervals[i] will have length 2, representing some integer interval.
  intervals[i][j] will be an integer in [0, 10^8].

 */

#include <iostream>
#include <vector>

using namespace std;

struct comp {
    bool operator() (const vector<int>& lhs, const vector<int>& rhs) const {
        if(lhs[0] != rhs[0])
            return lhs[0] < rhs[0];
        else
            return lhs[1] > rhs[1];
    }
};

int intersectionSizeTwo(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comp());
    vector<int> todo(intervals.size(), 2);
    int ans = 0;
    for(int t = intervals.size() - 1; t >= 0; t--) {
        int s = intervals[t][0];
        int e = intervals[t][1];
        int m = todo[t];
        for(int p = s; p < s + m; p++) {
            for(int i = 0; i <= t; i++) {
                if(todo[i] > 0 && p <= intervals[i][1])
                    todo[i] -= 1;
            }
            ans += 1;
        }
    }
    return ans;
}
