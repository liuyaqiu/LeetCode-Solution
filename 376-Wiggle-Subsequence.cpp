#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Wiggle Subsequence
 *
 * A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.
 *
 * For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.
 *
 * Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.
 *
 * Examples:
 * Input: [1,7,4,9,2,5]
 * Output: 6
 * The entire sequence is a wiggle sequence.
 *
 * Input: [1,17,5,10,13,15,10,5,16,8]
 * Output: 7
 * There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
 *
 * Input: [1,2,3,4,5,6,7,8,9]
 * Output: 2
 *
 *
 */

int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    vector<vector<vector<int>>> res(n, vector<vector<int>>(2, vector<int>()));
    //res[i][0]表示上一次为增，res[i][1]表示上一次为减
    for(int i = 0; i < n; i++) {
        vector<int> up;
        vector<int> down;
        for(int j = i - 1; j >= 0; j--) {
            if(nums[i] > nums[j] && up.size() < res[j][1].size())
                up = res[j][1];
            if(nums[i] < nums[j] && down.size() < res[j][0].size())
                down = res[j][0];
        }
        up.push_back(nums[i]);
        down.push_back(nums[i]);
        res[i][0] = up;
        res[i][1] = down;
    }
    int maxi = 0;
    for(auto cur: res)
        maxi = max(maxi, int(max(cur[0].size(), cur[1].size())));
    return maxi;
}

int wiggleMaxLength2(vector<int>& nums) {
    bool up = true;
    int res = 1;
    int n = nums.size();
    int pos = 0;
    int val = nums[pos];
    while(pos < n && nums[pos] == val)
        pos++;
    if(pos < n)
        up = nums[pos] > val;
    else
        return res;
    while(pos < n) {
        res += 1;
        pos++;
        while(pos < n) {
            if(nums[pos] != nums[pos - 1]) {
                if(up ^ (nums[pos] > nums[pos - 1])) {
                    up = !up;
                    break;
                }
            }
            pos++;
        }
    }
    return res;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    int res = wiggleMaxLength2(nums);
    cout << res << endl;
    return 0;
}
