#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

vector<int> reverse(vector<int>& nums) {
    vector<int> rev;
    for(auto iter = nums.rbegin(); iter != nums.rend(); iter++)
        rev.push_back(*iter);
    return rev;
}

void clear(vector<int>& nums) {
    int start = 0;
    int end = start;
    while(start < nums.size()) {
        while(start < nums.size() && nums[start] > 0) {
            start++;
        }
        if(start >= nums.size() || nums[start] == 0) {
            start++;
            continue;
        }
        end = start + 1;
        while(end < nums.size() && nums[end] > 0) {
            end++;
        }
        if(end >= nums.size() || nums[end] == 0) {
            start = end + 1;
            continue;
        }
        nums[start] *= -1;
        nums[end] *= -1;
        start = end + 1;
    }
}

int direction(vector<int>& nums) {
    int max = 0;
    int start = 0;
    int end = start + 1;
    while(start < nums.size()) {
        int cur = 1;
        while(start < nums.size() && nums[start] <= 0) {
            start++;
        }
        end = start;
        while(end < nums.size() && nums[end] > 0) {
            cur *= nums[end];
            end++;
        }
        if(cur > max)
            max = cur;
        start = end;
    }
    int tmp = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > tmp)
            tmp = nums[i];
    }
    if(tmp <= 0)
        return tmp;
    else
        return max;
}

int maxProduct(vector<int>& nums) {
    vector<int> rev = reverse(nums);
    clear(nums);
    clear(rev);
    int max1 = direction(nums);
    int max2 = direction(rev);
    return max(max1, max2);
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val) {
        nums.push_back(val);
    }
    int res = maxProduct(nums);
    cout << res << endl;
    return 0;
}
