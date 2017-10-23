/*
  Next Closest Time

  Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

  You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

  Example 1:

  Input: "19:34"
  Output: "19:39"
  Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
  Example 2:

  Input: "23:59"
  Output: "22:22"
  Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool valid(string time) {
    int pos = time.find(':');
    if(pos == -1)
        return false;
    string h = time.substr(0, pos);
    string m = time.substr(pos + 1, time.length() - pos - 1);
    int hour = stoi(h);
    int minute = stoi(m);
    return hour >= 0 && hour < 24 && minute >= 0 && minute < 60;
}

int delta(int h1, int m1, int h2, int m2) {
    int time1 = h1 * 60 + m1;
    int time2 = h2 * 60 + m2;
    return (time2 - time1 + 24 * 60) % (24 * 60);
}

struct comp {
    int h;
    int m;
    comp(string t) {
        int pos = t.find(':');
        h = stoi(t.substr(0, pos));
        m = stoi(t.substr(pos + 1, t.length() - pos - 1));
    }

    bool operator()(const string& a, const string& b) const {
        int pos1 = a.find(':');
        int pos2 = b.find(':');
        int ha = stoi(a.substr(0, pos1));
        int ma = stoi(a.substr(pos1 + 1, a.length() - pos1 - 1));
        int hb = stoi(b.substr(0, pos2));
        int mb = stoi(b.substr(pos2 + 1, b.length() - pos2 - 1));
        int d1 = delta(h, m, ha, ma);
        int d2 = delta(h, m, hb, mb);
        return d1 < d2;
    }
};

string nextClosestTime(string time) {
    vector<string> tmp;
    vector<bool> cnt(10, false);
    for(int i = 0; i < time.length(); i++) {
        if(time[i] != ':')
            cnt[time[i] - '0'] = true;
    }
    for(int i1 = 0; i1 < 10; i1++) {
        if(!cnt[i1])
            continue;
        for(int i2 = 0; i2 < 10; i2++) {
            if(!cnt[i2])
                continue;
            for(int i3 = 0; i3 < 10; i3++) {
                if(!cnt[i3])
                    continue;
                for(int i4 = 0; i4 < 10; i4++) {
                    if(!cnt[i4])
                        continue;
                    string t = to_string(i1) + to_string(i2) + ":" + to_string(i3) + to_string(i4);
                    if(valid(t))
                        tmp.push_back(t);
                }
            }
        }
    }
    sort(tmp.begin(), tmp.end(), comp(time));
    int pos = 0;
    while(pos < tmp.size() && tmp[pos] == time)
        pos++;
    if(pos >= tmp.size())
        return time;
    else
        return tmp[pos];
}
