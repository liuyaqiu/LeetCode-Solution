#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(vector<int>& sideLength, const vector<int>& matches, int index, const int target) {
    if(index == matches.size())
        return sideLength[0] == sideLength[1] && sideLength[1] == sideLength[2] && sideLength[2] == sideLength[3];
    for(int i = 0; i < 4; i++) {
        if(sideLength[i] + matches[index] > target)
            continue;
        int j = i;
        while(--j >= 0) {
            if(sideLength[i] == sideLength[j])
                break;
        }
        if(j != -1)
            continue;
        sideLength[i] += matches[index];
        if(dfs(sideLength, matches, index + 1, target))
            return true;
        sideLength[i] -= matches[index];
   }
    return false;
}

bool makesquare(vector<int>& nums) {
    if(nums.size() < 4)
        return false;
    int sum = 0;
    for(const int val: nums) {
        sum += val;
    }
    if(sum % 4 != 0)
        return false;
    int target = sum / 4;
    for(const int val: nums) {
        if(val > target)
            return false;
    }
    sort(nums.begin(), nums.end(), greater<int>());
    vector<int> sideLength(4, 0);
    return dfs(sideLength, nums, 0, target);
}
