#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

double median(multiset<int>& nums) {
    int len = nums.size();
    int i = len / 2;
    if(len % 2 == 0) {
        long m1 = *next(nums.begin(), i - 1);
        long m2 = *next(nums.begin(), i);
        return (m1 + m2) / 2.0;
    }
    else
        return *next(nums.begin(), i);
}

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    multiset<int> dict(nums.begin(), nums.begin() + k);
    vector<double> res{median(dict)};
    for(int i = k; i < nums.size(); i++) {
        auto iter = dict.find(nums[i - k]);
        dict.erase(iter);
        dict.insert(nums[i]);
        res.push_back(median(dict));
    }
    return res;
}

int main() {
    int k;
    cin >> k;
    int val;
    vector<int> nums;
    while(cin >> val) {
        nums.push_back(val);
    }
    vector<double> res = medianSlidingWindow(nums, k);
    for(auto item: res)
        cout << item << " ";
    cout << endl;
    return 0;
}
