/*
Next Greater Element III

Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21
Example 2:
Input: 21
Output: -1

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define inf numeric_limits<int>::max()

int nextGreaterElement(int m) {
    string num = to_string(m);
    int n = num.length();
    vector<int> digits;
    for(int i = 0; i < n; i++)
        digits.push_back(num[i] - '0');
    int pos = n - 1;
    while(pos > 0 && digits[pos] <= digits[pos - 1]) {
        pos--;
    }
    if(pos == 0)
        return -1;
    int right = n - 1;
    long long val = -1;
    while(right >= pos) {
        int left = pos - 1;
        while(left >= 0 && digits[left] >= digits[right])
            left--;
        if(left >= 0) {
            vector<int> tmp(digits);
            swap(tmp[left], tmp[right]);
            sort(tmp.begin() + left + 1, tmp.end());
		    string res = "";
		    for(int i = 0; i < n; i++) {
		        res += '0' + tmp[i];
		    }
            long long tmp_val = stoll(res);
            if(tmp_val > inf)
                tmp_val = -1;
            if(val < 0 || val > tmp_val)
                val = tmp_val;
        }
        right--;
    }
    return val;
}

int main() {
    int n;
    cin >> n;
    int res = nextGreaterElement(n);
    cout << res << endl;
    return 0;
}

