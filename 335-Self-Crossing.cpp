#include <iostream>
#include <vector>

using namespace std;

/*
 * Self Crossing
 *
 * You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.
 *
 * Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.
 *
 *
 * 容易注意到，相交的边必定是最近经过的边
 */

bool isSelfCrossing(vector<int>& x) {
    if(x.size() <= 3)
        return false;
    for(int i = 3; i < x.size(); i++) {
        if(x[i - 3] >= x[i - 1] && x[i] >= x[i - 2])
            return true;
        if(i >= 4 && x[i - 4] >= x[i - 2] - x[i] && x[i - 3] == x[i - 1])
            return true;
        if(i >= 5 && x[i - 5] <= x[i - 3] && x[i - 4] <= x[i - 2] && x[i - 1] <= x[i - 3] && x[i - 1] >= x[i - 3] - x[i - 5] && x[i] <= x[i - 2] && x[i] >= x[i - 2] - x[i - 4])
            return true;
    }
    return false;
}
