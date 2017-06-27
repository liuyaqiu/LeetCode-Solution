#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

/*
 * Number of Boomerangs
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
 *
 * Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
 *
 * Example:
 * Input:
 * [[0,0],[1,0],[2,0]]
 *
 * Output:
 * 2
 *
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 *
 *
 */

typedef pair<int, int> mypair;

long distance(mypair p1, mypair p2) {
    return pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2);
}

int numberOfBoomerangs(vector<mypair>& points) {
    set<mypair> dict(points.begin(), points.end());
    int n = points.size();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        map<long, int> radius;
        for(int j = 0; j < n; j++) {
            long dis = distance(points[i], points[j]);
            if(radius.find(dis) != radius.end())
                radius[dis] += 1;
            else
                radius[dis] = 1;
        }
        for(auto item: radius) {
            int k = item.second;
            cnt += k * (k - 1);
        }
    }
    return cnt;
}
