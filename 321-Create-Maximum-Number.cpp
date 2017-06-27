#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getMax(vector<int>& nums, int t) {
    vector<int> res;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        while(!res.empty() && res.back() < nums[i] && res.size() + n - i > t)
            res.pop_back();
        if(res.size() < t)
            res.push_back(nums[i]);
    }
    return res;
}

vector<int> merge(vector<int> nums1, vector<int> nums2) {
    vector<int> res;
    int i = 0, j = 0;
    while(i < nums1.size() && j < nums2.size()) {
        if(nums1[i] > nums2[j]) {
            res.push_back(nums1[i]);
            i++;
        }
        else {
            res.push_back(nums2[j]);
            j++;
        }
    }
    while(i < nums1.size()) {
        res.push_back(nums1[i]);
        i++;
    }
    while(j < nums2.size()) {
        res.push_back(nums2[j]);
        j++;
    }
    return res;
}

bool comp(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() != nums2.size())
        return false;
    for(int i = 0; i < nums1.size(); i++) {
        if(nums1[i] > nums2[i])
            return true;
        else if(nums1[i] < nums2[i])
            return false;
    }
    return true;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> res;
    int len1 = nums1.size(), len2 = nums2.size();
    for(int i = max(0, k - len2); i <= min(k, len1); i++) {
        vector<int> tmp = merge(getMax(nums1, i), getMax(nums2, k - i));
        if(comp(tmp, res))
            res = tmp;
    }
    return res;
}

int main() {
	vector<int> nums1 = {6, 6, 7, 0, 4};
	vector<int> nums2 = {6, 7, 6, 0, 4};
	cout << comp(nums1, nums2) << endl;
	cout << comp(nums2, nums1) << endl;
	return 0;
}