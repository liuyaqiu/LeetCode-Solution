#include <iostream>
#include <vector>

using namespace std;

/*
 * Find All Numbers Disappeared in an Array
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 *
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 *
 * Example:
 *
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [5,6]
 *
 *
 */

/*
 * 这道题是典型的坐标序列，可以通过置换法在O(n)时间复杂度内，使得所有坐标归位
 */

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int pos = 0;
    int n = nums.size();
    while(pos < n) {
        while(nums[pos] != pos + 1) {
            int next = nums[pos] - 1;
            if(nums[pos] == nums[next])
                break;
            else
                swap(nums[pos], nums[next]);
        }
        pos++;
    }
    vector<int> res;
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
        if(nums[i] != i + 1)
            res.push_back(i + 1);
    }
    cout << endl;
    return res;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    vector<int> res = findDisappearedNumbers(nums);
    for(auto r: res)
        cout << r << " ";
    cout << endl;
    return 0;
}
