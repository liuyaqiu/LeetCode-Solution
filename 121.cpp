#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.empty())
        return 0;
    int min = prices[0];
    int profit = 0;
    for(auto iter = prices.begin(); iter != prices.end(); iter++) {
        if(*iter < min)
            min = *iter;
        else {
            if(*iter - min > profit)
                profit = *iter - min;
        }
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
