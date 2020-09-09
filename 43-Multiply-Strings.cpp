/*
 * Multiply Strings
 *
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
 *
 * Note:
 *
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

int digitAdd(int& a,  int b) {
    int add = a + b;
    a = add % 10;
    return add / 10;
}  

void numAdd(vector<int>& a, vector<int>& b) {
    int i = 0;
    int a_last = a.size() - 1;
    int b_last = b.size() - 1;
    while(i <= b_last) {
        int carry = digitAdd(a[a_last - i], b[b_last - i]);
        int pos = a_last - i - 1;
        while(carry > 0) {
            carry = digitAdd(a[pos], carry);
            pos -= 1;
        }
        i += 1;
    }
}

void numMulti(vector<int> a, int b, int k, vector<int>& res) {
    for(auto iter = a.begin(); iter != a.end(); ++iter) {
        *iter *= b;
    }
    while(k > 0) {
        a.push_back(0);
        k -= 1;
    }
    numAdd(res, a);
}

vector<int> pre_multiply(vector<int>& a, vector<int>& b) {
    int k = 0;
    int b_last = b.size() - 1;
    vector<int> res(a.size() + b.size(), 0);
    while(k <= b_last) {
        numMulti(a, b[b_last - k], k, res);
        k += 1;
    }
    return res;
}

vector<int> getDigits(string s) {
    vector<int> digits;
    for(auto iter = s.begin(); iter != s.end(); ++iter)
        digits.push_back(*iter - '0');
    return digits;
}

string getString(vector<int> nums) {
    string res;
    auto iter = nums.begin();
    while(iter != nums.end() && *iter == 0)
        iter += 1;
    while(iter != nums.end()) {
        res += *iter + '0';
        iter += 1;
    }
    if(res.empty())
    	return "0";
    else
    	return res;
}

string multiply(string s1, string s2) {
	vector<int> a = getDigits(s1);
	vector<int> b = getDigits(s2);
	return getString(pre_multiply(a, b));
}

int main() {
    string s1, s2;
    cout << "Please input s1, s2: ";
    cin >> s1 >> s2;
    string s = multiply(s1, s2);
    cout << s << endl;;
    return 0;
}
