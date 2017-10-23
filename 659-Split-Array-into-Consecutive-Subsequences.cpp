/*
  Split Array into Consecutive Subsequences

  You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

  Example 1:
  Input: [1,2,3,3,4,5]
  Output: True
  Explanation:
  You can split them into two consecutive subsequences : 
  1, 2, 3
  3, 4, 5
  Example 2:
  Input: [1,2,3,3,4,4,5,5]
  Output: True
  Explanation:
  You can split them into two consecutive subsequences : 
  1, 2, 3, 4, 5
  3, 4, 5
  Example 3:
  Input: [1,2,3,4,4,5]
  Output: False

 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

bool isPossibleAnother(vector<int>& nums) {
    //this is a deform of this problem, not the consecutive sequence but the ascending sequence
    map<int, int> cnt;
    for(auto num: nums) {
        if(cnt.find(num) != cnt.end())
            cnt[num] += 1;
        else
            cnt[num] = 1;
    }
    map<int, int> tail;
    for(int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if(cnt.find(num) == cnt.end())
            continue;
        cnt[num] -= 1;
        if(cnt[num] == 0)
            cnt.erase(num);
        if(tail.empty() || tail.lower_bound(num) == tail.begin()) {
            auto iter1 = cnt.upper_bound(num);
            if(iter1 == cnt.end())
                return false;
            auto iter2 = cnt.upper_bound(iter1->first);
            if(iter2 == cnt.end())
                return false;
            iter1->second -= 1;
            if(iter1->second == 0)
                cnt.erase(iter1);
            iter2->second -= 1;
            if(iter2->second == 0)
                cnt.erase(iter2);
            if(tail.find(num) != tail.end())
                tail[num] += 1;
            else
                tail[num] = 1;
        }
        else {
            auto iter = tail.lower_bound(num);
            advance(iter, -1);
            iter->second -= 1;
            if(iter->second == 0)
                tail.erase(iter);
            if(tail.find(num) != tail.end())
                tail[num] += 1;
            else
                tail[num] = 1;
        }
    }
    return true;
}

bool isPossible(vector<int>& nums) {
    map<int, int> cnt;
    for(auto num: nums) {
        if(cnt.find(num) != cnt.end())
            cnt[num] += 1;
        else
            cnt[num] = 1;
    }
    map<int, int> tail;
    for(int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if(cnt.find(num) == cnt.end())
            continue;
        cnt[num] -= 1;
        if(cnt[num] == 0)
            cnt.erase(num);
        if(tail.empty() || tail.find(num - 1) == tail.end()) {
            auto iter1 = cnt.find(num + 1);
            if(iter1 == cnt.end())
                return false;
            auto iter2 = cnt.find(num + 2);
            if(iter2 == cnt.end())
                return false;
            iter1->second -= 1;
            if(iter1->second == 0)
                cnt.erase(iter1);
            iter2->second -= 1;
            if(iter2->second == 0)
                cnt.erase(iter2);
            if(tail.find(num + 2) != tail.end())
                tail[num + 2] += 1;
            else
                tail[num + 2] = 1;
        }
        else {
            auto iter = tail.find(num - 1);
            iter->second -= 1;
            if(iter->second == 0)
                tail.erase(iter);
            if(tail.find(num) != tail.end())
                tail[num] += 1;
            else
                tail[num] = 1;
        }
    }
    return true;
}

int main() {
    vector<int> nums;
    int val;
    while(cin >> val) {
        nums.push_back(val);
    }
    bool res = isPossible(nums);
    if(res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
