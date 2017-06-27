#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    set<int> ht(heaters.begin(), heaters.end());
    if(heaters.front() >= houses.back())
        return heaters.front() - houses.front();
    if(heaters.back() <= houses.front())
        return houses.back() - heaters.back();
    int tmp1 = max(abs(heaters.front() - houses.front()), abs(heaters.front() - houses.back()));
    int tmp2 = max(abs(heaters.back() - houses.front()), abs(heaters.back() - houses.back()));
    int high = min(tmp1, tmp2);
    int low = 0;
    while(low < high) {
        int mid = (low + high) / 2;
        bool lower = false;
        for(auto house: houses) {
            auto iter = ht.lower_bound(house - mid);
            if(iter != ht.end() && *iter <= house + mid) {
                continue;
            }
            else {
                lower = true;
                break;
            }
        }
        if(lower)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int findRadius2(vector<int>& houses, vector<int>& heaters) {
    set<int> ht(heaters.begin(), heaters.end());
    long res = 0;
    for(auto house: houses) {
        auto iter = ht.lower_bound(house);
        if(iter == ht.begin()) {
            res = max(long(*iter) - long(house), res);
        }
        else {
            if(iter == ht.end()) {
                res = max(long(house) - long(*prev(iter)), res);
            }
            else {
                auto pre = prev(iter);
                res = max(res, min(long(*iter) - long(house), long(house) - long(*pre)));
            }
        }
    }
    return res;
}

int main() {
    int m, n;
    cin >> m >> n;
    int val;
    vector<int> houses, heaters;
    for(int i = 0; i < m; i++) {
        cin >> val;
        houses.push_back(val);
    }
    for(int j = 0; j < n; j++) {
        cin >> val;
        heaters.push_back(val);
    }
    int res = findRadius(houses, heaters);
    cout << res << endl;
    return 0;
}
