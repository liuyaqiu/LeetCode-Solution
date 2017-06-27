#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
 * Minimum Moves to Equal Array Elements II
 *
 * Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
 *
 * You may assume the array's length is at most 10,000.
 *
 * Example:
 *
 * Input:
 * [1,2,3]
 *
 * Output:
 * 2
 *
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one element):
 *
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 *
 *
 */

int minMoves2(vector<int>& nums) {
    map<int, int> cnt;
    for(auto num: nums) {
        if(cnt.find(num) == cnt.end())
            cnt[num] = 1;
        else
            cnt[num] += 1;
    }
    vector<int> number;
    vector<int> times;
    for(auto item: cnt) {
        number.push_back(item.first);
        times.push_back(item.second);
    }
    if(number.size() <= 1)
        return 0;
    int cof = 0;
    for(int i = 0; i < number.size(); i++)
        cof -= times[i];
    int pos = 0;
    while(pos < times.size() && cof < 0) {
        cof += 2 * times[pos];
        pos++;
    }
    int res = 0;
    for(int i = 0; i < number.size(); i++)
        res += times[i] * abs(number[i] - number[pos - 1]);
    return res;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    int res = minMoves2(nums);
    cout << res << endl;
    return 0;
}
