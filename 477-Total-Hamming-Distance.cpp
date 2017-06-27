#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> mypair;

int totalHammingDistance(vector<int>& nums) {
    vector<mypair> digit(32, mypair(0, 0));
    for(int i = 0; i < nums.size(); i++) {
        int val = nums[i];
        int pos = 0;
        while(val > 0) {
            if((val & 1) == 0)
                digit[pos].first += 1; 
            else
                digit[pos].second += 1;
            val >>= 1;
            pos++;
        }
        while(pos < 32) {
            digit[pos].first += 1;
            pos++;
        }
    }
    int res = 0;
    for(int i = 0; i < 32; i++) {
        res += digit[i].first * digit[i].second;
    }
    return res;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    int res = totalHammingDistance(nums);
    cout << res << endl;
    return 0;
}
