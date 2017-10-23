/*
  Maximum Swap

  Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

  Example 1:
  Input: 2736
  Output: 7236
  Explanation: Swap the number 2 and the number 7.
  Example 2:
  Input: 9973
  Output: 9973
  Explanation: No swap.
  Note:
  The given number is in the range [0, 108]

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maximumSwap(int num) {
    string s = to_string(num);
    for(int i = 0; i < s.length() - 1; i++) {
        int pos = i;
        for(int j = i + 1; j < s.length(); j++) {
            if(s[j] >= s[pos])
                pos = j;
        }
        if(pos > i && s[pos] > s[i]) {
            swap(s[i], s[pos]);
            break;
        }
    }
    return stoi(s);
}
