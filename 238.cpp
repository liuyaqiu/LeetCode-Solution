#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> output(n, 1);
    int product = 1;
    for(int i = n - 1; i >= 0; i--) {
        output[i] *= product;
        product *= nums[i];
    }
    product = 1;
    for(int i = 0; i < n; i++) {
        output[i] *= product;
        product *= nums[i];
    }
    return output;
}

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums;
    int val;
    while(cin >> val) {
        nums.push_back(val);
    }
    vector<int> res = productExceptSelf(nums);
    print(nums);
    print(res);
    return 0;
}
