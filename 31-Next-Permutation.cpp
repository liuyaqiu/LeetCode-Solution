/*
 * Next Permutation
 *
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void swapPos(vector<int>& nums, int& posA, int& posB) {
	int right = nums.size() - 1;
	while(right > 0) {
		int left = right - 1;
		while(left >= 0) {
			if(nums[left] < nums[right]) {
				if(left > posA) {
					posA = left;
					posB = right;
				}
				else if(left == posA) {
					if(nums[right] < nums[posB])
						posB = right;
				}
				break;
			}
			left -= 1;
		}
		right -= 1; 
	}
}

void nextPermutation(vector<int>& nums) {
	int posA = -1;
	int posB = -1;
	swapPos(nums, posA, posB);
	if(posA >= 0)
		swap(nums[posA], nums[posB]);
	sort(nums.begin() + posA + 1, nums.end());
}

void print(vector<int>& res) {
    for(auto iter = res.begin(); iter != res.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

int main() {
    vector<int> a = {3, 2, 1};
    vector<int> b = {1, 2, 3};
    vector<int> c = {1, 1, 5};
    vector<int> d = {5, 4, 7, 5, 3, 2};
    vector<int> e = {2, 3, 1};
    vector<int> f = {4,2,0,2,3,2,0};
    vector<int> g = {1, 3, 2};
    vector<int> res = g;
    print(res);
    nextPermutation(res);
    print(res);
    return 0;
}
