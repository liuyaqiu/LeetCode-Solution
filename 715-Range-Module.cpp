/*
  Range Module

  A Range Module is a module that tracks ranges of numbers. Your task is to design and implement the following interfaces in an efficient manner.

  addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
  queryRange(int left, int right) Returns true if and only if every real number in the interval [left, right) is currently being tracked.
  removeRange(int left, int right) Stops tracking every real number currently being tracked in the interval [left, right).
  Example 1:
  addRange(10, 20): null
  removeRange(14, 16): null
  queryRange(10, 14): true (Every number in [10, 14) is being tracked)
  queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
  queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)
  Note:

  A half open interval [left, right) denotes all real numbers left <= x < right.
  0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
  The total number of calls to addRange in a single test case is at most 1000.
  The total number of calls to queryRange in a single test case is at most 5000.
  The total number of calls to removeRange in a single test case is at most 1000.

 */

#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

typedef pair<int, int> mypair;

struct comp {
    bool operator() (const mypair& lhs, const mypair& rhs) const {
        return lhs.first < rhs.first;
    }
};

class RangeModule {
public:
    RangeModule() {
        intervals = set<mypair, comp>();
    }

    void addRange(int left, int right) {
        if(left >= right)
            return;
        mypair start = mypair(left, left);
        mypair end = mypair(right, right);
        auto iter_start = intervals.upper_bound(start);
        auto iter_end = intervals.upper_bound(end);
        if(iter_start != intervals.begin()) {
            auto p = prev(iter_start);
            if(p->first <= left && p->second >= left) {
                left = p->first;
                advance(iter_start, -1);
            }
        }
        if(iter_end != intervals.begin()) {
            auto p = prev(iter_end);
            if(p->first <= right && p->second >= right)
                right = p->second;
        }
        intervals.erase(iter_start, iter_end);
        intervals.insert(mypair(left, right));
    }

    bool queryRange(int left, int right) {
        if(left >= right)
            return false;
        mypair start = mypair(left, left);
        mypair end = mypair(right, right);
        auto iter_start = intervals.upper_bound(start);
        if(iter_start == intervals.begin())
            return false;
        advance(iter_start, -1);
        auto iter_end = intervals.lower_bound(end);
        if(iter_end == intervals.begin())
            return false;
        advance(iter_end, -1);
        if(iter_start != iter_end)
            return false;
        return right <= iter_start->second;
    }

    void removeRange(int left, int right) {
        if(left >= right)
            return;
        mypair start = mypair(left, left);
        mypair end = mypair(right, right);
        auto iter_start = intervals.upper_bound(start);
        auto iter_end = intervals.upper_bound(end);
        int left_left = left, left_right = left;
        int right_left = right, right_right = right;
        if(iter_start != intervals.begin()) {
            auto p = prev(iter_start);
            if(p->first <= left && p->second >= left) {
                left_left = p->first;
                advance(iter_start, -1);
            }
        }
        if(iter_end != intervals.begin()) {
            auto p = prev(iter_end);
            if(p->first <= right && p->second >= right)
                right_right = p->second;
        }
        intervals.erase(iter_start, iter_end);
        if(left_left < left_right)
            intervals.insert(mypair(left_left, left_right));
        if(right_left < right_right)
            intervals.insert(mypair(right_left, right_right));
    }

    void printRange() {
        for(auto itv: intervals) {
            cout << "[" << itv.first << ", " << itv.second << ")" << "  ";
        }
        cout << endl;
    }

private:
    set<mypair, comp> intervals;
};
