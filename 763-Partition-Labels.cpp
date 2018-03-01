/*
  Partition Labels

  A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

  Example 1:
  Input: S = "ababcbacadefegdehijhklij"
  Output: [9,7,8]
  Explanation:
  The partition is "ababcbaca", "defegde", "hijhklij".
  This is a partition so that each letter appears in at most one part.
  A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
  Note:

  S will have length in range [1, 500].
  S will consist of lowercase letters ('a' to 'z') only.

 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> partitionLabels(string S) {
    int start = 0, end = 0;
    vector<int> res;
    while(end < S.length()) {
        int s = start;
        while(start <= end) {
            int pos = S.find_last_of(S[start]);
            if(pos != -1 && pos > end)
                end = pos;
            start += 1;
        }
        end = start;
        res.push_back(start - s);
    }
    return res;
}
