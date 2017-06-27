#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if(timeSeries.empty())
        return 0;
    int res = 0;
    int n = timeSeries.size();
    for(int i = 1; i < n; i++) {
        int pre = timeSeries[i - 1];
        int cur = timeSeries[i];
        res += min(cur - pre, duration);
    }
    return res + duration;
}
