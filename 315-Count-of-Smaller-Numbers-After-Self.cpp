#include <iostream>
#include <vector>

using namespace std;

/*
 * Count of Smaller Numbers After Self
 *
 * You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
 *
 * Example:
 *
 * Given nums = [5, 2, 6, 1]
 *
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * Return the array [2, 1, 1, 0].
 *
 *
 */

void mergeCount(vector<pair<int, int>>& pairs, int low, int high, vector<int>& res) {
    if(high == low + 1)
        return;
    int mid = (low + high) / 2;
    mergeCount(pairs, low, mid, res);
    mergeCount(pairs, mid, high, res);
    int i = low, j = mid;
    vector<pair<int, int>> tmp;
    while(i < mid && j < high) {
        if(pairs[i].first <= pairs[j].first) {
            res[pairs[i].second] += j - mid;
            tmp.push_back(pairs[i++]);
        }
        else
            tmp.push_back(pairs[j++]);
    }
    while(i < mid) {
        res[pairs[i].second] += j - mid;
        tmp.push_back(pairs[i++]);
    }
    while(j < high)
        tmp.push_back(pairs[j++]);
    for(int i = low; i < high; i++)
        pairs[i] = tmp[i - low];
}

vector<int> countSmaller(vector<int>& nums) {
    if(nums.empty())
        return {};
    int n = nums.size();
    vector<int> res(n, 0);
    vector<pair<int, int>> pairs;
    for(int i = 0; i < n; i++)
        pairs.push_back(pair<int, int>(nums[i], i));
    mergeCount(pairs, 0, n, res);
    return res;
}

void print(vector<int>& nums) {
    for(auto n: nums)
        cout << n << " ";
    cout << endl;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val) {
        nums.push_back(val);
    }
    vector<int> res = countSmaller(nums);
    print(nums);
    print(res);
    return 0;
}
