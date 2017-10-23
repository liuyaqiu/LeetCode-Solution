/*
  Can Place Flowers

  Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

  Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

  Example 1:
  Input: flowerbed = [1,0,0,0,1], n = 1
  Output: True
  Example 2:
  Input: flowerbed = [1,0,0,0,1], n = 2
  Output: False
  Note:
  The input array won't violate no-adjacent-flowers rule.
  The input array size is in the range of [1, 20000].
  n is a non-negative integer which won't exceed the input array size.

 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int res = 0;
    int pos = 0;
    while(pos < flowerbed.size()) {
        while(pos < flowerbed.size() && flowerbed[pos] == 1)
            pos++;
        if(pos > 0)
            pos += 1;
        int cnt = 0;
        while(pos < flowerbed.size() && flowerbed[pos] != 1) {
            pos++;
            cnt++;
        }
        if(pos < flowerbed.size())
            cnt--;
        res += ceil(cnt / 2.0);
    }
    return res >= n;
}
