/*
  Jewels and Stones

  You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

  The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

  Example 1:

  Input: J = "aA", S = "aAAbbbb"
  Output: 3
  Example 2:

  Input: J = "z", S = "ZZ"
  Output: 0
  Note:

  S and J will consist of letters and have length at most 50.
  The characters in J are distinct.

 */

#include <iostream>
#include <vector>

using namespace std;

int numJewelsInStones(string J, string S) {
    vector<bool> cnt(52, false);
    for(int i = 0; i < J.length(); i++) {
        if(J[i] - 'a' >= 0 && J[i] - 'a' < 26)
            cnt[J[i] - 'a'] = true;
        if(J[i] - 'A' >= 0 && J[i] - 'A' < 26)
            cnt[J[i] - 'A' + 26] = true;
    }
    int res = 0;
    for(int i = 0; i < S.length(); i++) {
        int c = -1;
        if(S[i] - 'a' >= 0 && S[i] - 'a' < 26)
            c = S[i] - 'a';
        if(S[i] - 'A' >= 0 && S[i] - 'A' < 26)
            c = S[i] - 'A' + 26;
        if(cnt[c])
            res += 1;
    }
    return res;
}
