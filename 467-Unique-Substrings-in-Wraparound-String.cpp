#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool next(char c1, char c2) {
	return c2 - 'a' == (c1 - 'a' + 1) % 26;
}

int findSubstringInWraproundString(string p) {
    int n = p.length();
    int pos = 0;
    vector<int> cnt(26, 0);
    while(pos < n) {
        int start = pos;
        pos++;
        while(pos < n && next(p[pos - 1], p[pos]))
            pos++;
        for(int i = start; i < pos; i++) {
            cnt[p[i] - 'a'] = max(pos - i, cnt[p[i] - 'a']);
        }
    }
    int res = 0;
    for(auto item: cnt) {
        res += item;
    }
    return res;
}
