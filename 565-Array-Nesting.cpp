/*
  Array Nesting

  A zero-indexed array A consisting of N different integers is given. The array contains all integers in the range [0, N - 1].

  Sets S[K] for 0 <= K < N are defined as follows:

  S[K] = { A[K], A[A[K]], A[A[A[K]]], ... }.

  Sets S[K] are finite for each K and should NOT contain duplicates.

  Write a function that given an array A consisting of N integers, return the size of the largest set S[K] for this array.

  Example 1:
  Input: A = [5,4,0,3,1,6,2]
  Output: 4
  Explanation: 
  A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

  One of the longest S[K]:
  S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
  Note:
  N is an integer within the range [1, 20,000].
  The elements of A are all distinct.
  Each element of array A is an integer within the range [0, N-1].

 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int arrayNesting(vector<int>& nums) {
    int n = nums.size();
    vector<bool> cnt(n, false);
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(!cnt[i]) {
            int count = 1;
            cnt[i] = true;
            int j = nums[i];
            while(!cnt[j]) {
                count++;
                cnt[j] = true;
                j = nums[j];
            }
            res = max(res, count);
        }
    }
    return res;
}

int main() {
    vector<int> nums;
    int val;
    cout << "Input nums: " << endl;
    while(cin >> val) {
        nums.push_back(val);
    }
    int res = arrayNesting(nums);
    cout << "Result is: " << res << endl;
    return 0;
}
