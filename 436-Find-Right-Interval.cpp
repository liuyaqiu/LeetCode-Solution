#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <set>

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

vector<int> findRightInterval(vector<Interval>& intervals) {
    int n = intervals.size();
    map<Interval, set<int> , comp> refer;
    for(int i = 0; i < n; i++) {
        if(refer.find(intervals[i]) == refer.end())
            refer[intervals[i]] = {i};
        else
            refer[intervals[i]].insert(i);
    }
    vector<int> res(n, -1);
    for(int i = 0; i < n; i++) {
        Interval tmp = Interval(intervals[i].end, intervals[i].end);
        auto iter = refer.lower_bound(tmp);
        if(iter != refer.end()) {
            res[i] = *((iter->second).begin());
        }
    }
    return res;
}

int main() {
    int s, e;
    vector<Interval> intervals;
    while(cin >> s >> e)
        intervals.push_back(Interval(s, e));
    vector<int> res = findRightInterval(intervals);
    for(auto r: res)
        cout << r << " ";
    cout << endl;
    return 0;
}

