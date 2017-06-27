#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool cmp(const string s1, const string s2) {
	if(s1.empty())
		return true;
	if(s2.empty())
		return false;
    int i = 0;
    while(i < s1.length() && i < s2.length()) {
        if(s1[i] < s2[i])
            return true;
        else if(s1[i] > s2[i])
            return false;
        else
            i++;
    }
    if(i < s1.length()) {
        int n = s2.length();
        while(i + n <= s1.length() && s1.substr(i, n) == s2) {
            i += n;
        }
        return cmp(s1.substr(i, s1.length() - i), s2);
    }
    if(i < s2.length()) {
        int n = s1.length();
        while(i + n <= s2.length() && s2.substr(i, n) == s1) {
            i += n;
        }
        return cmp(s1, s2.substr(i, s2.length() - i));
    }
    return false;
}

string largestNumber(vector<int>& nums) {
    vector<string> tmp;
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        stringstream ss;
        ss << *iter;
        string cur;
        ss >> cur;
        tmp.push_back(cur);
    }
    sort(tmp.begin(), tmp.end(), cmp);
    string res = "";
    for(auto iter = tmp.begin(); iter != tmp.end(); iter++) {
        res = *iter + res;
    }
    if(res[0] == '0')
        res = "0";
    return res;
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val) {
        nums.push_back(val);
    }
    string res = largestNumber(nums);
    cout << res << endl;
    return 0;
}

