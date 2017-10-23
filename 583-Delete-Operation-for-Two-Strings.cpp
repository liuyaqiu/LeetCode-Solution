/*
  Delete Operation for Two Strings

  Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

  Example 1:
  Input: "sea", "eat"
  Output: 2
  Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
  Note:
  The length of given words won't exceed 500.
  Characters in given words can only be lower-case letters.

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minDistance(string word1, string word2) {
    int n1 = word1.length(), n2 = word2.length();
    vector<vector<int>> res(n1 + 1, vector<int>(n2 + 1, 0));
    for(int i = 1; i < res.size(); i++) {
        for(int j = 1; j < res[0].size(); j++) {
            if(word1[i - 1] == word2[j - 1])
                res[i][j] = res[i - 1][j - 1] + 1;
            else
                res[i][j] = max(res[i - 1][j], res[i][j - 1]);
        }
    }
    return n1 + n2 - 2 * res[n1][n2];
}
