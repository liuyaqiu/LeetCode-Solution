#include <iostream>
#include <vector>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    int pivot = nums[(nums.size() - 1) / 2];
    vector<int> nums1, nums2;
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        if(*iter < pivot)
            nums1.push_back(*iter);
        else if(*iter > pivot)
            nums2.push_back(*iter);
    }
    if(k <= nums2.size())
        return findKthLargest(nums2, k);
    else if(k > nums.size() - nums1.size())
        return findKthLargest(nums1, k - nums.size() + nums1.size());
    else
        return pivot;
}

int main() {
    int val;
    vector<int> nums;
    int k;
    cin >> k;
    while(cin >> val) {
        nums.push_back(val);
    }
    int res = findKthLargest(nums, k);
    cout << res << endl;
    return 0;
}
