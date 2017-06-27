#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

/*
 * Partition Equal Subset Sum
 *
 * Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
 *
 * Note:
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * Example 1:
 *
 * Input: [1, 5, 11, 5]
 *
 * Output: true
 *
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * Example 2:
 *
 * Input: [1, 2, 3, 5]
 *
 * Output: false
 *
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 *
 */

bool canPartition(vector<int>& nums) {
    unordered_set<int> dict;
    int sum = 0;
    for(auto n: nums)
        sum += n;
    if(sum % 2 != 0)
        return false;
    sum /= 2;
    sort(nums.begin(), nums.end());
    for(auto n: nums) {
    	if(n == sum)
    		return true;
    	else if(n < sum) {
    		vector<int> tmp1;
    		vector<int> tmp2;
	        for(auto item: dict) {
	            if(item + n > sum)
	                tmp1.push_back(item);
	            else if(item + n < sum)
	                tmp2.push_back(item + n);
	            else
	                return true;
	        }
	        for(auto t: tmp1)
	        	dict.erase(t);
	        for(auto t: tmp2)
	        	dict.insert(t);
	        if(n <= sum / 2)
	        	dict.insert(n);
    	}
        else
            return false;
    }
    return false;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    bool res = canPartition(nums);
    cout << res << endl;
    return 0;
}
