#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0){};
    Interval(int s, int e): start(s), end(e){};
};

typedef pair<int, string> Pair;
vector<Interval> getRes(map<int, Pair>& points) {
    int cnt = 0;
    int start = 0;
    int end = 0;
    vector<Interval> res;
    for(auto iter = points.begin(); iter != points.end(); ++iter) {
        Pair p = iter->second;
        int x = iter->first;
        if(p.second == "start") {
            if(cnt == 0)
                start = x;
            cnt += p.first;
        }
        else if(p.second == "end") {
            cnt -= p.first;
            if(cnt == 0) {
                end = x;
                res.push_back(Interval(start, end));
            }
        }
        else {
        	if(cnt == 0) {
        		res.push_back(Interval(x, x));
        	}
        }
    }
    return res;
}

map<int, Pair> getPoints(vector<Interval>& intervals) {
    map<int, Pair> points;
    vector<int> tmp;
    for(auto iter = intervals.begin(); iter != intervals.end(); ++iter) {
        int start = iter->start, end = iter->end;
        auto iter1 = points.find(start);
        if(start == end)
        	tmp.push_back(start);
        else {
	        if(iter1 != points.end()) {
	            Pair& p = iter1->second;
	            if(p.second == "start") {
	                p.first += 1;
	            }
	            else {
	                p.first -= 1;
	                if(p.first == 0)
	                    points.erase(iter1);
	            }
	        }
	        else
	        	points.insert(pair<int, Pair>(start, Pair(1, "start")));
	        auto iter2 = points.find(end);
	        if(iter2 != points.end()) {
	            Pair& p = iter2->second;
	            if(p.second == "end")
	                p.first += 1;
	            else {
	                p.first -= 1;
	                if(p.first == 0)
	                    points.erase(iter2);
	            }
	        }
	        else
	        	points.insert(pair<int, Pair>(end, Pair(1, "end")));
        }
    }
    for(auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
    	auto the_iter = points.find(*iter);
    	if(the_iter == points.end()) {
    		points.insert(pair<int, Pair>(*iter, Pair(0, "none")));
    	}
    }
    return points;
}

vector<Interval> merge(vector<Interval>& intervals) {
    map<int, Pair> points = getPoints(intervals);
    return getRes(points);
}

void print(map<int, Pair>& points) {
	for(auto iter = points.begin(); iter != points.end(); ++iter) {
		cout << iter->first << " " << (iter->second).second << " " << (iter->second).first << endl;
	}
	cout << endl;
}

void printIntervals(vector<Interval>& intervals) {
	for(auto iter = intervals.begin(); iter != intervals.end(); ++iter) {
		cout << "[" << iter->start << " " << iter->end << "]"<< endl;
	}
	cout << endl;
}

int main() {
	int n;
	cout << "Please input the num: ";
	cin >> n;
	vector<Interval> intervals;
	while(n > 0) {
		int start, end;
		cin >> start >> end;
		intervals.push_back(Interval(start, end));
		n -= 1;
	}
	map<int, Pair> points = getPoints(intervals);
	vector<Interval> res = getRes(points);
	print(points);
	printIntervals(intervals);
	printIntervals(res);
	return 0;
}