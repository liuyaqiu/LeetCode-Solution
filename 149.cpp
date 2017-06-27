#include <iostream>
#include <vector>
#include <limits>
#include <map>

using namespace std;

#define inf numeric_limits<double>::infinity()
#define delta 1e-6

struct Point {
    int x;
    int y;
    Point(): x(0), y(0) {}
    Point(int a, int b): x(a), y(b) {}
};

void inject(map<double, int>& cnt, double k) {
    if(cnt.find(k) != cnt.end())
        cnt[k] += 1;
    else
        cnt[k] = 1;
}

void print(map<double, int> cnt) {
    for(auto iter = cnt.begin(); iter != cnt.end(); iter++) {
        if(iter->first == inf)
            cout << "inf";
        else
            cout << iter->first;
        cout << ", " << iter->second << endl;
    }
}

int maxPoints(vector<Point>& points) {
    int res = 0;
    for(auto iter1 = points.begin(); iter1 != points.end(); iter1++) {
        map<double, int> cnt;
        int cur = 0;
        for(auto iter2 = points.begin(); iter2 != points.end(); iter2++) {
            int dx = iter2->x - iter1->x;
            int dy = iter2->y - iter1->y;
            if(dx == 0) {
                if(dy == 0)
                    cur += 1;
                else 
                    inject(cnt, inf);
            }
            else {
                double k = dy * 1.0 / dx;
                inject(cnt, k);
            }
        }
        cout << "Point: " << iter1->x << ", " << iter1->y << endl;
        print(cnt);
        int max = 0;
        for(auto iter = cnt.begin(); iter != cnt.end(); iter++) {
            if(max < iter->second)
                max = iter->second;
        }
        max += cur;
        cout << "max: " << max << endl;
        if(res < max)
            res = max;
    }
    return res;
}

int main() {
    vector<Point> points;
    int x, y;
    while(cin >> x >> y) {
        Point cur = Point(x, y);
        points.push_back(cur);
    }
    int res = maxPoints(points);
    cout << res << endl;
    return 0;
}

