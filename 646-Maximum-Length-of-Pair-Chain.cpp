/*
  Maximum Length of Pair Chain

  You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

  Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

  Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

  Example 1:
  Input: [[1,2], [2,3], [3,4]]
  Output: 2
  Explanation: The longest chain is [1,2] -> [3,4]
  Note:
  The number of given pairs will be in the range [1, 1000].

 */

#include <iostram>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> mypair;

struct comp {
    bool operator()(const mypair& x, const mypair& y) {
        if(x.first != y.first)
            return x.first < y.first;
        else
            return x.second < y.second;
    }
};

int findLongestChain(vector<vector<int>>& pairs) {
    vector<int> res(pairs.size(), 1);
    vector<mypair> nums;
    for(auto vec: pairs) {
        nums.push_back(mypair(vec[0], vec[1]));
    }
    sort(nums.begin(), nums.end(), comp());
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j].second < nums[i].first)
                res[i] = max(res[i], res[j] + 1);
        }
    }
    int maxi = 0;
    for(auto item: res)
        maxi = max(maxi, item);
    return maxi;
}
