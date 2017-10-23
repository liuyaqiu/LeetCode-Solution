/*
  Shopping Offers

  In LeetCode Store, there are some kinds of items to sell. Each item has a price.

However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.

You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job is to output the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers.

Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, other numbers represents how many specific items you could get if you buy this offer.

You could use any of special offers as many times as you want.

Example 1:
Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
Output: 14
Explanation: 
There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B. 
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
Example 2:
Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
Output: 11
Explanation: 
The price of A is $2, and $3 for B, $4 for C. 
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
You cannot add more items, though only $9 for 2A ,2B and 1C.
Note:
There are at most 6 kinds of items, 100 special offers.
For each item, you need to buy at most 6 of them.
You are not allowed to buy more items than you want, even if that would lower the overall price.

 */

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <limits>

using namespace std;
#define inf numeric_limits<int>::max()

string vec2str(vector<int>& vec) {
    string res;
    for(auto item: vec) {
        char c = '0' + item;
        res = res + c;
    }
    return res;
}

vector<int> used(vector<int>& offer, int k, vector<int>& target) {
    vector<int> res = target;
    for(int i = 0; i < res.size(); i++)
        res[i] -= k * offer[i];
    return res;
}

bool judge(vector<int>& target) {
    for(auto item: target) {
        if(item > 0)
            return false;
    }
    return true;
}

int resolve(vector<map<string, int>>& res, vector<vector<int>>& offers, vector<int>& prices, int n, vector<int>& target) {
    if(judge(target))
        return 0;
    if(n < 0)
        return inf;
    string code = vec2str(target);
    if(res[n].find(code) != res[n].end())
        return res[n][code];
    int maxi = inf;
    for(int i = 0; i < target.size(); i++) {
        if(offers[n][i] > 0)
            maxi = min(maxi, target[i] / offers[n][i]);
    }
    int cur = inf;
    if(maxi != inf) {
        for(int i = 0; i <= maxi; i++) {
            vector<int> tmp = used(offers[n], i, target);
            int previous = resolve(res, offers, prices, n - 1, tmp);
            if(previous != inf)
                cur = min(cur, prices[n] * i + previous);
        }
    }
    res[n][code] = cur;
    return cur;
}

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    vector<vector<int>> offers;
    int n = price.size();
    vector<int> prices;
    for(int i = 0; i < price.size(); i++) {
        vector<int> tmp(n, 0);
        tmp[i] = 1;
        offers.push_back(tmp);
        prices.push_back(price[i]);
    }
    for(auto offer: special) {
        prices.push_back(offer.back());
        offer.pop_back();
        offers.push_back(offer);
    }
    vector<map<string, int>> res(offers.size());
    int result = resolve(res, offers, prices, offers.size() - 1, needs);
    return result;
}

