#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Longest Substring with At Least K Repeating Characters
 *
 * Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.
 *
 * Example 1:
 *
 * Input:
 * s = "aaabb", k = 3
 *
 * Output:
 * 3
 *
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 * Example 2:
 *
 * Input:
 * s = "ababbc", k = 2
 *
 * Output:
 * 5
 *
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 *
 */

int longestSubstring(string s, int k) {
    vector<int> cnt(26, 0);
    int n = s.length();
    for(int i = 0; i < n; i++)
        cnt[s[i] - 'a'] += 1;
    bool judge = true;
    for(auto c: cnt) {
        if(c >= k) {
            judge = false;
            break;
        }
    }
    if(judge)
        return 0;
    int pos = 0;
    while(pos < n && cnt[s[pos] - 'a'] >= k)
        pos++;
    if(pos >= n)
        return n;
    else
        return max(longestSubstring(s.substr(0, pos), k), longestSubstring(s.substr(pos + 1, n - pos - 1), k));
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    int res = longestSubstring(s, k);
    cout << res << endl;
    return 0;
}
