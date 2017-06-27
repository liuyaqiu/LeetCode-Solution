#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef pair<int, int> mypair;

string convert(string s1, string s2) {
    set<char> cnt;
    for(int i = 0; i < s2.length(); i++)
        cnt.insert(s2[i]);
    string res = "";
    set<char> tmp;
    for(int i = 0; i < s1.length(); i++) {
        if(cnt.find(s1[i]) != cnt.end()) {
            res += s1[i];
            tmp.insert(s1[i]);
        }
    }
    if(tmp.size() < cnt.size())
        return "";
    else
        return res;
}

int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    s1 = convert(s1, s2);
    if(s1.empty())
        return 0;
    int len1 = s1.length(), len2 = s2.length();
    map<mypair, mypair> dp;
    int x1 = 0, x2 = 0;
    while(x1 < len1 * n1) {
        while(s1[x1 % len1] != s2[x2 % len2])
            x1 += 1;
        if(x1 >= len1 * n1)
            break;
        int y1 = x1 % len1;
        int y2 = x2 % len2;
        mypair cur(y1, y2);
        if(dp.find(cur) == dp.end()) {
            dp[cur] = mypair(x1, x2);
        }
        else {
            int dx1 = dp[cur].first, dx2 = dp[cur].second;
            int round = (len1 * n1 - dx1) / (x1 - dx1);
            //由于存在循环，将x1移动round轮，每次移动的距离是(x1 - dx1)
            //显然此过程中x2每次移动的距离是(x2 - dx2)
            x1 = dx1 + round * (x1 - dx1);
            x2 = dx2 + round * (x2 - dx2);
        }
        if(x1 < len1 * n1) {
            x1 += 1;
            x2 += 1;
        }
    }
    return x2 / (n2 * len2);
}

int main() {
    string s1, s2;
    int n1, n2;
    cin >> s1 >> n1;
    cin >> s2 >> n2;
    int res = getMaxRepetitions(s1, n1, s2, n2);
    cout << res << endl;
    return 0;
}

/*
nlhqgllunmelayl
2
lnl
1
*/
