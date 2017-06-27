#include <iostream>
#include <vector>

using namespace std;

/*
 * Best Time to Buy and Sell Stock with Cooldown
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 *
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 * Example:
 *
 * prices = [1, 2, 3, 0, 2]
 * maxProfit = 3
 * transactions = [buy, sell, cooldown, buy, sell]
 *
 *
 */

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n <= 1)
        return 0;
    if(n == 2)
        return max(0, prices[1] - prices[0]);
    vector<int> profits1(n, 0); //第i天买入
    vector<int> profits2(n, 0); //第i天卖出
    vector<int> profits3(n, 0); //第i天cooldown
    vector<int> profits4(n, 0); //第i天无
    int v1 = prices[1] - prices[0];
    profits1[1] = 0;
    profits2[1] = v1;
    profits3[1] = 0;
    profits4[1] = 0;
    for(int i = 2; i < n; i++) {
        int val = prices[i] - prices[i - 1];
        profits1[i] = max(profits3[i - 1], profits4[i - 1]);
        profits2[i] = max(profits1[i - 1], profits2[i - 1]) + val;
        profits3[i] = profits2[i - 1];
        profits4[i] = max(profits3[i - 1], profits4[i - 1]);
    }
    print(prices);
    print(profits1);
    print(profits2);
    print(profits3);
    print(profits4);
    return max(profits1.back(), max(profits2.back(), max(profits3.back(), profits4.back())));
}

int main() {
    int val;
    vector<int> prices;
    while(cin >> val) {
        prices.push_back(val);
    }
    int res = maxProfit(prices);
    cout << res << endl;
    return 0;
}
