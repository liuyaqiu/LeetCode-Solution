#include <iostream>
#include <vector>

using namespace std;

int hammingWeight(int n) {
    int res = 0;
    while(n > 0) {
        res += (n & 1);
        n >>= 1;
    }
    return res;
}

int hammingDistance(int x, int y) {
    return hammingWeight(x ^ y);
}
