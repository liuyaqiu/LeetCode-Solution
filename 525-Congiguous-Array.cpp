#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    vector<int> sums(n, 0);
    unordered_map<int, int> max_index;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] == 0)
            sum -= 1;
        else
            sum += 1;
        sums[i] = sum;
        if(max_index.find(sum) == max_index.end())
            max_index[sum] = i;
        else
            max_index[sum] = max(max_index[sum], i);
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(sums[i] == 0)
            res = max(res, i + 1);
        else
            res = max(res, max_index[sums[i]] - i);
    }
    return res;
}
