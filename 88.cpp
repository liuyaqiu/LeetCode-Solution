#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pos1 = 0, pos2 = 0; 
    vector<int> tmp;
    while(pos1 < m && pos2 < n) {
        if(nums1[pos1] < nums2[pos2]) {
            tmp.push_back(nums1[pos1]);
            pos1 += 1;
        }
        else {
            tmp.push_back(nums2[pos2]);
            pos2 += 1;
        }
    }
    while(pos1 < m) {
        tmp.push_back(nums1[pos1]);
        pos1 += 1;
    }
    while(pos2 < n) {
        tmp.push_back(nums2[pos2]);
        pos2 += 1;
    }
    int pos = 0;
    while(pos < m + n) {
        nums1[pos] = tmp[pos];
        pos += 1;
    }
}
