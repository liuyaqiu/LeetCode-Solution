#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Water and Jug Problem
 *
 * You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.
 *
 * If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.
 *
 * Operations allowed:
 *
 * Fill any of the jugs completely with water.
 * Empty any of the jugs.
 * Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
 * Example 1: (From the famous "Die Hard" example)
 *
 * Input: x = 3, y = 5, z = 4
 * Output: True
 * Example 2:
 *
 * Input: x = 2, y = 6, z = 5
 * Output: False
 *
 *
 */

int gcd(int a, int b) {
    if(a < b)
        swap(a, b);
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

bool canMeasureWater(int x, int y, int z) {
    if(z == 0 || z == x || z == y || z == x + y)
        return true;
    if(x > y)
        swap(x, y);
    if(x == 0)
        return false;
    if(z > y + x)
        return false;
    int c = gcd(x, y);
    if(c == 1)
        return true;
    else
        return z % x == c;
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    bool res = canMeasureWater(x, y, z);
    cout << res << endl;
    return 0;
}
