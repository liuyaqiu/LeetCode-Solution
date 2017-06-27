#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef pair<int, int> mypair;

struct comp_heap {
    bool operator() (const mypair& lhs, const mypair& rhs) {
        return lhs.first < rhs.first;
    }
};

struct comp_map {
    bool operator() (const mypair& lhs, const mypair& rhs) {
        return lhs.second < rhs.second;
    }
};

int findMaximizedCapital(int k, int W, vector<int>& profits, vector<int>& Capital) {
    //useful的first: 收益, second: 项目编号
    priority_queue<mypair, vector<mypair>, comp_heap> useful;
    multiset<mypair, comp_map> projects;
    for(int i = 0; i < (int)profits.size(); i++)
        projects.insert(mypair(profits[i], Capital[i]));
    int pre = 0;
    while(k > 0) {
        k--;
        auto start = projects.lower_bound({0, pre});
        auto end = projects.upper_bound({0, W});
        for(auto it = start; it != end; it++)
            useful.push(*it);
        if(useful.empty())
            break;
        mypair top = useful.top();
        useful.pop();
        pre = W;
        W += top.first;
        projects.erase(top);
    }
    return W;
}

int main() {
    int k, W;
    cin >> k >> W;
    vector<int> profits;
    vector<int> Capital;
    int p, c;
    while(cin >> p >> c) {
        profits.push_back(p);
        Capital.push_back(c);
    }
    int res = findMaximizedCapital(k, W, profits, Capital);
    cout << res << endl;
    return 0;
}
