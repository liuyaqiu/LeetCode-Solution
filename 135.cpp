#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int candy(vector<int>& ratings) {
	if(ratings.empty())
		return 0;
    vector<int> value(ratings.size());
    value[0] = 1;
    for(int i = 1; i < ratings.size(); i++) {
        if(ratings[i] > ratings[i - 1])
            value[i] = value[i - 1] + 1;
        else
            value[i] = 1;
    }
    for(int i = ratings.size() - 2; i >= 0; i--) {
        if(ratings[i] > ratings[i + 1]) {
            if(i > 0)
                value[i] = max(value[i], value[i + 1] + 1);
            else
                value[i] = value[i + 1] + 1;
        }
    }
    int sum = 0;
    for(auto iter = value.begin(); iter != value.end(); iter++) {
        sum += *iter;
    }
    return sum;
}

int main() {
    int val;
    vector<int> ratings;
    while(cin >> val) {
        ratings.push_back(val);
    }
    int res = candy(ratings);
    cout << "The res is: " << res << endl;
    return 0;
}
