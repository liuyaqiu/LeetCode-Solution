/*
  Smallest Range

  You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

  We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

  Example 1:
  Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
  Output: [20,24]
  Explanation:
  List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
  List 2: [0, 9, 12, 20], 20 is in range [20,24].
  List 3: [5, 18, 22, 30], 22 is in range [20,24].
  Note:
  The given list may contain duplicates, so ascending order means >= here.
  1 <= k <= 3500
  -105 <= value of elements <= 105.
  For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see this point.

 */

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <bitset>

using namespace std;

typedef pair<int, int> mypair;

struct comp {
    bool operator() (const mypair& x, const mypair& y) const {
        if(x.first != y.first)
            return x.first < y.first;
        else
            return x.second < y.second;
    }
};

vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<mypair> tmp;
    for(int i = 0; i < nums.size(); i++) {
        for(auto item: nums[i]) {
            tmp.push_back(mypair(item, i));
        }
    }
    sort(tmp.begin(), tmp.end(), comp());
    mypair res(tmp.front().first, tmp.back().first);
    int start = 0;
    int end = 0;
    int k = 0;
    vector<int> cnt(nums.size(), 0);
    while(start < tmp.size()) {
        while(k < nums.size() && end < tmp.size()) {
            int type =tmp[end].second;
            if(cnt[type] == 0)
                k++;
            cnt[type] += 1;
            end++;
        }
        if(k >= nums.size()) {
            mypair cur(tmp[start].first, tmp[end - 1].first);
            int delta = (cur.second - cur.first) - (res.second - res.first);
            if(delta < 0 || (delta == 0 && cur.first < res.first))
               res = cur;
        }
        int index = tmp[start].second;
        cnt[index]--;
        if(cnt[index] <= 0)
            k--;
        start++;
    }
    return {res.first, res.second};
}
