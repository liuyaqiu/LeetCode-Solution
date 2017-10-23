/*
  Strange Printer

  There is a strange printer with the following two special requirements:

  The printer can only print a sequence of the same character each time.
  At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.
  Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.

  Example 1:
  Input: "aaabbb"
  Output: 2
  Explanation: Print "aaa" first and then print "bbb".
  Example 2:
  Input: "aba"
  Output: 2
  Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing

  Length of the given string will not exceed 100.
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int dfs(const string& s, vector<vector<int>>& res, int l, int r) {
    if(l > r)
        return 0;
    if(res[l][r] != -1)
        return res[l][r];
    res[l][r] = dfs(s, res, l, r - 1) + 1;
    for(int i = l; i < r; i++) {
        if(s[i] == s[r])
            res[l][r] = min(res[l][r], dfs(s, res, l, i) + dfs(s, res, i + 1, r - 1));
    }
    return res[l][r];
}

int strangePrinter(string s) {
    int n = s.length();
    vector<vector<int>> res(n, vector<int>(n, -1));
    return dfs(s, res, 0, n - 1);
}
