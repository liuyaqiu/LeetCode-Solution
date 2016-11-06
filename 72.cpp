#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<vector<int>>& res) {
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }
}

int minDistance(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> res(m + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < m + 1; ++i)
        res[i][0] = i;
    for(int j = 0; j < n + 1; ++j)
        res[0][j] = j;
    for(int i = 1; i < m + 1; ++i) {
        for(int j = 1; j < n + 1; ++j) {
            int tmp1;
            if(s1[i - 1] == s2[j - 1])
                tmp1 = res[i - 1][j - 1];
            else
                tmp1 = res[i - 1][j - 1] + 1;
            int tmp2 = min(res[i][j - 1], res[i - 1][j]) + 1;
            res[i][j] = min(tmp1, tmp2);
        }
    }
    return res[m][n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int res = minDistance(s1, s2);
    cout << "The distance is: " << res << endl;
    return 0;
}
