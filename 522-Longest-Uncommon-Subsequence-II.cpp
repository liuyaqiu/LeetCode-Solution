/*
  Longest Uncommon Subsequence II

  Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

  A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

  The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

  Example 1:
  Input: "aba", "cdc", "eae"
  Output: 3
  Note:

  All the given strings' lengths will not exceed 10.
  The length of the given list will be in the range of [2, 50].

 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool isSub(string a, string b) {
    int pos1 = 0, pos2 = 0;
    while(pos1 < a.length() && pos2 < b.length()) {
        while(pos2 < b.length() && b[pos2] != a[pos1])
            pos2++;
        if(pos2 >= b.length())
            return false;
        else {
            pos1++;
            pos2++;
        }
    }
    return pos1 >= a.length();
}

int findLUSlength(vector<string>& strs) {
    map<string, int> cnt;
    for(auto str: strs) {
        if(cnt.find(str) != cnt.end())
            cnt[str] += 1;
        else
            cnt[str] = 1;
    }
    int len = -1;
    for(auto item: cnt) {
        if(item.second == 1) {
            bool judge = false;
            for(auto it: cnt) {
                if(it.first != item.first && it.first.length() >= item.first.length() && isSub(item.first, it.first)) {
                    judge = true;
                    break;
                }
            }
            if(!judge)
                len = max(len, (int)item.first.length());
        }
    }
    return len;
}

int main() {
    vector<string> strs;
    string str;
    while(cin >> str) {
        strs.push_back(str);
    }
    int res = findLUSlength(strs);
    cout << res << endl;
    // string a, b;
    // cin >> a >> b;
    // cout << isSub(a, b) << endl;
    return 0;
}
