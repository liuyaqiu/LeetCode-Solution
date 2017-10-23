/*
  564. Find the Closest Palindrome

  Given an integer n, find the closest integer (not including itself), which is a palindrome.

  The 'closest' is defined as absolute difference minimized between two integers.

  Example 1:
  Input: "123"
  Output: "121"
  Note:
  The input n is a positive integer represented by string, whose length will not exceed 18.
  If there is a tie, return the smaller one as answer.

 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string leftPalin(string num) {
    int k = num.length() / 2;
    string res = "";
    for(int i = 0; i < k; i++)
        res = res + num[i];
    if(num.length() % 2 != 0)
        res = res + num[k];
    for(int i = k - 1; i >= 0; i--)
        res = res + num[i];
    return res;
}

string rightPalin(string num) {
    int k = num.length() / 2;
    string res = "";
    for(int i = k; i < num.length(); i++)
        res = res + num[i];
    for(int i = 0; i < k; i++)
        res = num[num.length() - k + i] + res;
    return res;
}

string nearestPalindromic(string n) {
    if(n.length() == 1)
        return to_string(stoi(n) - 1);
    long long num = stoll(n);
    string a = leftPalin(n);
    string b = rightPalin(n);
    vector<long long> candidate;
    if(stoll(a) != num)
        candidate.push_back(stoll(a));
    if(stoll(b) != num)
        candidate.push_back(stoll(b));
    int k = n.length() / 2;
    if(n.length() % 2 != 0) {
        if(n[k] != '0') {
            string tmp1 = a;
            tmp1[k] = tmp1[k] - 1;
            string tmp2 = b;
            tmp2[k] = tmp2[k] - 1;
            candidate.push_back(stoll(tmp1));
            candidate.push_back(stoll(tmp2));
        }
        if(n[k] != '9') {
            string tmp1 = a;
            tmp1[k] = tmp1[k] + 1;
            string tmp2 = b;
            tmp2[k] = tmp2[k] + 1;
            candidate.push_back(stoll(tmp1));
            candidate.push_back(stoll(tmp2));
        }
    }
    else {
        if(n[k - 1] != '0') {
            string tmp1 = a;
            tmp1[k] = tmp1[k] - 1;
            tmp1[k - 1] = tmp1[k - 1] - 1;
            candidate.push_back(stoll(tmp1));
        }
        if(n[k] != '0') {
            string tmp2 = b;
            tmp2[k] = tmp2[k] - 1;
            tmp2[k - 1] = tmp2[k - 1] - 1;
            candidate.push_back(stoll(tmp2));
        }
        if(n[k - 1] != '9') {
            string tmp1 = a;
            tmp1[k] = tmp1[k] + 1;
            tmp1[k - 1] = tmp1[k - 1] + 1;
            candidate.push_back(stoll(tmp1));
        }
        if(n[k] != '9') {
            string tmp2 = b;
            tmp2[k] = tmp2[k] + 1;
            tmp2[k - 1] = tmp2[k - 1] + 1;
            candidate.push_back(stoll(tmp2));
        }
    }
    long long guess1 = pow(10, (long long)log10(num)) - 1;
    long long guess2 = pow(10, (long long)log10(num) + 1) + 1;
    candidate.push_back(guess1);
    candidate.push_back(guess2);
    long long res = 0;
    for(auto item: candidate) {
        if(res == 0)
            res = item;
        if(abs(item - num) <= abs(res - num)) {
            if(abs(item - num) < abs(res - num) || item < res)
                res = item;
        }
    }
    return to_string(res);
}

int main() {
    string num;
    cin >> num;
    string res = nearestPalindromic(num);
    cout << res << endl;
    return 0;
}
