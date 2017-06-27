#include <iostream>
#include <vector>

using namespace std;

void move(vector<int>& nums, int& start, int& end, int& r, bool& dir) {
    if(dir) {
        for(int i = 0; i < r; i++) {
            int tmp = nums[start + i];
            nums[start + i] = nums[end - r + 1 + i];
            nums[end - r + 1 + i] = tmp;
        }
        end -= r;
        dir = (r <= end - start + 1 - r);
        r = min(r, end - start + 1 - r);
    }
    else {
        for(int i = 0; i < r; i++) {
            int tmp = nums[end - r + 1 + i];
            nums[end - r + 1 + i] = nums[start + i];
            nums[start + i] = tmp;
        }
        start += r;
        dir = (r > end - start + 1 - r);
        r = min(r, end - start + 1 - r);
    }
}

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    if(k <= n / 2) {
        int r = k, start = 0, end = n - 1;
        bool dir = false;
        while(r > 0) {
            move(nums, start, end, r, dir);
        }
    }
    else {
        int r = n - k, start = 0, end = n - 1;
        bool dir = true;
        while(r > 0) {
            move(nums, start, end, r, dir);
        }
    }
}

int main() {
    int val;
    vector<int> nums;
    int k;
    cin >> k;
    while(cin >> val) {
        nums.push_back(val);
    }
    print(nums);
    rotate(nums, k);
    print(nums);
    return 0;
}
