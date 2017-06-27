#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string getRange(vector<int>& nums, int start, int end) {
    stringstream ss;
    ss << nums[start] << " " << nums[end - 1];
    string a, b;
    ss >> a >> b;
    if(end == start + 1)
        return a;
    else
        return a + "->" + b;
}

vector<string> summaryRanges(vector<int>& nums) {
    int start = 0;
    int end = start + 1;
    vector<string> res;
    while(start < nums.size()) {
        while(end < nums.size() && nums[end] == nums[end - 1] + 1)
            end++;
        string tmp = getRange(nums, start, end);
        res.push_back(tmp);
        start = end;
        end = start + 1;
    }
    return res;
}

void print(vector<string>& ranges) {
    for(auto iter = ranges.begin(); iter != ranges.end(); iter++)
        cout << *iter << endl;
    cout << endl;
}
int main() {
    int val;
    vector<int> nums;
    while(cin >> val) {
        nums.push_back(val);
    }
    vector<string> res = summaryRanges(nums);
    print(res);
    return 0;
}
