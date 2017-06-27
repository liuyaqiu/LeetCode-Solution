#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, int> mypair;

struct comp {
    bool operator() (const mypair& lhs, const mypair& rhs) {
        return lhs.first < rhs.first;
    }
};

vector<string> findRelativeRanks(vector<int>& nums) {
    vector<mypair> refer;
    int n = nums.size();
    for(int i = 0; i < n; i++)
        refer.push_back(mypair(nums[i], i));
    sort(refer.begin(), refer.end(), comp());
    vector<string> res(n, "");
    int rank = n;
    for(int i = 0; i < n; i++) {
        int pos = refer[i].second;
        string tmp = to_string(rank);
        if(rank == 1)
            tmp = "Gold Medal";
        else if(rank == 2)
            tmp = "Silver Medal";
        else if(rank == 3)
            tmp = "Bronze Medal";
        res[pos] = tmp;
        rank--;
    }
    return res;
}
