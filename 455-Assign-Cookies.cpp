#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int n1 = g.size(), n2 = s.size();
    int pos1 = 0, pos2 = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int cnt = 0;
    while(pos1 < n1) {
        while(pos2 < n2 && s[pos2] < g[pos1])
            pos2++;
        if(pos2 >= n2)
            break;
        pos1++;
        pos2++;
        cnt += 1;
    }
    return cnt;
}

int main() {
    int m, n;
    int val;
    vector<int> g, s;
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        cin >> val;
        g.push_back(val);
    }
    for(int j = 0; j < n; j++) {
        cin >> val;
        s.push_back(val);
    }
    int res = findContentChildren(g, s);
    cout << res << endl;
    return 0;
}
