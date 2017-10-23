/*
  Find K Closest Elements

  Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

  Example 1:
  Input: [1,2,3,4,5], k=4, x=3
  Output: [1,2,3,4]
  Example 2:
  Input: [1,2,3,4,5], k=4, x=-1
  Output: [1,2,3,4]
  Note:
  The value k is positive and will always be smaller than the length of the sorted array.
  Length of the given array is positive and will not exceed 104
  Absolute value of elements in the array and x will not exceed 104

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct comp {
    int val;
    comp(int x): val(x) {}
    bool operator()(const int& x, const int& y) const {
        int dx = abs(x - val), dy = abs(y - val);
        if(dx != dy)
            return dx < dy;
        else
            return x < y;
    }
};

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    sort(arr.begin(), arr.end(), comp(x));
    vector<int> res(arr.begin(), arr.begin() + k);
    sort(res.begin(), res.end());
    return res;
}
