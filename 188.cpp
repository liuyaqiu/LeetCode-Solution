#include <iostream>
#include <vector>

using namespace std;

int solveProfit(vector<int>& prices) {
	if(prices.empty())
		return 0;
    int profit = 0;
    for(int i = 0; i < prices.size() - 1; i++) {
        if(prices[i + 1] - prices[i] > 0)
            profit += prices[i + 1] - prices[i];
    }
    return profit;
}

int maxProfit(int k, vector<int>& prices) {
    if(prices.size() <= k)
        return solveProfit(prices);
    int n = prices.size();
    vector<vector<int>> local(n, vector<int>(k + 1, 0));
    vector<vector<int>> global(n, vector<int>(k + 1, 0));
    for(int j = 0; j < k + 1; j++) {
        local[0][j] = 0;
        global[0][j] = 0;
    }
    for(int i = 0; i < n; i++) {
        local[i][0] = 0;
        global[i][0] = 0;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < k + 1; j++) {
            int diff = prices[i] - prices[i - 1];
            local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
            global[i][j] = max(local[i][j], global[i - 1][j]);
        }
    }
    return global[n - 1][k];
}

int main() {
    int val;
    vector<int> prices;
    while(cin >> val)
        prices.push_back(val);
    int k;
    cin >> k;
    int res = maxProfit(k, prices);
    cout << res << endl;
    return 0;
}
