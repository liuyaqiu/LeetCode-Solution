#include <iostream>
#include <vector>
#include <map>

using namespace std;

int numberOfArithmeticsSlices(vector<int>& A) {
    int len = A.size();
    vector<map<int, int>> dp(len, map<int, int>());
    int res = 0;
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < i; j++) {
            int delta = A[i] - A[j];
            if(dp[i].find(delta) == dp[i].end())
                dp[i][delta] = 1;
            else
                dp[i][delta] += 1;
            if(dp[j].find(delta) != dp[j].end()) {
                dp[i][delta] += dp[j][delta];
                res += dp[j][delta];
            }
        }
    }
    return res;
}

