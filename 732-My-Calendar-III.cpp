/*
  My Calendar III

  Implement a MyCalendarThree class to store your events. A new event can always be added.

  Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

  A K-booking happens when K events have some non-empty intersection (ie., there is some time that is common to all K events.)

  For each call to the method MyCalendar.book, return an integer K representing the largest integer such that there exists a K-booking in the calendar.

  Your class will be called like this: MyCalendarThree cal = new MyCalendarThree(); MyCalendarThree.book(start, end)
  Example 1:
  MyCalendarThree();
  MyCalendarThree.book(10, 20); // returns 1
  MyCalendarThree.book(50, 60); // returns 1
  MyCalendarThree.book(10, 40); // returns 2
  MyCalendarThree.book(5, 15); // returns 3
  MyCalendarThree.book(5, 10); // returns 3
  MyCalendarThree.book(25, 55); // returns 3
  Explanation: 
  The first two events can be booked and are disjoint, so the maximum K-booking is a 1-booking.
  The third event [10, 40) intersects the first event, and the maximum K-booking is a 2-booking.
  The remaining events cause the maximum K-booking to be only a 3-booking.
  Note that the last event locally causes a 2-booking, but the answer is still 3 because
  eg. [10, 20), [10, 40), and [5, 15) are still triple booked.
  Note:

  The number of calls to MyCalendarThree.book per test case will be at most 400.
  In calls to MyCalendarThree.book(start, end), start and end are integers in the range [0, 10^9].

 */

typedef pair<int, int> mypair;

struct comp1 {
    bool operator() (const mypair& lhs, const mypair& rhs) const {
        if(lhs.first != rhs.first)
            return lhs.first < rhs.first;
        else
            return lhs.second < rhs.second;
    }
};

struct comp2 {
    bool operator() (const mypair& lhs, const mypair& rhs) const {
        if(lhs.second != rhs.second)
            return lhs.second < rhs.second;
        else
            return lhs.first < rhs.first;
    }
};

class MyCalendarThree {
public:
    MyCalendarThree() {
        k = 0;
    }

    int book(int start, int end) {
        mypair s(start, start);
        mypair e(end, end);
        intervals.insert(mypair(start, end));
        auto iter_start = intervals.lower_bound(s);
        auto iter_end = intervals.lower_bound(e);
        multiset<mypair, comp1> cur(iter_start, iter_end);
        multiset<mypair, comp2> left(intervals.begin(), iter_start);
        auto iter_t = left.upper_bound(s);
        cur.insert(iter_t, left.end());
        /*
        cout << start << ", " << end << ": ";
        for(auto item: cur) {
            cout << "[" << item.first << ", " << item.second << "), ";
        }
        cout << endl;
        */
        vector<mypair> endpoint;
        for(auto item: cur) {
            endpoint.push_back(mypair(item.first, 1));
            endpoint.push_back(mypair(item.second, 0));
        }
        sort(endpoint.begin(), endpoint.end(), comp1());
        int cnt = 0;
        int c_max = 0;
        for(auto item: endpoint) {
            if(item.second == 1) {
                cnt += 1;
                c_max = max(c_max, cnt);
            }
            else
                cnt -= 1;
        }
        k = max(k, c_max);
        //cout << "cnt: " << c_max << ", " << "k: " << k << endl;
        return k;
    }

private:
    multiset<mypair, comp1> intervals;
    int k;
};
