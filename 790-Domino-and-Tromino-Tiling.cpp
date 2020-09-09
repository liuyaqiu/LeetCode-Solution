/*
 * Domino and Tromino Tiling
 *
 * We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.
 *
 * XX  <- domino
 *
 * XX  <- "L" tromino
 * X
 * Given N, how many ways are there to tile a 2 x N board? Return your answer modulo 10^9 + 7.
 *
 * (In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.)
 *
 * Example:
 * Input: 3
 * Output: 5
 * Explanation: 
 * The five different ways are listed below, different letters indicates different tiles:
 * XYZ XXZ XYY XXY XYY
 * XYZ YYZ XZZ XYY XXY
 * Note:
 *
 * N  will be in range [1, 1000].
 *
 */

#include <vector>

using namespace std;

int numTilings(int N) {
    int mod = 1000000007;
    vector<long long> f1(N + 1, 0);
    vector<long long> f2(N + 1, 0);
    vector<long long> f3(N + 1, 0);
    f3[1] = 1;
    f3[0] = 1;
    for(int i = 2; i <= N; i++) {
        f3[i] = (f1[i - 1] + f2[i - 1] + f3[i - 1] + f3[i - 2]) % mod;
        f2[i] = (f1[i - 1] + f3[i - 2]) % mod;
        f1[i] = (f2[i - 1] + f3[i - 2]) % mod;
    }
    return f3[N];
}
