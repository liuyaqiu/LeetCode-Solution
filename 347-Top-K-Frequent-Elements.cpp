#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/*
 * Top K Frequent Elements
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 *
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 *
 *
 */

struct mycomp {
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const {
        return lhs.second > rhs.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    for(auto n: nums) {
        if(cnt.find(n) != cnt.end())
            cnt[n]++;
        else
            cnt[n] = 1;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomp> topK;
    for(auto iter = cnt.begin(); iter != cnt.end(); iter++) {
        pair<int, int> tmp = pair<int, int>(iter->first, iter->second);
        topK.push(tmp);
        if(topK.size() > k)
            topK.pop();
    }
    vector<int> res;
    while(!topK.empty()) {
        res.push_back(topK.top().first);
        topK.pop();
    }
    int lo = 0, hi = res.size() - 1;
    while(lo < hi) {
        swap(res[lo], res[hi]);
        lo++;
        hi--;
    }
    return res;
}

vector<int> topKFrequent2(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    for(auto n: nums) {
        if(cnt.find(n) != cnt.end())
            cnt[n]++;
        else
            cnt[n] = 1;
    }
    int m = -1;
    for(auto c: cnt)
        m = max(m, c.second);
    vector<vector<int>> freq(m + 1, vector<int>());
    for(auto c: cnt) {
        int pos = c.second;
        int val = c.first;
        freq[pos].push_back(val);
    }
    vector<int> res;
    for(int i = m; i >= 1; i--) {
        if(!freq[i].empty()) {
            for(auto val: freq[i])
                res.push_back(val);
        }
        if(res.size() == k)
            break;
    }
    return res;
}

void print(vector<int>& nums) {
    for(auto n: nums)
        cout << n << " ";
    cout << endl;
}

int main() {
    int k;
    cin >> k;
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    vector<int> res = topKFrequent(nums, k);
    print(nums);
    print(res);
    return 0;
}
