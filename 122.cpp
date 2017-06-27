#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	if(prices.empty())
		return 0;
    int profit = 0;
    for(int i = 0; i < prices.size() - 1; i++) {
        if(prices[i + 1] - prices[i] > 0)
            profit += prices[i + 1] - prices[i];
    }
    return profit;
}

int main() {
    int val;
    vector<int> prices;
    while(cin >> val)
        prices.push_back(val);
    int res = maxProfit(prices);
    cout << res << endl;
    return 0;
}
