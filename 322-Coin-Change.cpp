#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int select(vector<int>& cnt, vector<int>& coins, int amount) {
    int n = coins.size();
    int res = -1;
    int m = -1;
    for(int i = 0; i < n; i++) {
        int val = amount - coins[i];
        if(val >= 0 && cnt[val] >= 0) {
            if(m < 0 || cnt[val] < m) {
                res = i;
                m = cnt[val];
            }
        }
    }
    return res;
}

int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end());
    vector<int> cnt(amount + 1, 0);
    for(int i = 1; i < amount + 1; i++) {
        int k = select(cnt, coins, i);
        if(k < 0)
            cnt[i] = -1;
        else
            cnt[i] = cnt[i - coins[k]] + 1;
    }
    return cnt[amount];
};

int main() {
    int amount;
    cin >> amount;
    int val;
    vector<int> coins;
    while(cin >> val)
        coins.push_back(val);
    int res = coinChange(coins, amount);
    cout << res << endl;
    return 0;
}
