/*
  Max Chunks To Make Sorted II

  This question is the same as "Max Chunks to Make Sorted" except the integers of the given array are not necessarily distinct, the input array could be up to length 2000, and the elements could be up to 10**8.

  Given an array arr of integers (not necessarily distinct), we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

  What is the most number of chunks we could have made?

  Example 1:

  Input: arr = [5,4,3,2,1]
  Output: 1
  Explanation:
  Splitting into two or more chunks will not return the required result.
  For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
  Example 2:

  Input: arr = [2,1,3,4,4]
  Output: 4
  Explanation:
  We can split into two chunks, such as [2, 1], [3, 4, 4].
  However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
  Note:

  arr will have length in range [1, 2000].
  arr[i] will be an integer in range [0, 10**8].

 */

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int res = 0;
    int start = 0;
    vector<int> tmp(arr);
    sort(tmp.begin(), tmp.end());
    while(start < arr.size()) {
        int end = start;
        unordered_map<int, int> cnt;
        while(start <= end) {
            auto iter = lower_bound(tmp.begin(), tmp.end(), arr[start]);
            if(cnt.find(arr[start]) == cnt.end()) {
                cnt[arr[start]] = 1;
            }
            else {
                advance(iter, cnt[arr[start]]);
                cnt[arr[start]] += 1;
            }
            int pos = distance(tmp.begin(), iter);
            end = max(end, pos);
            start += 1;
        }
        res += 1;
    }
    return res;
}
