/*
  2 Keys Keyboard

  Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

  Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
  Paste: You can paste the characters which are copied last time.
  Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

  Example 1:
  Input: 3
  Output: 3
  Explanation:
  Intitally, we have one character 'A'.
  In step 1, we use Copy All operation.
  In step 2, we use Paste operation to get 'AA'.
  In step 3, we use Paste operation to get 'AAA'.
  Note:
  The n will be in the range [1, 1000].

 */

#include <iostream>
#include <vector>

using namespace std;

int minSteps(int n) {
    vector<int> res(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = 2 * i; j <= n;j += i) {
            if(res[j] == 0)
                res[j] = res[i] + j / i;
            else
                res[j] = min(res[j], res[i] + j / i);
        }
    }
    return res[n];
}
