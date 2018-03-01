/*
  Special Binary String

  Special binary strings are binary strings with the following two properties:

  The number of 0's is equal to the number of 1's.
  Every prefix of the binary string has at least as many 1's as 0's.
  Given a special string S, a move consists of choosing two consecutive, non-empty, special substrings of S, and swapping them. (Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.)

  At the end of any number of moves, what is the lexicographically largest resulting string possible?

  Example 1:
  Input: S = "11011000"
  Output: "11100100"
  Explanation:
  The strings "10" [occuring at S[1]] and "1100" [at S[3]] are swapped.
  This is the lexicographically largest string possible after some number of swaps.
  Note:

  S has length at most 50.
  S is guaranteed to be a special binary string as defined above.

 */

#include <iostream>
#include <vector>
#include <string>
#include <numeric_limits>

using namespace std;

#define inf numeric_limits<int>::max()

string makeLargestSpecial(string S) {
    int count = 0;
    int mini = inf;
    for(int i = 0; i < S.length(); i++) {
        if(S[i] == '1') {
            if(i > 0 && S[i - 1] == '0') {
                mini = min(mini, count);
            }
            count += 1;
        }
        else
            count -= 1;
    }
    if(mini == inf)
        return S;
    string prefix(mini, '1');
    string suffix(mini, '0');
    S = S.substr(mini, S.length() - mini - mini);
    int cnt = 0;
    int pos = 0;
    int start = 0;
    vector<string> tmp;
    while(pos < S.length()) {
        if(S[pos] == '1')
            cnt += 1;
        else {
            cnt -= 1;
            if(cnt == 0) {
                string cur = S.substr(start, pos + 1 - start); //当前0所在位置终止了一个special string
                string convert = makeLargestSpecial(cur);
                tmp.push_back(convert);
                start = pos + 1;
            }
        }
        pos += 1;
    }
    while(!tmp.empty()) {
        bool update = false;
        for(int i = 0; i < tmp.size() - 1; i++) {
            if(tmp[i] + tmp[i + 1] < tmp[i + 1] + tmp[i]) {
                swap(tmp[i + 1], tmp[i]);
                update = true;
            }
        }
        if(!update)
            break;
    }
    string res = "";
    for(auto item: tmp)
        res = res + item;
    return prefix + res + suffix;
}
