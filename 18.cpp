#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

void  getCurRes(vector<int>& nums, map<vector<int>, int> &res, int pos1, int pos2, int target) {
    int start = 0;
    int end = nums.size() - 1;
    int sum = target - nums[pos1] - nums[pos2];
    while(start < pos1 && pos2 < end) {
        int tmp = nums[start] + nums[end];
        if(tmp == sum) {
            int array[] = {nums[start], nums[end], nums[pos1], nums[pos2]};
            vector<int> cur(array, array + sizeof(array) / sizeof(int));
            sort(cur.begin(), cur.end());
            if(res.find(cur) == res.end())
                res.insert(pair<vector<int>, int>(cur, 0));
            int s_val = nums[start];
            while(start < end && nums[start] == s_val)
                start += 1;
            int e_val = nums[end];
            while(start < end && nums[end] == e_val)
                end -= 1;
        }
        else if(tmp < sum) {
            int s_val = nums[start];
            while(start < end && nums[start] == s_val)
                start += 1;
        }
        else {
            int e_val = nums[end];
            while(start < end && nums[end] == e_val)
                end -= 1;
        }
    }
}

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    map<vector<int>, int> res;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i += 1) {
        for(int j = i + 1; j < nums.size(); j += 1) {
            getCurRes(nums, res, i, j, target);
        }
    }
    vector<vector<int>> theRes;
    for(auto iter = res.begin(); iter != res.end(); ++iter) {
    	theRes.push_back(iter->first);
    }
    return theRes;
} 

void printVector(vector<vector<int>> res) {
    for(int i = 0; i < res.size(); i += 1) {
        for(int j = 0; j < res[i].size(); j += 1) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int array[] = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    vector<vector<int>> res = fourSum(nums, target);
    printVector(res);
    return 0;
}
