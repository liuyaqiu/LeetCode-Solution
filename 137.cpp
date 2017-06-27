#include <iostream>
#include <vector>

using namespace std;

int cfun(int c, int a, int r) {
    return ((~c) & (a & r)) | (c & (~(a ^ r)));
}

int afun(int c, int a, int r) {
    return ((~c) & (a ^ r)) | (c & (a & r));
}

int singleNumber(vector<int>& nums) {
    int res = 0;
    int c = 0;
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        int tmp_res = afun(c, *iter, res);
        int tmp_c = cfun(c, *iter, res);
        res = tmp_res;
        c = tmp_c;
        cout << res << " " << c << endl;
    }           
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums = vector<int>(3 * n + 1, 0);
    for(int i = 0; i < 3 * n + 1; i++) {
        cin >> nums[i];
    }
    cout << singleNumber(nums) << endl;
    return 0;
}
