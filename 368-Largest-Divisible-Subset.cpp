#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Largest Divisible Subset
 *
 * Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
 *
 * If there are multiple solutions, return any subset is fine.
 *
 * Example 1:
 *
 * nums: [1,2,3]
 *
 * Result: [1,2] (of course, [1,3] will also be ok)
 * Example 2:
 *
 * nums: [1,2,4,8]
 *
 * Result: [1,2,4,8]
 *
 *
 */

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res(n, vector<int>());
    cout << n << endl;
    for(int i = n - 1; i >= 0; i--) {
        vector<int> tmp;
        for(int j = i + 1; j < n; j++) {
            if(nums[j] % nums[i] == 0 && tmp.size() < res[j].size()) {
                tmp = res[j];
            }
        }
        tmp.push_back(nums[i]);
        res[i] = tmp;
    }
    vector<int> maxi;
    for(auto vec: res) {
        if(vec.size() > maxi.size())
            maxi = vec;
    }
    reverse(maxi.begin(), maxi.end());
    return maxi;
}

template <typename T> void print(vector<T>& res) {
    for(auto item: res)
        cout << item << " ";
    cout << endl;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    vector<int> res = largestDivisibleSubset(nums);
    print(res);
    return 0;
}
