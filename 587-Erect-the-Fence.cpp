/*
  Erect the Fence

  There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.

 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

struct Point {
    int x;
    int y;
    Point(): x(0), y(0) {}
    Point(int a, int b): x(a), y(b) {}
};

struct cmp {
    bool operator()(const Point& a, const Point& b) const {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

int cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> outerTrees(vector<Point>& trees) {
    int n = trees.size(), k = 0;
    if(n == 1)
        return trees;
    sort(trees.begin(), trees.end(), cmp());
    vector<Point> H(2*n);
    for(int i = 0; i < n; i++) {
        while(k >= 2 && cross(H[k - 2], H[k - 1], trees[i]) < 0)
            k--;
        H[k++] = trees[i];
    }
    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t && cross(H[k - 2], H[k - 1], trees[i]) < 0)
            k--;
        H[k++] = trees[i];
    }
    H.resize(k - 1);
    set<Point, cmp> res;
    for(auto item: H)
        res.insert(item);
    vector<Point> result;
    for(auto item: res)
        result.push_back(item);
    return result;
}
