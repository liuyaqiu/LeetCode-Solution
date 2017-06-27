#include <iostream>
#include <vector>

using namespace std;

/*
 * Single Number III
 *
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
 *
 * For example:
 *
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 *
 * Note:
 * The order of the result is not important. So in the above example, [5, 3] is also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 *
 *
 */

int kdigit(int num, int k) {
    return (num >> k) % 2;
}

int getK(int num) {
    int k = 0;
    while(num % 2 == 0) {
        num = num / 2;
        k += 1;
    }
    return k;
}

vector<int> singleNumber(vector<int>& nums) {
    int xsum = 0;
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        xsum = xsum ^ *iter;
    }
    int k = getK(xsum);
    int a = 0;
    int b = 0;
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        if(kdigit(*iter, k) == 0)
            a = a ^ *iter;
        else
            b = b ^ *iter;
    }
    cout << a << " " << b << endl;
    vector<int> res = {a, b};
    return res;
}

int main() {
    vector<int> nums;
    int val;
    while(cin >> val) {
        nums.push_back(val);
    }
    singleNumber(nums);
    return 0;
}
