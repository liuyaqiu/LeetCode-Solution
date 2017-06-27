#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPowerOfTwo(int n) {
    int k = log2(n);
    return n == 1 << k;
}
