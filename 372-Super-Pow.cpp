#include <iostream>
#include <vector>

using namespace std;

/*
 * Super Pow
 *
 * Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
 *
 * Example1:
 *
 * a = 2
 * b = [3]
 *
 * Result: 8
 * Example2:
 *
 * a = 2
 * b = [1,0]
 *
 * Result: 1024
 *
 *
 */

template <typename T> void print(vector<T>& res) {
    for(auto item: res)
        cout << item << " ";
    cout << endl;
}

vector<int> binary(vector<int>& digits) {
    int start = 0;
    int n = digits.size();
    vector<int> res;
    while(start < n) {
        int pos = start;
        while(pos < n) {
            if(pos + 1 < n)
                digits[pos + 1] += (digits[pos] % 2) * 10;
            else
                res.push_back(digits[pos] % 2);
            digits[pos] /= 2;
            pos++;
        }
        while(start < n && digits[start] == 0)
            start++;
    }
    return res;
}

int superPow(int a, vector<int>& b) {
    vector<int> bits = binary(b);
    int k = 1337;
    int m = a % k;
    vector<int> mods;
    while(mods.size() < bits.size()) {
        mods.push_back(m);
        m = (m * m) % k;
    }
    int res = 1;
    for(int i = 0; i < bits.size(); i++)
        if(bits[i] != 0)
            res = (res * mods[i]) % k;
    return res;
}

int modPow(int& a, int b, int k) {
    int res = 1;
    for(int i = 0; i < b; i++)
        res = (res * a) % k;
    int tmp = a;
    for(int i = 1; i < 10; i++)
        a = (a * tmp) % k;
    return res;
}

int superPow2(int a, vector<int>& b) {
    int k = 1337;
    int res = 1;
    a = a % k;
    for(int i = 0; i < b.size(); i++) {
        int tmp = modPow(a, b[b.size() - 1 - i], k);
        res = (res * tmp) % k;
    }
    return res;
}

int main() {
    int a;
    cin >> a;
    int val;
    vector<int> digits;
    while(cin >> val)
        digits.push_back(val);
    int res = superPow2(a, digits); 
    cout << res << endl;
    return 0;
}
