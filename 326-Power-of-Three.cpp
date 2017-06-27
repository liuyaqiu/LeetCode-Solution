#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
 * Power of Three
 *
 * Given an integer, write a function to determine if it is a power of three.
 *
 * Follow up:
 * Could you do it without using any loop / recursion?
 *
 *
 */

bool isPowerOfThree(int n) {
	if(n == 0)
		return false;
    int t = round(log(n) / log(3));
    return n == pow(3, t);
}

int main() {
    int n;
    cin >> n;
    bool res = isPowerOfThree(n);
    cout << res << endl;
    return 0;
}

