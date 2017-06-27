#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

/*
 * Perfect Squares
 *
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
 *
 * Credits:
 *
 *
 */

#define inf numeric_limits<int>::max()

void print(vector<int>& mem) {
    for(auto iter = mem.begin(); iter != mem.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

bool isSquare(int n) {
    return int(pow(int(sqrt(n)), 2)) == n;
}

int count(vector<int>& mem, int n) {
    if(isSquare(n)) {
        mem[n] = 1;
        return 1;
    }
    if(mem[n] > 0)
        return mem[n];
    int k = sqrt(n);
    int res = inf;
    for(int i = 2; i <= k; i++) {
        int tmp = count(mem, n - i * i);
        if(tmp < res)
            res = tmp;
    }
    mem[n] = res + 1;
    return mem[n];
}

int numSquares(int n) {
    vector<int> mem(n + 1, 0);
    mem[1] = 1;
    mem[2] = 2;
    mem[3] = 3;
    int res = count(mem, n);
    return res;
}

int main() {
    int val;
    cin >> val;
    int res = numSquares(val);
    cout << res << endl;
    return 0;
}
