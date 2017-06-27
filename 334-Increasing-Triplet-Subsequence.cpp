#include <iostream>
#include <vector>

using namespace std;

/*
 * Increasing Triplet Subsequence
 *
 * Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
 *
 * Formally the function should:
 * Return true if there exists i, j, k 
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
 * Your algorithm should run in O(n) time complexity and O(1) space complexity.
 *
 * Examples:
 * Given [1, 2, 3, 4, 5],
 * return true.
 *
 * Given [5, 4, 3, 2, 1],
 * return false.
 *
 *
 */

bool increasingTriplet(vector<int>& nums) {
    if(nums.size() < 3)
        return false;
    vector<int> inc = {0, 0, 0};
    int cnt = 0;
    for(auto n: nums) {
        if(cnt == 0) {
            inc[0] = n;
            cnt++;
        }
        else if(cnt == 1){
            if(n > inc[0]) {
                inc[1] = n;
                cnt++;
            }
            else
                inc[0] = n;
        }
        else if(cnt == 2) {
            int pos = 1;
            while(pos >= 0 && inc[pos] >= n)
                pos--;
            inc[pos + 1] = n;
            if(pos == 1)
                cnt++;
        }
        else
            return true;
    }
    return cnt >= 3;
}
