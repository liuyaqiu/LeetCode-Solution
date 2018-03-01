/*
  Monotone Increasing Digits

  Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

  (Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

  Example 1:
  Input: N = 10
  Output: 9
  Example 2:
  Input: N = 1234
  Output: 1234
  Example 3:
  Input: N = 332
  Output: 299
  Note: N is an integer in the range [0, 10^9].

 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int monotoneIncreasingDigits(int N) {
    string num = to_string(N);
    int pos = 0;
    while((pos < num.size() - 1 && num[pos] <= num[pos + 1]) || pos == num.size() - 1)
        pos += 1;
    while(pos > 0 && num[pos] == num[pos - 1])
        pos -= 1;
    string left = num.substr(0, pos);
    if(pos < num.size()) {
        if(num[pos] == 1) {
            if(pos != 0)
                left = left + "0";
        }
        else
            left = left + to_string(stoi(num.substr(pos, 1)) - 1);
        left = left + string(num.size() - pos - 1, '9');
    }
    return stoi(left);
}
