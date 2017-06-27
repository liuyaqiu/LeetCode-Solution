#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

/*
 * Frog Jump
 *
 * A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
 *
 * Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.
 *
 * If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.
 *
 * Note:
 *
 * The number of stones is ≥ 2 and is < 1,100.
 * Each stone's position will be a non-negative integer < 231.
 * The first stone's position is always 0.
 * Example 1:
 *
 * [0,1,3,5,6,8,12,17]
 *
 * There are a total of 8 stones.
 * The first stone at the 0th unit, second stone at the 1st unit,
 * third stone at the 3rd unit, and so on...
 * The last stone at the 17th unit.
 *
 * Return true. The frog can jump to the last stone by jumping 
 * 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
 * 2 units to the 4th stone, then 3 units to the 6th stone, 
 * 4 units to the 7th stone, and 5 units to the 8th stone.
 * Example 2:
 *
 * [0,1,2,3,4,8,9,11]
 *
 * Return false. There is no way to jump to the last stone as 
 * the gap between the 5th and 6th stone is too large.
 *
 *
 */

typedef pair<int, int> mypair;

void print(vector<vector<bool>>& matrix) {
    for(auto row: matrix) {
        for(auto item: row) {
            cout << item << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void eval(vector<int>& nums, unordered_map<int, int>& index, vector<vector<bool>>& dp, int i, int j) {
    auto i1 = index.find(nums[i] - (j - 1));
    if(i1 != index.end())
        dp[i][j] = (dp[i][j] || dp[i1->second][j - 1]);
    auto i2 = index.find(nums[i] - j);
    if(i2 != index.end())
        dp[i][j] = (dp[i][j] || dp[i2->second][j]);
    auto i3 = index.find(nums[i] - (j + 1));
    if(i3 != index.end())
        dp[i][j] = (dp[i][j] || dp[i3->second][j + 1]);
}

bool canCross(vector<int>& stones) {
    int n = stones.size();
    if(stones.back() > n * (n - 1) / 2)
        return false;
    unordered_map<int, int> index;
    for(int i = 0; i < n; i++)
        index[stones[i]] = i;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    dp[0][1] = true;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            eval(stones, index, dp, i, j);
        }
    }
    for(int i = 1; i < n; i++)
        if(dp[n - 1][i])
            return true;
    return false;
}

bool canCross2(vector<int>& stones) {
    int n = stones.size();
    if(stones.back() > n * (n - 1) / 2)
        return false;
    unordered_set<int> dict(stones.begin(), stones.end());
    queue<mypair> que;
    que.push(mypair(0, 0));
    set<mypair> visit;
    while(!que.empty()) {
        int pos = que.front().first;
        int delta = que.front().second;
        if(pos == stones.back())
            return true;
        for(int i = -1; i <= 1; i++) {
            int next_pos = pos + delta + i;
            if(delta + i > 0 && next_pos <= stones.back()) {
                mypair cur = mypair(next_pos, delta + i);
                if(dict.find(next_pos) != dict.end() && visit.find(cur) == visit.end()) {
                    que.push(cur);
                    visit.insert(cur);
                }
            } 
        }
        que.pop();
    }
    return false;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    int res = canCross(nums);
    cout << res << endl;
    return 0;
}
