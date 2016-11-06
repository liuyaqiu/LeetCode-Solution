#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

void  getCurRes(vector<int>& nums, map<vector<int>, int> &res, int pos) {
    int start = 0;
    int end = nums.size() - 1;
    int sum = -nums[pos];
    while(start < pos && pos < end) {
        int tmp = nums[start] + nums[end];
        if(tmp == sum) {
            if(start != pos && end != pos) {
                int array[] = {nums[start], nums[end], nums[pos]};
                vector<int> cur(array, array + 3);
                sort(cur.begin(), cur.end());
                if(res.find(cur) == res.end())
                	res.insert(pair<vector<int>, int>(cur, 0));
            }
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

vector<vector<int>> threeSum(vector<int> &nums) {
    map<vector<int>, int> res;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i += 1) {
        getCurRes(nums, res, i);
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
    int array[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    vector<vector<int>> res = threeSum(nums);
    printVector(res);
    return 0;
}
