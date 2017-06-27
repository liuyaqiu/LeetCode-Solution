#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <cmath>

using namespace std;

#define inf numeric_limits<int>::max()

int convert(string time) {
    int index = time.find_first_of(':');
    string hour = time.substr(0, index);
    string minute = time.substr(index + 1, time.length() - index - 1);
    int h = stoi(hour);
    int m = stoi(minute);
    return h * 60 + m;
}

int findMinDifference(vector<string>& timePoints) {
    vector<int> times;
    for(auto str: timePoints)
        times.push_back(convert(str));
    sort(times.begin(), times.end());
    int mini = inf;
    int n = times.size();
    for(int i = 0; i < n - 1; i++) {
        int tmp = times[i + 1] - times[i];
        mini = min(mini, tmp);
    }
    mini = min(times[0] + 60 * 24 - times[n - 1], mini);
    return mini;
}

