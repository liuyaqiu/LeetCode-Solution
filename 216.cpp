#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void print(vector<vector<int>>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++)
            cout << *iter2 << " ";
        cout << endl;
    }
}

void printArray(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> nums;
    int sum = 0;
    for(int i = 0; i < k; i++) {
        nums.push_back(i + 1);
        sum += i + 1;
    }
    vector<vector<int>> res;
    int p = k - 1;
    while(true) {
        printArray(nums);
        if(sum == n)
            res.push_back(nums);
        if(nums[p] < 9 - (k - 1 - p)) {
            nums[p] += 1;
            sum += 1;
        }
        else {
            while(p >= 0 && nums[p] >= 9 - (k - 1 - p)) {
                p--;
            }
            if(p < 0)
                break;
            else {
                nums[p] += 1;
                sum += 1;
                while(p < k - 1) {
                    sum -= (nums[p + 1] - nums[p] - 1);
                    nums[p + 1] = nums[p] + 1;
                    p++;
                }
                continue;
            }
        }
    }
    return res;
}

int main() {
    int k;
    int n;
    cin >> k >> n;
    vector<vector<int>> res = combinationSum3(k, n);
    cout << endl;
    print(res);
    return 0;
}
