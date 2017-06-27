#include <iostream>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length())
        return false;
    vector<int> cnt(26, 0);
    for(int i = 0; i < s.length(); i++) {
        int pos = s[i] - 'a';
        cnt[pos] += 1;
    }
    for(int i = 0; i < t.length(); i++) {
        int pos = t[i] - 'a';
        cnt[pos] -= 1;
        if(cnt[pos] < 0)
            return false;
    }
    return true;
}
