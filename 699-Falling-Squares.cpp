/*
  On an infinite number line (x-axis), we drop given squares in the order they are given.

  The i-th square dropped (positions[i] = (left, side_length)) is a square with the left-most point being positions[i][0] and sidelength positions[i][1].

  The square is dropped with the bottom edge parallel to the number line, and from a higher height than all currently landed squares. We wait for each square to stick before dropping the next.

  The squares are infinitely sticky on their bottom edge, and will remain fixed to any positive length surface they touch (either the number line or another square). Squares dropped adjacent to each other will not stick together prematurely.


  Return a list ans of heights. Each height ans[i] represents the current highest height of any square we have dropped, after dropping squares represented by positions[0], positions[1], ..., positions[i].


  Example 1:
  Input: [[1, 2], [2, 3], [6, 1]]
  Output: [2, 5, 5]
  Explanation:

  After the first drop of positions[0] = [1, 2]:
  _aa
  _aa
  -------
  The maximum height of any square is 2.


  After the second drop of positions[1] = [2, 3]:
  __aaa
  __aaa
  __aaa
  _aa__
  _aa__
  --------------
  The maximum height of any square is 5.  
  The larger square stays on top of the smaller square despite where its center
  of gravity is, because squares are infinitely sticky on their bottom edge.


  After the third drop of positions[1] = [6, 1]:
  __aaa
  __aaa
  __aaa
  _aa
  _aa___a
  --------------
  The maximum height of any square is still 5.

  Thus, we return an answer of [2, 5, 5].


  Example 2:
  Input: [[100, 100], [200, 100]]
  Output: [100, 100]
  Explanation: Adjacent squares don't get stuck prematurely - only their bottom edge can stick to surfaces.
  Note:

  1 <= positions.length <= 1000.
  1 <= positions[i][0] <= 10^8.
  1 <= positions[i][1] <= 10^6.

 */

#include <map>
#include <utility>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> mypair;

struct comp {
    bool operator() (const mypair& lhs, const mypair& rhs) const {
        return lhs.first < rhs.first;
    }
};

vector<int> fallingSquares(vector<pair<int, int>>& positions) {
    map<mypair, int, comp> intervals;
    vector<int> res;
    for(auto item: positions) {
        int start = item.first;
        int end = item.first + item.second - 1;
        int hight = item.second;
        auto iter_start = intervals.lower_bound(mypair(start, start));
        auto iter_end = intervals.upper_bound(mypair(end, end));
        if(iter_start == intervals.end())
            iter_start = intervals.begin();
        if(iter_start != intervals.begin())
            advance(iter_start, -1);
        int max_h = 0;
        map<mypair, int, comp> copy(intervals);
        for(auto iter = iter_start; iter != iter_end; iter++) {
            auto cur = iter->first;
            auto tmp = iter->first;
            int h = iter->second;
            if(cur.second < start || cur.first > end)
                continue;
            if(cur.first <= start) {
                if(cur.second <= end)
                    cur.second = start - 1;
                else {
                    mypair right_one = mypair(end,cur.second);
                    cur.second = start - 1;
                    intervals[right_one] = h;
                }
            }
            else {
                if(cur.second > end)
                    cur.first = end + 1;
            }
            copy.erase(tmp);
            if(cur != tmp && cur.first <= cur.second)
                copy[cur] = h;
            max_h = max(max_h, h);
        }
        intervals = copy;
        intervals[mypair(start, end)] = max_h + hight;
        if(res.empty())
            res.push_back(max_h + hight);
        else
            res.push_back(max(res.back(), max_h + hight));
    }
    return res;
}
