#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Intersection of Two Arrays II
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 *
 * Note:
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order.
 * Follow up:
 * What if the given array is already sorted? How would you optimize your algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is better?
 * What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 *
 *
 */

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
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
            res.push_back(tmp);
            pos1++;
            pos2++;
        }
    }
    return res;
}
