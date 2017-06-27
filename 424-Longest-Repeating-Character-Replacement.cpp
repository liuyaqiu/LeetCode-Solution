#include <iostream>
#include <vector>
#include <string>

using namespace std;

int characterReplacement(string s, int k) {
    vector<int> cnt(26, 0);
    int w_start = 0, best = 0;
    for(int w_end = 0; w_end < s.length(); w_end++) {
        cnt[s[w_end] - 'A']++;
        best = max(best, cnt[s[w_end] - 'A']);
        if(best + k <= w_end - w_start) {
            cnt[s[w_start] - 'A']--;
            w_start++;
        }
    }
    return s.length() - w_start;
}
