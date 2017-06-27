#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

struct comp {
    bool operator() (const Interval& lhs, const Interval& rhs) {
        if(lhs.start != rhs.start)
            return lhs.start < rhs.start;
        else
            return lhs.end < rhs.end;
    }
};

bool overlap(const Interval& pre, const Interval& next) {
    return next.start < pre.end;
}

bool contain(set<Interval, comp>& dict, Interval itv) {
    auto it1 = dict.lower_bound(Interval(itv.start, itv.start));
    auto it2 = dict.lower_bound(Interval(itv.end, itv.end));
    if(distance(it1, it2) <= 0)
        return false;
    for(auto iter = it1; iter != it2; iter++) {
        if(iter->end < itv.end)
            return true;
    }
    return false;
}

int eraseOverlapIntervals(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), comp());
    set<Interval, comp> dict(intervals.begin(), intervals.end());
    vector<Interval> res;
    for(auto itv: intervals) {
        if(!contain(dict, itv)) {
            if(res.empty() || itv.start >= res.back().end)
                res.push_back(itv);
        }
    }
    return intervals.size() - res.size();
}

int main() {
    vector<Interval> intervals;
    int start, end;
    while(cin >> start >> end) {
        intervals.push_back(Interval(start, end));
    }
    int res = eraseOverlapIntervals(intervals);
    cout << res << endl;
    return 0;
}
