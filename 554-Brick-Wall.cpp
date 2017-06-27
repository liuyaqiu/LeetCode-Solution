#include <iostream>
#include <vector>
#include <map>

using namespace std;

int leastBricks(vector<vector<int>>& wall) {
    map<int, int> cnt;
    int all_width = 0;
    for(auto width: wall[0])
        all_width += width;
    for(auto row: wall) {
        int pos = 0;
        for(auto width: row) {
            pos += width;
            if(cnt.find(pos) == cnt.end())
                cnt[pos] = 1;
            else
                cnt[pos] += 1;
        }
    }
    int maxi = 0;
    for(auto item: cnt) {
        if(item.first != 0 && item.first != all_width)
            maxi = max(maxi, item.second);
    }
    return wall.size() - maxi;
}

