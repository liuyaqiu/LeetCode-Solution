/*
  Decode Ways II

  A message containing letters from A-Z is being encoded to numbers using the following mapping way:

  'A' -> 1
  'B' -> 2
  ...
  'Z' -> 26
  Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

  Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

  Also, since the answer may be very large, you should return the output mod 109 + 7.

  Example 1:
  Input: "*"
  Output: 9
  Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
  Example 2:
  Input: "1*"
  Output: 9 + 9 = 18
  Note:
  The length of the input string will fit in range [1, 105].
  The input string will only contain the character '*' and digits '0' - '9'.

 */

#include <iostream>
#include <vector>

using namespace std;

int fun(string s) {
    if(s.length() == 1) {
        if(s[0] == '*')
            return 9;
        else
            return s[0] == '0' ? 0 : 1;
    }
    if(s == "**")
        return 15;
    else if(s[1] == '*') {
        if(s[0] == '1')
            return 9;
        else
            return s[0] == '2' ? 6 : 0;
    }
    else if(s[0] == '*')
        return s[1] <= '6' ? 2 : 1;
    else
        return stoi(s) >= 10 && stoi(s) <= 26 ? 1 : 0;
}

int numDecodings(string s) {
    int n = s.length(), mod = 1000000007;
    long long f1 = 1, f2 = fun(s.substr(0, 1));
    for(int i = 1; i < n; i++) {
        long long f3 = (f2 * fun(s.substr(i, 1)) + f1 * fun(s.substr(i - 1, 2)));
        f1 = f2;
        f2 = f3 % mod;
    }
    return f2;
}
