#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int item = nums[0];
    int count = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(count == 0) {
            item = nums[i];
            count++;
        }
        else {
            if(nums[i] == item)
                count++;
            else
                count--;
        }
    }
    return item;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val) {
        nums.push_back(val);
    }
    int m = majorityElement(nums);
    cout << m << endl;
    return 0;
}
