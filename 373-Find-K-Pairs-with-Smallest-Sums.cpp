#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
 * Find K Pairs with Smallest Sums
 *
 * You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
 *
 * Define a pair (u,v) which consists of one element from the first array and one element from the second array.
 *
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 *
 * Example 1:
 * Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
 *
 * Return: [1,2],[1,4],[1,6]
 *
 * The first 3 pairs are returned from the sequence:
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * Example 2:
 * Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
 *
 * Return: [1,1],[1,1]
 *
 * The first 2 pairs are returned from the sequence:
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * Example 3:
 * Given nums1 = [1,2], nums2 = [3],  k = 3 
 *
 * Return: [1,3],[2,3]
 *
 * All possible pairs are returned from the sequence:
 * [1,3],[2,3]
 *
 *
 */

typedef pair<int, int> mypair;

struct comp {
    bool operator() (const mypair& lhs, const mypair& rhs) {
        return lhs.first + lhs.second < rhs.first + rhs.second;
    }
};

vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<mypair> res;
    if(nums1.empty() || nums2.empty())
        return res;
    priority_queue<mypair, vector<mypair>, comp> que;
    for(auto n1: nums1) {
        for(auto n2: nums2) {
            que.push(mypair(n1, n2));
            if(que.size() > k)
                que.pop();
        }
    }
    while(!que.empty()) {
        res.push_back(que.top());
        que.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
