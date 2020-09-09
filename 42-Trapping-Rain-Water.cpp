/*
 * Trapping Rain Water
 *
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 *
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int trap(vector<int>& height) {
    if(height.empty())
        return 0;
    vector<int> pos;
    pos.push_back(0);
    for(int i = 1; i < height.size(); i += 1) {
        if(height[i] >= height[pos.back()]) {
            pos.push_back(i);
        }
    }
    stack<int> tail;
    int t = height.size() - 1;
    if(t > pos.back())
        tail.push(t);
    for(int i = height.size() - 2; i > pos.back(); i -= 1) {
        if(height[i] >= height[tail.top()]) {
            tail.push(i);
        }
    }
    while(!tail.empty()) {
        pos.push_back(tail.top());
        tail.pop();
    }
    int res = 0;
    print(pos);
    for(auto iter = pos.begin(); iter != pos.end() - 1; ++iter) {
        for(int i = *iter + 1; i < *(iter + 1); i += 1) {
            res += min(height[*iter], height[*(iter + 1)]) - height[i];
        }
    }
    return res;
}


int main() {
    int n;
    cout << "Input the number of nums: ";
    cin >> n;
    cout << "Input the nums: ";
    int val;
    vector<int> nums;
    while(n > 0) {
        cin >> val;
        nums.push_back(val);
        n -= 1;
    }
    print(nums);
    int res = trap(nums);
    cout << "The result is: " << res << endl;
    return 0;
}
