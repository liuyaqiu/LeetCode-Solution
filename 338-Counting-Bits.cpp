#include <iostream>
#include <vector>

using namespace std;

/*
 * Counting Bits
 *
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
 *
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 *
 * Follow up:
 *
 * It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
 *
 *
 */

vector<int> countBits(int num) {
    vector<int> res(num + 1, 0);
    res[1] = 1;
    int cnt = 1;
    while((1 << cnt) <= num) {
        for(int i = 1 << cnt; i < (1 << (cnt + 1)) && i <= num; i++) {
            res[i] = 1 + res[i - (1 << cnt)];
        }
        cnt++;
    }
    return res;
}
