/*
  Reorganize String

  Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

  If possible, output any possible result.  If not possible, return the empty string.

  Example 1:

  Input: S = "aab"
  Output: "aba"
  Example 2:

  Input: S = "aaab"
  Output: ""
  Note:

  S will consist of lowercase letters and have length in range [1, 500].

 */

#include <iostream>
#include <vector>

typedef pair<int, char> mypair;

struct comp {
    bool operator() (const mypair& lhs, const mypair& rhs) const {
        return lhs.first < rhs.first;
    }
};

string reorganizeString(string S) {
    vector<mypair> cnt;
    for(int i = 0; i < 26; i++)
        cnt.push_back(mypair(0, 'a' + i));
    for(int i = 0; i < S.length(); i++)
        cnt[S[i] - 'a'].first += 1;
    sort(cnt.begin(), cnt.end(), comp());
    int k = 0;
    for(int i = 0; i < 25; i++)
        k += cnt[i].first;
    if(k < cnt.back().first - 1)
        return "";
    string res(cnt.back().first, cnt.back().second);
    cnt.pop_back();
    while(!cnt.empty() && cnt.back().first != 0) {
        string new_res = "";
        int pos = 0;
        for(int i = 0; i < res.length(); i++) {
            new_res = new_res + res[i];
            new_res = new_res + cnt.back().second;
            cnt.back().first -= 1;
            if(cnt.back().first <= 0)
                cnt.pop_back();
            pos = i;
            if(cnt.empty() || cnt.back().first == 0)
                break;
        }
        res = new_res + res.substr(pos + 1, res.length() - pos - 1);
    }
    return res;
}
