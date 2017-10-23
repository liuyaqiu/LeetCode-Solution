/*
  Non-negative Integers without Consecutive Ones

  Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary representations do NOT contain consecutive ones.

  Example 1:
  Input: 5
  Output: 5
  Explanation:
  Here are the non-negative integers <= 5 with their corresponding binary representations:
  0 : 0
  1 : 1
  2 : 10
  3 : 11
  4 : 100
  5 : 101
  Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule.
  Note: 1 <= n <= 109

 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> count(int n) {
    int k = ceil(log2(n));
    vector<int> cnt(k + 1, 0);
    cnt[0] = 1;
    cnt[1] = 1;
    int sums = cnt[0] + cnt[1];
    for(int i = 2; i <= k; i++) {
        cnt[i] = sums - cnt[i - 1];
        sums += cnt[i];
    }
    vector<int> res(k + 1, 0);
    res[1] = 2;
    sums = res[1];
    for(int i = 2; i <= k; i++) {
        sums += cnt[i];
        res[i] = sums;
    }
    return res;
}

int resolve(int n, vector<int>& res) {
    if(n <= 2)
        return n + 1;
    int k = ceil(log2(n));
    if(pow(2, k) == n + 1)
        return res[k];
    else if(pow(2, k) == n)
        return res[k] + 1;
    else {
        int m = n % (int)pow(2, k - 1);
        if(m >= pow(2, k - 2))
            return res[k - 1] + res[k - 2];
        else
            return res[k - 1] + resolve(m, res);
    }
}


int findIntegers(int num) {
    vector<int> cnt = count(num);
    return resolve(num, cnt);
}
