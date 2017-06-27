#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <unordered_set>

#define inf numeric_limits<int>::max();

using namespace std;

int minCut(string s) {
    int n = s.length();
    vector<int> Cut(n, 0);
    vector<vector<bool>> Pal(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++) {
        Pal[i][i] = true;
    }
    for(int L = 2; L <= s.length(); L++) {
        for(int i = 0; i < n - L + 1; i++) {
            int j = i + L - 1;
            if(L == 2)
                Pal[i][j] = (s[i] == s[j]);
            else
                Pal[i][j] = (s[i] == s[j]) && Pal[i + 1][j - 1];
        }
    }
    for(int i = 0; i < n; i++) {
        if(Pal[0][i])
            Cut[i] = 0;
        else {
            Cut[i] = inf;
            for(int j = 0; j < i; j++) {
                if(Pal[j + 1][i] && 1 + Cut[j] < Cut[i])
                    Cut[i] = 1 + Cut[j];
            }
        }
    }
    return Cut[n - 1];
}

int main() {
    string s;
    cin >> s;
    int res = minCut(s);
    cout << res << endl;
    return 0;
}
