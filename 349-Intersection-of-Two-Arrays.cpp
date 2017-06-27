#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Intersection of Two Arrays
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 *
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 *
 *
 */

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int pos1 = 0;
    int pos2 = 0;
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> res;
    while(pos1 < n1 && pos2 < n2) {
        while(pos2 < n2 && nums2[pos2] < nums1[pos1])
            pos2++;
        while(pos1 < n1 && nums1[pos1] < nums2[pos2])
            pos1++;
        if(pos1 < n1 && pos2 < n2 && nums1[pos1] == nums2[pos2]) {
            int tmp = nums1[pos1];
            if(res.empty() || tmp > res.back())
                res.push_back(tmp);
            pos1++;
            pos2++;
        }
    }
    return res;
}
