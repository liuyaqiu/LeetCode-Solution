/*
  My Calendar II

  Implement a MyCalendarTwo class to store your events. A new event can be added if adding the event will not cause a triple booking.

Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A triple booking happens when three events have some non-empty intersection (ie., there is some time that is common to all 3 events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true
Explanation: 
The first two events can be booked.  The third event can be double booked.
The fourth event (5, 15) can't be booked, because it would result in a triple booking.
The fifth event (5, 10) can be booked, as it does not use time 10 which is already double booked.
The sixth event (25, 55) can be booked, as the time in [25, 40) will be double booked with the third event;
the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
Note:

The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].

 */

#include <iostream>
#include <set>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> mypair;

struct comp {
    bool operator() (const mypair& lhs, const mypair& rhs) const {
        if(lhs.first != rhs.first)
            return lhs.first < rhs.first;
        else
            return lhs.second < rhs.second;
    }
};

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        ranges = {};
        judges = {};
    }

    bool book(int start, int end) {
        if(!judge(start, end))
            return false;
        for(auto iter = ranges.begin(); iter != ranges.end(); iter++) {
            int l = max(iter->first, start);
            int r = min(iter->second, end);
            if(l < r)
                judges.insert(mypair(l, r));
        }
        ranges.insert(mypair(start, end));
        return true;
    }

    bool judge(int start, int end) {
        auto iter = judges.lower_bound(mypair(start, start));
        if(iter != judges.end() && iter->first < end)
            return false;
        if(iter != judges.begin() && prev(iter)->second > start)
            return false;
        return true;
    }

private:
    set<mypair, comp> ranges;
    set<mypair, comp> judges;
};

typedef pair<int, int> mypair;

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        ranges = {};
    }

    bool book(int start, int end) {
        for(auto vec: ranges) {
            mypair key = vec[0];
            mypair& val = vec[1];
            if(key.first >= end || key.second <= start)
                continue;
            if(start >= key.first && end <= key.second) {
                if(val.first > start || val.second < end)
                    return false;
            }
            if(start >= key.first && end > key.second) {
                if(val.first > start || val.second < key.second)
                    return false;
            }
            if(start < key.first && end >= key.second) {
                if(val.first > key.first || val.second < key.second)
                    return false;
            }
            if(start < key.first && end < key.second) {
                if(val.first > key.first || val.second < end)
                    return false;
            }
        }
        int val_start = start, val_end = end;
        for(auto& vec: ranges) {
            mypair& key = vec[0];
            mypair& val = vec[1];
            if(key.first >= end || key.second <= start)
                continue;
            if(start >= key.first && end <= key.second) {
                val_start = end;
                val_end = start;
            }
            if(start >= key.first && end > key.second) {
                val.second = start;
            }
            if(start < key.first && end >= key.second) {
                val.first = key.second;
                val.second = key.first;
            }
            if(start < key.first && end < key.second) {
                val.first = end;
            }
        }
        ranges.push_back({mypair(start, end), mypair(val_start, val_end)});
        return true;
    }

private:
    vector<vector<mypair>> ranges;
};

class MyCalendar {
    vector<pair<int, int>> books;
public:
    bool book(int start, int end) {
        for (pair<int, int> p : books)
            if (max(p.first, start) < min(end, p.second)) return false;
        books.push_back({start, end});
        return true;
    }
};

class MyCalendarTwo {
    vector<pair<int, int>> books;
public:
    bool book(int start, int end) {
        MyCalendar overlaps;
        for (pair<int, int> p : books) {
            if (max(p.first, start) < min(end, p.second)) { // overlap exist
                pair<int, int> overlapped = getOverlap(p.first, p.second, start, end);
                if (!overlaps.book(overlapped.first, overlapped.second)) return false; // overlaps overlapped
            }
        }
        books.push_back({ start, end });
        return true;
    }

    pair<int, int> getOverlap(int s0, int e0, int s1, int e1) {
        return { max(s0, s1), min(e0, e1)};
    }
};
