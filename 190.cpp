#include <iostream>
#include <vector>

using namespace std;

uint32_t swapBits(uint32_t n, int i, int j) {
    int a = (n >> i) & 1;
    int b = (n >> j) & 1;
    if((a ^ b) != 0)
        return n ^= (1 << i) | (1 << j);  //与1异或，即表示对该位取反。当i位和j位不同时，各自取反即可
    else
        return n;   //当i位和j位相同时，不必处理
}

uint32_t reverseBits(uint32_t n) {
    for(int i = 0; i < 16; i++) {
        n = swapBits(n, i, 32 - 1 - i);
    }
    return n;
}
