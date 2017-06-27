#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

struct Edge {
    int x;
    int height;
    bool isStart;

    Edge(int val, int h, bool start) {
        x = val;
        height = h;
        isStart = start;
    }
};

class mycomp {
    bool reverse;

public:
    mycomp(const bool& revparam = false) {
        reverse = revparam;
    }

    bool judge(const Edge& lhs, const Edge& rhs) const {
        if(lhs.x != rhs.x)
            return lhs.x < rhs.x;
        if(lhs.isStart && rhs.isStart)
            return rhs.height < lhs.height;
        if(!lhs.isStart && !rhs.isStart)
            return lhs.height < rhs.height;
        return lhs.isStart;
    }

    bool operator() (const Edge& lhs, const Edge& rhs) const {
        if(reverse)
            return !judge(lhs, rhs);
        else
            return judge(lhs, rhs);
    }
};

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> res;
    if(buildings.empty())
        return res;
    vector<Edge> edges;
    for(auto iter = buildings.begin(); iter != buildings.end(); iter++) {
        Edge start = Edge((*iter)[0], (*iter)[2], true);
        edges.push_back(start);
        Edge end = Edge((*iter)[1], (*iter)[2], false);
        edges.push_back(end);
    }
    map<int, int> heightHeap;
    sort(edges.begin(), edges.end(), mycomp());
    for(auto iter = edges.begin(); iter != edges.end(); iter++) {
        if(iter->isStart) {
            if(heightHeap.empty() || iter->height > heightHeap.rbegin()->first)
                res.push_back(pair<int, int>(iter->x, iter->height));
            auto it = heightHeap.find(iter->height);
            if(it == heightHeap.end())
                heightHeap[iter->height] = 1;
            else
                heightHeap[iter->height] += 1;
        }
        else {
            if(heightHeap[iter->height] == 1)
                heightHeap.erase(iter->height);
            else
                heightHeap[iter->height] -= 1;
            if(heightHeap.empty())
                res.push_back(pair<int, int>(iter->x, 0));
            else if(iter->height > heightHeap.rbegin()->first)
                res.push_back(pair<int, int>(iter->x, heightHeap.rbegin()->first));
        }
    }
    return res;
}

void print(vector<pair<int, int>>& res) {
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        cout << "["<< iter->first << " " << iter->second << "]"<< endl;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> buildings;
    int li, ri, hi;
    while(cin >> li >> ri >> hi) {
        vector<int> cur = {li, ri, hi};
        buildings.push_back(cur);
    }
    vector<pair<int, int>> res = getSkyline(buildings);
    print(res);
    return 0;
}
