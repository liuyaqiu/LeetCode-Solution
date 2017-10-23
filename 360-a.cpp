#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pack(vector<int>& time, int t) {
    int sums = 0;
    for(auto item: time)
        sums += item;
    if(sums <= t)
        return sums;
    int n = time.size();
    vector<vector<int>> res(n + 1, vector<int>(t, 0));
    vector<vector<int>> tmp(res);
    int result = 0;
    for(int i = 1; i <= n; i++) {
        res = tmp;
        for(int j = 1; j <= n; j++) {
            for(int k = 0; k < t; k++) {
                if(j == i)
                    res[j][k] = res[j - 1][k];
                else {
                    if(time[j - 1] > k)
                        res[j][k] = res[j - 1][k];
                    else
                        res[j][k] = max(res[j - 1][k], res[j - 1][k - time[j - 1]] + time[j - 1]);
                }
            }
        }
        result = max(time[i - 1] + res[n][t - 1], result);
    }
    return result;
}

int main() {
    int n, t;
    scanf("%d%d", &n, &t);
    vector<int> time;
    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        time.push_back(val);
    }
    int res = pack(time, t);
    printf("%d\n", res);
    return 0;
}
