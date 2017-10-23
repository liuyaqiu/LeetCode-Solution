/*
  Valid Square

  Given the coordinates of four points in 2D space, return whether the four points could construct a square.

  The coordinate (x,y) of a point is represented by an integer array with two integers.

  Example:
  Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
  Output: True
  Note:

  All the input integers are in the range [-10000, 10000].
  A valid square has four equal sides with positive length and four equal angles (90-degree angles).
  Input points have no order.

 */

#include <vector>
#include <iostream>
#include <utility>

using namespace std;

typedef pair<double, double> mypair;

double dot(mypair p1, mypair p2) {
    return p1.first * p2.first + p1.second * p2.second;
}

mypair substract(mypair p1, mypair p2) {
    return mypair(p1.first - p2.first, p1.second - p2.second);
}

double length(mypair p) {
    return p.first * p.first + p.second * p.second;
}

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    vector<mypair> points {mypair(p1[0], p1[1]), mypair(p2[0], p2[1]), mypair(p3[0], p3[1]), mypair(p4[0], p4[1])};
    mypair center(0, 0);
    for(auto p: points) {
        center.first += p.first;
        center.second += p.second;
    }
    center.first /= 2.0;
    center.second /= 2.0;
    for(int i = 1; i < 4; i++) {
        if(substract(certer, points[i]) == points[0]) {
            mypair diag1 = substract(points[0], points[i]);
            int j = 0, k = 0;
            if(i == 1) {
                j = 2;
                k = 3;
            }
            else if(i == 2) {
                j = 1;
                k = 3;
            }
            else {
                j = 1;
                k = 2;
            }
            mypair diag2 = substract(points[j], points[k]);
            return diag1 != diag2 && dot(diag1, diag2) == 0 && length(diag1) > 0 && length(diag2) > 0 && length(diag1) == length(diag2);
        }
    }
    return false;
}

int main() {
    return 0;
}
