#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

int maxProfit(vector<int>& prices) {
	if(prices.empty())
		return 0;
    int n = prices.size();
    vector<int> left(n, 0);   
    vector<int> right(n, 0);
    int min = 0;
    int lp = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            min = prices[i];
        }
        else {
            if(prices[i] < min) {
                min = prices[i];
            }
            else {
            	int tmp = prices[i] - min;
            	if(lp < tmp)
            		lp = tmp;
            }
        }
        left[i] = lp;
    }
    int max = 0;
    int rp = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(i == n - 1) {
            max = prices[i];
        }
        else {
            if(prices[i] > max) {
                max = prices[i];
            }
            else {
            	int tmp = max - prices[i];
            	if(rp < tmp)
            		rp = tmp;
            }
        }
        right[i] = rp;
    }
    //print(prices);
    //print(left);
    //print(right);
    int res = 0;
    for(int i = 0; i < n; i++) {
        int tmp = left[i] + right[i];
        if(tmp > res)
            res = tmp;
    }
    return res;
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

