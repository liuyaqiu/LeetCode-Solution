#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<long, long> mypair;

struct comp {
    bool operator() (const mypair& lhs, const mypair& rhs) {
        if(lhs.first != rhs.first)
            return lhs.first < rhs.first;
        else
            return lhs.second < rhs.second;
    }
};

int findMinArrowShots(vector<pair<int, int>>& p) {
	vector<pair<long, long>> points;
	for(auto item: p)
		points.push_back(mypair(item.first, item.second));
    set<mypair> dict(points.begin(), points.end());
    int res = 0;
    while(!dict.empty()) {
        mypair tmp = *(dict.begin());
        auto start = dict.lower_bound(mypair(tmp.first, tmp.first));
        auto end = dict.lower_bound(mypair(tmp.second + 1, tmp.second + 1));
        res += 1;
        long max_end = tmp.second;
        for(auto it = start; it != end; it++) {
        	max_end = min(max_end, it->second);
        }
        for(auto it = start; it != end; it++) {
        	if(it->first <= max_end)
        		dict.erase(it);
        }
    }
    return res;
}

int main() {
    int start, end;
    vector<pair<int, int>> points;
    while(cin >> start >> end)
        points.push_back(pair<int, int>(start, end));
    int res = findMinArrowShots(points);
    cout << res << endl;
    return 0;
}
